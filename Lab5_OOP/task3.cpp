#include <iostream >
#include "Shape.h"

int main(int argc , char *argv []) {
    // Array of Shape pointers
    Shape **xs = new Shape*[10];
    xs[0] = new Circle(0,0,1);
    xs[1] = new Rectangle(0,1,1,0);
    xs[2] = new Triangle(0,0,1,1,0,1);
    xs[3] = new Triangle (5,6,9,10,7,8);
    xs[4] = new Circle(0,5,10);
    xs[5] = new Triangle(3,4,5,6,7,8);
    xs[6] = new Circle(4,6,2);
    xs[7] = new Rectangle(3,4,9,10);
    xs[8] = new Circle(3,5,6);
    xs[9] = new Triangle(5,6,7,8,9,10);

    // Loop to call to_string
    for(int i = 0; i<10;i++){
        std::cout << xs[i]->to_string() <<std::endl;
    }

    // Loop to change centers and call new to_string
    for(int i = 0; i<10;i++){

        int randNum = rand()%16;
        int randNum1 = rand()%16;

        std::cout << "New center to (" << randNum << ", " << randNum1 << ")" << std::endl;
        xs[i]->centre_at(randNum,randNum1);
        std::cout << xs[i]->to_string() <<std::endl;
    }

    // Deallocating Shape objects
    for(int i = 0; i<10;i++){
        delete xs[i];
    }

    delete []xs;
    return 0;
}