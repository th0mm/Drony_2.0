#include <iostream>
#include <GL/glew.h>

#include <vector>

#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "transform.h"

#include "drone.h"
#include "drawScene.h"

int main(int argc, char *argv[])
{
    Display display(800, 600, "yare yare daze");

    Shader shader("./res/basicShader");

    /*Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
                          Vertex(glm::vec3(0, 0.5, 0)),
                          Vertex(glm::vec3(0.5, -0.5, 0))};*/

    //Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    transform c_transform;

    float counter = 0.0f;

    setupScene();

    while(!display.IsClosed())
    {
        display.Clear(0.1, 0, 0, 1.0);

        //float sinCounter = sinf(counter);
        //float cosCounter = cosf(counter);

        //c_transform.GetPos().x = sinCounter;
        //c_transform.GetRot().z = counter;
        //c_transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.Bind();
        shader.Update(c_transform);
        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

        drawSceneC();
        //mesh.Draw();

        display.Update();
        counter += 0.01f;
    }

    return 0;
}
