#include <iostream>
#include <string>
using namespace std;
//Interfaz para mostrar información de empleados
class Interfaz{
public:
    virtual void mostrarInformacion() const = 0; // Método virtual puro
    virtual ~Interfaz() {} // Destructor virtual
};

//Clase Base para empleados
class Empleado : public Interfaz {
    protected:
        string nombre;
        double salarioBase;     //salario base acorde a su rol
        string fechaContratacion;
        static double tarifaHora; // Atributo estático

    public:
        //Constructor de clase base
        Empleado(string nom, double salario, string fecha): 
        nombre(nom), salarioBase(salario), fechaContratacion(fecha){}

        virtual double calcularSalario() const = 0; // Método virtual puro

        //Método estatico para establecer la tarifa por hora
        static void setTarifaHora(double tarifa) {
            tarifaHora = tarifa;
        }

        //Método para mostrar información básica del empleado
        void mostrarInformacion() const override {
            cout << "Nombre: " << nombre << endl;
            cout << "Salario Base: " << salarioBase << endl;
            cout << "Fecha de Contratacion: " << fechaContratacion << endl;
        }
        virtual ~Empleado() {} // Destructor virtual
};

// Inicialización outline del atributo estático
double Empleado::tarifaHora = 0.0;

//Clase derivada Gerente
class Gerente : public Empleado {
    private:
        double bono;    //Adicional a su sueldo
    public:
        //Constructor de clase Gerente
        Gerente(string nom, double salario, string fecha, double b):
        Empleado(nom, salario, fecha), bono(b) {}

        //Sobreescritura de método
        double calcularSalario() const override {
            return salarioBase + bono;
        }

        //Sobreescritura y refinamiento de método
        void mostrarInformacion() const override {  //sobreescritura
            Empleado::mostrarInformacion(); //refinamiento
            cout << "Bono: " << bono << endl;
        }
};

//Clase derivada Desarrollador
class Desarrollador : public Empleado {
    private:
        int horasExtras;    //Hora fuera de horario normal
    public:
        //Constructor de clase Desarrollador
        Desarrollador(string nom, double salario, string fecha, int horas):
        Empleado(nom, salario, fecha), horasExtras(horas) {}

        //Sobreescritura de método
        double calcularSalario() const override {
            return salarioBase + (horasExtras * tarifaHora);
        }
        //Sobreesritura y refinamiento de método
        void mostrarInformacion() const override {  //sobreescritura
            Empleado::mostrarInformacion();     //Refinamiento
            cout << "Horas Extras: " << horasExtras << endl;
            cout << "Tarifa por Hora Extra: " << tarifaHora << endl;
        }
};

//Clase derivada Diseñador
class Disenador : public Empleado {
    private:
        double porcentajeComision;  //ganancia por ventas
        double ventasTotales;   //ventas realizadas en soles

    public:
        //Constructor de Diseñador
        Disenador(string nom, double salario, string fecha, double comision, double ventas):
        Empleado(nom, salario, fecha), porcentajeComision(comision), ventasTotales(ventas) {}

        //Sobreescritura de método
        double calcularSalario() const override {   
            return salarioBase + (ventasTotales * porcentajeComision);
        }

        //Sobreescritura y refinamiento de método
        void mostrarInformacion() const override {  //Sobreescritura
            Empleado::mostrarInformacion();     //Refinamiento
            cout << "Porcentaje de Comision: " << porcentajeComision << endl;
            cout << "Ventas Totales: " << ventasTotales << endl;
        }
};

int main() {
    // Establecer tarifa estática
    double Thora;
    cout<<"Ingrese tarifa en soles de hora: "<<endl;
    cin>>Thora;
    Empleado::setTarifaHora(Thora);
    
    //creación de array de empleados
    int numEmpleados;
    cout<<"Ingrese numero de empleados a ingresar: "<<endl;
    cin>>numEmpleados;
    Empleado* empleados[numEmpleados];

    // Crear diferentes tipos de empleados
    for(int i = 0; i < numEmpleados; i++){
        string nombre, fechaContrato;
        double sueldoBase;
        int opcion;
        cout<<"Tipo de empleado a ingresar (1-Gerente, 2-Desarrollador, 3-Disenador)"<<endl;
        cin>>opcion;
        switch (opcion) {
        case 1: //Ingreso de datos para gerente
            cout<<"Nombre?: "<<endl;
            cin>>nombre;
            cout<<"Fecha de contrato?: "<<endl;
            cin>>fechaContrato;
            cout<<"Sueldo base?: "<<endl;
            cin>>sueldoBase;
            double bono;
            cout<<"Ingrese el bono en soles para nuestro gerente: "<<endl;
            cin>>bono;
            empleados[i] = new Gerente(nombre, sueldoBase, fechaContrato, bono);
            break;
        case 2: //Ingreso de datos para Desarrollador
            cout<<"Nombre?: "<<endl;
            cin>>nombre;
            cout<<"Fecha de contrato?: "<<endl;
            cin>>fechaContrato;
            cout<<"Sueldo base?: "<<endl;
            cin>>sueldoBase;
            int hora;
            cout<<"Ingrese horas extras trabajadas: "<<endl;
            cin>>hora;
            empleados[i] = new Desarrollador(nombre, sueldoBase, fechaContrato, hora);
            break;
        case 3: //  Ingreso de datos para Diseñador
            cout<<"Nombre?: "<<endl;
            cin>>nombre;
            cout<<"Fecha de contrato?: "<<endl;
            cin>>fechaContrato;
            cout<<"Sueldo base?: "<<endl;
            cin>>sueldoBase;
            double comision, venta;
            cout<<"Ingrese comision por ventas: "<<endl;
            cin>>comision;
            cout<<"Ingrese ventas en soles realizadas: "<<endl;
            cin>>venta;
            empleados[i] = new Disenador(nombre, sueldoBase, fechaContrato, comision, venta);
            break;        
        default:
            cout<<"opcion no valida, vuelva a ingresar"<<endl;
            i-=1;
            break;
        }
    }

    // Calcular y mostrar los salarios
    for (int i = 0; i < numEmpleados; ++i) {
        cout << "Informacion del Empleado " << i + 1 <<endl;
        empleados[i]->mostrarInformacion();
        cout << "Salario Calculado: " << empleados[i]->calcularSalario() << endl << endl;
    }

    // Liberar memoria manualmente
    for (int i = 0; i < numEmpleados; ++i) {
        delete empleados[i];
    }
    return 0;
}
