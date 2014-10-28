#include "arbol.h"
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>


using namespace std;

template< class T>
ArbolBinarioHuffman<T>::ArbolBinarioHuffman()
{
    raiz=new NodoBinario<T>();
}
template< class T>
ArbolBinarioHuffman<T>::ArbolBinarioHuffman(const T& val,const T& val2)
{
    raiz.fijarFrec(val);
    raiz.fijarVal(val2);
}
template< class T>
bool ArbolBinarioHuffman<T>::esVacio()
{
    if(raiz==NULL)
        return true;
    return false;
}

template< class T>
void ArbolBinarioHuffman<T>::fijarRaiz(NodoBinario<T>* dato)
{
    raiz=dato;
}

template< class T>
NodoBinario<T>* ArbolBinarioHuffman<T>::datoRaiz()
{
    return raiz;
}
template< class T>
void ArbolBinarioHuffman<T>::preOrden(NodoBinario<T> *inicio)
{
    if(inicio!=NULL)
    {
        cout<<inicio->obtenerFrec()<<" "<<inicio->obtenerVal()<<endl;
        preOrden(inicio->obtenerHijoIzq());
        preOrden(inicio->obtenerHijoDer());
    }
}
template< class T>
void ArbolBinarioHuffman<T>::inOrden(NodoBinario<T> *inicio)
{
    if(inicio!=NULL)
    {
        inOrden(inicio->obtenerHijoIzq());
        cout<<inicio->obtenerFrec()<<" ";
        cout<<inicio->obtenerVal()<<endl;
        inOrden(inicio->obtenerHijoDer());
    }
}
template< class T>
void ArbolBinarioHuffman<T>::posOrden(NodoBinario<T> *inicio)
{
    preorden(inicio->obtenerHijoIzq());
    preorden(inicio->obtenerHijoDer());
    cout<<inicio->obtenerFrec()<<" ";
    cout<<inicio->obtenerVal()<<endl;
}
template< class T>
void ArbolBinarioHuffman<T>::nivelOrden(NodoBinario<T> *inicio)
{
    queue<NodoBinario<T>*>q;
    NodoBinario<T> *t=inicio;
    while(t!=NULL)
    {
        cout<<inicio->obtenerFrec()<<" ";
        cout<<inicio->obtenerVal()<<endl;
        if(t->obtenerHijoIzq()!=NULL)
            q.push(t->obtenerHijoIzq());
        if(t->obtenerHijoDer()!=NULL)
            q.push(t->obtenerHijoDer());
        if(!q.empty())
            t=q.pop();
        else
            t=NULL;
    }
}
template< class T>
int ArbolBinarioHuffman<T>::altura(NodoBinario<T> *inicio)
{
    if(inicio==NULL)
        return -1;
    else if(inicio->obtenerHijoIzq()==NULL&&inicio->obtenerHijoDer()==NULL)
        return 0;
    int ai=this->altura(inicio->obtenerHijoIzq());
    int ad=this->altura->obtenerHijoDer();
    if(ai>ad)
        return (ai+1);
    else
        return (ad+1);
}
template< class T>
int ArbolBinarioHuffman<T>::tamano(NodoBinario<T> *inicio)
{
    if(inicio==NULL)return 0;
    int ti=this->tamano(inicio->obtenerHijoIzq());
    int td=this->tamano(inicio->obtenerHijoDer());
    return(1+ti+td);
}
template< class T>
bool ArbolBinarioHuffman<T>::buscar(char val,string& res,NodoBinario<T> *inicio)
{

    if(inicio->obtenerDato()==val)
        return true;

    if(inicio->obtenerHijoIzq()!=NULL&&buscar( val, res,inicio->obtenerHijoIzq()))
    {
        res+='0';
        return true;
    }
    if(inicio->obtenerHijoDer()!=NULL&&buscar( val, res,inicio->obtenerHijoDer()))
    {
        res+='1';
        return true;
    }
    return false;

}

template< class T>
bool ArbolBinarioHuffman<T>::insertarNodo(stringstream& val,NodoBinario<T>* n)
{
    int  cont=0, f,v;
    bool insertado=true;
    val>>f>>v;
    if(f==-1)
    {
        NodoBinario<T>*p =new NodoBinario<T>();
        n->fijarFrec(f);
        n->fijarVal(v);
        insertarNodo(val,p->hijoIzq());
    }
    else
    {
        if(n->obtenerHijoIzq()==NULL)
        {
            n =new NodoBinario<T>();
            n->fijarFrec(f);
            n->fijarVal(v);
            insertarNodo(val,n->hijoDer());
        }
        else
        {
            if(n->obtenerHijoDer()==NULL)
            {
                NodoBinario<T>*b =new NodoBinario<T>();
                b->fijarFrec(f);
                b->fijarVal(v);
                n->fijarHijoIzq(b);
                insertarNodo(val,n->hijoDer());
            }
        }

    }


    return insertado;
}


template< class T>
void ArbolBinarioHuffman<T>::entre(NodoBinario<T> *inicio, T&valMin, T&valMax)
{
    bool a=false;
    if(inicio!=NULL)
    {
        entre(inicio->obtenerHijoIzq(),valMin,valMax);
        if(inicio->obtenerDato()>=valMin&&inicio->obtenerDato()<=valMax)
            cout<<inicio->obtenerDato()<<" ";
        entre(inicio->obtenerHijoDer(),valMin,valMax);
    }
}

template< class T>

void ArbolBinarioHuffman<T>:: borrarArbol(NodoBinario<T> *inicio)
{

    if(inicio->obtenerHijoIzq()!=NULL)
        borrarArbol(inicio->obtenerHijoIzq());
    if(inicio->obtenerHijoDer()!=NULL)
        borrarArbol(inicio->obtenerHijoDer());

    NodoBinario<T>* aux= inicio;
    if(inicio=raiz)
        raiz=NULL;
    inicio=NULL;
    delete aux;


}


bool comp(NodoBinario<int>*a,NodoBinario<int>*b)
{

    if(a->obtenerFrec()<b->obtenerFrec())
        return true;
    if(a->obtenerFrec()>b->obtenerFrec())
        return false;

    return false;
}


template< class T>
string ArbolBinarioHuffman<T>:: generarArbol(string nomArchivo)
{
    ifstream lectura(nomArchivo);
    string bas, w,h,maxPix, retorno;
    int pix;
    map<int,int> pix_frec;
    map<int,int> ::iterator it;
    vector<NodoBinario<int>* > armando;
    vector<int> pixeles;

    lectura>>bas>>w>>h>>maxPix;
    retorno=w+" "+h+" "+maxPix;
    while(lectura>>pix)
    {
        pixeles.push_back(pix);
        pix_frec[pix]++;
    }
    for(it=pix_frec.begin(); it!=pix_frec.end(); it++)
    {
        NodoBinario<int> *aux=new NodoBinario<int>();
        aux->fijarFrec(it->second);
        aux->fijarVal(it->first);
        cout<<it->first<<"--- "<<it->second<<endl;
        armando.push_back(aux);
    }

    while (armando.size()!=1)
    {
        sort(armando.begin(),armando.end(),comp);
        for(int i=0; i<armando.size(); i++)
        {
            cout<<armando[i]->obtenerVal()<<" "<<armando[i]->obtenerFrec()<<"     ";
        }
        cout<<endl;
        NodoBinario<int> *nodo1= armando[0];
        NodoBinario<int> *nodo2= armando[1];
        NodoBinario<int> *nodoFinal= new NodoBinario<int>;
        nodoFinal->fijarFrec(nodo1->obtenerFrec()+nodo2->obtenerFrec());
        nodoFinal->fijarVal(-1);
        nodoFinal->fijarHijoDer(nodo2);
        nodoFinal->fijarHijoIzq(nodo1);
        //cout<<nodo1->obtenerVal()<<" "<<nodo2->obtenerVal()<<" "<<nodoFinal->obtenerFrec()<<"----";
        armando.erase(armando.begin(), armando.begin()+2);
        armando.push_back(nodoFinal);
    }
    this->fijarRaiz(armando[0]);
    //conversor(nomArchivo, retorno, pixeles);
    return retorno;

}

template< class T>
void ArbolBinarioHuffman<T>::preOrdenConversor(NodoBinario<T> *inicio, vector<pair<int,int> >&info)
{
    if(inicio!=NULL)
    {
        info.push_back(make_pair(inicio->obtenerVal(),inicio->obtenerFrec()));
        preOrdenConversor(inicio->obtenerHijoIzq(),info);
        preOrdenConversor(inicio->obtenerHijoDer(),info);
    }
}

template< class T>
void ArbolBinarioHuffman<T>:: conversor(string nomArchivo,string propiedades, vector<int>&pixeles)
{
    vector<pair<int,int> >info;
    ofstream salida(nomArchivo);
    salida<<propiedades<<endl;
    preOrdenConversor(datoRaiz(),info);
    for(int i=0; i<info.size(); i++)
    {
        salida<<info[i].first<<" "<<info[i].second<<" ";
    }
    salida<<endl;
}

