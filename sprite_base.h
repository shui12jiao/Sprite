#ifndef SPRITE_BASE_H__
#define SPRITE_BASE_H__

#include"acllib.h"

class SpriteBase {
public:
    class Pos {
    public:
        int x, y;
    public:
        Pos(int x = 0, int y = 0) :x(x), y(y) {}
    };
public:
    Pos pos;
    const int width, height;
    const int speed;
    ACL_Image* img;
public:
    SpriteBase(Pos pos = { 0,0 }, int height = 0, int width = 0, int speed = 0, ACL_Image* img = nullptr)
        : pos(pos), height(height), width(width), speed(speed), img(img) {}
    SpriteBase(SpriteBase& base)
        : pos(base.pos), height(base.height), width(base.width), speed(base.speed), img(base.img) {}
    virtual ~SpriteBase() {}

    virtual void move(int key, int HEIGHT, int WIDTH) = 0;
    void drawSprite();
};

#endif // SPRITE_BASE_H__

