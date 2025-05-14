#include <iostream>
#include <cstdlib>
#include "grafo.h"
#include "conjunto.h"
#include <queue>
#include <sstream>
#include <map>
#include <list>


using namespace std;

//Ejercicio 1
template <typename T>
T verticeMaxCoste(const Grafo<T, float>& G)
{
    int costeMax = 0;
    Conjunto<Vertice<T>> cv = G.vertices();
    Conjunto<Arista<T, float>> ca = G.aristas();
    T v, vMax;
    typedef map<T,float> Diccionario;
    typedef pair<T, float> Par;
    Diccionario d;

    for(int i = 0; i < G.numVertices(); i++){
        v = cv.quitar().getObj();
        Par p(v,0);
        d.insert(p);
    }

    while(!ca.esVacio()){
        Arista<T, float> a = ca.quitar();
        typename Diccionario::iterator id = d.find(a.getOrigen());
        id->second += a.getEtiqueta();
    }

    for(typename Diccionario::iterator idic = d.begin(); idic != d.end(); idic++){
        if(costeMax < idic->second){
            costeMax = idic->second;
            vMax = idic->first;
        }
    }
    return vMax;

}



//Ejercicio 2
template <typename T, typename U>
void inaccesibles(const Grafo<T, U>& G)
{
    Conjunto<Vertice<T>> cv;
    cv = G.vertices();

    Conjunto<Arista<T, float>> ca;
    ca = G.aristas();
    map<int,T> apuntados;
    bool apuntado;



    int i = 0;
    while(!ca.esVacio()){
        Arista<T,float> a = ca.quitar();
        apuntados[i] = a.getDestino();
        i++;
    }

    for(int j = 0; j < G.numVertices(); j++ ){
            apuntado = false;
            T v = cv.quitar().getObj();
        for(int h = 0; h < i; h++){
            if(v == apuntados[h]){
                apuntado = true;
            }
        }
        if(!apuntado){
            cout<< v <<" ";
        }
    }
    cout<<endl;
}


// Ejercicio 3
template <typename T, typename U>
bool caminoEntreDos(const Grafo<T, U>& G, const T& vo, const T& vd)
{
    if(!G.estaVertice(vo) || ! !G.estaVertice(vd)){
        return false;
    }

    Conjunto<Vertice<T>> cv = G.vertices();
    Conjunto<Arista<T, U>> ca = G.aristas();

    T vert = vo;
    Arista<T, U> a

    queue<T> cola;

    int i = 0;
    bool encontrado = false;
    while(!encontrado && i < G.numVertices()){
        if(vert == vd){
            encontrado = true;
            break;
        }
    }




}


//Ejercicio 4
template <typename T>
void caminosAcotados(const Grafo<T, float>& G, const T& u, float maxCoste)
{
}


//Ejercicio 5
template <typename T, typename U>
T outConectado(const Grafo<T, U>& G)
{
}


//Ejercicio 6
template <typename T, typename U>
void recorrido_profundidad(const Grafo<T, U>& G, const T& v)
{
}


//********************************************************************//
int main()
{
    Grafo<int, float> G(7);
    for (int i = 1; i <= 7; i++) G.insertarVertice(i);
    G.insertarArista(2, 1, 4);
    G.insertarArista(1, 3, 3);
    G.insertarArista(1, 4, 2);
    G.insertarArista(1, 6, 1);
    G.insertarArista(6, 4, 5);
    G.insertarArista(4, 7, 3);
    G.insertarArista(5, 1, 6);

    Grafo<string, float> H(7);
    H.insertarVertice("Huelva"); H.insertarVertice("Lepe"); H.insertarVertice("Niebla");
    H.insertarVertice("Mazagon"); H.insertarVertice("Almonte"); H.insertarVertice("Aljaraque");
    H.insertarVertice("Matalascañas");
    H.insertarArista("Lepe", "Huelva", 4);
    H.insertarArista("Huelva", "Niebla", 3);
    H.insertarArista("Huelva", "Mazagon", 2);
    H.insertarArista("Huelva", "Aljaraque", 1);
    H.insertarArista("Mazagon", "Almonte", 3);
    H.insertarArista("Mazagon", "Matalascañas", 4);
    H.insertarArista("Aljaraque", "Mazagon", 5);
    H.insertarArista("Almonte", "Huelva", 6);


    cout << " Vertice de maximo coste en G: " << verticeMaxCoste(G) << endl;
    cout << " Vertice de maximo coste en H: " << verticeMaxCoste(H) << endl;

    cout << endl << " Vertices inaccesibles en G: ";
    inaccesibles(G);

    /*
    cout << endl << " Camino entre Dos en H de Lepe a Almonte: ";
    cout << (caminoEntreDos(H, string("Lepe"), string("Almonte")) ? " SI " : " NO ") << endl;
    cout << endl << " Camino entre Dos en H de Aljaraque a Lepe: ";
    cout << (caminoEntreDos(H, string("Aljaraque"), string("Lepe")) ? " SI " : " NO ") << endl;

    cout << endl << " Caminos acotados en G a coste 9 desde el vertice 2:" << endl;
    caminosAcotados(G, 2, 9);

    cout << endl << endl << " Vertice outConectado en G: " << outConectado(G);
    cout << endl << " Vertice outConectado en H: " << outConectado(H);

    cout << endl << endl << " Recorrido en profundidad de H desde el vertice Huelva:  ";
    recorrido_profundidad(H, string("Huelva"));
    cout << endl << endl;
*/

    system("PAUSE");
    return EXIT_SUCCESS;
}
