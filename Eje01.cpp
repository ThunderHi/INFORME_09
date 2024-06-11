#include <iostream>
using namespace std;

// Clase base Figura
class Figura {
public:
    virtual double calcularArea()= 0; // Metodo virtual puro calcular el area
    virtual double calcularperimetro()= 0; // Metodo virtual puro para calcular el perimetro
    virtual void mostrarinfo()= 0; // Metodo virtual puro para mostrar informacion
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
    // Crear objetos de diferentes tipos de figuras e incluirlos al arreglo dinamico figuras
    Figura* figuras[3];      //Arreglo de punteros
    figuras[0]=new Circulo(5.0);
    figuras[1]=new Rectangulo(4.0,6.0);
    figuras[2]=new Triangulo(4.0,3.0);

    // Recorrer el arreglo y llamar a calcularArea() para cada objeto
    for (int i = 0; i < 3; ++i) {
        figuras[i]->mostrarinfo(); //El operador -> se utiliza porque figuras[i] es un puntero
    }

    // Liberar memoria
    for (int i = 0; i < 3; ++i) {
        delete figuras[i];
    }
    return 0;
}
