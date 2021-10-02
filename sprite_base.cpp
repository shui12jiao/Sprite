#include"sprite_base.h"

void SpriteBase::drawSprite() {
    putImageScale(img, pos.x, pos.y, width, height);
}