#include <iostream>
#include "display.h"
#include <GL/glew.h>

Display::Display(int width, int height, const std::string& title)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    n_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    n_glContext = SDL_GL_CreateContext(n_window);

    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Glew failed to initialize!" << std::endl;
    }

    n_isClosed = false;
}

Display::~Display()
{
    SDL_GL_DeleteContext(n_glContext);
    SDL_DestroyWindow(n_window);
    SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed()
{
    return n_isClosed;
}

void Display::Update()
{
    SDL_GL_SwapWindow(n_window);

    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
            n_isClosed = true;
    }
}
