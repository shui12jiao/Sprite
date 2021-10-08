#include"sprite_base.h"

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