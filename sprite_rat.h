#ifndef SPRITE_RAT_H__
#define SPRITE_RAT_H__

#include"sprite_base.h"

class SpriteRat : public SpriteBase {
private:
    int score = 1;
public:
    SpriteRat() {}
    SpriteRat(Pos pos, int height, int width, int speed, ACL_Image* img)
        :SpriteBase(pos, height, width, speed, img) {}
    SpriteRat(SpriteRat& rat) :SpriteBase(rat) {}
    ~SpriteRat() {}

    void move(int key, int HEIGHT, int WIDTH);
    int getScore();
    void initilize(Pos p, int h, int w, int s, ACL_Image* i);
};

#endif // SPRITE_RAT_H__

