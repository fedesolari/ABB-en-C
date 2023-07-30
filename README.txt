
SOLUCION IMPLEMENTADA (Las soluciones implementadas de borrar y buscar estan pensadas para que busque el sucesor inorden, pero el codigo lo
---------------------   modifique parar que pase las pruebas de chanutron)
---------------------

+ arbol_crear-----> Reservo el espacio de memoria necesario pra almacenar la estructura del arbol. Dicha estructura se compone de una raiz, una funcion de comparacion la cual es la encargada de definir el criterio de separacion de los elementos en el arbol y una funcion de destruccion de elementos que puede estar o ser nula, en caso de no ser nula se la asigno al arbol al igual que la funcion de comparacion.

+ arbol_insertar-----> Recibo el arbol junto con el elemento que quiero insertar, en el caso de que el arbol sea nulo salgo de la funcion. En caso contrario, reservo la memoria suficiente para almacenar un nodo nuevo al cual le asigno el nuevo elemento. Luego tengo dos casos a contemplar:
 
 (1)--> Si el arbol esta vacio, ubico al nuevo nodo como raiz y salgo de la funcion
 
 (2)---> Si el arbol no esta vacio llamo a una funcion ("insertar_nodo") que ira comparando si el elemento es mayor o menor que el nodo donde se encuentra, una vez que llego a un lugar donde la posicion siguiente sea nula lo inserto en ese lugar, es decir que si comparo un elemento con el nodo actual y resulta que el elemento que quiero insertar es mayor que el actual, me fijo si el nodo que esta a la derecha no es nulo, si no es nulo vuelvo a llamar a la funcion tomando a ese elemento como actual y si es nulo inserto el elemento en esa posicion. Si el elemento es mas chico hago exactamente lo mismo pero del lado izquierdo.


+Arbol_borrar---------> Esta funcion la pense como un sistema que a su vez se divide en tres sub-sistemas.

 (1)---> Si recibo un arbol que solo contiene su raiz y ningun elemento, es decir que el arbol es hoja, y a su vez el elemento que busco es el elemento que se encuentra en la raiz llamo a la funcion borrar raiz y devuelvo el valor que me otorga esa funcion. Esa funcion lo que hace es destruir el elemento si es que el arbol tiene un destructor, luego crea un nodo auxiliar que lo que hace es guardar la direccion de memoria de la raiz y luego a la raiz del arbol le otorgo valor nulo y luego libero el nodo que se encontraba en la raiz y el arbol queda vacio. Como esta funcion tambien lo utilizo para otro caso es un poco mas general, pero esta correctamente aplicada para este caso ya que donde digo que pongo al nodo que se encuentra a la izquierda de la raiz, en realidad para este caso, como el arbol tiene solo la raiz se que tanto su hijo izquierdo como derecho contienen NULL por ende lo puedo aplicar a este caso sin problema alguno.

 (2)------> Si el elemento que busco se encuentra en la raiz, llamo a una funcion que divide las soluciones en dos.
 
 Aclaro que no puede no tener rama derecha o izquierda, si o si tiene que tener una de las dos, sino entraria en el caso (1)-

 a) Si el arbol tiene rama derecha llamo a una funcion que se encarga de eliminarlo correctamente. Esta funcion lo primero que hace es encontrar el anterior al suecsor inorden por si llego a necesitarlo y el sucesor inorden del arbol, es decir va a buscar al elemento mas chico de la rama derecha. Una vez que tengo el sucesor inorden corroboro si ese nodo tiene un nodo no nulo en la rama derecha, en caso de no tenerlo y que dicho sucesor no sea el elemento que tiene la raiz a la derecha, le otorgo en su rama derecha lo que tiene la raiz original del arbol en su derecha.
 En caso de tener un elemento en la derecha y que dicho elemento no sea el elemento que esta a la derecha de la raiz original, tengo que ubicar el elemento que esta a la derecha del sucesor y ponerlo a la izquierda del anterior al sucesor, en otras palabras, el elemento que esta a la derecha del sucesor toma su lugar. 
 Una vez hecho alguno de estos dos procesos, tengo que otorgarle al sucesor la rama izquierda  de la raiz original. Luego destruyo el elemento en caso de ser necesario y luego libero el nodo.


 b) Si el arbol no tiene rama derecha tengo tomar el elemento que esta a su izquierda, que  a su vez es raiz de un sub arbol, y ponerlo como raiz, es decir, solo tengo que eliminar la raiz y quedarme con el sub-arbol que tenia a la izquierda. Una vez hecho eso tengo que destruir el elemento si es que es necesario y luego liberar el nodo que habia reservado previamente.

 (3)-----> Si el elemento que busco es mayor o menor que la raiz encuentro el el elemento y tomo al anteior y veo de que lado esta el elemento que busco y proceso a eliminarlo. Una vez hecho esto el problema se divide en 3 sub-problemas:

 a) El elemento que quiero borrar es hoja, verifico de que lado esta el elemento que quiero eliminar y del lado en el que este le tengo que cambiar la direccion a la que apunte el anterior por null para asi eliminarlo correctamente. Si tengo un destructor destruyo el elemento y luego libero el nodo que libere previamente

 b) El elemento que quiero borrar es raiz de un sub arbol, en este caso tengo que buscar el sucesor inorden pero con una particularidad, si el elemento que quiero borrar esta a la derecha del anterior, cuando busque el sucesor inorden solo tengo que ir para el lado izquierdo y lo voy a encontrar, pero si el elemento a borrar se encuentra a la izquierda del anterior, primero tengo que mandarle el elemento que esta a la derecha del que quiero borrar para asi el algoritmo solo tien que recorrer para la izquierda para encontrar el sucesor inorden. Una vez que encuentro el sucesor, si el sucesor no tiene derecha, al anterior a la izquierda le saco el puntero al sucesor y se lo pongo a null y al sucesor le otorgo las dos ramas que contenia el elemento que quiero eliminar, pero si el sucesor tiene derecha le tengo que otorgar al la izquierda elemento anterior al sucesor  la derecha del sucesor y recien ahi puedo hacer que el sucesor tome el lugar del elemento a eliminar. Si tengo un destructor destruyo el elemento y luego libero el nodo que libere previamente 



+ Arbol_buscar-------> En esta funcion empiezo chequeando que el arbol no este vacio, ya que si el arbol esta vacio o es nulo se que no voy a poder encontrar el elemento que busco. En caso contrario utilizo el comparador para saber si el elemento es menor, mayor o igual que la raiz. En el caso de que el elemento sea igual a la raiz directamente devuelvo el elemento de la raiz. En el caso en el que elemento que estoy buscando es mayor o menor a la raiz llamo a la funcio "encontrar_elemento" que lo que va a hacer es ir iterando recursivamente hasta que encuentre el elemento o hasta que no haya mas elementos en la rama en la cual se dirige. Si el elemento actual no es ni mayor ni menor al que busco, osea que es el elemento que busco, devulevo el elemento anterior. una vez que obtengo ese elemento verifico si el elemento que busco esta en la izquierda o en la derecha y devulevo el que corresponda.

+ Arbol_raiz-----> Primero verifico si el arbol es nulo o esta vacio, en caso de estarlo salgo de la funcion devolviendo null. en caso de que el arbol no esta vacio, devulevo la raiz y tengo un acceso directo a esa raiz por lo tanto solo tengo que hacer "arbol->nodo_raiz->elemento"-


+ Arbol_vacio------> Si el arbol es nulo o esta vacio devulevo true. Se que el arbol esta vacio cuando tengo que "nodo_raiz" apunta a null, si "nodo_raiz" no apunta a null quiere decir que tengo al menos un elemento. 



+Arbol_recorrido_inorden----> Llama a una funcion recursiva y le pasa la raiz del arbol junto con el vector y su tope, esta funcion  va dejar de iterar cuando el contador sea mayor al tope, una vez que llegue a ese punto devolvera el vector que armo. Si el elemento actual tiene izquierda se volvera a llamar a asi misma pasandole como actual el elemento que esta a la izquierda del mismo hasta encontrar un elemento que no tengo una rama izquierda. Una vez que lo encuentra lo inserta en el vector, incrementa el valor del contador y luego se fija si el eleento tiene derecha y si el contrador no supero el valor del tope, en caso de que estas dos condiciones se cumplan volvera a llamarse a si misma pero ahora pasandole la derecha del actual como su nuevo actual y se repetira el proceso. Si llega a un elemento que es hoja va a saltearse todas estas posibilidades y devuelve el vector.

+Arbol_recorrido_preorden----> Llama a una funcion recursiva y le pasa la raiz del arbol junto con el vector y su tope, esta funcion  va dejar de iterar cuando el contador sea mayor al tope, una vez que llegue a ese punto devolvera el vector que armo. Esta funcion comienza guardando el valor del actual en el vector e incrementando el valor del contador. si Dicho elemento tiene izquierda o derecha y a su vez el contador es menor que el tope, llamara a la funcion pasandole como actual el elemento que sen encuentra a la izquierda del actual y en ambos casos hara el mismo proceso, es decir lo agregara al vector y se fijara si tiene izquierda o derecha.


+Arbol_recorrido_postorden----> Llama a una funcion recursiva y le pasa la raiz del arbol junto con el vector y su tope, esta funcion  va dejar de iterar cuando el contador sea mayor al tope, una vez que llegue a ese punto devolvera el vector que armo. Esta funcion lo primero que hara es fijarse si primero el elemento tiene izquierda y despues derecha, en caso de tener cualquiera de las dos, se llamara a si misma pasandole como actual el valor que esta a su derecha o a su izquierda segun corresponda. cada vez que llega a lo mas izquierda posible lo agrega el vector, luego va a su derecha y si tiene lo agrega y por ultimo agrega la raiz del sub-arbol.



+ Arbol_destruir------> Si recibe un arbol nulo sale de la funcion. Si el arbol esta vacio libera el arbol y sale de la funcion. En caso contrarior se genera una iteracion que no dejara de iterar mientras que el arbol no quede vacio seguira iterando. Si el elemento donde esta el cursor, es decir el elemento actual, tiene un nodo a la izquierda no nulo llamara a la funcion "borrar desde las hojas" que lo que hara sera llegar hasta el final de la rama izquierda del arbol recorriendolo recursivamente, una vez que esta en el final comenzara a liberar la memoria sus nodos junto con sus elementos hasta que no quede ningun elemento en la rama izquierda. Lo mismo hara del lado derecho si es que existe rama derecha. Una vez que elimino ambas ramas del arbol destruira el elemento que se encuentra en la raiz y luego liberara la memoria el nodo de la raiz dejando el arbol completamente vacio. Una vez hecho esto liberaa la memoria reservada en el arbol.


+ Abb_con_cada_elemento----> Dependiendo del recorrido en el que me manden voy a realizar distintos recorridos, para el planteo de los recorridos hago casi lo mismo que en "Arbol_recorrido_xxxx" con la unica diferencia de que la funcion no es de tipo void** sino que es size_t y devuelve la veces que itero empezando a contar desde que el recorrido lo haria, es decir que si hago un recorrido inorden y tengo un arbol con los elementos [5, 3, 1, 0, 4, 15, 9, 7] insertados en ese orden, el contador va empezar a contar recien cuando llegue al elemento 0 y no empezara a contar desde el 5 que en este caso seria la raiz del arbol.


Un Readme.txt donde explique el TDA implementado. Explique qué es una árbol, árbol binario y árbol binario
de búsqueda. Explique por qué es importante la distinción de cada uno de estos conceptos.

PREGUNTAS TEORICAS
------------------
------------------


1)¿Que es un arbol?
 Un arbol es se puede definir como una coleccion de nodos los cuales tienen un nodo principal llamado raiz el cual divide el arbol en dos nodos (ramas) derecho e izquierdo y dichas nodos se pueden comportar del mismo modo que todo el arbol, es decir que tambien tienen una raiz y dos nodos a sus costados llamados hijos. Dichos nodos son considerados hermanos ya que provienen de la misma raiz (padre). Esta funcion es considerada una funcion recursiva ya que es un patron que se repite una y otra vez. Este tipo de implementaciones son usadas para reducir el tiempo de busqueda en comparacion a una lista ya que en la lista puede ser necesario tener que recorrer todos los elementos para encontrar al indicado cuando en el arbol en el peor de los casos revisarias solo una mitad.


2)¿Que es un arbol binario?
  Un arbol binario, es un arbol que contiene un nodo principal llamado raiz, al igual que lo otros, pero esta raiz solo tiene dos bifurcaciones, derecha e izquierda y cada rama que sale de esta raiz puede ser la raiz de un sub arbol o puede ser una hoja, osea que termina ahi el recorrido. Es una estructura recursiva, ya que como dije anteriormente cada rama del arbol se convierte en pequeños arboles binarios entonces puedo tener infinitos arboles binarios dentro del mismo. 


3)¿Que es un arbol binario de busqueda?
 Este arbol contiene la estructura de un arbol binario, es decir que visualmente es casi identico, pero con una diferencia quer agiliza lo tiempos de busqueda ya que cuenta con un comparador, este comparador es a criterio del usuario generalmente y lo que hace es comparar los elementos y los menores suelen ir de la izquierda y los mayores a la derecha. Por ejemplo si tengo n arbol de este estilo:

 							30
 				10						60
 							
y quiero ingresar el elemento 15, 5, 40 y 90 el arbol quedaria asi

 							30
 				10						60
 			5		15				40		90

 			
























