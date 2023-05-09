#include <iostream>
using namespace std;


class Banco
{
    static float tasa_interes;
    public:
    static void cambiar_tasa_interes(float nueva_tasa_interes){
        Banco::tasa_interes = nueva_tasa_interes;
    }
    static float get_tasa_interes(){
        return Banco::tasa_interes;
    }
};


float Banco::tasa_interes = 0.05;


class Cuenta_Bancaria
{
    float saldo;
    public:
    Cuenta_Bancaria(){
        saldo = 0;
    }
    float getSaldo(){
        return saldo;
    }
    void retiro(float c){
        if(saldo >= c){
            saldo -= c;
        }
        else {
            cout<<"Saldo insuficiente para hacer retiro"<<endl;
        }
    }
    void deposito(float c){
        saldo += c;
    }
    float calcular_interes(){
        return saldo * Banco::get_tasa_interes();
    }
};


int main(){
    //Objeto de la clase Cuenta_Bancaria
    Cuenta_Bancaria cuenta1;
    //Saldo se carga con 1000
    cuenta1.deposito(1000);
    cout<<"Saldo: "<<cuenta1.getSaldo()<<endl;  //Saldo Inicial
    cout<<"Interes ganado: "<<cuenta1.calcular_interes()<<endl;
    //Retiramos 500 de saldo
    cuenta1.retiro(500);
    cout<<"Saldo: "<<cuenta1.getSaldo()<<endl;  //Saldo despues del cambio o retiro
    cout<<"Interes ganado: "<<cuenta1.calcular_interes()<<endl;


    Banco::cambiar_tasa_interes(0.06);
    cout<<"Interes ganado con nueva tasa: "<<cuenta1.calcular_interes()<<endl;


    return 0;
}
