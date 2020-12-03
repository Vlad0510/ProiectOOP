//
// Created by vlad on 11/22/2020.
//

#include "Lego.h"

Lego::Lego(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
           const std::string &varstaRecomandata, int nrPiese, const catalog_de_promotii &cdp):
           Jucarie(numeJucarie, producator, pret, nrProduse), cdp(cdp)
           {
                this->varsta_recomandata = varstaRecomandata;
                this->nr_piese = nrPiese;
           }

void Lego::testare_jucarie()
{
    std::cout << "Nu lipsesc piese" << '\n';
}