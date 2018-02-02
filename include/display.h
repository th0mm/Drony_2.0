#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2/SDL.h>
#include <string>

class Display
{
public:
    Display(int width, int height, const std::string& title);

    void Clear(float r, float g, float b, float a);
    void Update();
    bool IsClosed();

    virtual ~Display();
protected:
private:
    Display(const Display& other);
    void operator=(const Display& other) {};

    SDL_Window* n_window;
    SDL_GLContext n_glContext;
    bool n_isClosed;
};

#endif // DISPLAY_H
