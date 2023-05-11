#include <iostream>
using namespace std;

class Alumno{
private:
    string nombre;
    string direccion;
public:
    int nota_final;

    Alumno(string nombre,string direccion,int nota_final){
        this ->nombre=nombre;
        this->direccion=direccion;
        this ->nota_final=nota_final;
    }
};

int operator *(const Alumno &al1,const Alumno &al2){
    int prom = (al1.nota_final+al2.nota_final)/2;
    return prom;
}
int main(){
    Alumno al("Juan","calle ",16);
    Alumno al2("Pepe","av",20);
    cout << al*al2;

    
}