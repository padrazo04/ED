/*!
   \file Polinomio.hpp
   \brief Definición de la clase Polinomio
*/

#ifndef _POLINOMIO_HPP_
#define _POLINOMIO_HPP_

// Control de asertos
#include <cassert>

// Vector de STL
#include <vector>

// Para usar la función abs
#include <cmath>

#include "PolinomioInterfaz.hpp"
#include "Monomio.hpp"
#include "operadoresExternosMonomios.hpp" // Para comparación de Monomios


// Se incluye la clase Polinomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

//!  Definición de la clase Polinomio que hereda de PolinomioInterfaz
class Polinomio : public ed::PolinomioInterfaz {

//! \name Atributos privados de la clase Polinomio
private:
	std::vector <Monomio> polinomio_; //!< Polinomio formado por un vector de Monomios	

//! \name Funciones o métodos públicos de la clase Polinomio
public:

	//! \name Constructores de la clase Polinomio

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	inline Polinomio() {
		polinomio_.push_back(Monomio());

		#ifndef NDEBUG
			assert(esNulo());
		#endif //NDEBUG
	}

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	inline Polinomio(Polinomio const & p) {
		this->polinomio_=p.polinomio_;

		#ifndef NDEBUG
			assert(this->polinomio_ == p.polinomio_);
		#endif //NDEBUG
	}

	//! \name Observadores: funciones de consulta de la clase Polinomio

	inline virtual bool esNulo() const {
		// Este primer caso nunca se dará puesto que en el 
		// constructor ya establece al menos size()=1
		if(polinomio_.size()==0) 
			return true;

		else if(polinomio_.size()==1 and polinomio_[0].esNulo())
			return true;

		else return false;
	}

	inline virtual int getGrado() const {
		#ifndef NDEBUG
			if(getNumeroMonomios()>1)
				for(int i=0 ; i<(getNumeroMonomios() - 1) ; i++)
					assert(polinomio_[i].getGrado() > polinomio_[i+1].getGrado());
		#endif //NDEBUG

		return (polinomio_.front().getGrado());
	}

	inline virtual int getNumeroMonomios() const {
		if(esNulo()) return 0;

		else return ((int)polinomio_.size());
	}

	inline virtual bool existeMonomio(int n) const {
		//El polinomio existe puesto que está ejecutando la función
		int i=0;

		while(i<getNumeroMonomios() and polinomio_[i].getGrado() >= n) {
			if(polinomio_[i].getGrado()==n)
				return true;
			i++;
		}

		return false;
	}

	inline virtual Monomio & getMonomio(int n) {
		// El polinomio existe puesto que está ejecutando la función
		int i=0;

		while(i<getNumeroMonomios() and polinomio_[i].getGrado() >= n) {
			if(polinomio_[i].getGrado()==n)
				return (polinomio_[i]);
			i++;
		}

		// Si no encuentra nada, devuelve un monomio nulo.
		return(*(new Monomio(0.0,0)));
	}

	///////////////////////////////////////////////////////////////////////

	//! \name Funciones de modificación de la clase Polinomio

	//! \name Operadores de la clase Polinomio

	//Operadores de asignación


	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(Monomio const &m);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator=(double const &x);


	// Operadores aritméticos y asignación


	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(Monomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator+=(double const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator-=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator-=(Monomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator-=(double const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator*=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator*=(Monomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator*=(double const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator/=(Polinomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator/=(Monomio const &p);

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	Polinomio & operator/=(double const &p);


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones lectura y escritura de la clase Polinomio


	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	void leerPolinomio();

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	void escribirPolinomio();


	///////////////////////////////////////////////////////////////////////

	//! \name Funciones auxiliares de la clase Polinomio


	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	double calcularValor(double const & x) const;

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	void ordenaPolinomio();

	// COMPLETAR LOS COMENTARIOS DE DOXYGEN
	void eliminaRepetidos();


}; // Fin de la definición de la clase Polinomio


} // \brief Fin de namespace ed.

//  _POLINOMIO_HPP_
#endif
