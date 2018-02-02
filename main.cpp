#include <iostream>
#include <GL/glew.h>

#include <vector>

#include "display.h"
#include "shader.h"
#include "mesh.h"

#include <drawScene.h>

int main(int argc, char *argv[])
{
    Display display(800, 600, "yare yare daze");

    Shader shader("./res/basicShader");

    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
                          Vertex(glm::vec3(0, 0.5, 0)),
                          Vertex(glm::vec3(0.5, -0.5, 0))};

    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    while(!display.IsClosed())
    {

        //drawSceneC();
        display.Clear(0.1, 0, 0, 1.0);

        shader.Bind();

        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

        mesh.Draw();

        display.Update();
    }

    return 0;
}
