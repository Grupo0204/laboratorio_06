#include <iostream>
#include <string>
using namespace std;
class VentaAutos
{
    private:
        float precio;
    protected:
        string nombre_del_dueno;
    public:
        string descripcion;
        VentaAutos(string descripcion, string nombre_del_dueno, float precio)
        {
            this->descripcion=descripcion;
            this->nombre_del_dueno=nombre_del_dueno;
            this->precio=precio;
        }
        string getNombre()
        {
            return nombre_del_dueno;
        }
        friend class Vendedor;


};
class Vendedor
{
    public:
        void modificarNombre(VentaAutos &auto1, string nuevo_nombre)
        {
            auto1.nombre_del_dueno=nuevo_nombre;
        }
};
int main()
{
    VentaAutos auto1("Auto de colos azul con 4 puertas","Juan",1200.50);
    cout<<"Nombre del dueno: "<<auto1.getNombre()<<endl;
    Vendedor vendedor1;
    vendedor1.modificarNombre(auto1,"Pedro");
    cout<<"Nombre del dueno modificado 1: "<<auto1.getNombre()<<endl;
    vendedor1.modificarNombre(auto1,"Ramiro");
    cout<<"Nombre del dueno modificado 2: "<<auto1.getNombre()<<endl;
    vendedor1.modificarNombre(auto1,"Julio");
    cout<<"Nombre del dueno modificado 3: "<<auto1.getNombre()<<endl;
}