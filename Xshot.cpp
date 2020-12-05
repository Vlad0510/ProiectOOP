//
// Created by vlad on 11/22/2020.
//

#include "Xshot.h"
#include <SFML/Audio.hpp>

Xshot::Xshot(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse,
             const std::string &tipMunitie, int nrTinte, int nrGloante, const catalog_de_promotii &cdp):
        Jucarie(numeJucarie, producator, pret, nrProduse), cdp(cdp)
         {
            this->tip_munitie = tipMunitie;
            this->nr_tinte = nrTinte;
            this->nr_gloante = nrGloante;
         }

void Xshot::verificare_tinte() const
{
    if(nr_tinte > 0)
        std::cout << "Produsul contine tinte" << '\n';
    else
        std::cout << "Produsul nu contine tinte, dar le puteti achizitiona separat" << '\n';
}

void Xshot::testare_jucarie()
{
    std::cout << "POC POC POC" << '\n';
}

void Xshot::tragaci() const
{
    sf::SoundBuffer Shotgun_buffer;
    Shotgun_buffer.loadFromFile("../Audio/Shotgun.wav");
    sf::Sound Shotgun_sound;
    Shotgun_sound.setBuffer(Shotgun_buffer);
    Shotgun_sound.setVolume(10);

    bool rsp;
    int x;
    x = nr_gloante;
    std::cout << "Doriti sa trageti? (0->Da, 1->Nu)" << '\n';
    std::cin >> rsp;

    while(x > 0 && rsp == 0)
    {
        x--;
        Shotgun_sound.play();
        std::cout << "Mai aveti " << x << " gloante. Mai trageti?";
        std::cin >> rsp;
    }
}

void Xshot::magazie() const
{
    sf::SoundBuffer Reload_buffer;
    Reload_buffer.loadFromFile("../Audio/Shotgun-reload.wav");
    sf::Sound Reload_sound;
    Reload_sound.setBuffer(Reload_buffer);
    Reload_sound.setVolume(80);

    bool rsp;
    std::cout << "Reincarcati ?" << '\n';
    std::cin >> rsp;

    if(rsp == 0)
    {

        std::cout << "....." << '\n';
        Reload_sound.play();
        std::cout << "....." << '\n';
        std::cout << "Acum aveti " << nr_gloante << " gloante" << '\n';
    }
    else
        std::cout << "Iti urez bafta cu munitia ramasa ;)";
}