#ifndef SPRITE_BASE_H__
#define SPRITE_BASE_H__

#include"acllib.h"

class Pos {
public:
    int x, y;
public:
    Pos(int x = 0, int y = 0) :x(x), y(y) {}
};

class SpriteBase {
public:
    bool survive = true;
    Pos pos;
    int width, height;
    int speed;
    ACL_Image* img;
public:
    SpriteBase(Pos pos = { 0,0 }, int height = 0, int width = 0, int speed = 0, ACL_Image* img = nullptr)
        : pos(pos), height(height), width(width), speed(speed), img(img) {}
    SpriteBase(SpriteBase& base)
        : pos(base.pos), height(base.height), width(base.width), speed(base.speed), img(base.img) {}
    virtual ~SpriteBase() {}

    virtual void move(int key, int HEIGHT, int WIDTH) = 0;
    void drawSprite();
    void initilize(Pos p, int h, int w, int s, ACL_Image* i);
};

#endif // SPRITE_BASE_H__

