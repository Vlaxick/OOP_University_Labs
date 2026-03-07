#include "Brawler.h"
#include "GameMap.h"
#include "Gadget.h"
#include <iostream>

int main () {
    std::cout << "Brawler Count: " << Brawler::getBrawlerCount() << std::endl;

    Gadget invisibility("Invisibility Cloak", 3);
    Brawler leon("Leon", 2400, 11, invisibility);
    Gadget speeeeeed("Speed Booster", 3);
    Brawler carl("Carl", 3440, 11, speeeeeed);
    Gadget trainingGadget("Training Gadget", 5);
    const Brawler trainer ("Training Bot", 10000, 1, trainingGadget);
    GameMap cavernChurn("Cavern Churn", "Showdown", "Desert", "None");

    std::cout << "Brawler Count: " << Brawler::getBrawlerCount() << std::endl;

    Brawler copyOfLeon = leon;
    copyOfLeon = carl;

    if (leon == carl) {
        std::cout << "Leon and Carl are the same brawler." << std::endl;
    } else {
        std::cout << "Leon and Carl are different brawlers." << std::endl;
    }

    ++leon;
    std::cout << leon;      
    carl.showInfo();      
    trainer.showInfo();   
    leon.useAbility();    
    cavernChurn.Rules();  
    cavernChurn.checkEnd(1);

    return 0;
}