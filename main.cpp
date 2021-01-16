#include <iostream>
#include <vector>
#include "Jucarie.h"
#include "Elicopter.h"
#include "Catalog.h"
#include "Lego.h"
#include "Xshot.h"
#include "rlutil.h"
#include "Papusa.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

template<class Ttype>
Ttype comp(Ttype a, Ttype b)
{
    if(a > b)
        return a;
    else
        return b;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode()), "SFML");

    setColor(rlutil::RED);
    std::cout << "Folositi 0 pentru DA si 1 pentru NU\n";
    setColor(rlutil::GREY);

    elicopter E1("elicopter", "iDrive", 119.99f, 8, "GREEN", 2);
    elicopter ElicopteR = E1;
    elicopter E2("elicopter", "CoolMachines", 84.99f, 5, "CYAN", 6);
    std::cout << E1 << '\n';
    std::cout << E2 << '\n';
    std::cout << ElicopteR << '\n';

    catalog_de_promotii C_lego("lego", 7, "20.10.2020-31.10.2020");
    Lego L("Lego city", "Lego", 59.99f, 20, "7+", 150, C_lego);
    std::cout << L;

    catalog_de_promotii C_xshot("X-shot", 15, "01.11.2020-15.11.2020");

    Xshot X1("Hawk eye", "Xshot", 79.99f, 8, "proiectile", 5, 8, C_xshot);
    std::cout << X1;
    X1.verificare_tinte();

    Xshot X2("Chaos", "Xshot", 59.99f, 6, "bile", 0, 2, C_xshot);
    std::cout << X2;
    X2.verificare_tinte();
    X2.tragaci();
    X2.magazie();

    std::vector<Jucarie*> juc;
    juc.push_back(&E1);
    juc.push_back(&E2);
    juc.push_back(&L);
    juc.push_back(&X1);
    juc.push_back(&X2);

    for(auto & i : juc)
    {
        i->testare_jucarie();
    }

    std::cout << "Comparatie intre " << X1.getNumeJucarie() << " si " << X2.getNumeJucarie() << '\n';
    std::cout << comp<int>(X1.getNrGloante(), X2.getNrGloante()) << '\n';
    std::cout << comp<float>(X1.getPret(), X2.getPret()) << '\n';
    std::cout << comp<std::string>(X1.getNumeJucarie(), X2.getNumeJucarie()) << '\n';

    cutie_papusi_builder a;
    papusa p = a.nr_papusi(0).nr_accesorii(6).nr_haine(4).nr_incaltari(2).bulid();
    std::cout << p << '\n';

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;

}