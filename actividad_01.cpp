#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Estudiante
{
    private:
        string nombre;
        string direccion;
        int DNI;
        float nota;
    public:
        string getNombre()
        {
            return nombre;
        }
        string getDireccion()
        {
            return direccion;
        }
        float getNota()
        {
            return nota;
        }
        Estudiante(string nombre, string direccion, int DNI, float nota)
        {
            this->nombre=nombre;
            this->direccion=direccion;
            this->DNI=DNI;
            this->nota=nota;
        }
};
int main()
{
    vector<Estudiante> estudiantes;
    estudiantes.push_back(Estudiante("Juan","AV.Flores",943750134,14.5));
    estudiantes.push_back(Estudiante("Pedro","AV.MiraFlores",97964954,11.6));
    estudiantes.push_back(Estudiante("Julio","AV.SanJuan",908625374,17.3));
    // Ordena estdiantes por nota de manera descendente
    sort(estudiantes.begin(),estudiantes.end(),
        [](Estudiante a,Estudiante b){return a.getNota() > b.getNota();});
    // Imprime el vector
    cout<<"Imprime el vector:"<<endl;
    for(Estudiante e: estudiantes)
    {
        cout<<e.getNombre()<<" - "<<e.getNota()<<endl;
    }
    // Imprime estudiantes con promedio mayor a 12
    cout<<"Imprime estudiantes con promedio mayor a 12:"<<endl;
    for(Estudiante e: estudiantes)
    {
        if(e.getNota()>=12)
        {
            cout<<e.getNombre()<<" - "<<e.getNota()<<endl;
        }
    }
    return 0;
}
