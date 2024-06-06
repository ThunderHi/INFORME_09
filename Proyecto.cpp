#include <iostream>
#include <string>
using namespace std;

class Interface{
    public:
        virtual void mostrarDatos() const = 0;
};
class Empleado{
    protected:
        string nombre;
        string fechaContratacion;
        string tipoContrato;
        float salario;
        static int precioHora;
    public:
        Empleado(string n, string f, string t):nombre(n), fechaContratacion(f), tipoContrato(t), salario(0){}
        ~Empleado(){}
        virtual void calcularSalario() const = 0;
};
int Empleado:: precioHora = 50;
class Gerente: public Empleado, public Interface{
    protected:
        
};
class Desarrollador: public Empleado, public Interface{};
class Diseñador: public Empleado, public Interface{};
