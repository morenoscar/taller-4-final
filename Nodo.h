#ifndef __Nodo_H__
#define __Nodo_H__

template <class T>
class NodoBinario
{
protected:
    T frec;
    T value;
    NodoBinario<T>* hijoI;
    NodoBinario<T>* hijoD;
public:
    NodoBinario();
    NodoBinario(const T& t,const T& x);
    NodoBinario(const T& val,const T& vall, NodoBinario<T>* i, NodoBinario<T>* d);
    T& obtenerFrec();
    T& obtenerVal();
    NodoBinario<T>* obtenerHijoDer();
    NodoBinario<T>* obtenerHijoIzq();
    void fijarHijoDer(NodoBinario<T>* val);
    void fijarHijoIzq(NodoBinario<T>* val);
    void fijarFrec(const T& t);
    void fijarVal(const T& t);


};


#include "Nodo.hxx"
#endif
