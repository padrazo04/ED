/*!
   \file Polinomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Polinomio
*/


// Ficheros de cabecera
#include <iostream>
#include <algorithm>

#include "Polinomio.hpp"

using std::cout;
using std::cin;

///////////////////////////////////////////////////////////////////////////

// Operadores de asignación


ed::Polinomio & ed::Polinomio::operator=(ed::Polinomio const &p) {
	#ifndef NDEBUG
		assert(this->polinomio_ != p.polinomio_);
	#endif //NDEBUG

	this->polinomio_=p.polinomio_;

	#ifndef NDEBUG
		assert(this->polinomio_ == p.polinomio_);
	#endif //NDEBUG

	return *this;
}

ed::Polinomio & ed::Polinomio::operator=(ed::Monomio const &m) {
	polinomio_.clear();

	polinomio_.push_back(m);

	#ifndef NDEBUG
		assert(polinomio_[0] == m);
	#endif //NDEBUG

	return *this;
}

ed::Polinomio & ed::Polinomio::operator=(double const &x) {
	polinomio_.clear();

	polinomio_.push_back(Monomio(x,0));

	#ifndef NDEBUG
		assert(polinomio_[0] == Monomio(x,0));
	#endif //NDEBUG

	return *this;
}

///////////////////////////////////////////////////////////////////////////

// Operadores aritméticos y de asignación


ed::Polinomio & ed::Polinomio::operator+=(ed::Polinomio const &p) {
	for(int i=0; i<p.getNumeroMonomios(); i++) {
		this->polinomio_.push_back(p.polinomio_[i]);
	}

	ordenaPolinomio();
	eliminaRepetidos();

	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(ed::Monomio const &p) {
	int i=0;

	while(i < getNumeroMonomios() and polinomio_[i].getGrado() >= p.getGrado()) {
		if(polinomio_[i].getGrado() == p.getGrado()) {
			polinomio_[i]+=p;
			return *this;
		}
		i++;
	}

	polinomio_.insert(polinomio_.begin()+i, p);

	return *this;
}

ed::Polinomio & ed::Polinomio::operator+=(double const &p) {
	if(existeMonomio(0))
		polinomio_.back()+=Monomio(p,0);
	else polinomio_.push_back(Monomio(p,0));

	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Polinomio const &p) {
	for(int i=0; i<p.getNumeroMonomios(); i++) {
		this->polinomio_.push_back(-p.polinomio_[i]);
	}

	ordenaPolinomio();
	eliminaRepetidos();

	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(ed::Monomio const &p) {
	int i=0;

	while(i < getNumeroMonomios() and polinomio_[i].getGrado() >= p.getGrado()) {
		if(polinomio_[i].getGrado() == p.getGrado()) {
			polinomio_[i]-=p;
			return *this;
		}
		i++;
	}

	polinomio_.insert(polinomio_.begin()+i, -p);

	return *this;
}

ed::Polinomio & ed::Polinomio::operator-=(double const &p) {
	if(existeMonomio(0))
		polinomio_.back()-=Monomio(p,0);
	else polinomio_.push_back(Monomio(-p,0));

	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Polinomio const &p) {
	


	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(ed::Monomio const &p) {
	


	return *this;
}

ed::Polinomio & ed::Polinomio::operator*=(double const &p) {
	


	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Polinomio const &p) {
	


	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(ed::Monomio const &p) {
	


	return *this;
}

ed::Polinomio & ed::Polinomio::operator/=(double const &p) {
	


	return *this;
}

///////////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Polinomio


void ed::Polinomio::leerPolinomio() {
	polinomio_.clear();

	int nmon;
	Monomio aux;

	cout << "Numero de Monomios del Polinomio: ";
	cin >> nmon;
	cin.ignore();

	for(int i=0; i<nmon; i++) {
		aux.leerMonomio();
		polinomio_.push_back(aux);
	}

	ordenaPolinomio();
	eliminaRepetidos();
}

void ed::Polinomio::escribirPolinomio() {
	if(esNulo())
		cout << "0";
	else for(int i=0; i<getNumeroMonomios(); i++) {
		polinomio_[i].escribirMonomio();
		if( (i!=getNumeroMonomios()-1) and (polinomio_[i+1].getCoeficiente()>=0) )
			cout << " +";
		else cout << " ";
	}
}

///////////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Polinomio


double ed::Polinomio::calcularValor(double const & x) const {
	return 0.0;
}

// Funcion auxiliar externa a la clase Polinomio
// Se utiliza para definir cómo un Monomio es mayor que otro
// COMPLETAR LOS COMENTARIOS DE DOXYGEN
bool ordenaMonomio(ed::Monomio const & m1, ed::Monomio const & m2) {
	return(m1.getGrado() > m2.getGrado());	
}

void ed::Polinomio::ordenaPolinomio() {
	std::sort(polinomio_.begin(), polinomio_.end(), ordenaMonomio);
}

void ed::Polinomio::eliminaRepetidos() {
	std::vector<Monomio> aux;
	int i=0;

	while (i < getNumeroMonomios()) {
		aux.push_back(polinomio_[i]);
		i++;
		while(aux.back().getGrado()==polinomio_[i].getGrado() and i < getNumeroMonomios()) {
			aux.back()+=polinomio_[i];
			i++;
		}
	}

	polinomio_=aux;
}

