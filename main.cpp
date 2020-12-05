#include <iostream>
#include "Jucarie.h"
#include "Elicopter.h"
#include "Catalog.h"
#include "Lego.h"
#include "Xshot.h"
#include "rlutil.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode()), "SFML");


    elicopter E1("elicopter", "iDrive", 119.99f, 8, "GREEN", 6);
    elicopter ElicopteR = E1;
    elicopter E2("elicopter", "CoolMachines", 84.99f, 5, "galben", 7);
    std::cout << E1 << '\n';
    E1.testare_jucarie();
    std::cout << E2 << '\n';
    std::cout << ElicopteR << '\n';
    E1 = E2;
    std::cout << E1 << '\n';

    catalog_de_promotii C_lego("lego", 7, "20.10.2020-31.10.2020");
    Lego L("Lego city", "Lego", 59.99f, 20, "7+", 150, C_lego);
    std::cout << L;
    L.testare_jucarie();

    catalog_de_promotii C_xshot("X-shot", 15, "01.11.2020-15.11.2020");

    Xshot X1("Hawk eye", "Xshot", 79.99f, 8, "proiectile", 5, 8, C_xshot);
    std::cout << X1;
    X1.verificare_tinte();
    X1.testare_jucarie();

    Xshot X2("Chaos", "Xshot", 59.99f, 6, "bile", 0, 6, C_xshot);
    std::cout << X2;
    X2.verificare_tinte();
    X2.tragaci();
    X2.magazie();


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