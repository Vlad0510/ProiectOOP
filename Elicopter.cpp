//
// Created by vlad on 11/22/2020.
//
#include "Jucarie.h"
#include "Elicopter.h"
#include "rlutil.h"

elicopter::elicopter(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse, const std::string &culoare, int nrBaterii):
          Jucarie(numeJucarie, producator, pret, nrProduse)
          {
            this->culoare = culoare;
            this->nr_baterii = nrBaterii;
          }
void elicopter::testare_jucarie()
{
    setColor(rlutil::GREEN);
    std::cout << "Elicopterul zboara" << '\n';
    setColor(rlutil::GREY);
}