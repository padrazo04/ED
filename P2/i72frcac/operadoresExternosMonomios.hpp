/*! 
	\file operadoresExternosMonomios.hpp
	\brief Ficheros con los prototipos de los operadores externos de la clase Monomio
*/

#ifndef _OperadoresExternosMonomios_HPP_
#define _OperadoresExternosMonomios_HPP_

// Facilita la entrada y salida
#include <iostream>

#include "Monomio.hpp"

// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;
using std::abs;

// Espacio de nombre de la asigantura: ed
namespace ed
{
//////////////////////////////////////////////////////////////////////////////////////
	// Operadores externos que no pertenecen a la clase Monomio

	//! \name Operadores de igualdad  

	/*! 
		\brief     Comprueba si dos monomios son iguales: m1 == m2
		\attention Función sobrecargada        
		\param     m1: Objeto de tipo Monomio comparado
		\param     m2: Objeto de tipo Monomio comparado
		\post	   El valor devuelto es verdadero si los dos monomios tienen el mismo grado y el mismo coeficiente
		\post	   El valor devuelto es falso, en caso contrario
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	bool operator==(ed::Monomio const & m1, ed::Monomio const & m2);

	/*! 
		\brief     Comprueba si un monomio es igual a un número real: m == x
		\attention Función sobrecargada        
		\param     m: Objeto de tipo Monomio comparado
		\param     x: Real que es comparado con el Monomio
		\post	   El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al número “x”
		\post	   El valor devuelto es falso, en caso contrario
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	bool operator==(ed::Monomio const & m1, double const & x);

	/*! 
		\brief     Comprueba si un monomio es igual a un número real: x == m
		\attention Función sobrecargada        
		\param     x: Real que es comparado con el Monomio
		\param     m: Objeto de tipo Monomio comparado
		\post	   El valor devuelto es verdadero si el monomio tiene grado 0 y su coeficiente es igual al número “x”
		\post	   El valor devuelto es falso, en caso contrario
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	bool operator==(double const & x, ed::Monomio const & m1);

	//! \name Operadores de desigualdad 

	/*! 
		\brief     Comprueba si dos monomios no son iguales: m1 != m2
		\attention Función sobrecargada        
		\param     m1: Objeto de tipo Monomio
		\param     m2: Objeto de tipo Monomio
		\post	   El valor devuelto es verdadero si los dos monomios no tienen el mismo grado o no tienen el mismo coeficiente
		\post	   El valor devuelto es falso, en caso contrario
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	bool operator!=(ed::Monomio const & m1, ed::Monomio const & m2);

	/*! 
		\brief     Comprueba si un monomio no es igual a un número real: m == x
		\attention Función sobrecargada        
		\param     m: Objeto de tipo Monomio
		\param     x: Real que es comparado con el Monomio
		\post	   El valor devuelto es verdadero si el monomio no tiene grado 0 o si su coeficiente no es igual al número “x”
		\post	   El valor devuelto es falso, en caso contrario
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	bool operator!=(double const & x, ed::Monomio const & m1);

	/*! 
		\brief     Comprueba si un monomio no es igual a un número real: x == m
		\attention Función sobrecargada        
		\param     x: Real que es comparado con el Monomio
		\param     m: Objeto de tipo Monomio
		\post	   El valor devuelto es verdadero si el monomio no tiene grado 0 o si su coeficiente no es igual al número “x”
		\post	   El valor devuelto es falso, en caso contrario
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	bool operator!=(ed::Monomio const & m1, double const & x);

	///////////////////////////////////////////////////

	//! \name Operadores unarios prefijos

	/*! 
		\brief     Devuelve una copia del Monomio “m”: +m
		\param     m: Objeto de tipo Monomio
		\post	   El monomio devuelto es igual al monomio “m”, es decir, tiene el mismo grado y el mismo coeficiente
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator+(ed::Monomio const & m);

	/*! 
		\brief     Devuelve una copia del Monomio “m”: -m
		\param     m: Objeto de tipo Monomio
		\post	   El monomio devuelto tiene el mismo grado que el monomio “m” pero su coeficiente es el opuesto
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator-(ed::Monomio const & m);

	//////////////////////////////////////////////////////////

	//! \name Operador binario de la suma 

	/*! 
		\brief     Devuelve otro monomio que es la suma de dos monomios: m1 + m2
		\param     m1: Objeto de tipo Monomio
		\param     m2: Objeto de tipo Monomio
		\pre 	   Los monomios m1 y m2 tienen el mismo grado
		\post	   El monomio devuelto tiene el mismo grado que los monomios m1 y m2
		\post 	   El monomio devuelto tiene como coeficiente la suma de los coeficientes de los monomios
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator+ (ed::Monomio const &m1, ed::Monomio const &m2);


	//////////////////////////////////////////////////////////
	//! \name Operador binario de la resta 

	/*! 
		\brief     Devuelve otro monomio que es la resta de dos monomios: m1 - m2
		\param     m1: Objeto de tipo Monomio
		\param     m2: Objeto de tipo Monomio
		\pre 	   Los monomios m1 y m2 tienen el mismo grado
		\post	   El monomio devuelto tiene el mismo grado que los monomios m1 y m2
		\post 	   El monomio devuelto tiene como coeficiente la resta de los coeficientes de los monomios
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator- (ed::Monomio const &m1, ed::Monomio const &m2);


	///////////////////////////////////////////////////////////////////////////
	//! \name Operadores binarios de la multiplicación 

	/*! 
		\brief     Devuelve otro monomio que es el producto de dos monomios: m1 * m2
		\param     m1: Objeto de tipo Monomio
		\param     m2: Objeto de tipo Monomio
		\post	   El monomio devuelto tiene un grado que es la suma de los grados de los monomios m1 y m2
		\post 	   El monomio devuelto tiene como coeficiente el producto de los coeficientes de los monomios m1 y m2
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator* (ed::Monomio const &m1, ed::Monomio const &m2);

	/*! 
		\brief     Devuelve otro monomio que es el producto de un monomio por un número real: m * x
		\param     m1: Objeto de tipo Monomio
		\param     x: Real que multiplica al Monomio
		\post	   El monomio devuelto tiene el mismo grado que el monomio "m"
		\post 	   El monomio devuelto tiene como coeficiente el producto del coeficiente del monomio “m” por el número “x”
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator* (ed::Monomio const &m, double const& x);

	/*! 
		\brief     Devuelve otro monomio que es el producto de un monomio por un número real: x * m
		\param     x: Real que multiplica al Monomio
		\param     m1: Objeto de tipo Monomio
		\post	   El monomio devuelto tiene el mismo grado que el monomio "m"
		\post 	   El monomio devuelto tiene como coeficiente el producto del coeficiente del monomio “m” por el número “x”
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator* (double const& x, ed::Monomio const &m);

	///////////////////////////////////////////////////////////////////////////

	//! \name Operadores binarios de la división 

	/*! 
		\brief     Devuelve otro monomio que es la división de dos monomios: m1 / m2
		\param     m1: Objeto de tipo Monomio
		\param     m2: Objeto de tipo Monomio
		\pre 	   El grado del monomio m2 es menor o igual que el grado del monomio m1
		\pre 	   El coeficiente del monomio m2 no es 0.
		\post	   El monomio devuelto tiene un grado que es la resta de los grados de los monomios m1 y m2
		\post 	   El monomio devuelto tiene como coeficiente la división de los coeficientes del monomioa m1 y m2.
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator/ (ed::Monomio const &m1, ed::Monomio const &m2);

	/*! 
		\brief     Devuelve otro monomio que es la división del monomio “m” por el número real “x”: m / x
		\param     m: Objeto de tipo Monomio
		\param     x: Real que divide al Monomio
		\pre 	   El número x no es 0.0
		\post	   El monomio devuelto tiene el mismo grado que el monomio “m”
		\post 	   El monomio devuelto tiene como coeficiente la división del coeficiente del monomio “m” por el número “x”
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator/ (ed::Monomio const &m, double const& x);

	/*! 
		\brief     Devuelve otro monomio que es la división del número “x” por el monomio “m”: x / m
		\param     x: Real que es dividido por un Monomio
		\param     m: Objeto de tipo Monomio
		\pre 	   El grado del monomio es 0 y su coeficiente es distinto de 0.0
		\post	   El monomio devuelto tiene grado igual a 0
		\post 	   El monomio devuelto tiene como coeficiente la división del número “x” por el coeficiente del monomio “m”
		\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
		\sa        getCoeficiente(), getGrado()
	*/
	ed::Monomio & operator/ (double const& x, ed::Monomio const &m);


	/////////////////////////////////////////////////////////////////////////////

	//! \name Sobrecarga de los operadores de entrada y salida 

	/*! 
		\brief     Lee desde el flujo de entrada los atributos de un monomio separados por espacios
		\param     stream: Refencia a un flujo que lee datos
		\param     m: Objeto de tipo Monomio
		\sa        setCoeficiente(), setGrado()
	*/
	 istream &operator>>(istream &stream, ed::Monomio &m);

	/*! 
		\brief     Escribe en el flujo de salida los atributos del monomio separados por espacios
		\param     stream: Refencia a un flujo en el que se escriben datos
		\param     m: Objeto de tipo Monomio
		\sa        setCoeficiente(), setGrado()
	*/
	 ostream &operator<<(ostream &stream, ed::Monomio const &m);

}  // Fin de namespace ed.

#endif // _OperadoresExternosMonomios_HPP_


