//Polimorfismo de sobrecarga

#include <iostream>
using namespace std;

class Calculadora { //Se sobrecarga el metodo sumar
public:
    // Metodo para sumar dos enteros
    int sumar(int a, int b) {
        return a + b;
    }

    // Metodo para sumar dos numeros de tipo double
    double sumar(double a, double b) {
        return a + b;
    }

    // Metodo para sumar tres enteros
    int sumar(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculadora calculadora;

    // Mostrar resultados
    cout<<"Suma de enteros (3+4): "<<calculadora.sumar(3,4)<<endl;
    cout<<"Suma de dos doubles (3.5+2.1): "<<calculadora.sumar(3.5,2.1)<<endl;
    cout<<"Suma de tres enteros (1+2+3): "<<calculadora.sumar(1,2,3)<<endl;

    return 0;
}
