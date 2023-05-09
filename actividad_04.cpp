#include <iostream>
using namespace std;


class Vector
{
    public:
    int x, y;
    Vector(const int x, const int y){
        this->x = x;
        this->y = y;
    }
};


Vector & operator + (const Vector &v1, const Vector &v2){
    return *(new Vector(v1.x + v2.x, v1.y + v2.y));
}


Vector & operator- (const Vector &v1, const Vector &v2){
    return *(new Vector(v1.x - v2.x, v1.y - v2.y));
}


int main(){
    //Suma de vectores
    Vector A(100, 45);
    Vector B(50, 30);
    Vector S = A + B;
    cout<<"Suma de los Vectores A y B:"<<endl;
    cout<<"("<<S.x<<", "<<S.y<<")"<<endl;
   
    //Resta de vectores
    Vector R = A - B;
    cout<<"Resta de los Vectores A y B:"<<endl;
    cout<<"("<<R.x<<", "<<R.y<<")"<<endl;
}
