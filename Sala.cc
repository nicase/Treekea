#include "Sala.hh"
#include <algorithm>
using namespace std;


//CONSTRUCTORAS

Sala::Sala() {
	//Matrix Estanteria (0,vector<string> 0);
}

Sala::Sala(int f, int c) {
	Matrix Est (f,vector<string> (c,"NULL"));
	Estanteria = Est;
	filas = f;
	columnas = c;
	totalprods = 0;
	
}

//MODIFICADORAS

void Sala::modificar_idsala(int idsala) {
	id_sala = idsala;
}

int Sala::sala_poner_items(string& id, int cantidad) {
	
	if (totalprods == filas*columnas) return cantidad;
	else {
		int aux = cantidad;
		for (int i=filas-1; i >= 0 and cantidad != 0; --i) {
			for (int j=0; j<columnas and cantidad != 0; ++j) {
				if (Estanteria[i][j] == "NULL") {
					Estanteria[i][j] = id;
					cantidad--;
				}
			}
		}

		aux = aux-cantidad;
		totalprods += aux;
		if (existeix_prod_sala(id)) {
			inventariosala[id] += aux;
		}
		else {
			inventariosala.insert(make_pair(id,aux));
		}
	
		return cantidad;
	}
}

int Sala::sala_quitar_items(string& id, int cantidad) {
	
	if (existeix_prod_sala(id)) { //optimitzar
		
		int aux = cantidad;
	
		for (int i=filas-1; i >= 0 and cantidad != 0; --i) {
			for (int j=0; j<columnas and cantidad != 0; ++j) {
				if (Estanteria[i][j] == id) {
					Estanteria[i][j] = "NULL";
					cantidad--;
				}
			}
		}
	
		aux = aux-cantidad;
		totalprods -= aux;
		if (cantidad > 0) {
			map<string,int>::iterator it = inventariosala.find(id);
			inventariosala.erase(it);
		}
		else {
			inventariosala[id] -= aux;
			if (inventariosala[id] == 0) {
				map<string,int>::iterator it = inventariosala.find(id);
				inventariosala.erase(it);
			}
		}
	}
	return cantidad;
}

void Sala::compactar() {
	
	int auxi = filas-1;
	int auxj = 0;
	
	bool fixat = false;
	
	for (int i=filas-1; i >= 0; --i) {
		for (int j=0; j<columnas; ++j) {
			
			if (Estanteria[i][j] == "NULL" and not fixat) {
				auxi = i;
				auxj = j;
				fixat = true;
			}
			else if (Estanteria[i][j] != "NULL" and fixat) {
				Estanteria[auxi][auxj] = Estanteria[i][j];
				Estanteria[i][j] = "NULL";
				if (auxj == columnas-1) {
					auxi--;
					auxj=0;
				}
				else {
					auxj++;
				}
			}
		}
	}
}

void Sala::reorganizar() {
	//falta treure els null (amb compactar i passar fins q trobi un null)
	
	actualizar_totalprods(); //es pot posar al main
	compactar();
	vector<string> ordenar(totalprods);
	int k =0;
	
	for (int i=filas-1; i >= 0 and k<totalprods; --i) {
		for (int j=0; j<columnas and k<totalprods ; ++j) {
			
			ordenar[k] = Estanteria[i][j];
			++k;
		}
	}
	
	sort(ordenar.begin(), ordenar.end());
	k=0;
	
	for (int i=filas-1; k<totalprods; --i) {
		for (int j=0; j<columnas and k<totalprods ; ++j) {
			
			Estanteria[i][j] = ordenar[k];
			++k;
		}
	}
	compactar();
}

void Sala::redimensionar(int f, int c) {
	Matrix aux (f,vector<string> (c,"NULL"));
	int k = f-1;
	int l = 0;
	
	for (int i=filas-1; i>=0; --i) {
		for (int j=0; j<columnas ; ++j) {
			if (Estanteria[i][j] != "NULL") {
				aux[k][l] = Estanteria[i][j];
				++l;
				if (l == c) {
					l = 0;
					--k;
				}
			}
		}
	}
	Estanteria = aux;
	filas = f;
	columnas = c;
}
//CONSULTORAS

string Sala::consultar_pos_sala(int i, int j, bool& b) const {

	if (i <= filas and j <= columnas) {
		b = true;
		return Estanteria[i-1][j-1];
	}
	else {
		b = false;
		return "error";
	}
}

bool Sala::consultar_prod_sala(string& id) const {
	
	for (int i=0; i < filas; ++i) {
		for (int j=0; j < columnas; ++j) {
			
			if (Estanteria[i][j] == id) return true;
		}
	}
	return false;
}



void Sala::actualizar_totalprods() {
	int cont = 0;
	
	for (int i = 0; i<filas; ++i) {
		for (int j=0; j<columnas; ++j) {
			if (Estanteria[i][j] != "NULL") {
				cont++;
			}
		}
	}
	totalprods = cont;
}
				
	
	
int Sala::total_prod() const {
	
	int cont = 0;
	
	for (int i=0; i < filas; ++i) {
		for (int j=0; j < columnas; ++j) { 
			if (Estanteria[i][j] != "NULL") cont++;
		}
	}
	return cont;
}

int Sala::consultar_id(){
	return id_sala;
}


bool Sala::existeix_prod_sala(const string id) const {
	map<string,int>::const_iterator it = inventariosala.find(id);
	if (it != inventariosala.end()) {
		return true;
	}
	else {
		return false;
	}
}

int Sala::consultar_total_items() {
	return totalprods;
}

//ENTRADA/SALIDA

void Sala::escribir_sala() const {
	
	if (filas*columnas == 1) cout << "  " << Estanteria[0][0] << endl;
	else {
	
		for (int i=0; i < filas; ++i) {
			for (int j=0; j < columnas; ++j) { 

				if (j == 0) {
					cout << "  "<< Estanteria[i][j];
					if (j == columnas-1) cout << endl;
				} 
				else if (j == columnas-1) cout << ' ' << Estanteria[i][j] << endl;
				else cout << ' ' << Estanteria[i][j];
			}
		}
	}
	cout << "  " << totalprods << endl;
	
	for (map<string,int>::const_iterator it = inventariosala.begin(); it != inventariosala.end(); ++it) {
		if (it->second != 0) {
			cout <<"  " <<  it->first << ' ' << it->second << endl;
		}
	}
	
}
	
			
	

			
			
	
	

	
	
	
	
	
	
