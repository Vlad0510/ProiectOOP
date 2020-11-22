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
    std::string munitie;
    int nr_tinte;
    catalog_de_promotii cdp;

public:
    Xshot(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
          const std::string &munitie, int nrTinte, const catalog_de_promotii &cdp);

    friend std::ostream& operator<<(std::ostream& putout, const Xshot &x)
    {
        putout << x.getNumeJucarie() << ' ' << "Producator:" << ' ' << x.getProducator() << ' ' << "Pret:" << ' ' << x.getPret()
        << ' ' << "Numar produse disponibile:" << ' ' << x.getNrProduse() << ' ' << "Tip munitie:" << ' ' << x.munitie
        << ' ' << "Numar tinte:" << ' ' << x.nr_tinte << ' ' << "Catalog:" << ' ' << x.cdp;
        return putout;
    }
    void verificare_tinte() const;

};

#endif //PROIECTOOP_XSHOT_H
