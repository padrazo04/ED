/*! 
	\file Monomio.hpp
	\brief Definición de la clase Monomio
*/

#ifndef _MONOMIO_HPP_
#define _MONOMIO_HPP_

// Para usar la funciones pow y std::abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#define COTA_ERROR 1.0e-6  //!< Cota de error para la comparación números reales

// Se incluye la clase Monomio dentro del espacio de nombre de la asigantura: ed
namespace ed {

	//!  Definición de la clase Monomio:  \f$ coeficiente \hspace{1ex} X^{grado} \f$ 
	class Monomio {
		//! \name Atributos privados de la clase Monomio
		private:
			double coef_; //!< Coeficiente del Monomio
			int grado_; //!< Grado del Monomio

		//! \name Funciones o métodos públicos de la clase Monomio
		public:

		//! \name Constructores de la clase Monomio

		/*! 
			\brief     Constructor que crea un Monomio a partir de su coeficiente y su grado
			\attention Función sobrecargada        
			\note      Función inline
		 	\warning   Los parámetros tienen valores por defecto
			\param     coef: Coeficiente del Monomio; valor por defecto 0.0
			\param     grado: Grado del Monomio; valor por defecto 0
			\pre       El grado del Monomio es mayor o igual que 0
			\post	   El coeficiente del monomio es igual al valor del parámetro “coeficiente”
			\post	   El grado del monomio es igual al valor del parámetro “grado”
			\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
			\sa        setCoeficiente(), setGrado()
		*/
		inline Monomio(double const &coef=0.0, int const &grado=0) {
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(grado >= 0);
			#endif //NDEBUG

			this->setCoeficiente(coef);
			this->setGrado(grado);

			#ifndef NDEBUG
				// Se comprueban las postcondiciones
				assert(std::abs(this->getCoeficiente() - coef) < COTA_ERROR); 
				assert(this->getGrado() == grado);
			#endif //NDEBUG
		}

		/*! 
			\brief     Constructor que crea un Monomio a partir de otro Monomio
			\attention Función sobrecargada        
			\note      Función inline
		 	\warning   Se require que las funciones de acceso getCoeficiente y getGrado tengan el calificador const
			\param     m: Monomio utilizado para proporcionar los valores iniciales del nuevo Monomio
			\post	   El coeficiente del monomio es igual al coeficiente del monomio “m”
			\post	   El grado del monomio es igual al grado del monomio “m”.
			\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
			\sa        setCoeficiente(), setGrado(), getCoeficiente(), getGrado()
		*/
		inline Monomio(Monomio const &m) {
			this->setCoeficiente(m.getCoeficiente());
			this->setGrado(m.getGrado());

			#ifndef NDEBUG
				assert(std::abs(this->getCoeficiente() - m.getCoeficiente()) < COTA_ERROR); 
				assert(this->getGrado() == m.getGrado());
			#endif //NDEBUG
		}

		//! \name Observadores: funciones de consulta de la clase Monomio

		/*! 
			\brief   Función que devuelve el coeficiente de un Monomio
			\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
			\note    Función inline
			\return  Coeficiente del Monomio (tipo double)
			\sa      getGrado()
		*/
		inline double getCoeficiente() const {return coef_;}

		/*! 
			\brief   Función que devuelve el grado de un Monomio
			\warning Se utiliza el modificador const en la definición de la función para poder definir el constructor de copia y el operador de asignacion "="
			\note    Función inline
			\return  Grado del Monomio (tipo int)
			\sa      getCoeficiente()
		*/
		inline int getGrado() const {return grado_;}

		//! \name Funciones de modificación de la clase Monomio

		/*! 
			\brief Función que asigna un valor "x" al coeficiente de un Monomio
			\note  Función inline
			\param x: nuevo valor del coeficiente del Monomio (tipo double)
			\post  El coeficiente del monomio es igual al número real “x”
			\note  Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
			\sa    setGrado()
		*/
		inline void setCoeficiente(double const & x) {
			coef_=x;

			#ifndef NDEBUG
				// Se comprueba la postcondicion
				assert(std::abs(this->getCoeficiente() - x) < COTA_ERROR); 
			#endif //NDEBUG
		}

		/*! 
			\brief Función que comprueba si un Monomio es nulo o no.
			\note  Función inline
			\sa    getGrado(), getCoeficiente()
		*/
		inline bool esNulo() const {
			if(this->getGrado()==0 and (std::abs(this->getCoeficiente())<COTA_ERROR))
				return true;
			else return false;
		}

		/*! 
			\brief Función que asigna un valor "n" al grado de un Monomio
			\note  Función inline
			\pre   El número entero “n” es mayor o igual que 0
			\param n: nuevo valor del grado del Monomio (tipo int)
			\post  El grado del monomio es igual al número entero “n”.
			\sa    setCoeficiente()
		*/
		inline void setGrado(const int& n) {
			#ifndef NDEBUG
				// Se comprueba la precondicion
				assert(n >= 0);
			#endif //NDEBUG

			grado_=n;

			#ifndef NDEBUG
				// Se comprueba la postcondicion 
				assert(this->getGrado() == n);
			#endif //NDEBUG
		}

		/////////////////////////////////////////////////

		//! \name Operadores de la clase Monomio

		// Operadores de asignación

		/*! 
			\brief     Operador de asignacion: operador que "copia" un Monomio en otro Monomio
			\attention Se sobrecarga el operador de asignacion "="
			\warning   Se requiere que las funciones de acceso getGrado y getCoeficiente tengan el modificador const
			\param     m: objeto de tipo Monomio pasado como referencia constante
			\post	   El grado del Monomio debe tener el valor del grado del Monomio m
			\post	   El coeficiente del Monomio debe tener el valor del ceoficiente del Monomio m
			\note	   Se debe utilizar COTA_ERROR para controlar la precisión de los números reales
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
		*/
		Monomio& operator=(Monomio const &m);

		/*! 
			\brief     Operador de asignacion: operador que asigna grado 0 al Monomio y el valor x al coeficiente
			\attention Se sobrecarga el operador de asignacion "="
			\param     x: nuevo valor del coeficiente del Monomio(tipo double)
			\post	   El grado del Monomio es igual a 0
			\post	   El coeficiente del monomio es igual al número real “x”.
			\sa        setCoeficiente, setGrado()
		*/
		Monomio& operator=(double const &x);

		// Operadores aritméticos y asignación

		/*! 
			\brief     Modifica el monomio sumándole otro monomio de igual grado
			\warning   Se requiere que la función de acceso getCoeficiente tenga el modificador const
			\param     m: objeto de tipo Monomio pasado como referencia constante
			\pre 	   El monomio “m” tiene el mismo grado que el monomio actual
			\post	   El coeficiente del monomio actual se ha incrementado con el coeficiente del monomio “m”
			\post	   El grado del monomio actual no ha sido modificado
			\sa        getCoeficiente(), setCoeficiente()
		*/
		Monomio& operator+=(Monomio const &m);

		/*! 
			\brief     Modifica el monomio restándole otro monomio de igual grado
			\warning   Se requiere que la función de acceso getCoeficiente tenga el modificador const
			\param     m: objeto de tipo Monomio pasado como referencia constante
			\pre 	   El monomio “m” tiene el mismo grado que el monomio actual
			\post	   El coeficiente del monomio actual se ha decrementado con el coeficiente del monomio “m”
			\post	   El grado del monomio actual no ha sido modificado
			\sa        getCoeficiente(), setCoeficiente()
		*/
		Monomio& operator-=(Monomio const &m);

		/*! 
			\brief     Modifica el monomio multiplicándolo por otro monomio
			\warning   Se requiere que las funciones de acceso getGrado y getCoeficiente tengan el modificador const
			\param     m: objeto de tipo Monomio pasado como referencia constante
			\post	   El coeficiente del monomio actual se ha multiplicado por el coeficiente del monomio “m”
			\post	   El grado del monomio actual se ha incrementado con el grado del monomio “m”
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
		*/
		Monomio& operator*=(Monomio const &m);

		/*! 
			\brief     Modifica el monomio dividiéndolo entre otro monomio
			\warning   Se requiere que las funciones de acceso getGrado y getCoeficiente tengan el modificador const
			\param     m: objeto de tipo Monomio pasado como referencia constante
			\pre 	   El grado del monomio “m” es igual o inferior al grado del monomio actual
			\pre 	   El coeficiente del monomio “m” no es 0.0
			\post	   El coeficiente del monomio actual se ha dividido por el coeficiente del monomio “m”
			\post	   El grado del monomio actual se ha decrementado con el grado del monomio “m”
			\sa        getCoeficiente(), getGrado(), setCoeficiente(), setGrado()
		*/
		Monomio& operator/=(Monomio const &m);

		/*! 
			\brief     Modifica el monomio multiplicándolo por un número real
			\param     x: valor que multiplica al Monomio(tipo double)
			\post	   El coeficiente del monomio actual se ha multiplicado por el número real “x”
			\post	   El grado del monomio actual no ha sido modificado
			\sa        setCoeficiente()
		*/
		Monomio& operator*=(double const &x);

		/*! 
			\brief     Modifica el monomio dividiéndolo entre un número real
			\param     x: valor que divide al Monomio(tipo double)
			\post	   El coeficiente del monomio actual se ha dividido por el número real “x”
			\post	   El grado del monomio actual no ha sido modificado
			\sa        setCoeficiente()
		*/
		Monomio& operator/=(double const &x);

		/////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones lectura y escritura de la clase Monomio

		/*! 
			\brief   Lee desde teclado los atributos "coeficiente" y "grado" del Monomo
			\warning Se deben teclear números
			\post    Los atributos coef_ y grado_ de Monomio deben tener valores numéricos
			\sa      setCoeficiente(), setGrado(), escribirMonomio()
		*/
		void leerMonomio();

		/*! 
			\brief Escribe por pantalla los atributos del monomio con el formato: coeficiente X^grado
			\note  Si el coeficiente es 1 entonces se escribirá X^grado
			\note  Si el coeficiente es -1 entonces se escribirá -X^grado
			\note  Si el grado es 0 entonces se escribirá solo el coeficiente.
			\note  Si el grado es 1 entonces se escribirá X pero sin grado
			\sa    getCoeficiente(), getGrado(), leerMonomio()
		*/
		void escribirMonomio();

		///////////////////////////////////////////////////////////////////////

		//! \name Funciones auxiliares de la clase Monomio

		/*! 
			\brief   Calcula el valor del Monomio para un número real “x”
			\param 	 x: Valor que se sustituye en el Monomio
			\sa      pow(), getCoeficiente(), getGrado()
		*/
		double calcularValor(double x);

	};  // Fin de la definición de la clase Monomio

}  //  Fin de namespace ed.

// _MONOMIO_HPP_
#endif
