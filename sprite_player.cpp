#include"sprite_player.h"

void SpritePlayer::move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite) {
    int h = height / 3, w = width / 3;

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

    if (pos.x > WIDTH + w) {
        pos.x = -w;
    }
    else if (pos.x < -w) {
        pos.x = WIDTH + w;
    }
    if (pos.y > HEIGHT + h) {
        pos.y = -h;
    }
    else if (pos.y < -h) {
        pos.y = HEIGHT + h;
    }
}

bool SpritePlayer::collision(const SpriteBase& sprite) {
    if (pos.x < sprite.pos.x && pos.x + width > sprite.pos.x) {
        if (pos.y > sprite.pos.y && pos.y < sprite.pos.y + sprite.height) { return true; }
        if (pos.y < sprite.pos.y && pos.y + height > sprite.pos.y) { return true; }
    }
    else if (pos.x > sprite.pos.x && pos.x < sprite.pos.x + sprite.width) {
        if (pos.y > sprite.pos.y && pos.y < sprite.pos.y + sprite.height) { return true; }
        if (pos.y < sprite.pos.y && pos.y + height > sprite.pos.y) { return true; }
    }
    if (pos.y < sprite.pos.y && pos.y + width > sprite.pos.y) {
        if (pos.x > sprite.pos.x && pos.x < sprite.pos.x + sprite.height) { return true; }
        if (pos.x < sprite.pos.x && pos.x + height > sprite.pos.x) { return true; }
    }
    else if (pos.y > sprite.pos.y && pos.y < sprite.pos.y + sprite.width) {
        if (pos.x > sprite.pos.x && pos.x < sprite.pos.x + sprite.height) { return true; }
        if (pos.x < sprite.pos.x && pos.x + height > sprite.pos.x) { return true; }
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