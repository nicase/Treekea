/** @file Sala.hh
    @brief Especificación de la clase Sala
*/


#ifndef _SALA_
#define _SALA_

#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no  
#include <iostream>         // incluya estas clases en los diagramas modulares,
#include <vector>	    // mientras que el compilador de c++ 
#include <string>
#include <map>		    // sí que las procesa correctamente 
#endif 
using namespace std;

typedef vector<vector<string> > Matrix;

class Sala {
	private:
		
		int id_sala;
		Matrix Estanteria;
		int filas,columnas;
		int totalprods;
		map<string,int> inventariosala;

    public:

        //Constructoras


        /** @brief Constructora por defecto
	    \pre Cierto
	    \post se ha creado una sala con una estanteria de 0 filas y columnas y 0 productos en ella
        */

        Sala();

        /** @brief Constructora con dos parámetros concretos   
	    \pre Cierto
	    \post se ha creado una sala con una estanteria de 'c' columnas y 'f' filas
        */

        Sala(int f, int c);
        
        void modificar_idsala(int idsala);

        //Modificadoras

        /** @brief Añade items de un producto
	    \pre Cierto
	    \post Se han añadido 'cantidad' items al producto con identificación 'id' de la sala 's'
              y se han devuelto los sobrantes si los hay (los que no se han podido colocar debido a que la estanteria esta llena)
        */

        int sala_poner_items(string& id, int cantidad);

        /** @brief Elimina items de un producto
	    \pre Cierto
	    \post Se han eliminado 'cantidad' items al producto con identificación 'id' de la sala 's'
              y se ha devuelto el numero de items que no se han podido eliminar (debido a que ya no quedaban)
        */

        int sala_quitar_items(string& id, int cantidad);

        /** @brief Compacta la sala
	    \pre El parámetro implícito no está vacío
	    \post La sala se ha compactado, de manera que no quedan huecos entre productos
        */

        void compactar();

        /** @brief Reorganiza la sala
	    \pre El parámetro implícito no está vacío
	    \post Se ha reorganizado la sala, de manera que los productos han quedado ordenados alfabéticamente sin huecos entre ellos
        */

        void reorganizar();

        /** @brief Redimensiona la sala
	    \pre Cierto
	    \post El parámetro booleano b indica si con las nuevas medidas cabrán los productos que hay en la sala. Si b=false, se produce
            un error. Si b=true se ha redimensionado la sala con c columnas y f filas
        */

        void redimensionar(int f, int c);

      
        //Consultoras

        /** @brief Consulta un elemento 
	    \pre Cierto
	    \post El parámetro booleano b indica si la posición [i,j] existe en la sala. Si b = false, se produce un error. Si b=true, 
            se devuelve el identificador del producto que hay en la posicion [i,j]
        */

        string consultar_pos_sala(int i, int j, bool& b) const;

        /** @brief Consulta si existe un producto en la sala
        \pre El parámetro implícito está inicializado
        \post La función retorna true si existe el producto en la sala y false si no existe
        */

        bool consultar_prod_sala(string& id) const;
        
        
        /** @brief Consulta el numero de elementos de una sala
			\pre Cierto
			\post Retorna el total de elementos de una sala
        */
        
        int total_prod() const;
        
        
		bool existeix_prod_sala(const string id) const;
        
        void actualizar_totalprods();
        
        int consultar_id();

        int consultar_total_items();

        //Entrada/Salida

        /** @brief Se escriben los elementos de la sala
	    \pre Cierto 
	    \post Se han escrito en el canal estándar de salida los elementos del parámetro implícito de izquierda a derecha y de arriba a bajo
        */

        void escribir_sala() const;



};

#endif
