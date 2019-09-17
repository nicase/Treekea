/** @file Sistema.hh
    @brief Especificación de la clase Sistema 
*/


#ifndef _SISTEMA_
#define _SISTEMA_

#include "Almacen.hh"
#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no 
#include <iostream>	    // incluya estas clases en los diagramas modulares, 
#include <string>           // mientras que el compilador de c++ 
#include <map>              // sí que las procesa correctamente 
using namespace std;
#endif      

class Sistema {
	private:
	
		map<string,int> inventario;
		
    public:

        //Constructoras

         /** @brief Constructora por defecto
	    \pre Cierto
	    \post Se ha creado un sistema sin ningún producto
         */  

        Sistema();

        //Modificadoras

        /** @brief Añade un producto al sistema
	    \pre id es el identificador de un producto
	    \post El parámetro booleano b indica si el producto ya existía en el sistema. Si b = true, el producto ya existe y
            se produce un error. Si b = false, se ha añadido el producto con identificador 'id'
         */

        void poner_prod(string id);

        /** @brief Elimina un producto del sistema
	    \pre El parámetro implícito está inicializado
	    \post El parámetro booleano b indica si el producto ya existía en el sistema. Si b = false, el producto no existe en el sistema
            y se produce un error. Si b = true, entonces se ha eliminado el producto con identificador 'id' del sistema
         */  

        void quitar_prod(string id, bool& b);

        /** @brief Modificadora de los atributos
	    \pre El parámetro implícito (A) está inicializado
	    \post El parámetro implícito ha aumentado en n unidad el poducto
        */
        void aumentar_prod(string id, int n);
  
        /** @brief Modificadora de los atributos
	    \pre El parámetro implícito (A) está inicializado
	    \post El parámetro implícito ha disminuido en n unidad el poducto
        */
        void disminuir_prod(string id, int n);
        
        //PASSAR STRING PER REFERENCIA

        //Consultoras



         /** @brief Consulta un producto del sistema
	    \pre Cierto
	    \post El parámetro booleano b indica si el producto existe en el sistema. Si b = false, el producto no esta en el sistema y se produce
            un error. Si b=true, se devuelve las unidades del producto que hay en el sistema
         */  

        int consultar_prod(const string id) const;
        
        bool existeix_prod(const string id) const;

        //Entrada/Salida

        /** @brief Escribe los elementos del inventario del almacén
	    \pre Cierto
	    \post Se han escito por el canal estandar de salida los identificadores de los productos seguidos por
            la cantidad total en el almacén, ordenados según los identificadores
         */  

        void escribir_inventario();

};

#endif
