//
// Created by vlad on 11/22/2020.
//

#ifndef PROIECTOOP_ELICOPTER_H
#define PROIECTOOP_ELICOPTER_H

#include <iostream>
#include <cstring>
#include "Jucarie.h"

class elicopter: public Jucarie
{
    std::string culoare;
    int nr_baterii;

public:
    elicopter(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse, const std::string &culoare, int nrBaterii);

    elicopter(const elicopter &sursa): Jucarie(sursa)
    {
       this->culoare = sursa.culoare;
       this->nr_baterii = sursa.nr_baterii;
    }

    elicopter& operator=(const elicopter &e)
    {
        this->setNumeJucarie(e.getNumeJucarie());
        this->setProducator(e.getProducator()) ;
        this->setPret(e.getPret());
        this->setNrProduse(e.getNrProduse()) ;
        this->culoare = e.culoare;
        this->nr_baterii = e.nr_baterii;
        return *this;
    }

    const std::string &getCuloare() const {
        return culoare;
    }

    int getNrBaterii() const {
        return nr_baterii;//*nr_baterii;
    }

    friend std::ostream& operator<<(std::ostream& putout, const elicopter &elic)
    {
        putout << elic.getNumeJucarie() << ' ' << "Producator:" << ' ' << elic.getProducator() << ' ' << "Pret:" << ' ' << elic.getPret()
               << ' ' << "Numar produse disponibile:" << ' ' << elic.getNrProduse() << ' ' << "Culoare:" << ' ' << elic.getCuloare()
               << ' ' << "Are nevoie de" << ' ' << elic.getNrBaterii() << ' ' << "baterii";
        return putout;
    }
};

#endif //PROIECTOOP_ELICOPTER_H
