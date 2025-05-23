#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_

#include "excep_conjunto.h"
#include <memory>

template <typename T>
class Conjunto {
    public:
		Conjunto(int n = 100);
		Conjunto(const Conjunto<T>& conj);
		Conjunto<T> operator=(const Conjunto<T>& conj);
		bool esVacio() const;
		int cardinalidad() const;
		void anadir(const T& objeto); //throw (ConjuntoLlenoExcepcion)
		void eliminar(const T& objeto);
		T quitar();
		bool pertenece(const T& objeto) const;
		~Conjunto();
	private:
	    T** c;
	    int num;
	    int capacidad;
};

#endif

// -----  Instanciaciones realizadas -----
//
//        Conjunto<Vertice<T> >
//        Conjunto<Arista<T, U> >
