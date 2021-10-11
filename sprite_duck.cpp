#include"sprite_duck.h"
#include<cmath>

void SpriteDuck::move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite) {
    int h = height / 3, w = width / 3;

    danger(sprite);

    if (escape) {
        double x1 = pos.x, y1 = pos.y, x2 = sprite->pos.x, y2 = sprite->pos.y;
        double dx = x1 - x2, dy = y1 - y2, dd = sqrt(dx * dx + dy * dy);
        if (speed > 0) {
            pos.x += speed * dx / dd;
            pos.y += speed * dy / dd;
        }
        else {
            pos.x -= speed * dx / dd;
            pos.y -= speed * dy / dd;
        }
    }
    else {
        pos.x += speed;
        pos.y -= speed;
    }

    if (pos.x > WIDTH + w && speed > 0) {
        pos.x = -w;
    }
    else if (pos.x < -w && speed < 0) {
        pos.x = WIDTH + w;
    }
    if (pos.y > HEIGHT + h && speed < 0) {
        pos.y = -h;
    }
    else if (pos.y < -h && speed > 0) {
        pos.y = HEIGHT + h;
    }
}

int SpriteDuck::getScore() {
    return score;
}

void SpriteDuck::danger(const SpriteBase* sprite) {
    double x1 = pos.x, y1 = pos.y, h1 = height, w1 = width;
    double x2 = sprite->pos.x, y2 = sprite->pos.y, h2 = sprite->height, w2 = sprite->width;

    double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    double limit = (h1 + h2) * (h1 + h2) + (w1 + w2) * (w1 + w2);

    if (dist < limit / 2 && !escape) {
        escape = true;
        speed *= 2;
    }
    if (dist > limit && escape) {
        escape = false;
        speed /= -2;
    }
}
