#ifndef CAT_H
#define CAT_H

using namespace std;

#include <string>

class Cat
{
    public:
        // Constructor with one argument
        Cat(const std::string& name);
        // Constructor with two arguments
        Cat(const std::string& name, unsigned int lives);
        // Default constructor
        Cat();
        // Destructor
        ~Cat();
        // Getter for the name variable
        const std::string& get_name() const;
        // Getter for the lives variable
        const unsigned int& get_lives() const;

        void setName(const std::string& name);
        void setLives(const unsigned int& lives);

    private:
        std::string name;
        unsigned int lives;
    };

#endif
