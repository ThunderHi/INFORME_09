#include <iostream>
using namespace std;

// Clase base Figura
class Figura {
public:
    virtual double calcularArea()= 0; // Metodo virtual puro calcular el area
    virtual double calcularperimetro()= 0; // Metodo virtual puro para calcular el perimetro
    virtual void mostrarinfo()= 0; // Metodo virtual puro para mostrar informacion
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

    double calcularperimetro() override{
        return 3.1416*2*radio;
    }

    void mostrarinfo() override {
        cout<<"Circulo: Radio = "<<radio<<", Area = "<<calcularArea()<<", Perimetro = "<<calcularperimetro()<<endl;
    }
};

// Clase derivada Rectangulo
class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(int a, int b) : ancho(a),alto(b) {}
    double calcularArea() override {
        return ancho*alto;
    }

    double calcularperimetro() override{
        return 2*(ancho+alto);
    }

    void mostrarinfo() override {
        cout<<"Rectangulo: Ancho = "<<ancho<<", Alto = "<<alto<<", Area = "<< calcularArea()<<", Perimetro = "<<calcularperimetro()<<endl;
    }
};

// Clase derivada Triangulo
class Triangulo : public Figura {
private:
    int base, altura;
public:
    Triangulo(int b, int h) : base(b),altura(h) {}
    double calcularArea() override {
        return 0.5*base*altura;
    }

    double calcularperimetro() override {
        // Perimetro de un triángulo equilatero para simplificar
        return 3*base;
    }
    void mostrarinfo() override {
        cout<<"Triangulo: Base = "<<base<<", Altura = "<<altura<<", Area = "<<calcularArea()<<", Perimetro = "<<calcularperimetro()<<endl;
    }
};

int main() {

    Circulo circulo(5.0);
    circulo.mostrarinfo();

    Rectangulo rectangulo(4,6);
    rectangulo.mostrarinfo();

    Triangulo triangulo(4,3);
    triangulo.mostrarinfo();

    return 0;
}
