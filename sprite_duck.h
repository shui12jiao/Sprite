#ifndef SPRITE_DUCK_H__
#define SPRITE_DUCK_H__

#include"sprite_base.h"

class SpriteDuck : public SpriteBase {
public:
    bool escape = false;
    int score = 3;
public:
    SpriteDuck() {}
    SpriteDuck(Pos pos, int height, int width, int speed, ACL_Image* img)
        :SpriteBase(pos, height, width, speed, img) {}
    SpriteDuck(SpriteDuck& rat) :SpriteBase(rat) {}
    ~SpriteDuck() {}

    void move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite);
    int getScore();
    void danger(const SpriteBase* sprite);
};

#endif // SPRITE_DUCK_H__
