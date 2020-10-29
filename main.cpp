#include <iostream>

class Jucarie
{
    std::string nume_jucarie;
    std::string producator;
    float pret;
    int nr_produse;
public:
    Jucarie(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse)
    {
        this->nume_jucarie = numeJucarie;
        this->producator = producator;
        this->pret = pret;
        this->nr_produse = nrProduse;
    }

    Jucarie(const Jucarie &sursa)
    {
        this->nume_jucarie = sursa.nume_jucarie;
        this->producator = sursa.producator;
        this->pret = sursa.pret;
        this->nr_produse = sursa.nr_produse;
    }

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

    void setNumeJucarie(const std::string &numeJucarie) {
        nume_jucarie = numeJucarie;
    }

    void setProducator(const std::string &producator) {
        Jucarie::producator = producator;
    }

    void setPret(float pret) {
        Jucarie::pret = pret;
    }

    void setNrProduse(int nrProduse) {
        nr_produse = nrProduse;
    }
};

class elicopter: public Jucarie
{
    char *culoare;
    int *nr_baterii;

public:
    elicopter(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse, char *culoare,int *nr_baterii):
    Jucarie(numeJucarie, producator, pret, nrProduse)
    {
        this->culoare = new char[20];
        this->nr_baterii = new int;
        *(this->nr_baterii) = *nr_baterii;
        strcpy(this->culoare, culoare);
    }

    elicopter(const elicopter &sursa): Jucarie(sursa)
    {
        this->culoare = sursa.culoare;
        this->nr_baterii = sursa.nr_baterii;
    }

    elicopter& operator=(const elicopter &e)
    {
        this->setNumeJucarie(e.getNumeJucarie());
        this->setProducator(e.getProducator()) ;
        this->setPret(e.getPret());
        this->setNrProduse(e.getNrProduse()) ;
        this->culoare = e.culoare;
        this->nr_baterii = e.nr_baterii;
        return *this;
    }

    char* getCuloare() const {
        return culoare;
    }

    int getNrBaterii() const {
        return *nr_baterii;
    }

    friend std::ostream& operator<<(std::ostream& putout, const elicopter &elic)
    {
        putout << elic.getNumeJucarie() << ' ' << elic.getProducator() << ' ' << elic.getPret() << ' ' << elic.getNrProduse() << ' ' << elic.getCuloare() << ' ' << elic.getNrBaterii();
        return putout;
    }

    virtual ~elicopter()
    {
        delete nr_baterii;
        delete culoare;
    }
};

class catalog_de_promotii
{
    std::string numele_catalogului;
    int nr_cataloage;
    std::string valabilitate_oferte;

public:
    catalog_de_promotii(const std::string &numeleCatalogului, int nrCataloage, const std::string &valabilitateOferte)
    {
        this->numele_catalogului = numeleCatalogului;
        this->nr_cataloage = nrCataloage;
        this->valabilitate_oferte = valabilitateOferte;
    }

    const std::string &getNumeleCatalogului() const {
        return numele_catalogului;
    }

    int getNrCataloage() const {
        return nr_cataloage;
    }

    const std::string &getValabilitateOferte() const {
        return valabilitate_oferte;
    }
};

class Lego
{
    std::string varsta_recomandata;
    int nr_piese;
    catalog_de_promotii cdp;

public:
    Lego(const std::string &varstaRecomandata, int nrPiese, const catalog_de_promotii &cdp)
    {
        this->varsta_recomandata = varstaRecomandata;
        this->nr_piese = nrPiese;
        this->cdp = cdp;
    }
};


int main()
{
    int *p = new int;
    *p = 6;
    elicopter E1("elicopter", "Idrive", 59.99f, 8, "verde", p);
    elicopter ElicopteR = E1;
    elicopter E2("ELIcopter", "IdrivE", 79.99f, 5, "galben", p);
    std::cout << E1 << '\n';
    std::cout << ElicopteR << '\n';
    std::cout << E2 << '\n';
    E1 = E2;
    std::cout << E1;

   catalog_de_promotii C("lego", 7, "20.10.2020-31.10.2020");
   Lego L("7+", 150, C);
    return 0;
}
