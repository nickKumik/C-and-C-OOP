#include <iostream> 
#include "cat.h"
using namespace std; 
int main(int argc, char* argv[]) {
    int numCats = argc / 2;

    
    Cat* cats = new Cat[numCats];

    for (int i = 0; i < numCats; i++) {
        string name = argv[2 * i + 1];
        int lives = (2 * i + 2 < argc) ? stoi(argv[2 * i + 2]) : 9;
        cats[i] = Cat(name, lives);
    }

    for (int i = 0; i < numCats; i++) {
        cout << "Cat " << i << ": " << cats[i].get_name() << " has " << cats[i].get_lives() << " lives." << endl;
    }

    delete[] cats;

    return 0;
}