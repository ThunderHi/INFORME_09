/* Cree una clase abstracta FiguraGeometrica con métodos virtuales puros para calcular el
área y el perímetro.
▪ Cree clases derivadas de FiguraGeometrica, como Circulo, Rectangulo y
Triangulo, que implementen los métodos abstractos.
▪ En la función main, cree objetos de diferentes tipos de figuras geométricas y almacénelos
en un arreglo de punteros a FiguraGeometrica.
▪ Recorra el arreglo y llame a los métodos calcularArea() y calcularPerimetro() para
cada objeto. Observe cómo se ejecuta la implementación correcta de los métodos en función
del tipo real del objeto en tiempo de ejecución. */

#include <iostream>
#include <string>
using namespace std;

class FiguraGeometrica{ //interfaz o clase completamente abstracta
    public:
    virtual double calcularPerimetro() = 0; //metodos virtualmente puros
    virtual double calcularArea() = 0;
};

class Triangulo : public FiguraGeometrica{ //clase derivada "Triangulo"
    public:
    int base, altura, lado;
    Triangulo(int b, int h, int l) : base(b), altura(h), lado(l){} //constructor de la clase

    double calcularPerimetro()override{ //redefinicion del metodo de la clase base
        return lado*3;
    }
    double calcularArea()override{ //redefinicion del metodo de la clase base
        return (base*altura)/2;
    }
};

class Circulo : public FiguraGeometrica{
    public:
    int radio;
    Circulo(int r) : radio(r){}

    double calcularPerimetro()override{
        return radio*3.14*2;
    }
    double calcularArea()override{
        return 3.14*radio*radio;
    }
};

class Cuadrado : public FiguraGeometrica{
    public:
    int lado;
    Cuadrado(int l) : lado(l){}

    double calcularPerimetro()override{
        return lado*4;
    }
    double calcularArea()override{
        return lado*lado;
    }
};

int main(){
    FiguraGeometrica *figs[3]; //arreglo de punteros
    figs[0] = new Triangulo (3, 3, 3); //objetos de las clases derivadas
    figs[1] = new Cuadrado (5);
    figs[2] = new Circulo (7);

    for(int i = 0; i<3; i++){ //recorriendo el arreglo
        cout<<"el perimetro de la forma " << i+1 << " es: "<<figs[i]->calcularPerimetro()<<endl;
        cout<<"el area de la forma " << i+1 << " es: "<<figs[i]->calcularArea()<<endl;
    }

    return 0;
}
