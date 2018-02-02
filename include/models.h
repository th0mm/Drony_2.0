#include "stand.h"

typedef std::vector<std::vector<float>> t_vector;

class Coordinates{
public:
    t_vector drone {{ 0.5, 1.0, 1.0}, { 0.0, 0.0, 1.0}, { 1.0, 0.0, 1.0}};
    void getFloor (t_vector &result, float width, int n, int x, int y, int z){
        std::vector<float> vx;
        std::vector<float> vy;
        std::vector<float> vz;
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                vx.push_back(x+i*width);
                vy.push_back(y+(j+1)*width);
                vz.push_back(z);

                vx.push_back(x+i*width);
                vy.push_back(y+j*width);
                vz.push_back(z);

                vx.push_back(x+width+i*width);
                vy.push_back(y+j*width);
                vz.push_back(z);

                vx.push_back(x+width+i*width);
                vy.push_back(y+(j+1)*width);
                vz.push_back(z);

                vx.push_back(x+i*width);
                vy.push_back(y+(j+1)*width);
                vz.push_back(z);
            }
            vx.push_back(vx.at(vx.size()-2));
            vy.push_back(vy.at(vy.size()-2));
            vz.push_back(vz.at(vz.size()-2));

        }
        vx.push_back(vx.at(vx.size()-1));
        vy.push_back(y+width);
        vz.push_back(vz.at(vz.size()-1));

        result.push_back(vx);
        result.push_back(vy);
        result.push_back(vz);
    }
} coord;

Stand drone;
void setupDrone(void){
    drone.addPolygon(3, coord.drone.at(0), coord.drone.at(1), coord.drone.at(2));
}

Stand deck;
void setupFloor(void){
    int n = 6;
    t_vector dummy;
    coord.getFloor(dummy, 0.1, n, 0, 0, 0);
    deck.addPolygon(dummy.at(0).size(), dummy.at(0), dummy.at(1), dummy.at(2));
}
