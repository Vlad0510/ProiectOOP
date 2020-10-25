//Cotoarba Vlad, gr 252
//Este doar un inceput, iar tema este un magazin de jucarii.

#include <iostream>

class Jucarie
{
    int nr_produse;
    float pret;
    std::string nume_produs;
};

class jucarii_de_baieti: Jucarie
{
    int nr_produse;
    float pret;
    std::string producator;
    std::string nume_produs;
public:
    jucarii_de_baieti(int nrProduse = 8, float pret = 129.99, const std::string &producator = "Xshot", const std::string &numeProdus = "Hawk_eye")
    : nr_produse(nrProduse), pret(pret), producator(producator), nume_produs(numeProdus)
    {
        std::cout << producator << ' ' << nume_produs << ' ' << nr_produse << ' ' << pret << '\n';
    }
};

class jucarii_de_fete: Jucarie
{
    int nr_produse;
    float pret;
    std::string producator;
    std::string nume_produs;
public:
    jucarii_de_fete(int nrProduse = 6, float pret = 89.99, const std::string &producator = "Maia", const std::string &numeProdus = "Maia_balerina")
    : nr_produse(nrProduse), pret(pret), producator(producator), nume_produs(numeProdus)
    {
        std::cout << producator << ' ' << nume_produs << ' ' << nr_produse << ' ' << pret << '\n';
    }
};

int main()
{
    jucarii_de_baieti b;
    jucarii_de_fete f;
    return 0;
}
