#include <iostream>
using namespace std;

//Clase base Empleado
class Empleado {
    protected:
        string nombre;
    public:
        //Constructor Empleado
        Empleado(string n):nombre(n){}
        virtual double calcularSalario() const = 0; // Método virtual puro
        void datoEmpleado(){
            cout<<"Nombre de empleado: "<<nombre<<endl;
        }
        virtual ~Empleado() {} // Destructor virtual
};

//Clase derivada EmpleadoAsalariado
class EmpleadoAsalariado : public Empleado {
    private:
        double salarioMensual;
    public:
        //Constructor de EmpleadoAsalariado
        EmpleadoAsalariado(string n, double s) : Empleado(n), salarioMensual(s) {}
        //Sobreescritura de método
        double calcularSalario() const override {
            return salarioMensual;
        }
};

// Clase derivada EmpleadoPorHora
class EmpleadoPorHora : public Empleado {
    private:
        double tarifaPorHora;
        int horasTrabajadas;
    public:
        // Constructor de EmpleadoPorHora
        EmpleadoPorHora(string n, double tarifa, int horas) : Empleado(n),tarifaPorHora(tarifa), horasTrabajadas(horas) {}
        //Sobreescritura de método
        double calcularSalario() const override {
            return tarifaPorHora * horasTrabajadas;
        }
};

// Clase derivada EmpleadoComisionista
class EmpleadoComisionista : public Empleado {
    private:
        double ventas;
        double tasaComision;
    public:
        //Constructor de EmpleadoComisionista
        EmpleadoComisionista(string n, double vent, double tasa):Empleado(n),ventas(vent),tasaComision(tasa) {}
        //Sobreescritura de método
        double calcularSalario() const override {
            return ventas * tasaComision;
        }
};

int main() {
    int numEmpleados;
    cout<<"Ingrese numero de empleados: "<<endl;
    cin>>numEmpleados;

    //Creación de array de empleados
    Empleado* empleados[numEmpleados];

    // Crear diferentes tipos de empleados
    for (int i = 0; i < numEmpleados; i++){
        //Variables para opcion y nombre de empleado
        int opc;
        string nombre;
        cout<<"Ingrese el tipo de empleado (1-Asalariado, 2-PorHora, 3-Comisionista)"<<endl;
        cin>>opc;
        cout<<"Ingrese nombre de empleado"<<endl;
        cin>>nombre;
        switch (opc){   //Condicional para crear objetos
        case 1:
            //Asignando datos para Empleado Asalariado
            double salario;
            cout<<"Ingrese sueldo: "<<endl;
            cin>>salario;
            empleados[i] = new EmpleadoAsalariado(nombre, salario);
            break;
        
        case 2:
            //Asignando datos para Empleado Por hora
            double tarif;
            int hora;
            cout<<"Ingrese tarifa en soles por hora: "<<endl;
            cin>>tarif;
            cout<<"Ingrese horas trabajadas: "<<endl;
            cin>>hora;
            empleados[i] = new EmpleadoPorHora(nombre, tarif, hora);
            break;

        case 3:
            //Asignando datos para Empleado Comisionista
            double venta, tas;
            cout<<"Ingrese cantidad de ventas: "<<endl;
            cin>>venta;
            cout<<"Ingrese tasa en soles por venta: "<<endl;
            cin>>tas;
            empleados[i] = new EmpleadoComisionista(nombre,venta, tas);
            break;

        default:
            cout<<"Opción incorrecta..."<<endl;
        }
    }
    
    // Calcular y mostrar los salarios
    cout<<"Mostrando datos de empleados:"<<endl;
    for (int i = 0; i < numEmpleados; ++i) {
        empleados[i]->datoEmpleado();
        cout<<"Salario: S/. "<<empleados[i]->calcularSalario()<<endl;
        cout<<endl;
    }

    // Liberar memoria
    for (int i = 0; i < numEmpleados; ++i) {
        delete empleados[i];
    }
    return 0;
}
