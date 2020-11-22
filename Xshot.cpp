//
// Created by vlad on 11/22/2020.
//

#include "Xshot.h"

Xshot::Xshot(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
             const std::string &munitie, int nrTinte, const catalog_de_promotii &cdp):
        Jucarie(numeJucarie, producator, pret, nrProduse), cdp(cdp)
         {
            this->munitie = munitie;
            this->nr_tinte = nrTinte;
         }

void Xshot::verificare_tinte() const
{
    if(nr_tinte > 0)
        std::cout << "Produsul contine tinte" << '\n';
    else
        std::cout << "Produsul nu contine tinte, dar le puteti achizitiona separat" << '\n';
}


