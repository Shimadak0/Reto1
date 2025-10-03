#include <iostream>
using namespace std;



/*Reto:
Verificar si una operacion, por ejemplo (3+4)*{8+(3+2)}, esta equilibrada
*/



struct Reto{
	string operacion;
	Reto* siguiente;
};

bool verificar_operacion(Reto*&, Reto*&);
void ingresar_finales(Reto*&, string);
void ingresar_inicios(Reto*&,string);
void imprimir_operacion(Reto*&);

string operacion;
char opcion;


int main() {
	setlocale(LC_ALL, "spanish");

	inicio:
	cout << "Ingrese la operacion: ";
	cin >> operacion;
	cout << endl;
	Reto* reto1 = nullptr;
	Reto* reto2 = nullptr;
	ingresar_inicios(reto1, operacion);
	ingresar_finales(reto2, operacion);
	bool verificar = verificar_operacion(reto1, reto2);


	if (verificar != true) {
		cout << "La operacion no esta balanceada." << endl;
	}
	else {
		cout << "La operacion esta balanceada." << endl;
	}

	cout << "Quieres intentar otra operacion? S/N ";
	cin >> opcion;
	cout << endl;
	
	if (opcion == 'S' || opcion == 's') {
		goto inicio;
	}
	
}


void ingresar_inicios(Reto*& pila, string letras) {
	for (int n = 0; n < letras.size(); n++) {
		if (letras[n] == '(' || letras[n] == '{' || letras[n] == '[') {
			Reto* nuevo_reto = new Reto;
			nuevo_reto->operacion = letras[n];
			nuevo_reto->siguiente = pila;
			pila = nuevo_reto;

		}
	}
 }


void ingresar_finales(Reto*& pila, string letras) {

	for (int n = 0; n < letras.size(); n++) {
		if (letras[n] == ')' || letras[n] == '}' || letras[n] == ']') {
			Reto* nuevo_reto = new Reto;
			nuevo_reto->operacion = letras[n];
			nuevo_reto->siguiente = pila;
			pila = nuevo_reto;

		}
	}

}

void imprimir_operacion(Reto*& pila){
	while (pila != nullptr) {
		cout << "Las cosas son: ";
		cout << pila->operacion << endl;
		Reto* aux = pila;
		pila = pila->siguiente;
		delete aux;
	}

}

bool verificar_operacion(Reto*& pila1, Reto*& pila2) {

	int n = 0;
	int m = 0;
	while (pila1 != nullptr) {	
		pila1->operacion;
		Reto* aux = pila1;
		pila1 = pila1->siguiente;
		delete aux;
		n++;
	}
	while (pila2 != nullptr) {
		pila2->operacion;
		Reto* aux = pila2;
		pila2 = pila2->siguiente;
		delete aux;
		m++;
	}


	if (n != m) {

		return false;

	}
	else
	{
		return true;
	}


	
}