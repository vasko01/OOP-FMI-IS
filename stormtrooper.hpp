#include <iostream>
#include <cstring>
#include "planet.hpp"

enum Rank
{
    None,
    Cadet,
    Private,
    Corporal,
    Sergeant
};

class Stormtrooper
{
private:
    char* id;
    Rank rank;
    char* type;
    Planet planet;

public:
    Stormtrooper();
    Stormtrooper(const Stormtrooper& other);
    Stormtrooper& operator=(const Stormtrooper& other);
    Stormtrooper(char* _id, Rank _rank, char* _type, Planet _planet);
    ~Stormtrooper();

    void set_id(const char* _id);
    void set_rank(const Rank _rank);
    void set_type(const char* _tyspe);
    void set_planet(const Planet _planet);
  
    char* get_id() const;
    Rank get_rank() const;
    void print_rank(Rank _rank);
    char* get_type() const;
    Planet get_planet() const;

    void print() const;
};