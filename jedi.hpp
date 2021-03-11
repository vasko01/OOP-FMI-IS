#include <iostream>
#include <cstring>
#include "planet.hpp"

enum Rank
{
    None,
    Guardian,
    Consular,
    Sentinel,
};

class Jedi
{
private:
    char* name;
    Rank rank;
    double midiChlorian;
    Planet planet;
    char* spicies;
    char* militaryRank;

public:
    Jedi();
    Jedi(const Jedi& other);
    Jedi& operator=(const Jedi& other);
    Jedi(char* _name, Rank _rank, double _midiChlorian, Planet _planet, char* _spicies, char* _militaryRank);
    ~Jedi();


    void set_name(const char* _name);
    void set_rank(const Rank _rank);
    void set_midiChlorian(const double _midiChlorian);
    void set_planet(const Planet _planet);
    void set_spicies(const char* _spicies);
    void set_militaryRank(const char* _militaryRank);

    char* get_name() const;
    Rank get_rank() const;
    double get_midiChlorian() const;
    Planet get_planet() const;
    char* get_spicies() const;
    char* get_militaryRank() const;

    void print() const;



};