#ifndef SPRITE_DOG_H__
#define SPRITE_DOG_H__

#include"sprite_base.h"

class SpriteDog : public SpriteBase {
public:
    SpriteDog() {}
    SpriteDog(Pos pos, int height, int width, int speed, ACL_Image* img)
        :SpriteBase(pos, height, width, speed, img) {}
    SpriteDog(SpriteDog& rat) :SpriteBase(rat) {}
    ~SpriteDog() {}

    void move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite);
};

#endif // SPRITE_DOG_H__

