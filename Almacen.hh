/** @file Almacen.hh
    @brief Especificación de la clase Almacen
*/

#ifndef _ALMACEN_
#define _ALMACEN_

#include "Sala.hh"

#ifndef NO_DIAGRAM          // esto hace que el Doxyfile de la sesión no 
#include <iostream>         // incluya estas clases en los diagramas modulares, 
#include "BinTree.hh"       // mientras que el compilador de c++ 
#endif                

class Almacen {
	
	private:
	
		int numsales;
	
		/** @brief Estructura del almacen
		*/
		BinTree<int> arbreids;
		
		/** @brief Vecor de salas donde trabajaremos
		*/
		vector<Sala> sales;
		
		void leer_vector();
		
		void leer_arbol(BinTree<int>& a);
		
		
    public:

        //Constructoras

        /** @brief Constructora por defecto
	    \pre Cierto
	    \post Se ha creado un almacén con 0 salas
        */

        Almacen();

        /** @brief Constructora con un parámetro concreto
	    \pre  Cierto
	    \post Se ha creado un almacén con n salas
        */

        Almacen(int n);

        //Modificadoras

        
       /** @brief Añade elementos a la sala
	    \pre El parámetro implícito contiene la sala s
	    \post El parámetro booleano b indica si el producto existe en la sala. Si b=false, se produce un error. Si b=true se han incrementado 
            en "cantidad" unidades los items del producto con identificador "id". Si la sala se llena y aún no se ha incrementado el producto todo lo 
            que se queria incrementar, se devuelve la cantidad que no se ha podido incrementar
        */

        int poner_items(int s, string id, int cantidad);

        
        /** @brief Elimina elementos de la sala
	    \pre El parámetro implícito contiene la sala s
	    \post El parámetro booleano b indica si el producto existe en la sala. Si b=false, se produce un error. Si b=true se han decrementado 
            en "cantidad" unidades los items del producto con identificador "id". Si  el producto llega a 0 unidades y no se han quitado los que se querian
            quitar, se retorna la cantidad que no se ha podido quitar
        */

        int quitar_items(int s, string& id, int cantidad);

        /** @brief Distibuye elementos en el almacén
	    \pre El parámetro implícito no está vacío
	    \post El parámetro booleano b indica si el producto con identicicación 'id' existe en el sistema.
            si b es falso, no existe el producto y se produce un error. Si b es cierto entonces se distribuyen
            'cantidad' elementos del producto con identificación 'id' por el almacén. Se empieza por llenar la sala
            incicial. Si aún quedan elementos por distribuir, se distribuirá la mitad por la izquierda y la mitad por
            la derecha. Si el número de elementos que queda por distribuir es impar, l unidad sobrante se distribuye a la
            izquierda
        */

        int Distribuir(string id, int cantidad);
        
        int distribuir_i(BinTree<int> a, vector<Sala>& salas, string id_prod, int cantidad);

        /** @brief Se compactan los elementos de la sala s
	    \pre Existe una sala s que pertenece al almacén
	    \post Se ha compactado la sala s, de manera que ya no hay huecos entre los productos de esa sala
        */
        

        void Compactar(int s);

        /** @brief Se reorganiza la sala s
	    \pre Existe una sala s que pertenece al almacén
	    \post Se ha ordenado alfabéticamente la sala s y se ha compactado, de manera que no quedan huecos entre productos
        */

        void Reorganizar(int s);

        /** @brief Se redimensiona la sala s
	    \pre Existe una sala s que pertenece al almacén
	    \post Se ha redimensionado la estanteria de la sala 's', de manera que ahora tiene c columnas y f filas
        */

        void Redimensionar(int s, int f, int c, bool& b);

        //Consultoras

        /** @brief Consulta un elemento
	    \pre Existe una sala s que pertenece al almacén
	    \post La función ha retornado el elemento de la sala s, fila i y columna j
        */

        string consultar_pos(int s, int i, int j, bool& b) const;
        
        
        /** @brief Consulta si existe la sala s en el almacén
			\pre Cierto
			\post Retorna true si la sala está en el almacén y false si no lo está 
        */
        bool consultar_sala(int s); 
        
        /** @brief Compara dos posicions
			\pre Cierto
			\post Retorna true si la posición [x1,y1] es anterior a [x2,y2] y false si no lo es
        */
        
        bool comp_posicion(int const x1, int const y1, int const x2, int const y2) const; 

        //Entrada/Salida
        
        /** @brief Escribe los elementos de una sala
	    \pre Existe una sala s que pertenece al almacén
	    \post  Se han escrito en el canal estándar de salida los elementos del parámetro implícito de izquierda a derecha y de arriba a bajo
            de la sala s
        */

        void escribir(int s);
        
        /** @brief Operación de lectura
	    \pre N > 0, el canal estandar de entrada contiene los datos del alamcen de N salas
	    \post EL parámetro implícito está formado por las N salas procedentes del canal estándard de entrada
        */

        void leer();
};

#endif
