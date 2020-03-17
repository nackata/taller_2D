#ifndef CONTEXT_H
#define CONTEXT_H

#include <player.h>

class Context
{
public:

    virtual bool initContext(int width, int height, const char * title) = 0;

    // temporal solution; Context should not know about Player class
    // TODO : add input mask that context should update
    virtual void processInput(Player & player) = 0;


    virtual bool shouldClose() = 0;
    virtual void swapBuffers() = 0;

    virtual void update() = 0;

    Context();

    virtual ~Context();

    virtual int width() const = 0;
    virtual int height() const = 0;
    virtual float screenRatio() const = 0;
};

#endif // CONTEXT_H
