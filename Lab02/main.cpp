#include "Brawler.h"
#include "GameMap.h"
#include "Gadget.h"
#include <iostream>

int main () {
    Gadget invisibility("Invisibility Cloak", 3);
    Brawler leon("Leon", 2400, 11, invisibility);
    Gadget speeeeeed("Speed Booster", 3);
    Brawler carl("Carl", 3440, 11, speeeeeed);
    GameMap cavernChurn("Cavern Churn", "Showdown", "Desert", "None");

    leon.showInfo();      
    carl.showInfo();      
    leon.useAbility();    
    cavernChurn.Rules();  
    cavernChurn.checkEnd(1); 

    return 0;
}
