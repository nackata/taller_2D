#ifndef CONTEXT_H
#define CONTEXT_H

#include <player.h>

class Context
{
public:

    virtual bool initContext(int width, int height, const char * title) = 0;
    virtual void processInput(Player & player) = 0;
    virtual bool shouldClose() = 0;
    virtual void swapBuffers() = 0;

    virtual void update() = 0;

    Context();

    virtual ~Context();
};

#endif // CONTEXT_H
