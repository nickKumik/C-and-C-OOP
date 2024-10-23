#include <iostream>
#include "cat.h"

Cat::Cat(const std::string& name)
    : name(name), lives(9)
{
    std::cout << "Constructor called with name: " << name << std::endl;
}

Cat::Cat()
{
    std::cout << "Default constructor called..." << std::endl;
}

// Constructor with two arguments
Cat::Cat(const std::string& name, unsigned int lives)
    : name(name), lives(lives)
{
    std::cout << "Constructor called with name: " << name 
              << " and lives: " << lives << std::endl;
}

// Destructor
Cat::~Cat()
{
    std::cout << "Destructor called..." << std::endl;
}

// Getter for the name variable
const std::string& Cat::get_name() const
{
    return name;
}

// Getter for the lives variable
const unsigned int& Cat::get_lives() const
{
    return lives;
}

void Cat::setName(const std::string& name) {
    this->name = name;
    std::cout << "set_name called..." << std::endl;
}

void Cat::setLives(const unsigned int& lives) {
    if (lives >= this->lives) {
        return;
    }

    this->lives = lives;
    std::cout << "set_lives called..." << std::endl;

    if (this->lives == 0) {
        std::string newName = "The Cat formerly known as " + this->name;
        setName(newName);
    }
}



