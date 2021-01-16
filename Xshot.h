//
// Created by vlad on 11/22/2020.
//

#ifndef PROIECTOOP_XSHOT_H
#define PROIECTOOP_XSHOT_H

#include <iostream>
#include <cstring>
#include "Jucarie.h"
#include "Catalog.h"

class Xshot: public Jucarie
{
    std::string tip_munitie;
    int nr_tinte;
    int nr_gloante;
    catalog_de_promotii cdp;

public:
    Xshot(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
          const std::string &tip_munitie, int nrTinte, int nr_gloante, const catalog_de_promotii &cdp);

    friend std::ostream& operator<<(std::ostream& putout, const Xshot &x)
    {
        putout << x.getNumeJucarie() << ' ' << "Producator:" << ' ' << x.getProducator() << ' ' << "Pret:" << ' ' << x.getPret()
        << ' ' << "Numar produse disponibile:" << ' ' << x.getNrProduse() << ' ' << "Tip munitie:" << ' ' << x.tip_munitie
        << ' ' << "Numar tinte:" << ' ' << x.nr_tinte << ' ' << "Numar gloante:" << ' ' << x.nr_gloante<< ' ' << "Catalog:" << ' ' << x.cdp;
        return putout;
    }

    void verificare_tinte() const;
    void testare_jucarie() override;
    void tragaci() const;
    void magazie() const;

    virtual ~Xshot();

    const std::string &getTipMunitie() const;

    int getNrTinte() const;

    int getNrGloante() const;

    const catalog_de_promotii &getCdp() const;
};

#endif //PROIECTOOP_XSHOT_H
