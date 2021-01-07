//
// Created by vlad on 11/22/2020.
//

#include "Catalog.h"

catalog_de_promotii::catalog_de_promotii(const std::string &numeleCatalogului, int nrCataloage, const std::string &valabilitateOferte/*, const Lego &lego, const Xshot &xshot, const elicopter &Elic*/)//:
//lego(lego), xshot(xshot), Elic(Elic)
{
    this->numele_catalogului = numeleCatalogului;
    this->nr_cataloage = nrCataloage;
    this->valabilitate_oferte = valabilitateOferte;
}


catalog_de_promotii::~catalog_de_promotii() {

}
