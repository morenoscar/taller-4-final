#include<iostream>
#include<sstream>
#include<fstream>
#include "arbol.h"
#include "Nodo.h"
#include <set>

using namespace std;

/*void hauffman(string nomAr,ArbolBinarioOrd<int>& tree,string nar)
{
    ifstream ar(nomAr.c_str());
    string arbol;
    int f,v;
    getline(ar,arbol);
    if(ar.good())
    {
        stringstream ss;
        ss<<arbol;
        ss>>v>>f;
        NodoBinario<int> r=new NodoBinario<int>();
        tree.insertarNodo(ss);


    }
    else
    {
        cout<<"Problema en el archivo"<<endl;
    }



}*/

int main()
{
    ArbolBinarioHuffman<int>huffmancito;
    string comando,msj;
    set<char>caracter;
    bool casos=true;
    while(casos)
    {
        cin>>comando;
        if(comando=="codificar_imagen")
        {
            string nomImagen, nomArchivo, propiedades;
            cin>>nomImagen>>nomArchivo;
            propiedades=huffmancito.generarArbol(nomImagen);
            huffmancito.conversor(nomArchivo, propiedades);
        }
        /*if(comando=="decodificar_archivo")
        {
            string nom,nar;
            cin>>nom>>nar;
            hauffman(nom,hauf,nar);




        }*/
        cout<<endl;
        if(comando=="salir")
        {
            casos=false;
        }
    }
    return 0;
}
