//
// Created by vlad on 11/22/2020.
//

#include "Lego.h"
#include <stdlib.h>
#include <chrono>
#include <thread>

Lego::Lego(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
           const std::string &varstaRecomandata, int nrPiese, const catalog_de_promotii &cdp):
           Jucarie(numeJucarie, producator, pret, nrProduse), cdp(cdp)
           {
                this->varsta_recomandata = varstaRecomandata;
                this->nr_piese = nrPiese;
           }

void Lego::testare_jucarie() {
    int nrRand;
    char c;
    bool rsp;
    using namespace std::chrono_literals;

    std::cout << "Doriti sa verificati produsul lego ?" << '\n';
    std::cin >> rsp;
    if (rsp == 1)
        std::cout << "Va doresc o zi buna!" << '\n';
    else {
        std::cout << "Se deschide cutia" << '\n';
        std::this_thread::sleep_for(1s);
        std::cout << "..." << '\n';
        std::this_thread::sleep_for(3s);
        std::cout << "..." << '\n';

        for (int i = 0; i < nr_piese / 3; i++)
            std::cout << '-';
        std::cout << '\n';

        for (int i = 1; i < (nr_piese / 10) - 1; i++) {
            std::cout << '|';
            for (int j = 1; j < (nr_piese / 3) - 1; j++) {
                nrRand = rand() % 2;
                if (nrRand == 0)
                    std::cout << ' ';
                else {
                    nrRand = rand() % 11 + 1;
                    c = '!' + nrRand;
                    std::cout << c;
                }
            }
            std::cout << '|' << '\n';
        }
        for (int i = 0; i < nr_piese / 3; i++)
            std::cout << '-';
        std::cout << '\n';
        std::cout << "Nu lipsesc piese" << '\n';
    }
}

Lego::~Lego() {

}

const std::string &Lego::getVarstaRecomandata() const {
    return varsta_recomandata;
}

int Lego::getNrPiese() const {
    return nr_piese;
}

const catalog_de_promotii &Lego::getCdp() const {
    return cdp;
}
