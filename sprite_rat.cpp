#include"sprite_rat.h"

void SpriteRat::move(int key, int HEIGHT, int WIDTH) {
    /*switch (key) {
    case VK_UP:
        pos.y -= speed;
        break;
    case VK_DOWN:
        pos.y += speed;
        break;
    case VK_LEFT:
        pos.x -= speed;
        break;
    case VK_RIGHT:
        pos.x += speed;
        break;
    }*/

    pos.x += speed;
    pos.y += speed;


    if (pos.x > WIDTH + height) {
        pos.x = -height;
    }
    else if (pos.x < -height) {
        pos.x = WIDTH + height;
    }
    if (pos.y > (HEIGHT + height)) {
        pos.y = -height;
    }
    else if (pos.y < -height) {
        pos.y = HEIGHT + height;
    }
}

int SpriteRat::getScore() {
    return score;
}

void SpriteRat::initilize(Pos p, int h, int w, int s, ACL_Image* i) {
    pos = p;
    height = h;
    width = w;
    speed = s;
    img = i;
}