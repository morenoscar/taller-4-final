#ifndef __Arbol_H__
#define __Arbol_H__
#include "Nodo.h"
#include<vector>

template< class T>

class ArbolBinarioHuffman
{
protected:
    NodoBinario<T>* raiz;
public:
    ArbolBinarioHuffman();
    ArbolBinarioHuffman(const T& val,const T& val2);
    bool esVacio();
    void fijarRaiz(NodoBinario<T>* dato);
    NodoBinario<T>*datoRaiz();
    void preOrden(NodoBinario<T> *inicio);
    void inOrden(NodoBinario<T> *inicio);
    void posOrden(NodoBinario<T> *inicio);
    void nivelOrden(NodoBinario<T> *inicio);
    int altura(NodoBinario<T> *inicio);
    int tamano(NodoBinario<T> *inicio);
    bool buscar(int val,string& res,NodoBinario<T> *inicio);
    bool insertarNodo(stringstream& val,NodoBinario<T> *n); //Modificar
    void entre(NodoBinario<T> *inicio, T& valMin, T& valMax); //que es
    void borrarArbol(NodoBinario<T> *inicio);
    string generarArbol(string nomArchivo);
    void conversor(string nomArchivo,string propiedades, vector<int>&pixeles);
    void preOrdenConversor(NodoBinario<T> *inicio, vector<pair<int,int> >&info);
    string codificado(NodoBinario<T> *inicio, int pixel);
};

#include "arbol.hxx"
#endif
