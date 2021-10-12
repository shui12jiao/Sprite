#include"sprite_dog.h"
#include<cmath>

void SpriteDog::move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite) {
    if (escape) { return; }
    double x1 = pos.x, y1 = pos.y, x2 = sprite->pos.x, y2 = sprite->pos.y;
    double dx = x1 - x2, dy = y1 - y2, dd = sqrt(dx * dx + dy * dy);
    pos.x -= speed * dx / dd;
    pos.y -= speed * dy / dd;
}

void SpriteDog::escMove(int key, int HEIGHT, int WIDTH, const SpriteDog* dog) {
    danger(dog);
    if (escape) {
        double x1 = pos.x, y1 = pos.y, x2 = dog->pos.x, y2 = dog->pos.y;
        double dx = x1 - x2, dy = y1 - y2, dd = sqrt(dx * dx + dy * dy);
        pos.x += speed * dx / dd;
        pos.y += speed * dy / dd;
    }
    
}


void SpriteDog::danger(const SpriteBase* sprite) {
    double x1 = pos.x, y1 = pos.y, h1 = height, w1 = width;
    double x2 = sprite->pos.x, y2 = sprite->pos.y, h2 = sprite->height, w2 = sprite->width;

    double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    double limit = (h1 + h2) * (h1 + h2) + (w1 + w2) * (w1 + w2);

    if (dist < limit / 4 && !escape) {
        escape = true;
    }
    if (dist > limit * 1.5 && escape) {
        escape = false;
    }
}
