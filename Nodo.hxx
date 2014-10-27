#include "Nodo.h"
#include <iostream>
using namespace std;
template <class T>
NodoBinario<T>::NodoBinario()
{
    frec=0;
    value=0;
    hijoD=NULL;
    hijoI=NULL;

}
template <class T>
NodoBinario<T>::NodoBinario(const T& t,const T& x)
{
    frec=t;
    value=x;
    hijoD=NULL;
    hijoI=NULL;
}
template <class T>
T& NodoBinario<T>::obtenerFrec()
{
    return frec;

}
template <class T>
T& NodoBinario<T>::obtenerVal()
{
    return value;

}
template <class T>
NodoBinario<T>::NodoBinario(const T& val,const T& vall, NodoBinario<T>* i, NodoBinario<T>* d)
{
   frec=vall;
    value=val;
    hijoI=i;
    hijoD=d;

}
template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer()
{
    return hijoD;
}
 template <class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq()
{
    return hijoI;
}
       template <class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T>* val)
{
    hijoD=val;

}
template <class T>
void  NodoBinario<T>::fijarHijoIzq(NodoBinario<T>* val)
{
    hijoI=val;
}
template <class T>
void NodoBinario<T>::fijarFrec(const T& t)
{
    frec=t;

}
template <class T>
void NodoBinario<T>::fijarVal(const T& t)
{
    value=t;

}

