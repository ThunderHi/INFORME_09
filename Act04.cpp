#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout<<"Sonido general"<<endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout<<"El perro ladra" <<endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout<<"El gato maulla"<<endl;
    }
};

class Vaca : public Animal {
public:
    void hacerSonido() override {
        cout<<"La vaca mugula"<<endl;
    }
};

int main() {
    // Arreglo estático de punteros a Animal
    Animal* animales[3];

    // Creación de objetos de diferentes tipos de animales
    animales[0] = new Perro();
    animales[1] = new Gato();
    animales[2] = new Vaca();

    // Recorrido del arreglo y llamada al método hacerSonido()
    for (int i = 0; i < 3; i++) {
        animales[i]->hacerSonido();
    }

    // Liberación de memoria
    for (int i = 0; i < 3; i++) {
        delete animales[i];
    }

    return 0;
}
