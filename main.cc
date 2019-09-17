	/**
 *  @mainpage Práctica: Treekea
    
    En esta practica se construye un programa modular que ofrece un menu de opciones para
    gestionar una tienda llamada Treekea. Lo he planteado creando tres clases llamadas Almacén,
    Sistema y Sala.
 
 */

/** @file main.cc
    @brief Programa principal para el ejercicio <em>Gestión de un Treekea</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Almacen.hh"
#include "Sistema.hh"

/** @brief Programa principal para el ejercicio <em>Gestión de un Treekea</em>.
*/

int main ()
{
    Sistema S;
    bool b;
    int n;
    cin >> n;
    Almacen A(n);
    A.leer(); 
    string funcion = "";
    while (funcion != "fin" ) {
			cin >> funcion;
		if (funcion == "poner_prod") {
	  string prod;
	  cin >> prod;
	  cout << funcion << ' ' << prod << endl;
	  b = S.existeix_prod(prod);
	  if (not b) {
		  S.poner_prod(prod);
	  }
	  else cout << "  error" << endl;
	}
	else if (funcion == "quitar_prod") {
	  string prod;
	  cin >> prod;
	  cout << funcion << ' ' << prod << endl;
	  b = S.existeix_prod(prod);
	  if (not b) cout << "  error" << endl;
	  else {
		  S.quitar_prod(prod,b);
		  if (not b) cout << "  error" << endl;
	  }
	}
	else if (funcion == "poner_items") {
	  int n, cant;
	  string prod;
	  cin >> n >> prod >> cant;
	  b = S.existeix_prod(prod);
	  cout << funcion << ' ' << n << ' ' << prod << ' ' << cant << endl;
		if (not b) cout << "  error" << endl;
	  else {
		int aux = A.poner_items(n,prod,cant);
		cant = cant-aux;
		S.aumentar_prod(prod,cant);
		cout << "  "<< aux << endl;
		}
	}
	else if (funcion == "quitar_items") {
	  int n, cant;
	  string prod;
	  cin >> n >> prod >> cant;
	  b = S.existeix_prod(prod);
	  cout << funcion << ' ' << n << ' ' << prod << ' ' << cant << endl;
	  if (not b) cout << "  error" << endl;
	  else {
		int aux = A.quitar_items(n,prod,cant);
		cant = cant-aux;
		S.disminuir_prod(prod,cant);
		cout << "  " << aux << endl;
		}
	}
	//REVISAR
	else if ( funcion == "distribuir" ) {
	  string prod;
	  int cant;
	  cin >> prod >> cant;
	  cout << funcion << ' ' << prod << ' ' << cant << endl;
	  b = S.existeix_prod(prod);
	  if (not b) cout << "  error" << endl;
	  else {
		int aux = A.Distribuir(prod,cant);
		cant = cant - aux;
		S.aumentar_prod(prod,cant);
		cout << "  " << aux << endl;
		}
	}
	else if (funcion == "compactar" ) {
	  int sala;
	  cin >> sala;
	  cout << funcion << ' ' << sala << endl;
	  A.Compactar(sala);
	}
	else if (funcion == "reorganizar" ) {
	  int sala;
	  cin >> sala;
	  cout << funcion << ' ' << sala << endl;
	  A.Reorganizar(sala);
	}
	else if (funcion == "redimensionar" ) {
	  int sala, f, c;
	  cin >> sala >> f >> c;
	  cout << funcion << ' ' << sala <<' ' << f << ' ' << c << endl;
	  A.Redimensionar(sala,f,c,b);
		if (not b) cout << "  error" << endl;
	}
	else if (funcion == "inventario" ) {
		cout << funcion << endl;
	  S.escribir_inventario();
	}
	else if (funcion == "escribir" ) {
	  int sala;
	  cin >> sala;
		cout << funcion << ' ' << sala << endl;
	  A.escribir(sala);
	}
	else if (funcion == "consultar_prod" ) {
	  string prod;
	  int aux;
	  cin >> prod;
	  cout << funcion << ' ' << prod << endl;
	  b = S.existeix_prod(prod);
	  if (not b) cout << "  error" << endl;
	  else {
		  aux = S.consultar_prod(prod);
		  cout <<"  " <<  aux << endl;
	  }
	}
	else if (funcion == "consultar_pos" ) {
	  int sala, f, c;
	  cin >> sala >> f >> c;
	  cout << funcion << ' ' << sala << ' ' << f << ' ' << c << endl;
	  string prod = A.consultar_pos(sala,f,c,b);
		if (b) {
			cout << "  " << prod << endl;
		}
		else {
			cout << "  error"<< endl;
		}
}
		}

		cout << "fin" << endl;
}
