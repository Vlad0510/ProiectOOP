#include <iostream>
#include <cstring>

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
        this->culoare = new char[20];
        strcpy(this->culoare, sursa.culoare);
        this->nr_baterii = new int;
        *this->nr_baterii = *sursa.nr_baterii;
    }

    elicopter& operator=(const elicopter &e)
    {
        this->setNumeJucarie(e.getNumeJucarie());
        this->setProducator(e.getProducator()) ;
        this->setPret(e.getPret());
        this->setNrProduse(e.getNrProduse()) ;
        strcpy(this->culoare, e.culoare);
        *this->nr_baterii = *e.nr_baterii;
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
        delete [] culoare;
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

    friend std::ostream& operator<<(std::ostream& putout, const catalog_de_promotii &c)
    {
        putout << c.numele_catalogului << ' ' << c.nr_cataloage << ' ' << c.valabilitate_oferte << '\n';
        return putout;
    }
};

class Lego
{
    std::string model;
    float pret;
    std::string varsta_recomandata;
    int nr_piese;
    catalog_de_promotii cdp;

public:
    Lego(const std::string &model, float pret, const std::string &varstaRecomandata, int nrPiese, const catalog_de_promotii &cdp):
    cdp(cdp)
    {
        this->model = model;
        this->pret = pret;
        this->varsta_recomandata = varstaRecomandata;
        this->nr_piese = nrPiese;
    }

    friend std::ostream& operator<<(std::ostream& putout, const Lego &l)
    {
        putout << l.model << ' ' << l.pret << ' ' << l.varsta_recomandata << ' ' << l.nr_piese << ' ' << l.cdp;
        return putout;
    }
};

class Xshot
{
    std::string model;
    std::string munitie;
    int nr_tinte;
    catalog_de_promotii cdp;

public:

    Xshot(const std::string &model, const std::string &munitie, int nrTinte, const catalog_de_promotii &cdp):
    cdp(cdp)
    {
        this->model = model;
        this->munitie = munitie;
        this->nr_tinte = nrTinte;
    }

    friend std::ostream& operator<<(std::ostream& putout, const Xshot &x)
    {
        putout << x.model << ' ' << x.munitie << ' ' << x.nr_tinte << ' ' << x.cdp;
        return putout;
    }
    void verificare_tinte()
    {
        if(nr_tinte > 0)
            std::cout << "Produsul contine tinte" << '\n';
        else
            std::cout << "Produsul nu contine tinte, dar le puteti cumpara separat" << '\n';
    }
};

int main()
{
    int *p = new int;
    *p = 6;
    int *n = new int;
    *n = 7;
    elicopter E1("elicopter", "iDrive", 119.99f, 8, "verde", p);
    elicopter ElicopteR = E1;
    elicopter E2("elicopter", "CoolMachines", 84.99f, 5, "galben", n);
    std::cout << E1 << '\n';
    std::cout << E2 << '\n';
    std::cout << ElicopteR << '\n';
    E1 = E2;
    std::cout << E1 << '\n';

    catalog_de_promotii C_lego("lego", 7, "20.10.2020-31.10.2020");
    Lego L("Lego-city", 59.99f, "7+", 150, C_lego);
    std::cout << L;
    catalog_de_promotii C_xshot("X-shot", 15, "01.11.2020-15.11.2020");
    Xshot X1("Hawk_eye", "proiectile", 5, C_xshot);
    std::cout << X1;
    X1.verificare_tinte();
    Xshot X2("Chaos", "bile", 0, C_xshot);
    std::cout << X2;
    X2.verificare_tinte();

    delete p;
    delete n;
    return 0;
}