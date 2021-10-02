#include"sprite_player.h"

void SpritePlayer::move(int key, int HEIGHT, int WIDTH) {
    switch (key) {
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
    }

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

bool SpritePlayer::collision(const SpriteBase& sprite) {
    if (pos.x < sprite.pos.x && pos.x + width > sprite.pos.x) {
        if (pos.y > sprite.pos.y && pos.y < sprite.pos.y + sprite.height)return true;
        if (pos.y < sprite.pos.y && pos.y + height > sprite.pos.y)return true;
    }
    else if (pos.x > sprite.pos.x && pos.x < sprite.pos.x + sprite.width) {
        if (pos.y > sprite.pos.y && pos.y < sprite.pos.y + sprite.height)return true;
        if (pos.y < sprite.pos.y && pos.y + height > sprite.pos.y)return true;
    }

    return false;
}

int SpritePlayer::getScore() {
    return score;
}

void SpritePlayer::setScore(int s) {
    score = s;
}

void SpritePlayer::addScore(int m) {
    score += m;
}