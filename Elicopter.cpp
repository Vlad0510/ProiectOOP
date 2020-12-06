//
// Created by vlad on 11/22/2020.
//
#include "Jucarie.h"
#include "Elicopter.h"
#include "rlutil.h"
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>

elicopter::elicopter(const std::string &numeJucarie, const std::string &producator, float pret, int nrProduse, const std::string &culoare, int nrBaterii):
          Jucarie(numeJucarie, producator, pret, nrProduse)
          {
            this->culoare = culoare;
            this->nr_baterii = nrBaterii;
          }
void elicopter::testare_jucarie()
{
    bool rsp;
    using namespace std::chrono_literals;

    sf::SoundBuffer Elicopter_buffer;
    Elicopter_buffer.loadFromFile("../Audio/Military_Helicopter.wav");
    sf::Sound Elicopter_sound;
    Elicopter_sound.setBuffer(Elicopter_buffer);
    Elicopter_sound.setVolume(10);

    if(culoare == "BLACK")
    {
        setColor(rlutil::BLACK);
    }
    else if(culoare == "BLUE")
    {
        setColor(rlutil::BLUE);
    }
    else if(culoare == "GREEN")
    {
        setColor(rlutil::GREEN);
    }
    else if(culoare == "CYAN")
    {
        setColor(rlutil::CYAN);
    }
    else if(culoare == "RED")
    {
        setColor(rlutil::RED);
    }
    else if(culoare == "MAGENTA")
    {
        setColor(rlutil::MAGENTA);
    }
    else if(culoare == "BROWN")
    {
        setColor(rlutil::BROWN);
    }
    else if(culoare == "GREY")
    {
        setColor(rlutil::GREY);
    }
    else if(culoare == "DARKGREY")
    {
        setColor(rlutil::DARKGREY);
    }
    else if(culoare == "LIGHTBLUE")
    {
        setColor(rlutil::LIGHTBLUE);
    }
    else if(culoare == "LIGHTGREEN")
    {
        setColor(rlutil::LIGHTGREEN);
    }
    else if(culoare == "LIGHTCYAN")
    {
        setColor(rlutil::LIGHTCYAN);
    }
    else if(culoare == "LIGHTRED")
    {
        setColor(rlutil::LIGHTRED);
    }
    else if(culoare == "LIGHTMAGENTA")
    {
        setColor(rlutil::LIGHTMAGENTA);
    }
    else if(culoare == "YELLOW")
    {
        setColor(rlutil::YELLOW);
    }
    else if(culoare == "WHITE")
    {
        setColor(rlutil::WHITE);
    }
    else
        setColor(rlutil::GREY);

    std::cout << "Doriti sa-l testati ?\n";
    std::cin >> rsp;
    if(rsp == 0)
    {
        std::cout << "Porneste...\n";
        Elicopter_sound.play();
        Elicopter_sound.setPlayingOffset(sf::seconds(7.f));
        std::this_thread::sleep_for(2s);
        std::cout << "Ca sa-l opriti apasati 1, ca sa continue apasati 0\n";
        for (int i = nr_baterii; i > 0; i--)
        {
            std::this_thread::sleep_for(1s);
            std::cout << ">";
            std::cin >> rsp;
            Elicopter_sound.play();
            Elicopter_sound.setPlayingOffset(sf::seconds(8.f));
            if (rsp == 1) {
                std::cout << "Se opreste...\n";
                break;
            }
            if (i == 1)
                std::cout << "S-au descarcat bateriile\n";
        }
    }
    else
        std::cout << "Va doresc o zi buna!" << '\n';
    setColor(rlutil::GREY);
}

elicopter::~elicopter() {

}
