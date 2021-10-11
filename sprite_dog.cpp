#include"sprite_dog.h"
#include<cmath>

void SpriteDog::move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite) {
    double x1 = pos.x, y1 = pos.y, x2 = sprite->pos.x, y2 = sprite->pos.y;
    double dx = x2 - x1, dy = y2 - y1, dd = sqrt(dx * dx + dy * dy);
    pos.x += speed * dx / dd;
    pos.y += speed * dy / dd;
}
