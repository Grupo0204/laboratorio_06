#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Distancia
{
public:
    int a, b;
    Distancia(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    float operator->*(const Distancia &p2)
    {
        int r1 = pow((b - a), 2);
        int r2 = pow((p2.b - p2.a), 2);
        float dis = sqrt(r1 + r2);
        return dis;
    }
};

int main()
{
    Distancia A(4, 8);
    Distancia B(2, 5);
    float D = A->*B;
    cout << "La distancia entre el punto A y B es: " << D << endl;
}
