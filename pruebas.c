#include "abb.h"
#include <stdio.h>
#include "pa2mm.h"
#include "string.h"

typedef struct dato{
    int id;
    char contenido[10];
}dato_t;

dato_t* crear_dato(int clave){
    dato_t* c = (dato_t*)malloc(sizeof(dato_t));
    if(c)
        c->id = clave;
    return c;
}

int comparar_datos(void* elemento1, void* elemento2){
    if(!elemento1 || !elemento2)
        return 0;

    dato_t* c1 = elemento1;
    dato_t* c2 = elemento2;

    return c1->id - c2->id;
}

void destruir_dato(dato_t* c){
    free(c);
}

bool contar_elementos_hasta_el_9(void* elemento, void* extra){

    if(((dato_t*)elemento)->id == 9){
        return true;
    }
    if(elemento && extra){
        *(int*)extra += 1;
    }
    return false;
}

bool contar_elementos(void* elemento, void* extra){
    if(elemento && extra)
        *(int*)extra += 1;
    return false;
}

void destructor_de_datos(void* elemento){
    if(!elemento)
        return;
    destruir_dato((dato_t*)elemento);
}

void probar_borrado_de_e1(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e1) == 0, "Arbol con varios elementos borro nodo hoja.");

    dato_t* aux = crear_dato(0);
    aux->id = 1;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e2(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e2) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 2;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e3(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e3) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 3;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e4(){

    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e4) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 4;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e5(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e5) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 5;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e6(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e6) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 6;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");
    
    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e7(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e7) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 7;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");
    
    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e8(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e8) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 8;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e9(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e9) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 9;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e10(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e10) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto
    
    dato_t* aux = crear_dato(0);
    aux->id = 10;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e11(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e11) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 11;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");
    
    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e12(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e12) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 12;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");
    
    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e13(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e13) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 13;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");
    
    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e14(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e14) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 14;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e20(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e20) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 20;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e21(){

    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e21) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 21;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e22(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e22) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 22;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void probar_borrado_de_e23(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e23) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 23;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e20) == e20 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22)
        pa2m_afirmar(1 == 1, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void cuandocreounabb_secreaunabbvacio(){
	abb_t* arbol;
	pa2m_afirmar((arbol = arbol_crear(comparar_datos, destructor_de_datos)) != NULL, "Se crear un arbol no nulo.");
	pa2m_afirmar(arbol_vacio(arbol) == true, "Puedo crear un arbol vacio.");

	arbol_destruir(arbol);
}

void cuandoquierocrearunarbolsincomparador_devuelveNULL(){
    abb_t* arbol;
    pa2m_afirmar((arbol = arbol_crear(NULL, destructor_de_datos)) == NULL, "No se puede crear un arbol sin comparador.");
    arbol_destruir(arbol);
}

void cuandocreounabbsindestructor_secreaunabbvacio(){
	abb_t* arbol = arbol_crear(comparar_datos, NULL);
	pa2m_afirmar(arbol_vacio(arbol) == true, "Crear un arbol vacio.");

	arbol_destruir(arbol);
}

void cuandoinsertounelementoenarbolvacio_loinsertaenlaraiz(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e1= crear_dato(1);
    
    pa2m_afirmar(arbol_insertar(abb, e1) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(abb->nodo_raiz->elemento == e1, "EL elemento se inserto en la raiz.");

    arbol_destruir(abb);
}

void insertar_bastantes_elementos(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e1= crear_dato(1);
    dato_t* e2= crear_dato(2);
    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e6= crear_dato(6);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e7= crear_dato(7);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);

    pa2m_afirmar(arbol_insertar(abb, e2) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e1) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e12) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e8) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e13) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e6) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e10) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e4) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e7) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e9) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e11) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e3) == 0, "Puedo insertar correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e5) == 0, "Puedo insertar correctamente.");

    arbol_destruir(abb);
}

void cuandoinsertounelementoenarbolNULO_noloinserta(){
	abb_t* abb = NULL;

    dato_t* e1= crear_dato(1);
    pa2m_afirmar(arbol_insertar(abb, e1) == -1, "No puedo insertar en arbol nulo.");

    destructor_de_datos(e1);
}

void cuandoinsertounelementoenarbolconelemetos_losinsertacorrectamente(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e1= crear_dato(2);
    dato_t* e2= crear_dato(1);
    dato_t* e3= crear_dato(3);

    pa2m_afirmar(arbol_insertar(abb, e1) == 0, "Puedo insertar 1 elemento correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e2) == 0, "Puedo insertar 2 elemento correctamente.");
    pa2m_afirmar(arbol_insertar(abb, e3) == 0, "Puedo insertar 3 elemento correctamente.");

    pa2m_afirmar(abb->nodo_raiz->elemento == e1, "EL elemento se inserto en la raiz.");
    pa2m_afirmar(abb->nodo_raiz->izquierda->elemento == e2, "EL elemento se inserto a la izquierda de la raiz.");
    pa2m_afirmar(abb->nodo_raiz->derecha->elemento == e3, "El elemento se inserto a la derecha de la raiz.");

    arbol_destruir(abb);
}

void cuando_borro_un_elemento_del_arbol_de_un_solo_elemento_se_elimina_correctamente(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e1= crear_dato(1);
    arbol_insertar(abb, e1);

    pa2m_afirmar(arbol_raiz(abb) == e1, "El elemento se inserto en la raiz.");
    pa2m_afirmar(arbol_borrar(abb, e1) == 0, "Arbol con un elemento borro la raiz.");
    pa2m_afirmar(arbol_raiz(abb) == NULL, "La raiz es NULL.");

    arbol_destruir(abb);
}

void cuando_borro_la_raiz_del_arbol_de_varios_elementos_del_lado_derecho_se_elimina_correctamente(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e1= crear_dato(1);
    dato_t* e2= crear_dato(2);
    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e6= crear_dato(6);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e7= crear_dato(7);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);

    arbol_insertar(abb, e2);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e12);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e7);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);

    pa2m_afirmar(arbol_borrar(abb, e2) == 0, "Arbol con varios elementos borro la raiz.");

    pa2m_afirmar(arbol_raiz(abb) == e1, "El elemento se inserto en la raiz.");
    pa2m_afirmar(abb->nodo_raiz->izquierda == NULL, "el e1 es el elemento izquierdo de la raiz.");
    pa2m_afirmar(abb->nodo_raiz->derecha->elemento == e12, "el e12 es el elemento derecho de la raiz");


    arbol_destruir(abb);
}

void cuando_borro_la_hoja_del_arbol_de_varios_elementos_se_elimina_correctamente(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e1) == 0, "Hoja borrada correctamente");
    pa2m_afirmar(arbol_borrar(abb, e3) == 0, "Hoja borrada correctamente");
    pa2m_afirmar(arbol_borrar(abb, e5) == 0, "Hoja borrada correctamente");
    pa2m_afirmar(arbol_borrar(abb, e7) == 0, "Hoja borrada correctamente");

    dato_t* e1_bis= crear_dato(1);//CREO E INSERTO DE NUEVO PARA QUE SEAN HOJAS 
    dato_t* e3_bis= crear_dato(3);
    dato_t* e5_bis= crear_dato(5);
    dato_t* e7_bis= crear_dato(7);
    arbol_insertar(abb, e1_bis);
    arbol_insertar(abb, e3_bis);
    arbol_insertar(abb, e5_bis);
    arbol_insertar(abb, e7_bis);


    pa2m_afirmar(arbol_borrar(abb, e3_bis) == 0, "Hoja borrada correctamente");
    pa2m_afirmar(arbol_borrar(abb, e1_bis) == 0, "Hoja borrada correctamente");
    pa2m_afirmar(arbol_borrar(abb, e7_bis) == 0, "Hoja borrada correctamente");
    pa2m_afirmar(arbol_borrar(abb, e5_bis) == 0, "Hoja borrada correctamente");
    
    arbol_destruir(abb);
}

void cuando_borro_la_raiz_del_arbol_de_varios_elementos_del_lado_izquierdo_se_elimina_correctamente(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e12) == 0, "Arbol con varios elementos borro la raiz (12).");
    pa2m_afirmar(arbol_raiz(abb) == e11, "La raiz ahora es su sucesor in-orden (13).");

    pa2m_afirmar(arbol_borrar(abb, e11) == 0, "Arbol con varios elementos borro la raiz (13).");
    pa2m_afirmar(arbol_raiz(abb) == e10, "La raiz ahora es su sucesor in-orden (8).");

    pa2m_afirmar(arbol_borrar(abb, e10) == 0, "Arbol con varios elementos borro la raiz (8).");
    
    pa2m_afirmar(abb->nodo_raiz->derecha->elemento == e13, "El elemento que esta en la rama derecha de la raiz del arbol es el (10).");
    pa2m_afirmar(abb->nodo_raiz->izquierda->elemento == e8, "El elemento que esta en la rama izquierda de la raiz del arbol es el (4).");
    
    pa2m_afirmar(arbol_raiz(abb) == e9, "La raiz ahora es su sucesor in-orden(9).");
    pa2m_afirmar(arbol_borrar(abb, e9) == 0, "Arbol con varios elementos borro la raiz(9).");

    pa2m_afirmar(arbol_raiz(abb) == e8, "La raiz ahora es su sucesor in-orden(10).");

    pa2m_afirmar(abb->nodo_raiz->izquierda->elemento == e4, "EL (e4) es el elemento izquierdo de la raiz.");
    pa2m_afirmar(abb->nodo_raiz->derecha->elemento == e13, "EL (e11) es el elemento derecho de la raiz");

    arbol_destruir(abb);
}

void eliminar_elemento_que_no_esta_devuleve_MENOSUNO(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e13= crear_dato(13);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);

    pa2m_afirmar(arbol_borrar(abb, e7) == -1, "Arbol con varios elementos borro la raiz.");

    destructor_de_datos(e7);
    arbol_destruir(abb);
}

void eliminar_subarbol_e_insertar_sucesor_inorden_con_raiz_derecha_correctamente(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);
    dato_t* e15= crear_dato(15);

    
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e12);
    arbol_insertar(abb, e15);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);


    pa2m_afirmar(arbol_borrar(abb, e12) == 0, "Arbol con varios elementos borro nodo hoja.");
    pa2m_afirmar(abb->nodo_raiz->elemento == e20, "El elemento (20) ahora se encunetra en la raiz del arbol");
    
    pa2m_afirmar(abb->nodo_raiz->izquierda->elemento == e11, " El e11 es el predecesor inorden");
    
    pa2m_afirmar(arbol_buscar(abb, e15) == e15, "El elemento se encuentra dentro del arbol (15)");
    pa2m_afirmar(arbol_buscar(abb, e10) == e10, "El elemento se encuentra dentro del arbol (10)");
    pa2m_afirmar(arbol_buscar(abb, e22) == e22, "El elemento se encuentra dentro del arbol (22)");
    pa2m_afirmar(arbol_buscar(abb, e23) == e23, "El elemento se encuentra dentro del arbol (23)");

    arbol_destruir(abb);
}

void elimino_raiz_y_busco_sucesor_inorden_e_inserto_correctamente(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e12) == 0, "Arbol con varios elementos borro raiz.");//lo elimina perfecto

    
    pa2m_afirmar(abb->nodo_raiz->izquierda->elemento == e8, "El elemento 8 es la raiz de la rama derecha del arbol");
    pa2m_afirmar(abb->nodo_raiz->derecha->elemento == e20, "El elemento 20 es la raiz de la rama derecha del arbol");
    pa2m_afirmar(abb->nodo_raiz->elemento == e11, "El elemento 11 es el predecesor inorden del elemento eliminado");

    if(arbol_buscar(abb, e1) == e1     && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e9) == e9 && arbol_buscar(abb, e10) == e10 && arbol_buscar(abb, e13) == e13 && arbol_buscar(abb, e14) == e14 && arbol_buscar(abb, e21) == e21 && arbol_buscar(abb, e22) == e22 && arbol_buscar(abb, e23) == e23)
        pa2m_afirmar(arbol_buscar(abb, e23) == e23, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
}

void buscar_un_elemento_en_un_arbol_nulo_devuleve_NULL(){
	abb_t* abb = NULL;

    dato_t* e1= crear_dato(1);
    pa2m_afirmar(arbol_buscar(abb, e1) == NULL, "No se encuentra el elemento buscado.");

    destructor_de_datos(e1);
}

void buscar_un_elemento_en_un_arbol_con_elemento_devuleve_el_buscado(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);


	pa2m_afirmar(arbol_buscar(abb, e12) == e12, "Se encuentra el elemento buscado (12).");
	pa2m_afirmar(arbol_buscar(abb, e1) == e1, "Se encuentra el elemento buscado (1).");
	pa2m_afirmar(arbol_buscar(abb, e3) == e3, "Se encuentra el elemento buscado (3).");
	pa2m_afirmar(arbol_buscar(abb, e9) == e9, "Se encuentra el elemento buscado (9).");
	pa2m_afirmar(arbol_buscar(abb, e7) == e7, "Se encuentra el elemento buscado (7).");

    //destructor_de_datos(e1);
    arbol_destruir(abb);
}

void buscar_un_elemento_que_no_se_encuentra_en_el_arbol_devuelve_NULL(){
	abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

	//arbol
    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    //no insertados
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e24= crear_dato(24);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

	pa2m_afirmar(arbol_buscar(abb, e22) == NULL, "EL elemento buscado no se encuentra en el arbol.");
	pa2m_afirmar(arbol_buscar(abb, e23) == NULL, "EL elemento buscado no se encuentra en el arbol.");
	pa2m_afirmar(arbol_buscar(abb, e24) == NULL, "EL elemento buscado no se encuentra en el arbol.");

    destructor_de_datos(e22);
    destructor_de_datos(e23);
    destructor_de_datos(e24);
    arbol_destruir(abb);
}

void el_recorrido_inorden_devuleve_un_vector_de_menor_a_mayor(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    dato_t* elementos[13];

    pa2m_nuevo_grupo("Recorrido INORDEN");
    printf("Muestro:  ");
    size_t cantidad = arbol_recorrido_inorden(abb, (void**)elementos, 13);
    for(size_t i=0;i<cantidad;i++)
        printf("%i--", elementos[i]->id);
    printf("\n");

    pa2m_afirmar((cantidad) == 13, "La cantidad de elemento recorridos es la correcta.");

    pa2m_afirmar((elementos[0]) == e1, "(1) se encuentra en la posicion 1.");
    pa2m_afirmar((elementos[1]) == e2, "(2) se encuentra en la posicion 2.");
    pa2m_afirmar((elementos[2]) == e3, "(3) se encuentra en la posicion 3.");
    pa2m_afirmar((elementos[3]) == e4, "(4) se encuentra en la posicion 4.");
    pa2m_afirmar((elementos[4]) == e5, "(5) se encuentra en la posicion 5.");
    pa2m_afirmar((elementos[5]) == e6, "(6) se encuentra en la posicion 6.");
    pa2m_afirmar((elementos[6]) == e7, "(7) se encuentra en la posicion 7.");
    pa2m_afirmar((elementos[7]) == e8, "(8) se encuentra en la posicion 8.");
    pa2m_afirmar((elementos[8]) == e9, "(9) se encuentra en la posicion 9.");
    pa2m_afirmar((elementos[9]) == e10, "(10) se encuentra en la posicion 10.");
    pa2m_afirmar((elementos[10]) == e11, "(11) se encuentra en la posicion 11.");
    pa2m_afirmar((elementos[11]) == e12, "(12) se encuentra en la posicion 12.");
    pa2m_afirmar((elementos[12]) == e13, "(13) se encuentra en la posicion 13.");

    printf("\n");
    printf("\n");

    arbol_destruir(abb);
}

void el_recorrido_inorden_devuleve_un_vector_de_menor_a_mayor_hasta_donde_el_tope_le_indica(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    dato_t* elementos[13];

    pa2m_nuevo_grupo("Recorrido INORDEN, hasta el (9)");
    printf("Muestro:  ");
    size_t cantidad = arbol_recorrido_inorden(abb, (void**)elementos, 9);
    for(size_t i=0;i<cantidad;i++)
        printf("%i--", elementos[i]->id);
    printf("\n");

    pa2m_afirmar((cantidad) == 9, "La cantidad de elemento recorridos es la correcta.");

    pa2m_afirmar((elementos[0]) == e1, "(1) se encuentra en la posicion 1.");
    pa2m_afirmar((elementos[1]) == e2, "(2) se encuentra en la posicion 2.");
    pa2m_afirmar((elementos[2]) == e3, "(3) se encuentra en la posicion 3.");
    pa2m_afirmar((elementos[3]) == e4, "(4) se encuentra en la posicion 4.");
    pa2m_afirmar((elementos[4]) == e5, "(5) se encuentra en la posicion 5.");
    pa2m_afirmar((elementos[5]) == e6, "(6) se encuentra en la posicion 6.");
    pa2m_afirmar((elementos[6]) == e7, "(7) se encuentra en la posicion 7.");
    pa2m_afirmar((elementos[7]) == e8, "(8) se encuentra en la posicion 8.");
    pa2m_afirmar((elementos[8]) == e9, "(9) se encuentra en la posicion 9.");
    printf("\n");

    arbol_destruir(abb);
}

void el_recorrido_preorden_devuelve_un_vector_desordenado(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    dato_t* elementos[13];

    pa2m_nuevo_grupo("Recorrido PREORDEN");
    printf("Muestro:  ");
    size_t cantidad = arbol_recorrido_preorden(abb, (void**)elementos, 13);
    for(size_t i=0;i<cantidad;i++)
        printf("%i--", elementos[i]->id);
    printf("\n");   

    pa2m_afirmar((cantidad) == 13, "La cantidad de elemento recorridos es la correcta.");
   
    pa2m_afirmar((elementos[0]) == e12, "(12) se encuentra en la posicion 1°.");
    pa2m_afirmar((elementos[1]) == e8, "(8) se encuentra en la posicion 2°.");
    pa2m_afirmar((elementos[2]) == e4, "(4) se encuentra en la posicion 3°.");
    pa2m_afirmar((elementos[3]) == e2, "(2) se encuentra en la posicion 4°.");
    pa2m_afirmar((elementos[4]) == e1, "(1) se encuentra en la posicion 5°.");
    pa2m_afirmar((elementos[5]) == e3, "(3) se encuentra en la posicion 6°.");
    pa2m_afirmar((elementos[6]) == e6, "(6) se encuentra en la posicion 7°.");
    pa2m_afirmar((elementos[7]) == e5, "(5) se encuentra en la posicion 8°.");
    pa2m_afirmar((elementos[8]) == e7, "(7) se encuentra en la posicion 9°.");
    pa2m_afirmar((elementos[9]) == e10, "(10) se encuentra en la posicion 10°.");
    pa2m_afirmar((elementos[10]) == e9, "(9) se encuentra en la posicion 11°.");
    pa2m_afirmar((elementos[11]) == e11, "(11) se encuentra en la posicion 12°.");
    pa2m_afirmar((elementos[12]) == e13, "(13) se encuentra en la posicion 13°.");

    printf("\n");
    printf("\n");

    arbol_destruir(abb);
}

void el_recorrido_preorden_devuelve_un_vector_hasta_donde_el_tope_le_indica(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    dato_t* elementos[13];

    pa2m_nuevo_grupo("Recorrido PREORDEN, hasta el (7)");
    printf("Muestro:  ");
    size_t cantidad = arbol_recorrido_preorden(abb, (void**)elementos, 7);
    for(size_t i=0;i<cantidad;i++)
        printf("%i--", elementos[i]->id);
    printf("\n");   

    pa2m_afirmar((cantidad) == 7, "La cantidad de elemento recorridos es la correcta.");
   
    pa2m_afirmar((elementos[0]) == e12, "(12) se encuentra en la posicion 1°.");
    pa2m_afirmar((elementos[1]) == e8, "(8) se encuentra en la posicion 2°.");
    pa2m_afirmar((elementos[2]) == e4, "(4) se encuentra en la posicion 3°.");
    pa2m_afirmar((elementos[3]) == e2, "(2) se encuentra en la posicion 4°.");
    pa2m_afirmar((elementos[4]) == e1, "(1) se encuentra en la posicion 5°.");
    pa2m_afirmar((elementos[5]) == e3, "(3) se encuentra en la posicion 6°.");
    pa2m_afirmar((elementos[6]) == e6, "(6) se encuentra en la posicion 7°.");
    printf("\n");

    arbol_destruir(abb);
}

void el_recorrido_postorden_devuelve_un_vector_formado_primero_por_las_hojas(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    dato_t* elementos[13];

    pa2m_nuevo_grupo("Recorrido POSTORDEN");
    printf("Muestro:  ");
    size_t cantidad = arbol_recorrido_postorden(abb, (void**)elementos, 13);
    for(size_t i=0;i<cantidad;i++)
        printf("%i--", elementos[i]->id);
    printf("\n");

    pa2m_afirmar((cantidad) == 13, "La cantidad de elemento recorridos es la correcta.");
    
    pa2m_afirmar((elementos[0]) == e1, "(1) se encuentra en la posicion 1°.");
    pa2m_afirmar((elementos[1]) == e3, "(3) se encuentra en la posicion 2°.");
    pa2m_afirmar((elementos[2]) == e2, "(2) se encuentra en la posicion 3°.");
    pa2m_afirmar((elementos[3]) == e5, "(5) se encuentra en la posicion 4°.");
    pa2m_afirmar((elementos[4]) == e7, "(7) se encuentra en la posicion 5°.");
    pa2m_afirmar((elementos[5]) == e6, "(6) se encuentra en la posicion 6°.");
    pa2m_afirmar((elementos[6]) == e4, "(4) se encuentra en la posicion 7°.");
    pa2m_afirmar((elementos[7]) == e9, "(9) se encuentra en la posicion 8°.");
    pa2m_afirmar((elementos[8]) == e11, "(11) se encuentra en la posicion  9°.");
    pa2m_afirmar((elementos[9]) == e10, "(10) se encuentra en la posicion 10°.");
    pa2m_afirmar((elementos[10]) == e8, "(8) se encuentra en la posicion 11°.");
    pa2m_afirmar((elementos[11]) == e13, "(13) se encuentra en la posicion 12°.");
    pa2m_afirmar((elementos[12]) == e12, "(12) se encuentra en la posicion 13°.");

    printf("\n");


    arbol_destruir(abb);
}

void el_recorrido_postorden_devuelve_un_vector_formado_hasta_donde_el_tope_le_indica(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    dato_t* elementos[13];

    pa2m_nuevo_grupo("Recorrido POSTORDEN, hasta el (5)");
    printf("Muestro:  ");
    size_t cantidad = arbol_recorrido_postorden(abb, (void**)elementos, 5);
    for(size_t i=0;i<cantidad;i++)
        printf("%i--", elementos[i]->id);
    printf("\n");

    pa2m_afirmar((cantidad) == 5, "La cantidad de elemento recorridos es la correcta.");
    
    pa2m_afirmar((elementos[0]) == e1, "(1) se encuentra en la posicion 1°.");
    pa2m_afirmar((elementos[1]) == e3, "(3) se encuentra en la posicion 2°.");
    pa2m_afirmar((elementos[2]) == e2, "(2) se encuentra en la posicion 3°.");
    pa2m_afirmar((elementos[3]) == e5, "(5) se encuentra en la posicion 4°.");
    pa2m_afirmar((elementos[4]) == e7, "(7) se encuentra en la posicion 5°.");
    printf("\n");

    arbol_destruir(abb);
}

void nodo_con_un_hijo(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_afirmar(arbol_borrar(abb, e10) == 0, "Arbol con varios elementos borro nodo hoja.");//lo elimina perfecto

    dato_t* aux = crear_dato(0);
    aux->id = 10;
    
    pa2m_afirmar(arbol_buscar(abb, aux) == NULL, "El elemento se elimino");
    

    if(arbol_buscar(abb, e1) == e1 && arbol_buscar(abb, e2) == e2 && arbol_buscar(abb, e3) == e3 && arbol_buscar(abb, e4) == e4 && arbol_buscar(abb, e5) == e5 && arbol_buscar(abb, e6) == e6 && arbol_buscar(abb, e7) == e7 && arbol_buscar(abb, e8) == e8 && arbol_buscar(abb, e11) == e11 && arbol_buscar(abb, e12) == e12 && arbol_buscar(abb, e13) == e13)
        pa2m_afirmar(1 == 1, "TODOS LOS ELEMENTOS QUE NO SE BORRARON SE ENCUENTRAN EN EL ARBOL");

    arbol_destruir(abb);
    destruir_dato(aux);
}

void borro_arbol_y_queda_vacio(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);
    dato_t* e20= crear_dato(20);
    dato_t* e21= crear_dato(21);
    dato_t* e22= crear_dato(22);
    dato_t* e23= crear_dato(23);
    dato_t* e14= crear_dato(14);


    arbol_insertar(abb, e12);
    arbol_insertar(abb, e20);
    arbol_insertar(abb, e22);
    arbol_insertar(abb, e21);
    arbol_insertar(abb, e23);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e14);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    if(arbol_borrar(abb, e1) == 0  && arbol_borrar(abb, e2) == 0 && arbol_borrar(abb, e3) == 0 && arbol_borrar(abb, e4) == 0 && arbol_borrar(abb, e5) == 0 && arbol_borrar(abb, e6) == 0 && arbol_borrar(abb, e7) == 0 && arbol_borrar(abb, e8) == 0 && arbol_borrar(abb, e9) == 0 && arbol_borrar(abb, e10) == 0 && arbol_borrar(abb, e11) == 0 && arbol_borrar(abb, e12) == 0 && arbol_borrar(abb, e13) == 0 && arbol_borrar(abb, e14) == 0 && arbol_borrar(abb, e20) == 0 && arbol_borrar(abb, e21) == 0 && arbol_borrar(abb, e22) == 0 && arbol_borrar(abb, e23) == 0)
        pa2m_afirmar(1 == 1, "TODOS LOS ELEMENTOS SE FUERON BORRADOS DEL ARBOL CON EXITO");


    pa2m_afirmar(arbol_vacio(abb) == true, "El arbol esta vacio");

    free(abb);
}

void borro_arbol_con_memoria_estatica_y_queda_vacio(){
    abb_t* abb = arbol_crear(comparar_datos, NULL);

    int e12=12;
    int e8=8; 
    int e13=13;
    int e10=10;
    int e4=4; 
    int e2=2; 
    int e6=6; 
    int e9=9; 
    int e11=11;
    int e1=1; 
    int e3=3; 
    int e5=5; 
    int e7=7; 
    int e20=20;
    int e21=21;
    int e22=22;
    int e23=23;
    int e14=14;

    arbol_insertar(abb, &e12);
    arbol_insertar(abb, &e20);
    arbol_insertar(abb, &e22);
    arbol_insertar(abb, &e21);
    arbol_insertar(abb, &e23);
    arbol_insertar(abb, &e13);
    arbol_insertar(abb, &e14);
    arbol_insertar(abb, &e8);
    arbol_insertar(abb, &e10);
    arbol_insertar(abb, &e4);
    arbol_insertar(abb, &e2);
    arbol_insertar(abb, &e6);
    arbol_insertar(abb, &e9);
    arbol_insertar(abb, &e11);
    arbol_insertar(abb, &e1);
    arbol_insertar(abb, &e3);
    arbol_insertar(abb, &e5);
    arbol_insertar(abb, &e7);

    if(arbol_borrar(abb, &e1) == 0  && arbol_borrar(abb, &e2) == 0 && arbol_borrar(abb, &e3) == 0 && arbol_borrar(abb, &e4) == 0 && arbol_borrar(abb, &e5) == 0 && arbol_borrar(abb, &e6) == 0 && arbol_borrar(abb, &e7) == 0 && arbol_borrar(abb, &e8) == 0 && arbol_borrar(abb, &e9) == 0 && arbol_borrar(abb, &e10) == 0 && arbol_borrar(abb, &e11) == 0 && arbol_borrar(abb, &e12) == 0 && arbol_borrar(abb, &e13) == 0 && arbol_borrar(abb, &e14) == 0 && arbol_borrar(abb, &e20) == 0 && arbol_borrar(abb, &e21) == 0 && arbol_borrar(abb, &e22) == 0 && arbol_borrar(abb, &e23) == 0)
        pa2m_afirmar(1 == 1, "TODOS LOS ELEMENTOS SE FUERON BORRADOS DEL ARBOL CON EXITO");


    pa2m_afirmar(arbol_vacio(abb) == true, "El arbol se encuentra vacio");

    free(abb);
}

void insertar_eliminar_elemento_insertado_insertar_mismo_elemento_buscar_elemento(){
   abb_t* abb = arbol_crear(comparar_datos, NULL);

    int e12=12;
    int e8=8; 
    int e13=13;
    int e10=10;
    int e4=4; 
    int e2=2; 
    int e6=6; 
    int e9=9; 
    int e11=11;
    int e1=1; 
    int e3=3; 
    int e5=5; 
    int e7=7; 
    int e20=20;
    int e21=21;
    int e22=22;
    int e23=23;
    int e14=14;


    arbol_insertar(abb, &e12);
    arbol_insertar(abb, &e20);
    arbol_insertar(abb, &e22);
    arbol_insertar(abb, &e21);
    arbol_insertar(abb, &e23);
    arbol_insertar(abb, &e13);
    arbol_insertar(abb, &e14);
    arbol_insertar(abb, &e8);
    arbol_insertar(abb, &e10);
    arbol_insertar(abb, &e4);
    arbol_insertar(abb, &e2);
    arbol_insertar(abb, &e6);
    arbol_insertar(abb, &e9);
    arbol_insertar(abb, &e11);
    arbol_insertar(abb, &e1);
    arbol_insertar(abb, &e3);
    arbol_insertar(abb, &e5);
    arbol_insertar(abb, &e7);

    pa2m_afirmar(arbol_borrar(abb, &e12) == 0, "Borro el (e12) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e12) == 0, "Inserto el (e12) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e12) == &e12, "Busco el (e12) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e20) == 0, "Borro el (e20) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e20) == 0, "Inserto el (e20) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e20) == &e20, "Busco el (e12) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e22) == 0, "Borro el (e22) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e22) == 0, "Inserto el (e22) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e22) == &e22, "Busco el (e22) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e21) == 0, "Borro el (e21) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e21) == 0, "Inserto el (e21) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e21) == &e21, "Busco el (e21) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e23) == 0, "Borro el (e23) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e23) == 0, "Inserto el (e23) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e23) == &e23, "Busco el (e23) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e13) == 0, "Borro el (e13) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e13) == 0, "Inserto el (e13) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e13) == &e13, "Busco el (e13) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e14) == 0, "Borro el (e14) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e14) == 0, "Inserto el (e14) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e14) == &e14, "Busco el (e14) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e8) == 0, "Borro el (e8) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e8) == 0, "Inserto el (e8) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e8) == &e8, "Busco el (e8) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e10) == 0, "Borro el (e10) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e10) == 0, "Inserto el (e10) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e10) == &e10, "Busco el (e10) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e4) == 0, "Borro el (e4) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e4) == 0, "Inserto el (e4) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e4) == &e4, "Busco el (e4) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e2) == 0, "Borro el (e2) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e2) == 0, "Inserto el (e2) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e2) == &e2, "Busco el (e2) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e6) == 0, "Borro el (e6) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e6) == 0, "Inserto el (e6) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e6) == &e6, "Busco el (e6) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e9) == 0, "Borro el (e9) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e9) == 0, "Inserto el (e9) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e9) == &e9, "Busco el (e9) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e11) == 0, "Borro el (e11) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e11) == 0, "Inserto el (e11) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e11) == &e11, "Busco el (e11) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e1) == 0, "Borro el (e1) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e1) == 0, "Inserto el (e1) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e1) == &e1, "Busco el (e1) y lo encunetra");
    printf("\n");

    pa2m_afirmar(arbol_borrar(abb, &e3) == 0, "Borro el (e3) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e3) == 0, "Inserto el (e3) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e3) == &e3, "Busco el (e3) y lo encunetra");
    printf("\n");
    
    pa2m_afirmar(arbol_borrar(abb, &e5) == 0, "Borro el (e5) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e5) == 0, "Inserto el (e5) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e5) == &e5, "Busco el (e5) y lo encunetra");
    printf("\n");
   
    pa2m_afirmar(arbol_borrar(abb, &e7) == 0, "Borro el (e7) correctamente");
    pa2m_afirmar(arbol_insertar(abb, &e7) == 0, "Inserto el (e7) correctamente");
    pa2m_afirmar(arbol_buscar(abb, &e7) == &e7, "Busco el (e7) y lo encunetra");
    printf("\n");

    arbol_destruir(abb);
}    

void iterador_inorden(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    size_t cantidad_IN = 0;
    int contador = 0;

    pa2m_nuevo_grupo("Recorrido INORDEN");
    cantidad_IN = abb_con_cada_elemento(abb, ABB_RECORRER_INORDEN, contar_elementos, &contador);
    pa2m_afirmar((cantidad_IN) == 13, "La cantidad de elemento recorridos es la correcta.");

    contador = 0;
    cantidad_IN = abb_con_cada_elemento(abb, ABB_RECORRER_INORDEN, contar_elementos_hasta_el_9, &contador);
    pa2m_afirmar((cantidad_IN) == 9, "La cantidad de elemento recorridos hasta encontar el numero (9) es la correcta.");

    arbol_destruir(abb);
}

void iterador_postrden(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_nuevo_grupo("Recorrido POSTORDEN");
    size_t cantidad_POST = 0;
    int contador = 0;
    cantidad_POST = abb_con_cada_elemento(abb, ABB_RECORRER_POSTORDEN, contar_elementos, &contador);
    pa2m_afirmar((cantidad_POST) == 13, "La cantidad de elemento recorridos es la correcta.");

    contador = 0;
    cantidad_POST = abb_con_cada_elemento(abb, ABB_RECORRER_POSTORDEN, contar_elementos_hasta_el_9, &contador);
    pa2m_afirmar((cantidad_POST) == 8, "La cantidad de elemento recorridos hasta encontar el numero (9) es la correcta.");

     arbol_destruir(abb);
}

void iterador_preorden(){
    abb_t* abb = arbol_crear(comparar_datos, destructor_de_datos);

    dato_t* e12= crear_dato(12);
    dato_t* e8= crear_dato(8);
    dato_t* e13= crear_dato(13);
    dato_t* e10= crear_dato(10);
    dato_t* e4= crear_dato(4);
    dato_t* e2= crear_dato(2);
    dato_t* e6= crear_dato(6);
    dato_t* e9= crear_dato(9);
    dato_t* e11= crear_dato(11);
    dato_t* e1= crear_dato(1);
    dato_t* e3= crear_dato(3);
    dato_t* e5= crear_dato(5);
    dato_t* e7= crear_dato(7);

    arbol_insertar(abb, e12);
    arbol_insertar(abb, e13);
    arbol_insertar(abb, e8);
    arbol_insertar(abb, e10);
    arbol_insertar(abb, e4);
    arbol_insertar(abb, e2);
    arbol_insertar(abb, e6);
    arbol_insertar(abb, e9);
    arbol_insertar(abb, e11);
    arbol_insertar(abb, e1);
    arbol_insertar(abb, e3);
    arbol_insertar(abb, e5);
    arbol_insertar(abb, e7);

    pa2m_nuevo_grupo("Recorrido PREORDEN");
    size_t cantidad_PRE = 0;
    int contador = 0;
    cantidad_PRE = abb_con_cada_elemento(abb, ABB_RECORRER_PREORDEN, contar_elementos, &contador);
    pa2m_afirmar((cantidad_PRE) == 13, "La cantidad de elemento recorridos es la correcta.");


    contador = 0;
    cantidad_PRE = abb_con_cada_elemento(abb, ABB_RECORRER_PREORDEN, contar_elementos_hasta_el_9, &contador);
    pa2m_afirmar((cantidad_PRE) == 11, "La cantidad de elemento recorridos hasta encontar el numero (9) es la correcta.");

     arbol_destruir(abb);
}

void pruebas_crear(){
	pa2m_nuevo_grupo("Pruebas crear");
	cuandoquierocrearunarbolsincomparador_devuelveNULL();
    cuandocreounabb_secreaunabbvacio();
	cuandocreounabbsindestructor_secreaunabbvacio();
}

void BORRAR_UNO_POR_UNO(){
    pa2m_nuevo_grupo("Borrar e1");
	probar_borrado_de_e1();
    pa2m_nuevo_grupo("Borrar e2");
    probar_borrado_de_e2();
    pa2m_nuevo_grupo("Borrar e3");
    probar_borrado_de_e3();
    pa2m_nuevo_grupo("Borrar e4");
    probar_borrado_de_e4();
    pa2m_nuevo_grupo("Borrar e5");
    probar_borrado_de_e5();
    pa2m_nuevo_grupo("Borrar e6");
    probar_borrado_de_e6();
    pa2m_nuevo_grupo("Borrar e7");
    probar_borrado_de_e7();
    pa2m_nuevo_grupo("Borrar e8");
    probar_borrado_de_e8();
    pa2m_nuevo_grupo("Borrar e9");
    probar_borrado_de_e9();
    pa2m_nuevo_grupo("Borrar e10");
    probar_borrado_de_e10();
    pa2m_nuevo_grupo("Borrar e11");
    probar_borrado_de_e11();
    pa2m_nuevo_grupo("Borrar e12");
    probar_borrado_de_e12();
    pa2m_nuevo_grupo("Borrar e13");
    probar_borrado_de_e13();
    pa2m_nuevo_grupo("Borrar e14");
    probar_borrado_de_e14();
    pa2m_nuevo_grupo("Borrar e20");
    probar_borrado_de_e20();
    pa2m_nuevo_grupo("Borrar e21");
    probar_borrado_de_e21();
    pa2m_nuevo_grupo("Borrar e22");
    probar_borrado_de_e22();
    pa2m_nuevo_grupo("Borrar e23");
    probar_borrado_de_e23();
    printf("\n");

    nodo_con_un_hijo();
    insertar_eliminar_elemento_insertado_insertar_mismo_elemento_buscar_elemento();
}

void pruebas_borrar(){
	pa2m_nuevo_grupo("Pruebas borrar");
	//cuando_borro_un_elemento_del_arbol_NULL_se_elimina_correctamente();
	//OPCIONAL
    //BORRAR_UNO_POR_UNO();// va llamando a funciones identicas que solo cambian en el valor en el que eliminan. elimina c/u de los valores por separado
    
    cuando_borro_la_hoja_del_arbol_de_varios_elementos_se_elimina_correctamente();
	cuando_borro_un_elemento_del_arbol_de_un_solo_elemento_se_elimina_correctamente();
	
    printf("\n");
    cuando_borro_la_raiz_del_arbol_de_varios_elementos_del_lado_derecho_se_elimina_correctamente();
    printf("\n");

	cuando_borro_la_raiz_del_arbol_de_varios_elementos_del_lado_izquierdo_se_elimina_correctamente();
    printf("\n");
    eliminar_elemento_que_no_esta_devuleve_MENOSUNO();
    printf("\n");
    eliminar_subarbol_e_insertar_sucesor_inorden_con_raiz_derecha_correctamente();
    printf("\n");
    elimino_raiz_y_busco_sucesor_inorden_e_inserto_correctamente();

    pa2m_nuevo_grupo("Borrar arbol completo (memoria dinamica)");
    borro_arbol_y_queda_vacio();
    pa2m_nuevo_grupo("Borrar arbol completo (memoria estatica)");
    borro_arbol_con_memoria_estatica_y_queda_vacio();
}

void pruebas_insertar(){
	pa2m_nuevo_grupo("Pruebas insertar");
	cuandoinsertounelementoenarbolvacio_loinsertaenlaraiz();
	cuandoinsertounelementoenarbolNULO_noloinserta();
	cuandoinsertounelementoenarbolconelemetos_losinsertacorrectamente();
	insertar_bastantes_elementos();
}

void pruebas_buscar(){
	pa2m_nuevo_grupo("Pruebas buscar");
	buscar_un_elemento_en_un_arbol_nulo_devuleve_NULL();
	buscar_un_elemento_en_un_arbol_con_elemento_devuleve_el_buscado();
	buscar_un_elemento_que_no_se_encuentra_en_el_arbol_devuelve_NULL();
}

void pruebas_ordenes(){
    el_recorrido_inorden_devuleve_un_vector_de_menor_a_mayor();
    el_recorrido_inorden_devuleve_un_vector_de_menor_a_mayor_hasta_donde_el_tope_le_indica();

    el_recorrido_preorden_devuelve_un_vector_desordenado();
    el_recorrido_preorden_devuelve_un_vector_hasta_donde_el_tope_le_indica();

    el_recorrido_postorden_devuelve_un_vector_formado_primero_por_las_hojas();
    el_recorrido_postorden_devuelve_un_vector_formado_hasta_donde_el_tope_le_indica();
}

void pruebas_iterador(){
    iterador_inorden();
    iterador_preorden();
    iterador_postrden();
}


int main(){

	pruebas_crear();
	pruebas_insertar();
	pruebas_borrar();
	pruebas_buscar();
    pruebas_ordenes();
    pruebas_iterador();
    
	/* 
	*/
  return pa2m_mostrar_reporte();
}
