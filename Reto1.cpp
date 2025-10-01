#include <iostream>
using namespace std;

struct Reto{
	string operacion;
	Reto* siguiente{};
	Reto() {};
};

bool verificar_operacion(string);
void ingresar_letras(Reto*&,string);
void imprimir_operacion(Reto*&);

string operacion;


int main() {
	setlocale(LC_ALL, "spanish");
	
	cout << "Ingrese la operacion: ";
	cin >> operacion;
	Reto* reto1 = nullptr;
	ingresar_letras(reto1, operacion);
	imprimir_operacion(reto1);
	

}


void ingresar_letras(Reto*& pila, string letras) {
	for (int n = 0; n < letras.size(); n++) {
		Reto* nuevo_reto = new Reto;
		nuevo_reto->operacion = letras[n];
		nuevo_reto->siguiente = pila;
		pila = nuevo_reto;
	}
	
	

 }

void imprimir_operacion(Reto*& pila) {
	cout << "La operacion es: ";
	while (pila != nullptr) {		
		cout << pila->operacion << " ";
		Reto* aux = pila;
		pila = pila->siguiente;
		delete aux;
	}
}


bool verificar_operacion(string letras) {
	if () {

	}


	return true;
}