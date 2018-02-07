#ifndef DRONE_H
#define DRONE_H

#include <vector>

#include "Mesh.h"

std::vector<Mesh> planes;

class Drone
{
public:
    Vertex d[4][3] =
        {
            {

                    Vertex(glm::vec3(0, 0, 1)
                ,

                    Vertex(glm::vec3(0.1, 0, 0)
                ,

                    Vertex(glm::vec3(-0.1, 0, 0)

            },
            {

                    Vertex(glm::vec3(1, 0, 0)
                ,

                    Vertex(glm::vec3(0, 0, -0.1)
                ,

                    Vertex(glm::vec3(0, 0, 0.1)

            },
            {

                    Vertex(glm::vec3(0, 0, 1)
                ,

                    Vertex(glm::vec3(0.1, 0, 0)
                ,

                    Vertex(glm::vec3(-0.1, 0, 0)

            },
            {

                    Vertex(glm::vec3(-1, 0, 0)
                ,

                    Vertex(glm::vec3(0, 0, -0.1)
                ,

                    Vertex(glm::vec3(0, 0, 0,1)

            }
        };

    void setupDrone(void)
    {
        for(int i=0; i < stands.size(); i++)
        {
            Vertex cVertices[] = {  Vertex(glm::vec3(0, 0, 0)),
                                    Vertex(glm::vec3(0, 0, 0)),
                                    Vertex(glm::vec3(0, 0, 0))};

            for(int j=0; j < 3; j++)
            {
                cVertices[j] = drone.stands.at(i).at(j);
            }
            Mesh dummy(cVertices);
            planes.push_back(dummy);
        }
    }
private:
    //ryan
    std::vector< std::vector<Vertex> > stands
};

#endif DRONE_H
