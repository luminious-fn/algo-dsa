#include<iostream>
#include<string>
using namespace std;

class four_side_shape {
    public:
        string name;
        double get_area(void){
            cout <<  "in base class" << endl;
            return 0.0;
        }
};
class Rectangle : public four_side_shape{
    public:
        double l, w;
        double area;
        double get_area(void);
};


double Rectangle:: get_area(void){
    area = l * w;
    cout << "area of " << name << " is " << area << endl;
    return area;
}

int main(int argc, char *argv[]){
    
    Rectangle r;
    r.l = 2;
    r.w = 4;
    r.name = string("rectangle ");
    r.get_area();
    cout << r.area;
    return 0;
}
