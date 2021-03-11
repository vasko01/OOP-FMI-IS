#include <iostream>
#include <cstring>

class Planet
{
private:
    char* name;
    char* planetSystem;
    char* republic;

public:
    Planet();
    Planet(const Planet& other);
    Planet& operator=(const Planet& other);
    Planet(char* _name, char* _planetSystem, char* _republic);
    ~Planet();

    void set_name(const char* _name);
    void set_planetSystem(const char* _planetSystem);
    void set_republic(const char* _republic);

    char* get_name() const;
    char* get_planetSystem() const;
    char* get_republic() const;

    void print() const;

};