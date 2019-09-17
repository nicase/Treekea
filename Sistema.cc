#include "Sistema.hh"
#include <map>
using namespace std;

//CONSTRUCTORAS

Sistema::Sistema() {
}

//MODIFICADORAS

void Sistema::poner_prod(string id) {
	
	
	inventario.insert(make_pair(id,0));
}

void Sistema::quitar_prod(string id, bool& b) {
	
	/*map<string,int>::iterator it = inventario.find(id);
	if (it != inventario.end()) {
		if (it->second == 0) {
			b = true;
			inventario.erase(id);
		}
	}
}*/
	map<string,int>::iterator it = inventario.find(id);
	if (it->second == 0) {
		b = true;
		inventario.erase(id);
	}
	else b = false;
}

void Sistema::aumentar_prod(string id, int n) {
	inventario[id] += n;
}

void Sistema::disminuir_prod(string id, int n) {
	inventario[id] -= n;
}

//CONSULTORAS

int Sistema::consultar_prod(const string id) const {
	map<string,int>::const_iterator it = inventario.find(id);
		return it->second;
}

bool Sistema::existeix_prod(const string id) const {
	map<string,int>::const_iterator it = inventario.find(id);
	if (it != inventario.end()) {
		return true;
	}
	else {
		return false;
	}
}

void Sistema::escribir_inventario() {
	
	for (map<string,int>::iterator it = inventario.begin(); it != inventario.end(); ++it) {
		cout <<"  " <<  it->first << ' ' << it->second << endl;
	}
}
	
	
	
	
	
	
	
	
	

		
