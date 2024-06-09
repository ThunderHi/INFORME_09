#include <iostream>
#include <string>

using namespace std;

// Clase base Personaje
class Personaje {
public:
    virtual void atacar() = 0;
    virtual void defender() = 0;
    virtual void usarHabilidadEspecial() = 0;
};

// Clase derivada Guerrero
class Guerrero : public Personaje {
public:
    void atacar() override {
        cout<<"El guerrero ataca con su espada."<<endl;
    }

    void defender() override {
        cout<<"El guerrero defiende con su escudo."<<endl;
    }

    void usarHabilidadEspecial() override {
        cout<<"El guerrero usa su habilidad especial: 'Furia de berserker'."<<endl;
    }
};

// Clase derivada Mago
class Mago : public Personaje {
public:
    void atacar() override {
        cout<<"El mago ataca con su hechizo."<<endl;
    }

    void defender() override {
        cout<<"El mago defiende con su escudo magico."<<endl;
    }

    void usarHabilidadEspecial() override {
        cout<<"El mago usa su habilidad especial: 'Lluvia estrellada de meteoros'."<<endl;
    }
};

// Clase derivada Arquero
class Arquero : public Personaje {
public:
    void atacar() override {
        cout<<"El arquero ataca con su arco."<<endl;
    }

    void defender() override {
        cout<<"El arquero defiende con su escudo."<<endl;
    }

    void usarHabilidadEspecial() override {
        cout<<"El arquero usa su habilidad especial: 'Flecha magica de Apolo'."<<endl;
    }
};

// Clase principal para jugar el juego
int main() {
    // Creamos un array de punteros a Personaje
    Personaje* personajes[3];

    // Agregamos diferentes personajes
    personajes[0] = new Guerrero();
    personajes[1] = new Mago();
    personajes[2] = new Arquero();

    // Simulamos las acciones comunes
    for (int i = 0; i < 3; i++) {
        personajes[i]->atacar();
        personajes[i]->defender();
        personajes[i]->usarHabilidadEspecial();
    }

    // Liberar la memoria dinámica
    for (int i = 0; i < 3; i++) {
        delete personajes[i];
    }

    return 0;
}
