/*! 
   \file  Monomio.cpp
   \brief Fichero que contiene el código de las funciones de la clase Monomio
*/

//  Ficheros de cabecera
#include <iostream>

#include "Monomio.hpp"

using std::cout;
using std::cin;

// Operadores de asignación

ed::Monomio & ed::Monomio::operator=(ed::Monomio const &m) {
	this->setCoeficiente(m.getCoeficiente());
	this->setGrado(m.getGrado());

	#ifndef NDEBUG
		// Se comprueban las postcondiciones 
		assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR);
		assert(this->getGrado() == m.getGrado());
	#endif //NDEBUG

	// Se devuelve el objeto actual
	return *this;
}

ed::Monomio & ed::Monomio::operator=(double const &x) {
	this->setCoeficiente(x);
	this->setGrado(0);

	#ifndef NDEBUG
		assert(this->getGrado() == 0);
		assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR); 
	#endif //NDEBUG

	return *this;
}

//////////////////////////////////////////////////////////////

// Operadores aritméticos y asignación

ed::Monomio & ed::Monomio::operator+=(ed::Monomio const &m) {
	#ifndef NDEBUG
		// Se comprueba la precondicion
		assert(this->getGrado() == m.getGrado());
	#endif //NDEBUG

	double oldcoef = this->getCoeficiente();
	int oldgrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() + m.getCoeficiente());

	#ifndef NDEBUG
		assert(this->getGrado() == oldgrado);
		assert(std::abs(this->getCoeficiente() - (oldcoef + m.getCoeficiente())) < COTA_ERROR);
	#endif //NDEBUG

	return *this;
}

ed::Monomio & ed::Monomio::operator-=(ed::Monomio const &m) {
	#ifndef NDEBUG
		assert(this->getGrado() == m.getGrado());
	#endif //NDEBUG

	double oldcoef = this->getCoeficiente();
	int oldgrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() - m.getCoeficiente());

	#ifndef NDEBUG
		assert(this->getGrado() == oldgrado);
		assert(std::abs(this->getCoeficiente() - (oldcoef - m.getCoeficiente())) < COTA_ERROR);
	#endif //NDEBUG

	return *this;
}

ed::Monomio & ed::Monomio::operator*=(ed::Monomio const &m) {
	double oldcoef = this->getCoeficiente();
	int oldgrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() * m.getCoeficiente());
	this->setGrado(this->getGrado() + m.getGrado());

	#ifndef NDEBUG
		assert(this->getGrado() == (oldgrado + m.getGrado()));
		assert(std::abs(this->getCoeficiente() - (oldcoef * m.getCoeficiente())) < COTA_ERROR);
	#endif //NDEBUG

	return *this;
}

ed::Monomio & ed::Monomio::operator/=(ed::Monomio const &m) {
	#ifndef NDEBUG
		assert(this->getGrado() >= m.getGrado());
		assert(std::abs(this->getCoeficiente()) > COTA_ERROR);
	#endif //NDEBUG

	double oldcoef = this->getCoeficiente();
	int oldgrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() / m.getCoeficiente());
	this->setGrado(this->getGrado() - m.getGrado());

	#ifndef NDEBUG
		assert(this->getGrado() == (oldgrado - m.getGrado()));
		assert(std::abs(this->getCoeficiente() - (oldcoef / m.getCoeficiente())) < COTA_ERROR);
	#endif //NDEBUG

	return *this;
}

ed::Monomio & ed::Monomio::operator*=(double const &x) {
	double oldcoef = this->getCoeficiente();
	int oldgrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() * x);

	#ifndef NDEBUG
		assert(this->getGrado() == oldgrado);
		assert(std::abs(this->getCoeficiente() - (oldcoef * x)) < COTA_ERROR);
	#endif //NDEBUG

	return *this;
}

ed::Monomio & ed::Monomio::operator/=(double const &x) {
	#ifndef NDEBUG
		assert(x != 0.0);
	#endif //NDEBUG

	double oldcoef = this->getCoeficiente();
	int oldgrado = this->getGrado();

	this->setCoeficiente(this->getCoeficiente() / x);

	#ifndef NDEBUG
		assert(this->getGrado() == oldgrado);
		assert(std::abs(this->getCoeficiente() - (oldcoef / x)) < COTA_ERROR);
	#endif //NDEBUG

	return *this;
}

///////////////////////////////////////////////////////////////////////

// Funciones lectura y escritura de la clase Monomio

void ed::Monomio::leerMonomio() {
	int n;
	double x;

	cout << "Coeficiente: ";
	cin >> x;

	cout << "Grado: ";
	cin >> n;

	this->setCoeficiente(x);
	this->setGrado(n);

	#ifndef NDEBUG
		assert(this->getGrado() >= 0);
	#endif //NDEBUG
}

void ed::Monomio::escribirMonomio() {
	if(this->getGrado()==0) cout << this->getCoeficiente();
	else {
		if(this->getCoeficiente()==1);

		else if(this->getCoeficiente()==-1) cout<<"-";

	 	else cout << this->getCoeficiente();

	 	cout << "x";

		if(this->getGrado()!=1) cout << "^" << this->getGrado();
	}
}

///////////////////////////////////////////////////////////////////////

// Funciones auxiliares de la clase Monomio

double ed::Monomio::calcularValor(double x) {
	return (this->getCoeficiente()*(pow(x, this->getGrado())));
}