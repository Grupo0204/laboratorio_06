#include <iostream>
using namespace std;
class Numeros{
public:
 int a,b;
};
istream& operator >>(istream &o, Numeros &p ){
    cout << "Ingrese a: ";
    o >> p.a;
    cout << "Ingrese b: ";
    o >> p.b;
    if (p.a > p.b)
    {
        cout << "El mayor es: "<<p.a;
    }else{cout << "El mayor es: "<<p.b;}
}
int main (){

    Numeros num;
    cin >>num;
}