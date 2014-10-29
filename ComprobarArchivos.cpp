#include<bits/stdc++.h>

using namespace std;

int main()
{
    string archivo1,archivo2;
    cout << "Ingrese archivo 1 " << endl;
    cin >> archivo1;
    cout << "Ingrese archivo 2 " << endl;
    cin >> archivo2;
    ifstream ifs ("8.txt");
    ifstream ifs1 ("a.huffman");
    ofstream cout("comprobador.txt");
    string aux,aux1,a,b;
    aux = aux1 = "";
    if (ifs1.good())
    {
        bool es=true;
        while(ifs1>>b>>aux1&&ifs>>a>>aux){
                if(aux!=aux1)
                {
                    cout<<archivo1<<":"<<a<<" "<<aux<<endl;
                    cout<<archivo2<<":"<<b<<" "<<aux1<<endl;
                    cout<<endl;
                    es=false;
                }
        }
        if(es)
            cout<<"Iguales"<<endl;
    }
    ifs1.close();

    return 0;
}
