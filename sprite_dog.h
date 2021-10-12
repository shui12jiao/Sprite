#ifndef SPRITE_DOG_H__
#define SPRITE_DOG_H__

#include"sprite_base.h"

class SpriteDog : public SpriteBase {
public:
    bool escape = false;
public:
    SpriteDog() {}
    SpriteDog(Pos pos, int height, int width, int speed, ACL_Image* img)
        :SpriteBase(pos, height, width, speed, img) {}
    SpriteDog(SpriteDog& rat) :SpriteBase(rat) {}
    ~SpriteDog() {}

    void move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite);
    void escMove(int key, int HEIGHT, int WIDTH, const SpriteDog* dog);
    void danger(const SpriteBase* sprite);
};

#endif // SPRITE_DOG_H__

