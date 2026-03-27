#include "Brawler.h"
#include "GameMap.h"
#include "Gadget.h"
#include "TankBrawler.h"
#include "Shield.h"
#include <iostream>

int main () {
    std::cout << "Initial Brawler Count: " << Brawler::getBrawlerCount() << std::endl;

    Gadget invisibility("Invisibility Cloak", 3);
    Gadget speeeeeed("Speed Booster", 3);
    Gadget trainingGadget("Training Gadget", 5);

    Brawler leon("Leon", 2400, 11, invisibility, 0.0, 0.0, 1);
    Brawler carl("Carl", 3440, 11, speeeeeed, 5.0, 5.0, 2);

    TankBrawler frank("Frank", 14000, 10, trainingGadget, 100, Shield("Iron", 2000), 10.0, 10.0, 3);

    const Brawler trainer ("Training Bot", 10000, 1, trainingGadget, 50.0, 50.0, 999);

    GameMap cavernChurn("Cavern Churn", "Showdown", "Desert", "None");

    std::cout << "Brawler Count after creation: " << Brawler::getBrawlerCount() << std::endl;

    std::cout << "Static Binding Demonstration:" << std::endl;
    Brawler* staticBrawlerPtr = &frank;
    staticBrawlerPtr->showInfo();  
    staticBrawlerPtr->takeDamage(50);  

    frank.move(2.0, 3.0);
    frank.showPosition();
    frank.takeDamage(50);

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