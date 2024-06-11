/*Implemente un sistema de gestión de inventario que maneje diferentes tipos de productos 
(electrónicos, ropa, alimentos, etc.). Utilice el polimorfismo para calcular el valor total del 
inventario, aplicar descuentos y realizar otras operaciones relevantes para cada tipo de producto.*/

#include <iostream>
#include <string>
using namespace std;

class Producto{ //interfaz o clase completamente abstracta
    public:
    virtual int consultar_stock() = 0; //metodos virtualmente puros
    virtual void descuentos() = 0;
    virtual string getnombre() = 0;
    virtual int getprecio() = 0;
    virtual void cambiar_stock(int cantidad) = 0;
    virtual void cambiar_precio(int precio) = 0;
};



class Electrodomestico : public Producto{ //clase derivada "Triangulo"
    public:
    float precio;
    int cantidad;
    string tipo_producto, nombre;
    Electrodomestico(float pre,  int cant, string t_p, string nom) : precio(pre), cantidad(cant), tipo_producto(t_p), nombre(nom) {} //constructor de la clase

    int consultar_stock()override{ //redefinicion de los metodos de la clase base
        return cantidad;
    }
    void descuentos()override{
        cout<<"el descuento en este producto es de 20%"<<endl; //cantidad de descuento
        cout<<"el precio original del producto es: S/."<<precio<<endl;
        cout<<"el precio con descuento del producto es: S/."<<precio-((precio*20)/100)<<endl; //precio - descuento
    }
    string getnombre()override{
        return nombre;
    }
    int getprecio()override{
        return precio;
    }
    void cambiar_stock(int cant) override{
        cantidad = cantidad + cant;
    }
    void cambiar_precio(int prec) override{
        precio = precio + prec;
    }
};

class Ropa : public Producto{ //clase derivada "Ropa"
    public:
    float precio;
    int cantidad;
    string tipo_producto, nombre;
    Ropa(float pre,  int cant, string t_p, string nom) : precio(pre), cantidad(cant), tipo_producto(t_p), nombre(nom) {} //constructor de la clase

    int consultar_stock()override{ 
        return cantidad;
    }
    void descuentos()override{
        cout<<"el descuento en este producto es de 40%"<<endl;
        cout<<"el precio original del producto es: S/."<<precio<<endl;
        cout<<"el precio con descuento del producto es: S/."<<precio-((precio*40)/100)<<endl;
    }
    string getnombre()override{
        return nombre;
    }
    int getprecio()override{
        return precio;
    }
    void cambiar_stock(int cant) override{
        cantidad = cantidad + cant;
    }
    void cambiar_precio(int prec) override{
        precio = precio + prec;
    }
};

class Alimento : public Producto{ //clase derivada "Alimento"
    public:
    float precio;
    int cantidad;
    string tipo_producto, nombre;
    Alimento(float pre,  int cant, string t_p, string nom) : precio(pre), cantidad(cant), tipo_producto(t_p), nombre(nom) {} //constructor de la clase

    int consultar_stock()override{ 
        return cantidad;
    }
    void descuentos()override{ 
        cout<<"el descuento en este producto es de 15%"<<endl;
        cout<<"el precio original del producto es: S/."<<precio<<endl;
        cout<<"el precio con descuento del producto es: S/."<<precio-((precio*15)/100)<<endl;
    }
    string getnombre()override{
        return nombre;
    }
    int getprecio()override{
        return precio;
    }
    void cambiar_stock(int cant) override{
        cantidad = cantidad + cant;
    }
    void cambiar_precio(int prec) override{
        precio = precio + prec;
    }
};


void menu(Producto* prods[], string usr) { //funcion para el menu del sistema
    int opc = 0; //variable para las opciones del menu a elegir
    int i; //variable para elegir cierto elemento del arreglo dinamico de objetos

    do { //menu del sistema
        cout << "Bienvenido al sistema de gestion de inventario! Seleccione la operacion a realizar:" << endl;
        cout << "(1. Consultar stock de un producto)" << endl; //revisar la cantidad de cierto producto
        cout << "(2. Cambiar stock de un producto)" << endl; //cambiar dicha cantidad (aumentar o disminuir)
        cout << "(3. Cambiar precio de un producto)" << endl; 
        cout << "(4. Revisar precio de un producto con descuento incluido)" << endl;
        cout << "(5. Cerrar sesion) -> "; //finalizar el programa
        cin >> opc; //ingresamos la opcion de nuestra eleccion

        if (opc == 1) { //revisar stock
            cout<<"--------------------------"<<endl;
            do{
                cout << "Productos disponibles: Electrodomesticos(0), Ropa(1), Alimentos(2)" << endl;
                cout << "Seleccione el producto que desea revisar el stock: ";
                cin >> i;
            }while(i<0 || i>2); //el programa no admite otros números aparte de 0, 1 y 2
            cout << "El stock del producto " << prods[i]->getnombre() << " es: " << prods[i]->consultar_stock() << endl;
            cout << " " << endl;
        }

        if (opc == 2 && usr == "a") { //si el cliente ingresado es administrador
            int sto;
            cout<<"--------------------------"<<endl;
            do{
                cout << "Productos disponibles: Electrodomesticos(0), Ropa(1), Alimentos(2)" << endl;
                cout << "Seleccione el producto al que desea cambiar el stock: ";
                cin >> i;
            }while(i<0 || i>2);
            do{
                cout << "Ingrese la cantidad (positiva o negativa): "; //añadir-restar stock
                cin >> sto;
            }while((sto + prods[i]->consultar_stock())<0); //mientras la cantidad restada de stock no sea un numero negativo
            prods[i]->cambiar_stock(sto); //envia el valor ingresado a la funcion cambiar_stock
            cout << "Ahora el stock del producto " << prods[i]->getnombre() << " es: " << prods[i]->consultar_stock() << endl;
            cout << " " << endl;
        }
        if (opc == 2 && usr == "u") { //si el cliente es un usuario comun y corriente
            cout<<"--------------------------"<<endl;
            cout<<"Accion no permitida: no eres administrador!"<<endl;
            cout << " " << endl;
        }

        if (opc == 3 && usr == "a") {
            int prec;
            cout<<"--------------------------"<<endl;
            do{
                cout << "Productos disponibles: Electrodomesticos(0), Ropa(1), Alimentos(2)" << endl;
                cout << "Seleccione el producto al que desea cambiar el precio: ";
                cin >> i;
            }while(i<0 || i>2);
            do{
                cout << "Ingrese la cantidad (positiva o negativa): ";
                cin >> prec;
            }while((prec + prods[i]->getprecio())<1); //mientras el precio restado no de como resultado 0 (producto gratis)
            prods[i]->cambiar_precio(prec); //envia el valor ingresado a la funcion cambiar_precio
            cout << "Ahora el precio del producto " << prods[i]->getnombre() << " es: " << prods[i]->getprecio() << endl;
            cout << " " << endl;
        }

        if (opc == 3 && usr == "u") {
            cout<<"--------------------------"<<endl;
            cout<<"Accion no permitida: no eres administrador!"<<endl;
            cout << " " << endl;
        }


        if (opc == 4) { //revisar precio con descuento incluido
            cout<<"--------------------------"<<endl;
            do{
                cout << "Productos disponibles: Electrodomesticos(0), Ropa(1), Alimentos(2)" << endl;
                cout << "Seleccione el producto que desea revisar el precio con descuento:" << endl;
                cin >> i;
            }while(i<0 || i>2);
            prods[i]->descuentos(); //llama a la funcion descuentos
            cout << " " << endl;
        }

    } while (opc != 5); //finalizar programa si se elige "Cerrar sesion", de otro modo el programa se repite siempre
}

int main() {
    string usr = " ";
    Producto* prods[3]; // arreglo de punteros
    prods[0] = new Electrodomestico(150.0, 5, "Electrodomestico", "Microondas"); // objetos de las clases derivadas
    prods[1] = new Ropa(100.0, 9, "Ropa", "Casaca"); //precio, stock, tipo de producto y nombre
    prods[2] = new Alimento(7.0, 15, "Alimento", "BolsadeArroz");

    do {
        cout << "Indique si es administrador (a) o usuario (u): "; //ingresar tipo de usuario
        cin >> usr;
    } while (usr != "a" && usr != "u");

    menu(prods, usr); //llamado a la funcion menu para empezar a ejecutar el programa

    //liberacion de la memoria dinamica
    for (int j = 0; j < 3; j++) {
        delete prods[j];
    }

    return 0;
}
