/*! 
    \file  operadoresExternosMonomios.cpp
	\brief Ficheros con el código de los operadores externos de la clase Monomio
*/


//  Ficheros de cabecera
#include <iostream>

#include "operadoresExternosMonomios.hpp"


//  Se incluyen los operadores sobrecargados dentro del espacio de nombres ed
namespace ed 
{
	// Operadores de igualdad

	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2) {

		bool tmp = (m1.getGrado()==m2.getGrado() and abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR);

		#ifndef NDEBUG
			assert(tmp == (m1.getGrado()==m2.getGrado() and abs(m1.getCoeficiente() - m2.getCoeficiente()) < COTA_ERROR));
		#endif //NDEBUG

		return tmp;
	}

	bool operator==(ed::Monomio const & m, double const & x) {

		bool tmp = (m.getGrado()==0 and abs(m.getCoeficiente() - x) < COTA_ERROR);

		#ifndef NDEBUG
			assert(tmp == (m.getGrado()==0 and abs(m.getCoeficiente() - x) < COTA_ERROR));
		#endif //NDEBUG

		return tmp;
	}

	bool operator==(double const & x, ed::Monomio const & m) {

		bool tmp = (m.getGrado()==0 and abs(m.getCoeficiente() - x) < COTA_ERROR);

		#ifndef NDEBUG
			assert(tmp == (m.getGrado()==0 and abs(m.getCoeficiente() - x) < COTA_ERROR));
		#endif //NDEBUG

		return tmp;
	}

	// Operadores de desigualdad

	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2) {

		bool tmp = (m1.getGrado()!=m2.getGrado() or abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR);

		#ifndef NDEBUG
			assert(tmp == (m1.getGrado()!=m2.getGrado() or abs(m1.getCoeficiente() - m2.getCoeficiente()) > COTA_ERROR));
		#endif //NDEBUG

		return tmp;
	}

	bool operator!=(double const & x, ed::Monomio const & m) {

		bool tmp = (m.getGrado()!=0 or (abs(m.getCoeficiente() - x) > COTA_ERROR));

		#ifndef NDEBUG
			assert(tmp == (m.getGrado()!=0 or abs(m.getCoeficiente() - x) > COTA_ERROR));
		#endif //NDEBUG

		return tmp;
	}

	bool operator!=(ed::Monomio const & m, double const & x) {

		bool tmp = (m.getGrado()!=0 or (abs(m.getCoeficiente() - x) > COTA_ERROR));

		#ifndef NDEBUG
			assert(tmp == (m.getGrado()!=0 or abs(m.getCoeficiente() - x) > COTA_ERROR));
		#endif //NDEBUG

		return tmp;
	}

	////////////////////////////////////////////////////////////

	// Operadores unarios prefijos 

	ed::Monomio & operator+(ed::Monomio const & m) {
		// Se crea un nuevo objeto
		ed::Monomio *nuevo = new ed::Monomio(m.getCoeficiente(), m.getGrado());

		#ifndef NDEBUG
			assert(*nuevo == m);
		#endif //NDEBUG

		// Se devuelve el resultado
		return *nuevo;
	}

	ed::Monomio & operator-(ed::Monomio const & m) {
		ed::Monomio *nuevo = new ed::Monomio(-m.getCoeficiente(), m.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado() and abs(nuevo->getCoeficiente() + m.getCoeficiente()) < COTA_ERROR);
		#endif //NDEBUG
		
		return *nuevo;
	}


	////////////////////////////////////////////////////////////
	// Operadores aritméticos binarios

	// Suma
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2) {
		
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente()+m2.getCoeficiente(), m1.getGrado());

		#ifndef NDEBUG
			assert((nuevo->getGrado()) == (m1.getGrado()));
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() + m2.getCoeficiente())) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}


	////////////
	// Resta

	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2) {
		#ifndef NDEBUG
			assert(m1.getGrado() == m2.getGrado());
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente()-m2.getCoeficiente(), m1.getGrado());

		#ifndef NDEBUG
			assert((nuevo->getGrado()) == (m1.getGrado()));
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() - m2.getCoeficiente())) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}


	//////////////////
	// Multiplicación

	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2) {
		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente()*m2.getCoeficiente(), m1.getGrado()+m2.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == (m1.getGrado() + m2.getGrado()));
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() * m2.getCoeficiente())) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}

	ed::Monomio & operator* (ed::Monomio const &m, double const& x) {
		ed::Monomio *nuevo = new ed::Monomio(m.getCoeficiente()*x, m.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m.getCoeficiente() * x)) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}

	ed::Monomio & operator* (double const& x, ed::Monomio const &m) {
		ed::Monomio *nuevo = new ed::Monomio(m.getCoeficiente()*x, m.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m.getCoeficiente() * x)) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}

	////////////
	// División

	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2) {
		#ifndef NDEBUG
			assert(m2.getGrado() <= m1.getGrado());
			assert(abs(m2.getCoeficiente()) > COTA_ERROR);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio(m1.getCoeficiente()/m2.getCoeficiente(), m1.getGrado()-m2.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == (m1.getGrado() - m2.getGrado()));
			assert(abs(nuevo->getCoeficiente() - (m1.getCoeficiente() / m2.getCoeficiente())) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}

	ed::Monomio & operator/ (ed::Monomio const &m, double const& x) {
		#ifndef NDEBUG
			assert(abs(x) > COTA_ERROR);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio(m.getCoeficiente()/x, m.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == m.getGrado());
			assert(abs(nuevo->getCoeficiente() - (m.getCoeficiente() / x)) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}

	ed::Monomio & operator/ (double const& x, ed::Monomio const &m) {
		#ifndef NDEBUG
			assert(m.getGrado() == 0 and abs(m.getCoeficiente()) > COTA_ERROR);
		#endif //NDEBUG

		ed::Monomio *nuevo = new ed::Monomio(x/m.getCoeficiente(), m.getGrado());

		#ifndef NDEBUG
			assert(nuevo->getGrado() == 0);
			assert(abs(nuevo->getCoeficiente() - (x / m.getCoeficiente())) < COTA_ERROR);
		#endif //NDEBUG

		return *nuevo;
	}


	/////////////////////////////////////////////////////////////////////////////

	//  Sobrecarga del operador de entrada
	istream &operator>>(istream &stream, ed::Monomio &m) {
		double x;
		int n;

		stream >> x;
		stream >> n;

		m.setCoeficiente(x);
		m.setGrado(n);

   		// Se devuelve el flujo de entrada
		return stream;
	}


	//  Sobrecarga del operador de salida
	ostream &operator<<(ostream &stream, ed::Monomio const &m) {
		stream << m.getCoeficiente() << " " << m.getGrado(); 

		return stream;
	}
	
}  // namespace ed
