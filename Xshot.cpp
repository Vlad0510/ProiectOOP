//
// Created by vlad on 11/22/2020.
//

#include <chrono>
#include <thread>
#include "Xshot.h"
#include "rlutil.h"
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
    using namespace std::chrono_literals;

    sf::SoundBuffer Shotgun_buffer;
    Shotgun_buffer.loadFromFile("../Audio/Shotgun.wav");
    sf::Sound Shotgun_sound;
    Shotgun_sound.setBuffer(Shotgun_buffer);
    Shotgun_sound.setVolume(10);

    std::this_thread::sleep_for(3s);
    setColor(rlutil::BLUE);
    std::cout << "=* =* =*" << '\n';
    setColor(rlutil::GREY);
    Shotgun_sound.play();
    std::this_thread::sleep_for(2s);
}

void Xshot::tragaci() const
{
    using namespace std::chrono_literals;

    sf::SoundBuffer Shotgun_buffer;
    Shotgun_buffer.loadFromFile("../Audio/Shotgun.wav");
    sf::Sound Shotgun_sound;
    Shotgun_sound.setBuffer(Shotgun_buffer);
    Shotgun_sound.setVolume(10);

    bool rsp;
    int x;
    x = nr_gloante;
    std::cout << "Doriti sa trageti?" << '\n';
    std::cin >> rsp;

    while(x > 0 && rsp == 0)
    {
        x--;
        Shotgun_sound.play();
        std::this_thread::sleep_for(0.5s);
        std::cout << "Mai aveti " << x << " gloante. Mai trageti?";
        std::cin >> rsp;
    }
}

void Xshot::magazie() const
{
    using namespace std::chrono_literals;

    sf::SoundBuffer Reload_buffer;
    Reload_buffer.loadFromFile("../Audio/Shotgun-reload.wav");
    sf::Sound Reload_sound;
    Reload_sound.setBuffer(Reload_buffer);
    Reload_sound.setVolume(60);

    bool rsp;
    std::cout << "Reincarcati ?" << '\n';
    std::cin >> rsp;

    if(rsp == 0)
    {
        std::this_thread::sleep_for(1s);
        std::cout << "....." << '\n';
        Reload_sound.play();
        std::this_thread::sleep_for(2s);
        std::cout << "Acum aveti " << nr_gloante << " gloante" << '\n';
    }
    else
        std::cout << "Iti urez bafta cu munitia ramasa ;)";
}

Xshot::~Xshot() {

}
