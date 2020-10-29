#include <iostream>

class Jucarie
{
    std::string nume_jucarie;
    std::string producator;
    float pret;
    int nr_produse;
public:
    Jucarie(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse):
    nume_jucarie(numeJucarie), producator(producator), pret(pret), nr_produse(nrProduse) {}

    const std::string &getNumeJucarie() const {
        return nume_jucarie;
    }

    const std::string &getProducator() const {
        return producator;
    }

    float getPret() const {
        return pret;
    }

    int getNrProduse() const {
        return nr_produse;
    }
};

class elicopter: public Jucarie
{
    char *culoare = new char[20];
    int *nr_baterii = new int;

public:
    elicopter(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse, char *culoare,int *nrBaterii):
              Jucarie(numeJucarie, producator, pret, nrProduse), culoare(culoare),nr_baterii(nrBaterii) {}

    char *getCuloare() const {
        return culoare;
    }

    int *getNrBaterii() const {
        return nr_baterii;
    }

    friend std::ostream& operator<<(std::ostream& putout, const elicopter &elic)
    {
        putout << elic.getNumeJucarie() << ' ' << elic.getProducator() << ' ' << elic.getPret() << ' ' << elic.getNrProduse() << ' ' << elic.getCuloare() << ' ' << elic.getNrBaterii();
    }
};


int main()
{
    elicopter E("elicopter", "Idrive", 59.99, 8, "verde", 6);
    std::cout << E;
    return 0;
}
