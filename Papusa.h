//
// Created by vlad on 1/7/2021.
//

#ifndef PROIECTOOP_PAPUSA_H
#define PROIECTOOP_PAPUSA_H

#include <iostream>
#include <cstring>

class papusa
{
    int nr_papusi;
    int nr_accesorii;
    int nr_haine;
    int nr_incaltari;
    friend class cutie_papusi_builder;
public:
    papusa() = default;

    friend std::ostream &operator<<(std::ostream &os, const papusa &papusa);
};

class cutie_papusi_builder
{
private:
    papusa p;
public:
    cutie_papusi_builder() = default;
    cutie_papusi_builder& nr_papusi(int nr)
    {
        p.nr_papusi = nr;
        try{
            if(p.nr_papusi < 1)
                throw "Numarul papusilor trebuie sa fie mai mare decat 1.\n";
        } catch (const char* msg) {
            std::cerr << msg << '\n';
        }
        return *this;
    }
    cutie_papusi_builder& nr_accesorii(int nr)
    {
        p.nr_accesorii = nr;
        return *this;
    }
    cutie_papusi_builder& nr_haine(int nr)
    {
        p.nr_haine = nr;
        return *this;
    }
    cutie_papusi_builder& nr_incaltari(int nr)
    {
        p.nr_incaltari = nr;
        return *this;
    }
    papusa bulid()
    {
        return p;
    }

};

std::ostream &operator<<(std::ostream &os, const papusa &papusa) {
    os << "Nr papusi: " << papusa.nr_papusi << " Nr accesorii: " << papusa.nr_accesorii << " Nr haine: "
       << papusa.nr_haine << " Nr incaltari: " << papusa.nr_incaltari << '\n';
    return os;
}

#endif //PROIECTOOP_PAPUSA_H