#include<iostream>
#include<sstream>
#include<fstream>
#include "arbol.h"
#include "Nodo.h"
#include <set>

using namespace std;

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
        }
        cout<<endl;
        if(comando=="salir")
        {
            casos=false;
        }
    }
    return 0;
}
