//
// Created by vlad on 11/22/2020.
//

#ifndef PROIECTOOP_CATALOG_H
#define PROIECTOOP_CATALOG_H

#include <iostream>
#include <cstring>


class catalog_de_promotii
{
    std::string numele_catalogului;
    int nr_cataloage;
    std::string valabilitate_oferte;


public:
    catalog_de_promotii(const std::string &numeleCatalogului, int nrCataloage, const std::string &valabilitateOferte/*, const Lego &lego, const Xshot &xshot, const elicopter &Elic*/);


    friend std::ostream& operator<<(std::ostream& putout, const catalog_de_promotii &c)
    {
        putout << c.numele_catalogului << ' ' << "Numar cataloage:" << ' ' << c.nr_cataloage << ' ' << "Valabilitate catalog:" << ' ' << c.valabilitate_oferte << '\n';
        return putout;
    }

    virtual ~catalog_de_promotii();
};

#endif //PROIECTOOP_CATALOG_H
