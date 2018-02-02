#include "models.h"

void setupScene(void){
    //setupDrone();
    setupFloor();
}

void drawSceneC(void){
    for(int i=0; i < stands.size(); i++){
        stands.at(i) -> drawStand();
        //std::cout << "KIRA KUIN" << i << std::endl;
    }
}
