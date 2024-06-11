#include <iostream>
using namespace std;
//Clase base Animal
class Animal {
public:
    virtual ~Animal(){} //Destructor virtual
    //Método usando virtual
    virtual void hacerSonido() {
        cout << "Animal esta haciendo un sonido" << endl;
    }
};

//Clase derivada Perro
class Perro : public Animal {
public:
    //Redefinimiento de método de clase base
    void hacerSonido() override{
        cout << "Guau Guau" << endl;
    }
};

int main() {
    //Asignación de objeto Perro a clase Animal
    Animal* miAnimal = new Perro(); //Creación dinámica de objeto Perro
    miAnimal->hacerSonido();  // Enlace temprano: se llama al método de la clase base
    delete miAnimal;    //Eliminación manual de objeto
    return 0;
}
