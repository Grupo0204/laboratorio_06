
#include <iostream>
#include <math.h>
using namespace std;
class Circulo {
private:
    float radio;
    float diametro;
public:
    friend float calcularArea(Circulo &ci);
    Circulo(float radio, float diametro){
        this -> radio=radio;
        this -> diametro=diametro;
    }
    int getRadio(){cout << "El radio es: "<<radio<<endl;}
    int getDiametro(){cout <<"El diamentro es: "<< diametro<<endl;}
    float calcularAreaDiametro(){
        float rpta;
        radio = diametro/2;
        rpta = 3.14*pow(radio,2);
        cout << "El radio del circulo es: "<<radio<<endl;
        cout<<"El area del circulo es: "<<rpta<<endl; 

    }
};

float calcularArea(Circulo &ci){
    float rpta;
    rpta = 3.14*pow(ci.radio,2);
    cout<<"El area del circulo es: "<<rpta<<endl; 

}
int main(){
    float radio,diametro;
    cout << "Ingrese el radio: ";
    cin >> radio;
    cout << "ngrese el diametro: ";
    cin  >> diametro; 
    Circulo ci1(radio,diametro);
    calcularArea(ci1);
    cout << "----------------------------------"<<endl;
    cout << "-Calcular el area con el diametro-"<<endl;
    cout << "----------------------------------"<<endl;
    ci1.calcularAreaDiametro();
}


