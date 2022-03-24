#ifndef ARBOLAVL__H__
#define ARBOLAVL__H__

#include "NodoAVL.h"
#include <list>
template <class T>
class ArbolAVL
{
protected:
    NodoAVL<T> *raiz;

public:
    ArbolAVL();
    NodoAVL<T> *getRaiz();
    bool esVacio();
    T datoRaiz();
    bool insertar(T &val);
    bool buscar(T &val);
    int altura();
    int tamano();
    int altura(NodoAVL<T> *inicio);
    int tamano(NodoAVL<T> *inicio);
    int diff(NodoAVL<T> *);
    NodoAVL<T> *insertar(T &val, NodoAVL<T> *padre);
    NodoAVL<T> *eliminarf(T &val, NodoAVL<T> *padre);
    NodoAVL<T> *rotacionDerecha(NodoAVL<T> *);
    NodoAVL<T> *rotacionIzquierda(NodoAVL<T> *);
    NodoAVL<T> *rotacionDI(NodoAVL<T> *);
    NodoAVL<T> *rotacionID(NodoAVL<T> *);
    NodoAVL<T> *balance(NodoAVL<T> *);
    void eliminar(T &val);
    void preOrden(NodoAVL<T> *inicio);
    void inOrden(NodoAVL<T> *inicio);
    void posOrden(NodoAVL<T> *inicio);
    void nivelOrden(NodoAVL<T> *inicio);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    void inOrdenL(NodoAVL<T> *inicio, list<T> &l);
    void inOrdenL(list<T> &l);
    void valorMax(T &mayor);

};

#include "ArbolAVL.hxx"
#endif