#include"sprite_rat.h"

void SpriteRat::move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite) {
    int h = height / 2, w = width / 2;

    if ( pos.x < 0 || pos.x > WIDTH - w) speed = -speed;
    if ( pos.y < 0 || pos.y > HEIGHT - h) speed = -speed;

    pos.x += speed / 3;
    pos.y += speed / 3;

}

int SpriteRat::getScore() {
    return score;
}