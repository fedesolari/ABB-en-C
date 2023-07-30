#include "abb.h"
#include <stdio.h>
#include <stdbool.h>

abb_t* arbol_crear(abb_comparador comparador, abb_liberar_elemento destructor){
    
	if(!comparador){
		return NULL;
	}

	abb_t* abb = calloc(1, sizeof(abb_t));

    if(destructor){
    	abb->destructor = destructor;
    }
   	abb->comparador = comparador;
   	return abb;
}

int insertar_nodo(abb_t* abb, nodo_abb_t* actual, nodo_abb_t* nuevo){

	//izquierda
	if(abb->comparador(actual->elemento, nuevo->elemento) >= 0){
		if(actual->izquierda == NULL){
			actual->izquierda = nuevo;
			return 0;
		}
		return insertar_nodo(abb, actual->izquierda, nuevo);
	}
	else{//derecha
		if(actual->derecha == NULL){
			actual->derecha = nuevo;
			return 0;
		}
		return insertar_nodo(abb, actual->derecha, nuevo);
	}
	free(nuevo);
	return -1;
}

int arbol_insertar(abb_t* arbol, void* elemento){

	if(!arbol)
		return -1;

	nodo_abb_t* nuevo = calloc(1, sizeof(nodo_abb_t));
	nuevo->elemento = elemento;
	nuevo->izquierda = NULL;
	nuevo->derecha = NULL;

	if(arbol_vacio(arbol)){
		arbol->nodo_raiz = nuevo;
		return 0;
	}

	return insertar_nodo(arbol, arbol->nodo_raiz, nuevo);
}

/*
 * Recibe un nodo con todas sus estructuras validas
 * Devuelve true si no tiene nodo a la izquierda y a la derecha. En caso contrario devuelve false
*/
bool es_hoja(nodo_abb_t* nodo){
	if(nodo != NULL && nodo->derecha == NULL && nodo->izquierda == NULL)
		return true;
	return false;
}

/*
 * Recibe el arbol con el nodo del elemento que quiere destruir 
 * Si el arbol tiene un destructor lo utiliza
*/
void destruir_elemento(abb_t* arbol, nodo_abb_t* eliminar){
	if(arbol->destructor){
		arbol->destructor(eliminar->elemento);
	}
	return;
}

/*
 * Recibe un nodo con todas sus estructuras validas
 * Si el nodo tiene un nodo que no sea nulo en su rama derecha devuelve true, en caso contrario devuelve false
*/
bool tiene_derecha(nodo_abb_t* nodo){
	return (nodo->derecha != NULL);
}

/*
 * Recibe un nodo con todas sus estructuras validas
 * Si el nodo tiene un nodo que no sea nulo en su rama derecha devuelve true, en caso contrario devuelve false
*/
bool tiene_izquierda(nodo_abb_t* nodo){
	return (nodo->izquierda != NULL);
}

/*
 * Recibe el arbol junto con dos nodos, el anterior sera la raiz del arbol o de un sub arbol y el actual su elemento a la derecha en el caso inicial luego sera     	siempre el de la izquierda del anterior
 * 
 * Si el nodo actual tiene izquierda se llamara una y otra vez recursivamente hasta que encuentre un nodo actual que no la tenga
 
 * Si el nodo encontrado no tiene derecha y no es el elemento de la derecha del anterior ni tampoco el anterior es la raiz del arbol al anterior le va a poner como rama izquierda  NULL
 
 * Si solamente no tiene derecha le pondra como rama derecha  NULL
 
 * Devolvera el ultimo nodo con rama izquierda que haya encontrado 
*/
nodo_abb_t* buscar_predecesor_inorden(abb_t* arbol, nodo_abb_t* anterior, nodo_abb_t* actual){
	
	if(tiene_derecha(actual)){
		return buscar_predecesor_inorden(arbol, actual, actual->derecha);
	}

	if(!tiene_izquierda(actual) && anterior->izquierda != actual && anterior != arbol->nodo_raiz){
		anterior->derecha = NULL;
	}
	else if(!tiene_izquierda(actual)){
		anterior->izquierda = NULL;
	}
	return actual;
}

/*
 * Recibe el arbol junto con dos nodos, el anterior sera la raiz del arbol o de un sub arbol y el actual su elemento a la derecha en el caso inicial luego sera     	siempre el de la izquierda del anterior
 * 
 * Devolvera el ultimo nodo con rama izquierda que haya encontrado 
*/
nodo_abb_t* anterior_predecesor(abb_t* arbol, nodo_abb_t* anterior, nodo_abb_t* actual){
	
	if(tiene_derecha(actual))
		return anterior_predecesor(arbol, actual, actual->derecha);

	return anterior;
}


/*
 * Recibe el arbol junto con dos nodos, el anterior y el que le sigue al anterior
 * 
 * Compara el elemento con el elemento del nodo actual, si es mayor o menor se llama a si misma pasandole como anterior la 
 * direccion del actual, y como actual la direccion del su siguiente a la izquierda o derecha, si era mayor sera derecha sino la izquierda
 * 
 * Devolvera el nodo anterior al buscado en caso de encontrarlo. En caso contrario devolvera NULL
*/
nodo_abb_t* encontrar_elemento(abb_t* abb, nodo_abb_t* anterior, nodo_abb_t* actual, void* elemento){
	
	if(!actual){
		return NULL;
	}

	int comparacion = abb->comparador(actual->elemento, elemento);

	if(comparacion > 0){//tengo que ir para la izquierda
		return encontrar_elemento(abb, actual, actual->izquierda, elemento);
	}
	else if(comparacion < 0){//tengo que ir para la derecha
		return encontrar_elemento(abb, actual, actual->derecha, elemento);
	}
	return anterior;
}

/*
 *	Recibe el arbol junto con dos nodos, el anterior y el que le sigue al anterior.
 * 
 *  Si el actual se encuentra a la derecha del anterior, cambia esa direccion y pone direccion null
 *  Si el actual se encuentra a la izquierda del anterior, cambia esa direccion y pone direccion null
 * 
 *  Destruye el elemento y lugo libera el nodo. LUego sale de la funcion devolviendo 0
*/
int eliminar_hojas(abb_t* arbol, nodo_abb_t* anterior, nodo_abb_t* actual){
	if(anterior->derecha == actual)
		anterior->derecha = NULL;	
	else
		anterior->izquierda = NULL;

	destruir_elemento(arbol, actual);
	free(actual);
	return 0;
}

/*
 *	Recibe el arbol. Busca su sucesor inorden y lo inserta en el lugar donde se encontraba la raiz
 *  
 *  Destruye el elemento de la raiz y libera el nodo del elememento que se encontraba en la raiz. Luego sale de la funcion devolviendo 0
*/
int borrar_raiz_con_rama_izquierda(abb_t* arbol){

	nodo_abb_t* anterior = anterior_predecesor(arbol, arbol->nodo_raiz, arbol->nodo_raiz->izquierda);// se que el sucesor in orden esta en la izq
	nodo_abb_t* nueva_raiz = buscar_predecesor_inorden(arbol, arbol->nodo_raiz, arbol->nodo_raiz->izquierda);

	if(!tiene_izquierda(nueva_raiz) && nueva_raiz != arbol->nodo_raiz->izquierda){
		nueva_raiz->izquierda = arbol->nodo_raiz->izquierda;
	}
	else if(tiene_izquierda(nueva_raiz) && nueva_raiz != arbol->nodo_raiz->izquierda){//mirar eliminar_raiz_subarbol, no esta entrando en este else if
		anterior->derecha = nueva_raiz->izquierda;
		nueva_raiz->izquierda = arbol->nodo_raiz->izquierda;
	}

	nueva_raiz->derecha = arbol->nodo_raiz->derecha;
	
	destruir_elemento(arbol, arbol->nodo_raiz);
	free(arbol->nodo_raiz);
	arbol->nodo_raiz = nueva_raiz;

	return 0;
}

/*
 *	Recibe el arbol y cambia la raiz por el nodo que tiene a su izquierda
 * 
 *  Destruye el elemento de la raiz y libera el nodo del elememento que se encontraba en la raiz. Luego sale de la funcion devolviendo 0
*/
int borrar_raiz(abb_t* arbol){
	
	destruir_elemento(arbol, arbol->nodo_raiz);
	nodo_abb_t* aux = arbol->nodo_raiz;
	arbol->nodo_raiz = arbol->nodo_raiz->derecha;
	free(aux);
	return 0;
}

/*
 *	Recibe el arbol junto con el nodo donde se encuentra y su anterior
 * 
 *  Busca el sucesor inorden y el anterior al sucesor del elemento actual
 *
 *  Destruye el elemento actual, ubica en su lugar al sucesor inorden y lyego libera la memoria del nodo actual. Sale devolviendo 0.
*/
int eliminar_raiz_subarbol(abb_t* arbol, nodo_abb_t* anterior, nodo_abb_t* actual){

	if(es_hoja(actual))
		return eliminar_hojas(arbol, anterior, actual);

	nodo_abb_t* sustituto;
	nodo_abb_t* ant_sucesor;

	if(!tiene_izquierda(actual)){//NO TIENE IZQUIERDA, POR O TANTO NO TIENE PREDECESOR
		if(anterior->derecha == actual)
			anterior->derecha = actual->derecha;
		else
			anterior->izquierda = actual->derecha;
		destruir_elemento(arbol, actual);
		free(actual);
		return 0;
	}

	ant_sucesor = anterior_predecesor(arbol, actual, actual->izquierda);
	sustituto = buscar_predecesor_inorden(arbol, actual, actual->izquierda);

	if(anterior->derecha == actual)//tiene izq y el sustituto es la izquierda del actual
		anterior->derecha = sustituto;
	else
		anterior->izquierda = sustituto;

	sustituto->derecha = actual->derecha;//va en las 3 opciones

	//si el sustituto no es la izquierda del actual y a su vez  tiene izq
	if(sustituto != actual->izquierda){
		ant_sucesor->derecha = sustituto->izquierda;
		sustituto->izquierda = actual->izquierda;
	}

	destruir_elemento(arbol, actual);
	free(actual);
	return 0;
}	

/*
 *	Recibe el arbol, si la raiz tiene derecha llama a una funcion, sino llama a otra diferente 
 * 
 *  Devuelve el valor que returnea una de las dos funciones a las que llama
*/
int eliminar_elemento_en_raiz(abb_t* arbol){

	if(tiene_izquierda(arbol->nodo_raiz)){
		return borrar_raiz_con_rama_izquierda(arbol);
	}
	else{
		return borrar_raiz(arbol);
	}
}

/*
 *	Recibe el arbol junto con un elemento y con un argumento que sera 1 si el elemento es menor a la raiz o -1 si es mayor
 * 
 *  Encuentra el elemento anterior al que se quiere eliminar y llama a la funcion correspondiente pra que lo elimine 
 *
 * En caso en el que no se pueda encontrar el anterior al elmento sale de la funcion devolviendo -1, en caso contrario devuelve el valor de la funcion 
 * correspondiente
*/
int borrar_elemento_mayor_o_menor(abb_t* arbol, int argumento, void* elemento){
	nodo_abb_t* anterior;

	if(argumento < 0){//der---> es mas grande que la raiz
		anterior = encontrar_elemento(arbol, arbol->nodo_raiz, arbol->nodo_raiz->derecha, elemento);
	}
	else{//izq---> es mas chico que la raiz
		anterior = encontrar_elemento(arbol, arbol->nodo_raiz, arbol->nodo_raiz->izquierda, elemento);
	}

	if(!anterior)
		return -1;

	int comparacion = arbol->comparador(anterior->elemento, elemento);

	if(tiene_derecha(anterior) && comparacion < 0)
		return eliminar_raiz_subarbol(arbol, anterior, anterior->derecha);
	else
		return eliminar_raiz_subarbol(arbol, anterior, anterior->izquierda);

	return -1;
}

int arbol_borrar(abb_t* arbol, void* elemento){
	if(!arbol)
		return -1;

	int comparacion = arbol->comparador(arbol->nodo_raiz->elemento, elemento);

	if(es_hoja(arbol->nodo_raiz) && comparacion == 0){//solo tengo la raiz en el arbol
		return borrar_raiz(arbol);
	}
	
	if(comparacion == 0){     //ELEMENTO IGUAL A LA RAIZ
		return eliminar_elemento_en_raiz(arbol);
	}
	else if(comparacion > 0){//ELEMENTO MENOR A LA RAIZ
		return borrar_elemento_mayor_o_menor(arbol, 1, elemento);
	}	
	else{//ELEMENTO MAYOR A LA RAIZ
		return borrar_elemento_mayor_o_menor(arbol, -1, elemento);
	}
	return -1;
}

void* arbol_buscar(abb_t* arbol, void* elemento){
    
    if(arbol_vacio(arbol))
    	return NULL;

    nodo_abb_t* anterior;
    
    if(arbol->comparador(arbol->nodo_raiz->elemento, elemento) == 0)
		return arbol_raiz(arbol);
    else
    	anterior = encontrar_elemento(arbol, arbol->nodo_raiz, arbol->nodo_raiz, elemento);

    if(!anterior)
		return NULL;

	if(tiene_derecha(anterior) && arbol->comparador(anterior->derecha->elemento, elemento) == 0)
		return anterior->derecha->elemento;
	else
		return anterior->izquierda->elemento;

    return NULL;
}

void* arbol_raiz(abb_t* arbol){

	if(!arbol || arbol_vacio(arbol))
		return NULL;
	return arbol->nodo_raiz->elemento;
}

bool arbol_vacio(abb_t* arbol){
    if(!arbol || arbol->nodo_raiz == NULL)
    	return true;
    return false;
}

void** recorrer_inorden(nodo_abb_t* actual, void** vector, int tope, int* contador){
	
	if(tiene_izquierda(actual) && *contador < tope)
		vector = recorrer_inorden(actual->izquierda, vector, tope, contador);
	
	if( *contador >= tope)
		return vector;
	
	vector[*contador] = actual->elemento;
	(*contador) += 1;

	if(tiene_derecha(actual) && *contador <= tope)
		vector = recorrer_inorden(actual->derecha, vector, tope, contador);

	return vector;
}	

size_t arbol_recorrido_inorden(abb_t* arbol, void** array, size_t tamanio_array){
	if(arbol_vacio(arbol))
		return 0;
	
	int contador = 0;
	nodo_abb_t* actual = arbol->nodo_raiz;
	
	//tope es lo mas derecha posible
	array = recorrer_inorden(actual, array, (int)tamanio_array, &contador);
	
	return (size_t)contador;
}

void** recorrer_preorden(nodo_abb_t* actual, void** vector, int tope, int* contador){
	if(*contador >= tope)
		return vector;

	vector[*contador] = actual->elemento;
	(*contador) += 1;

	if(tiene_izquierda(actual) && *contador <= tope)
		vector = recorrer_preorden(actual->izquierda, vector, tope, contador);

	if(tiene_derecha(actual) && *contador <= tope)
		vector = recorrer_preorden(actual->derecha, vector, tope, contador);
	return vector;
}

size_t arbol_recorrido_preorden(abb_t* arbol, void** array, size_t tamanio_array){
    if(arbol_vacio(arbol))
		return 0;
	
	int contador = 0;
	nodo_abb_t* actual = arbol->nodo_raiz;
	
	array = recorrer_preorden(actual, array, (int)tamanio_array, &contador);
	
	return (size_t)contador;
}

void** recorrer_postorden(nodo_abb_t* actual, void** vector, int tope, int* contador){

	if(tiene_izquierda(actual) && *contador < tope)
		vector = recorrer_postorden(actual->izquierda, vector, tope, contador);

	if(tiene_derecha(actual) && *contador < tope)
		vector = recorrer_postorden(actual->derecha, vector, tope, contador);
	
	if(*contador >= tope)
		return vector;

	vector[*contador] = actual->elemento;
	(*contador) += 1;

	return vector;
}

size_t arbol_recorrido_postorden(abb_t* arbol, void** array, size_t tamanio_array){
    if(arbol_vacio(arbol))
		return 0;
	
	int contador = 0;
	nodo_abb_t* actual = arbol->nodo_raiz;
	
	array = recorrer_postorden(actual, array, (int)tamanio_array, &contador);
	
	return (size_t)contador;
}

/*
 *	Recibe el arbol junto con el nodo actual y su siguiente
 * 
 * Recorre todo el arbol hasta llegar al final y va eliminando los nodos y elementos
 * Una vez que no quedan  mas elementos sale de la funcion 
*/
void borrar_desde_las_hojas(abb_t* abb, nodo_abb_t* actual, nodo_abb_t* sig){

	if(sig->izquierda != NULL)
		borrar_desde_las_hojas(abb, sig,  sig->izquierda);
	else if(sig->derecha != NULL)
		borrar_desde_las_hojas(abb, sig, sig->derecha);

	destruir_elemento(abb, sig);
	free(sig);

	if(actual->derecha == sig)
		actual->derecha = NULL;
	else
		actual->izquierda = NULL;

	if(actual->derecha != NULL){
		borrar_desde_las_hojas(abb, actual, actual->derecha);
	}
	return;
}

void arbol_destruir(abb_t* arbol){
	if(!arbol){
		return;
	}
	nodo_abb_t* actual = arbol->nodo_raiz;
	while(!arbol_vacio(arbol)){
		
		if(actual->izquierda != NULL)
			borrar_desde_las_hojas(arbol, actual, actual->izquierda);
		else if(actual->derecha != NULL)
			borrar_desde_las_hojas(arbol, actual, actual->derecha);

		destruir_elemento(arbol, actual);
		free(actual);
		arbol->nodo_raiz = NULL;
	}
	free(arbol);
	return;
}

/*
 * Recibe un nodo inicial de donde va a iniciar el recorrido, un contador por referencia, una funcion  junto con un extra y un corte que mientras que 
 * este sea 0 la funcion seguira corriendo, cuando este es -1 la funcion parara de iterar
 *
 * Recorrera todo el arbol de manera recursiva mientras que la funcion que recibe devuleva false y mientras queden elementos en el arbol, una vez que 
 * devuleve true el corte pasara a ser -1 y se detendra el recorrido
 *
 * Como indica el recorrido es inorden, por lo tanto primero se dirigira lo mas a la izquierda posible y recien en ese momento contara el primer 
 * elemento, luego contara el elemento que se encuentre en la raiz de el sub-arbol que contenia a ese elemento y luego ira a la derecha de esa 
 * raiz si es que posee un nodo derecho. 
*/
int contar_inorden(nodo_abb_t* actual, size_t *contador, bool (*funcion)(void*, void*), void* extra, int* corte){
	
	if(*corte == 0 && tiene_izquierda(actual))
		contar_inorden(actual->izquierda, contador, funcion, extra, corte);
	
	if(*corte == 0 && funcion(actual->elemento, extra)){
		(*contador) += 1;
		return (*corte = -1);
	}
	
	if(*corte == 0)
		(*contador) += 1;
	

	if(tiene_derecha(actual) && *corte == 0)
		contar_inorden(actual->derecha, contador, funcion, extra, corte);

	return 0;
}	

/*
 * Recibe un nodo inicial de donde va a iniciar el recorrido, un contador por referencia, una funcion  junto con un extra y un corte que mientras que 
 * este sea 0 la funcion seguira corriendo, cuando este es -1 la funcion parara de iterar
 *
 * Recorrera todo el arbol de manera recursiva mientras que la funcion que recibe devuleva false y mientras queden elementos en el arbol, una vez que 
 * devuleve true el corte pasara a ser -1 y se detendra el recorrido
 *
 * Como indica el recorrido es postorden, por lo tanto primero se dirigira lo mas a la izquierda posible y recien en ese momento contara el primer 
 * elemento, luego ira a la derecha de la raiz del sub-arbol si es que posee un nodo derecho y por ultimo contara el elemento que se encuentre en la raiz de el sub-arbol que contenia a ese elemento. 
*/
int contar_postorden(nodo_abb_t* actual, size_t *contador, bool (*funcion)(void*, void*), void* extra, int* corte){

	if(*corte == 0 && tiene_izquierda(actual))
		contar_postorden(actual->izquierda, contador, funcion, extra, corte);

	if(*corte == 0 && tiene_derecha(actual))
		contar_postorden(actual->derecha, contador, funcion, extra, corte);
	
	if(*corte == 0 && funcion(actual->elemento, extra)){
		(*contador) += 1;
		return (*corte = -1);
	}

	if(*corte == 0)
		(*contador) += 1;

	return 0;
}

/*
 * Recibe un nodo inicial de donde va a iniciar el recorrido, un contador por referencia, una funcion  junto con un extra y un corte que mientras que 
 * este sea 0 la funcion seguira corriendo, cuando este es -1 la funcion parara de iterar
 *
 * Recorrera todo el arbol de manera recursiva mientras que la funcion que recibe devuleva false y mientras queden elementos en el arbol, una vez que 
 * devuleve true el corte pasara a ser -1 y se detendra el recorrido
 *
 * Como indica el recorrido es preorden, por lo tanto primero contara el elemento que se encuentra en la raiz del subarbol, luego se dirigira a su izquierda si es posible e incrementara el contador y por ultimo contara el elemento que se encuentre ira a la derecha de la raiz del sub-arbol si es que posee un nodo derecho. 
*/
int contar_preorden(nodo_abb_t* actual, size_t *contador, bool (*funcion)(void*, void*), void* extra, int* corte){
	if(*corte == 0 && funcion(actual->elemento, extra)){
		(*contador) += 1;
		return (*corte = -1);
	}

	if(*corte == 0)
		(*contador) += 1;

	if(*corte == 0 && tiene_izquierda(actual))
		contar_preorden(actual->izquierda, contador, funcion, extra, corte);

	if(*corte == 0 && tiene_derecha(actual))
		contar_preorden(actual->derecha, contador, funcion, extra, corte);
	
	return 0;
}


size_t abb_con_cada_elemento(abb_t* arbol, int recorrido, bool (*funcion)(void*, void*), void* extra){

	if(!arbol || !funcion)
		return 0;
	size_t cant_elementos = 0;
	int corte = 0;

	if(recorrido == ABB_RECORRER_INORDEN){
		contar_inorden(arbol->nodo_raiz, &cant_elementos, funcion, extra, &corte);
	}
	else if(recorrido == ABB_RECORRER_POSTORDEN){
		contar_postorden(arbol->nodo_raiz, &cant_elementos, funcion, extra, &corte);
	}
	else if(recorrido == ABB_RECORRER_PREORDEN){
		contar_preorden(arbol->nodo_raiz, &cant_elementos, funcion, extra, &corte);
	}
	return cant_elementos;
}
	