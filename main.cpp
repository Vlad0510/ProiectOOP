#include <iostream>
#include "Jucarie.h"
#include "Elicopter.h"
#include "Catalog.h"
#include "Lego.h"
#include "Xshot.h"

int main()
{
    elicopter E1("elicopter", "iDrive", 119.99f, 8, "verde", 6);
    elicopter ElicopteR = E1;
    elicopter E2("elicopter", "CoolMachines", 84.99f, 5, "galben", 7);
    std::cout << E1 << '\n';
    std::cout << E2 << '\n';
    std::cout << ElicopteR << '\n';
    E1 = E2;
    std::cout << E1 << '\n';

    catalog_de_promotii C_lego("lego", 7, "20.10.2020-31.10.2020");
    Lego L("Lego city", "Lego", 59.99f, 20, "7+", 150, C_lego);
    std::cout << L;
    catalog_de_promotii C_xshot("X-shot", 15, "01.11.2020-15.11.2020");
    Xshot X1("Hawk eye", "Xshot", 79.99f, 8, "proiectile", 5, C_xshot);
    std::cout << X1;
    X1.verificare_tinte();
    Xshot X2("Chaos", "Xshot", 59.99f, 6, "bile", 0, C_xshot);
    std::cout << X2;
    X2.verificare_tinte();

    return 0;
}