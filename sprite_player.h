#ifndef SPRITE_PLAYER_H__
#define SPRITE_PLAYER_H__

#include"sprite_base.h"


class SpritePlayer : public SpriteBase {
private:
    static int score;
public:
    SpritePlayer() {}
    SpritePlayer(Pos pos, int height, int width, int speed, ACL_Image* img)
        : SpriteBase(pos, height, width, speed, img) {}
    SpritePlayer(SpritePlayer& player) :SpriteBase(player) {}
    ~SpritePlayer() {}

    void move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite = nullptr);

    bool collision(const SpriteBase& sprite);
    int getScore();
    void setScore(int s);
    void addScore(int m);
};


#endif // SPRITE_PLAYER_H__ 
