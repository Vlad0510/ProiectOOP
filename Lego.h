//
// Created by vlad on 11/22/2020.
//

#ifndef PROIECTOOP_LEGO_H
#define PROIECTOOP_LEGO_H

#include <iostream>
#include <cstring>
#include "Jucarie.h"
#include "Catalog.h"

class Lego: public Jucarie
{
    std::string varsta_recomandata;
    int nr_piese;
    catalog_de_promotii cdp;

public:
    Lego(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
         const std::string &varstaRecomandata, int nrPiese, const catalog_de_promotii &cdp);

    friend std::ostream& operator<<(std::ostream& putout, const Lego &l)
    {
        putout << l.getNumeJucarie() << ' ' << "Producator:" << ' ' << l.getProducator() << ' ' << "Pret:" << ' ' << l.getPret()
        << ' ' << "Numar produse disponibile:" << ' ' << l.getNrProduse() << ' ' << "Varsta recomandata:" << ' ' <<  l.varsta_recomandata
        << ' ' << "Numar piese:" << ' ' << l.nr_piese << ' ' << "Catalog:" << ' ' << l.cdp;
        return putout;
    }

    void testare_jucarie() override;

    virtual ~Lego();

    const std::string &getVarstaRecomandata() const;

    int getNrPiese() const;

    const catalog_de_promotii &getCdp() const;
};

#endif //PROIECTOOP_LEGO_H
