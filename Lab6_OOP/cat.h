#ifndef CAT_H
#define CAT_H
#include <string>
#include <sstream>

using namespace std;

class Cat {
    public:
        Cat(const std::string& name);
        Cat();
        Cat(const std::string& name, unsigned int lives);
        ~Cat();

       // Getter for the name variable
        const std::string& get_name() const;

        // Getter for the lives variable
        const unsigned int& get_lives() const;

        // Setter for the name variable
        void setName(const std::string& name);

        // Setter for the lives variable
        void setLives(const unsigned int& lives);
    


        // Friend std::ostream operator for writing a Cat with its name and lives to an output stream
        friend std::ostream& operator<<(std::ostream& os, const Cat& cat);
        friend bool operator ==( const Cat & lhs , const Cat & rhs );
        friend bool operator <( const Cat & lhs , const Cat & rhs );
    private:
        std::string name;
        unsigned int lives;

};

namespace std {
    template<>
    struct hash<Cat> {
        size_t operator()(const Cat& obj) const {
            std::stringstream ss;
            ss << obj;
            return std::hash<std::string>()(ss.str());
        }
    };
}
#endif