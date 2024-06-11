//Polimorfismo de Subtipo (Herencia)
#include <iostream>
using namespace std;
//
// Clase base Figura
class Figura {
public:
    virtual double calcularArea() = 0; // Metodo virtual puro calcularArea
    virtual ~Figura() {} // Destructor virtual
};
// Clase derivada Circulo
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    double calcularArea() override {
        return 3.1416*radio*radio;
    }
};

// Clase derivada Rectangulo
class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double b) : ancho(a), alto(b) {}
    double calcularArea() override {
        return ancho * alto;
    }
};

// Clase derivada Triangulo
class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double calcularArea() override {
        return 0.5 * base * altura;
    }
};

int main() {
    // Crear objetos de diferentes tipos de figuras e incluirlos al arreglo dinamico figuras
    Figura* figuras[3];      //Arreglo de punteros
    figuras[0]=new Circulo(5.0);
    figuras[1]=new Rectangulo(4.0,6.0);
    figuras[2]=new Triangulo(4.0,3.0);

    // Recorrer el arreglo y llamar a calcularArea() para cada objeto
    for (int i = 0; i < 3; ++i) {
        cout <<"El área de la figura es: "<<figuras[i]->calcularArea()<<endl; //El operador -> se utiliza porque figuras[i] es un puntero
    }

    // Liberar memoria
    for (int i = 0; i < 3; ++i) {
        delete figuras[i];
    }
    return 0;
}
