#include <iostream>
#include <string>

using namespace std;

// Clase base Animal
class Animal {
public:
    virtual void comer() {
        cout<<"El animal come."<<endl;
    }

    virtual void dormir() {
        cout<<"El animal duerme."<<endl;
    }

    virtual void moverse() {
        cout<<"El animal se mueve."<<endl;
    }
};

// Clase derivada Mamífero
class Mamifero : public Animal {
public:
    void comer() override {
        cout<<"El mamifero come hierba y frutas."<<endl;
    }

    void dormir() override {
        cout<<"El mamifero duerme en un lugar seco."<<endl;
    }
};

// Clase derivada Ave
class Ave : public Animal {
public:
    void comer() override {
        cout<<"La ave come insectos y semillas."<<endl;
    }

    void dormir() override {
        cout<<"La ave duerme en un nido."<<endl;
    }
};

// Clase derivada Reptil
class Reptil : public Animal {
public:
    void comer() override {
        cout<<"El reptil come carne y huevos."<<endl;
    }

    void dormir() override {
        cout<<"El reptil duerme en un lugar caluroso."<<endl;
    }
};

// Clase principal para simular animales
int main() {
    // Creamos un array de punteros a Animal
    Animal* animales[3];

    // Agregamos diferentes especies de animales
    animales[0] = new Mamifero();
    animales[1] = new Ave();
    animales[2] = new Reptil();

    // Simulamos los comportamientos comunes
    for (int i = 0; i < 3; i++) {
        animales[i]->comer();
        animales[i]->dormir();
        animales[i]->moverse();
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < 3; i++) {
        delete animales[i];
    }

    return 0;
}
