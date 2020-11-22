//
// Created by vlad on 11/22/2020.
//

#ifndef PROIECTOOP_JUCARIE_H
#define PROIECTOOP_JUCARIE_H

#include <iostream>
#include <cstring>

class Jucarie
{
    std::string nume_jucarie;
    std::string producator;
    float pret;
    int nr_produse;
public:

    Jucarie(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse);

    Jucarie(const Jucarie &sursa)
    {
        this->nume_jucarie = sursa.nume_jucarie;
        this->producator = sursa.producator;
        this->pret = sursa.pret;
        this->nr_produse = sursa.nr_produse;
    }

    const std::string &getNumeJucarie() const {
        return nume_jucarie;
    }

    const std::string &getProducator() const {
        return producator;
    }

    float getPret() const {
        return pret;
    }

    int getNrProduse() const {
        return nr_produse;
    }

    void setNumeJucarie(const std::string &numeJucarie) {
        nume_jucarie = numeJucarie;
    }

    void setProducator(const std::string &producator) {
        Jucarie::producator = producator;
    }

    void setPret(float pret) {
        Jucarie::pret = pret;
    }

    void setNrProduse(int nrProduse) {
        nr_produse = nrProduse;
    }
};


#endif //PROIECTOOP_JUCARIE_H
