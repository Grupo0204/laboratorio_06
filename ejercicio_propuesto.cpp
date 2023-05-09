#include <iostream>
#include <math.h>
using namespace std;
class Alumno{
private:
    string nombre;
    int edad;
    float promedio;
    friend bool operator <(const Alumno &alumno1, const Alumno &alumno2);
    friend ostream& operator <<(ostream &o,const Alumno &alumno);
public:
    Alumno(){nombre = " "; edad = 0; promedio = 0.0;}
    Alumno(string nombre, int edad, float promedio){
        this -> nombre=nombre;
        this -> edad = edad;
        this -> promedio = promedio;
    }
    string getNombre(){return nombre;}
    int getEdad(){return edad;}
    float getPromedio(){return promedio;}


};

ostream& operator <<(ostream &o,const Alumno &alumno)
{
    o << "Nombre: "<<alumno.nombre<<endl<<
         "Edad: "<<alumno.edad<<endl<<
         "Promedio: "<<alumno.promedio<<endl;
    return o;
}

bool operator <(const Alumno &alumno1, const Alumno &alumno2)
{
    return alumno1.promedio < alumno2.promedio;
}

class Grupo{
private:
    int cantidad;
    int cant_alumnos;
    Alumno* alumno1;
    friend ostream& operator <<(ostream &o,const Grupo &grupo1);
public:
    Grupo(int cantidad){
        this -> cantidad=cantidad;
        this -> alumno1 = new Alumno[cantidad];
        cant_alumnos = 0;
    }
    ~Grupo(){cout << "Destruyendo objetos" ;delete[]alumno1;}
    void agregarAlumno(Alumno& alumno) {    
        if (cant_alumnos < cantidad) {
            alumno1[cant_alumnos] = alumno;
            cant_alumnos++;
        }
    }
        void ordenarPromedio() {
            for (int i = 0; i < cantidad - 1; i++) {
                for (int j = i + 1; j < cantidad; j++) {
                    if (alumno1[j] < alumno1[i]) {
                        Alumno temp = alumno1[i];
                        alumno1[i] = alumno1[j];
                        alumno1[j] = temp;
                    }
                }
            }
        }
        float promedioGrupo() {
            float sum = 0;
            for (int i = 0; i < cantidad; i++) {
                sum += alumno1[i].getPromedio();
            }
            return sum / cantidad;
        }
        Alumno mejorPromedio() {
            Alumno mejorAlumno("", 0, 0);
            for (int i = 0; i < cantidad; i++) {
                if (alumno1[i].getPromedio() > mejorAlumno.getPromedio()) {
                    mejorAlumno = alumno1[i];
                }
            }
            return mejorAlumno;
        }
};
ostream& operator <<(ostream &o,const Grupo &grupo1)
{
    o << "-----Registro de grupo----" << endl;
    for (int i = 0; i < grupo1.cantidad; i++) {
        o << grupo1.alumno1[i] << endl;
    }
    return o;
}

int main(){
    Grupo grupo(5);
    Alumno* al1 = new Alumno("Juan", 20, 18.5);
    Alumno* al2 = new Alumno("Maria", 21, 13.1);
    Alumno* al3 = new Alumno("Pedro", 19,11.8);
    Alumno* al4 = new Alumno("Luis", 18, 16.5);
    Alumno* al5 = new Alumno("Ana", 22, 9.7);
    grupo.agregarAlumno(*al1);
    grupo.agregarAlumno(*al2);
    grupo.agregarAlumno(*al3);
    grupo.agregarAlumno(*al4);
    grupo.agregarAlumno(*al5);
    grupo.ordenarPromedio();
    cout << grupo<<endl;
    cout << "Promedio de los promedios: " << grupo.promedioGrupo() << endl;
    cout << "Mejor promedio: " << grupo.mejorPromedio() << endl;

}
