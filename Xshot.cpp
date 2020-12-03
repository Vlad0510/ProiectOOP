//
// Created by vlad on 11/22/2020.
//

#include "Xshot.h"

Xshot::Xshot(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
             const std::string &tipMunitie, int nrTinte, int nrGloante, const catalog_de_promotii &cdp):
        Jucarie(numeJucarie, producator, pret, nrProduse), cdp(cdp)
         {
            this->tip_munitie = tipMunitie;
            this->nr_tinte = nrTinte;
            this->nr_gloante = nrGloante;
         }

void Xshot::verificare_tinte() const
{
    if(nr_tinte > 0)
        std::cout << "Produsul contine tinte" << '\n';
    else
        std::cout << "Produsul nu contine tinte, dar le puteti achizitiona separat" << '\n';
}

void Xshot::testare_jucarie()
{
    std::cout << "POC POC POC" << '\n';
}



void Xshot::magazie()
{
    bool raspuns;
    std::cout << "Doriti sa trageti? (0->Da, 1->Nu)" << '\n';
    std::cin >> raspuns;

    if(raspuns == 1)
        std::cout << "Mai aveti: " << nr_gloante << '\n';
    else
        Xshot::tragaci(nr_gloante);

}

void Xshot::tragaci(int x)
{
    bool rsp = 0;
    while(x > 0&& rsp == 0)
    {
        x--;
        std::cout << "Mai aveti " << x << " gloante. Mai trageti? (0->Da, 1->Nu)";
        std::cin >> rsp;
    }
    if(x == 0)
    {
        std::cout << "Nu mai aveti gloante. Reincarcare..." << '\n';
        x = nr_gloante;
        std::cout << "+" << nr_gloante;
    }
    else
    {
        std::cout << "Ati ramas cu " << x << " gloante. Reincarcati ?";
        std::cin >> rsp;
        if(rsp == 0)
            std::cout << "Reincarcare..." << '\n' << "+" << nr_gloante;
    }
}