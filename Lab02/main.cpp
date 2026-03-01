#include "Brawler.h"
#include "GameMap.h"
#include "Gadget.h"
#include <iostream>

int main () {
    Brawler leon("Leon", 3440, 11);
    Brawler carl("Carl");
    Gadget leonGadget;
    GameMap cavernChurn("Cavern Churn", "Showdown", "Desert", "None");

    leon.showInfo();      
    carl.showInfo();      
    leonGadget.use();     
    cavernChurn.Rules();  
    cavernChurn.checkEnd(1); 

    return 0;
}
