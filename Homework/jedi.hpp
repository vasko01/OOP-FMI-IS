#include <iostream>
#include <cstring>
#include "planet.hpp"

enum JediRank
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
    JediRank rank;
    double midiChlorian;
    Planet planet;
    char* spicies;
    char* militaryRank;

public:
    Jedi();
    Jedi(const Jedi& other);
    Jedi& operator=(const Jedi& other);
    Jedi(char* _name, JediRank _rank, double _midiChlorian, Planet _planet, char* _spicies, char* _militaryRank);
    ~Jedi();


    void set_name(const char* _name);
    void set_rank(const JediRank _rank);
    void set_midiChlorian(const double _midiChlorian);
    void set_planet(const Planet _planet);
    void set_spicies(const char* _spicies);
    void set_militaryRank(const char* _militaryRank);

    char* get_name() const;
    JediRank get_rank() const;
    double get_midiChlorian() const;
    Planet get_planet() const;
    char* get_spicies() const;
    char* get_militaryRank() const;

    friend ostream& operator<<(ostream &os, const Jedi &jedi);
    friend istream& operator>>(istream &is, Jedi &jedi);

    const char* enumToString(const JediRank &r) const;

};

JediRank stringToEnum(char* str);