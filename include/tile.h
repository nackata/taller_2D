#ifndef TILE_H
#define TILE_H

#include "entity.h"
#include "texture.h"
#include "spritecomponent.h"

class TileEntity : Entity<TileEntity, 1>
{
public:
    TileEntity(ComponentManager & manager, TextureManager::Texture tex)
    {
        manager.addComponent(SpriteComponent(tex));
    }
};


#endif // TILE_H
