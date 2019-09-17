#include "Almacen.hh"
#include <cassert>
using namespace std;

//CONSTRUCTORAS

/*Almacen::Almacen() {
	
	BinTree<int> a;
	vector<Sala> sales(0);
	Alm = sales;
	numsales = 0;
}*/

Almacen::Almacen(int n) {
	
	BinTree <int> a;
	vector<Sala> b(n);
	sales = b;
	numsales = n;
}
void Almacen::leer_vector() {
	int files,columnes;
	for (int i=0; i<numsales; ++i) {
		cin >> files >> columnes;
		Sala aux(files,columnes);
		sales[i] = aux;
	}
}
		
void Almacen::leer_arbol(BinTree<int>& a) {
  int x;
  cin >> x;
  if (x!=0){
	BinTree<int> l;
	leer_arbol(l);
	BinTree<int> r;
	leer_arbol(r);
	a=BinTree<int>(x,l,r);
  }
}


//MODIFICADORAS

int Almacen::poner_items(int s, string id, int cantidad) {
		return sales[s-1].sala_poner_items(id, cantidad);
}

int Almacen::quitar_items(int s, string& id, int cantidad) {
	return sales[s-1].sala_quitar_items(id, cantidad);
}


int Almacen::Distribuir(string id, int cantidad){
	return distribuir_i(arbreids, sales, id, cantidad);
}

int Almacen::distribuir_i(BinTree<int> a, vector<Sala>& salas, string id_prod, int cantidad) {
	if(a.empty() ) return cantidad;
	else{
		int i = a.value();
		int aux;
		aux = sales[i-1].sala_poner_items(id_prod, cantidad);
		if (aux > 0) {
			BinTree<int> a1 = a.left();
			BinTree<int> a2 = a.right();
			int guardaraux = aux;
			if(aux%2==0) {
				aux = distribuir_i(a1, sales, id_prod, aux/2);
				aux += distribuir_i(a2, sales, id_prod, guardaraux/2);
			}
			else {
				aux = distribuir_i(a1, salas, id_prod, (aux/2) +1);
				aux += distribuir_i(a2, salas, id_prod, guardaraux/2);
			}
		}
		return aux;
	}
}

void Almacen::Compactar(int s) {
	sales[s-1].compactar();
}

void Almacen::Reorganizar(int s) {
	sales[s-1].reorganizar();
}

void Almacen::Redimensionar(int s, int f, int c, bool& b) {
	if (f*c < sales[s-1].consultar_total_items()) b = false;
	else {
		b = true;
		sales[s-1].redimensionar(f,c);
	}
}

//CONSULTORAS

string Almacen::consultar_pos(int s, int i, int j, bool& b) const {

	return sales[s-1].consultar_pos_sala(i,j,b);

}


bool Almacen::consultar_sala(int s) {
	
	for (int i=1; i <= numsales; ++i) {
		if (sales[i-1].consultar_id() == s) return true;
	}
	return false;
}

bool Almacen::comp_posicion(int const x1, int const y1, int const x2, int const y2) const{
	if (x1 > x2) return true;
	else if (x1 == x2) {
		if (y1 > y2) return true;
	}
	return false;
}

//ENTRADA/SALIDA

void Almacen::escribir(int s) {
	sales[s-1].escribir_sala();
}

void Almacen::leer() {
	leer_arbol(arbreids);
	leer_vector();
}
	
	

	



	

	
	










