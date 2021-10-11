#include"sprite_base.h"

SpriteBase::SpriteBase(Pos pos , int height , int width , int speed, ACL_Image* img )
    : pos(pos), height(height), width(width), speed(speed), img(img) {}

SpriteBase::SpriteBase(SpriteBase& base)
    : pos(base.pos), height(base.height), width(base.width), speed(base.speed), img(base.img) {}

void SpriteBase::drawSprite() {
    if (survive) { putImageScale(img, pos.x, pos.y, width, height); }
}

void SpriteBase::initilize(Pos p, int h, int w, int s, ACL_Image* i) {
    pos = p;
    height = h;
    width = w;
    speed = s;
    img = i;
}