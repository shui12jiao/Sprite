#include"acllib.h"
#include"sprite_base.h"
#include"sprite_player.h"
#include"sprite_rat.h"
#include"sprite_duck.h"
#include"sprite_dog.h"
#include<cstdio>
#include<ctime>


#define HEIGHT 800
#define WIDTH 1200

const int baseSpeed = 10;
const int spriteNum = 2;    //sprit种类
const int spriteRatNum = 9;
const int spriteDuckNum = 6;
const int spriteDogNum = 3;

static SpritePlayer player;
static SpriteRat rats[spriteRatNum];
static SpriteDuck ducks[spriteDuckNum];
static SpriteDog dogs[spriteDogNum];
static ACL_Image images[spriteNum];

static bool gameOver = false;
static bool pause = false;

void timerEvent(int id);
void keyEvent(int key, int event);
void paint();
void spriteMove(int key);
void createSprite();
void paintSprite();

int Setup() {
    srand((unsigned)time(NULL));

    initWindow("sprite game", DEFAULT, DEFAULT, WIDTH, HEIGHT);

    loadImage("tom.bmp", images);
    loadImage("jerry.bmp", images + 1);
    loadImage("duck.jpg", images + 2);
    loadImage("dog.bmp", images + 3);

    createSprite();

    registerTimerEvent(timerEvent);
    registerKeyboardEvent(keyEvent);
    startTimer(0, 20);
    startTimer(1, 100);

    return 0;
}

void keyEvent(int key, int event) {
    if (event != KEY_DOWN) { return; }

    spriteMove(key);

    paint();
}

void timerEvent(int id) {
    switch (id) {
    case 0: {
        spriteMove(id);
    } break;
    case 1: {
        createSprite();
    } break;
    }

    paint();
}

void paint() {
    beginPaint();
    clearDevice();

    //sprite
    paintSprite();

    //score
    char txt[20];
    sprintf_s(txt, "Score: %d", player.getScore());
    setTextSize(20);
    paintText(10, 10, txt);

    endPaint();
}

//---change
void spriteMove(int key) {
    if (key == 0) {
        //meet rat
        for (int i = 0; i < spriteRatNum; ++i) {
            if (rats[i].survive && player.collision(rats[i])) {
                rats[i].survive = false;
                player.addScore(rats[i].getScore());
            }
        }
        //meet duck
        for (int i = 0; i < spriteDuckNum; ++i) {
            if (ducks[i].survive && player.collision(ducks[i])) {
                ducks[i].survive = false;
                player.addScore(ducks[i].getScore());
            }
        }
        //meet dog
        for (int i = 0; i < spriteDogNum; ++i) {
            if (player.survive && player.collision(dogs[i])) {
                player.survive = false;
                player.setScore(player.getScore() / 2);
            }
        }
        

        //rat
        for (int i = 0; i < spriteRatNum; ++i) {
            rats[i].move(key, HEIGHT, WIDTH);
        }
        //duck
        for (int i = 0; i < spriteDuckNum; ++i) {
            ducks[i].move(key, HEIGHT, WIDTH, &player);
        }
        //dog
        for (int i = 0; i < spriteDogNum - 1; ++i) {
            dogs[i].move(key, HEIGHT, WIDTH, &player);
            for (int j = i + 1; j < spriteDogNum; ++j) {
                dogs[i].escMove(key, HEIGHT, WIDTH, &dogs[j]);
            }
        } dogs[spriteDogNum - 1].move(key, HEIGHT, WIDTH, &player);
            

    }
    else {
        //player
        player.move(key, HEIGHT, WIDTH);
    }
}

void createSprite() {
    //player
    if (!player.survive) {
        int nSpeed = player.speed / 2 + rand() % baseSpeed + baseSpeed;
        player.initilize(Pos(rand() % WIDTH, rand() % HEIGHT), HEIGHT / 10, WIDTH / 10, nSpeed, images);
    }

    //rat
    for (int i = 0; i < spriteRatNum; ++i) {
        if (rats[i].survive) {
            continue;
        }
        else {
            int nSpeed = (rats[i].speed / 2 + rand() % baseSpeed) / 3;
            if (nSpeed < 0) {
                nSpeed -= baseSpeed;
            }
            else {
                nSpeed += baseSpeed;
            }
            int h = HEIGHT / 10, w = WIDTH / 10;
            rats[i].initilize(Pos(rand() % (WIDTH - w - 10) + w / 2, rand() % (HEIGHT - h - 10) + h / 2), h / 1.5, w / 1.5, nSpeed, images + 1);
        }
    }

    //duck
    for (int i = 0; i < spriteDuckNum; ++i) {
        if (ducks[i].survive) {
            continue;
        }
        else {
            ducks[i].escape = true;

            int nSpeed = rand() % baseSpeed / 3 + baseSpeed / 1.5;
            int h = HEIGHT / 10, w = WIDTH / 10;
            ducks[i].initilize(Pos(rand() % (WIDTH - w - 10) + w / 2, rand() % (HEIGHT - h - 10) + h / 2), h / 1.5, w / 1.5, nSpeed, images + 2);
        }
    }

    //dog
    for (int i = 0; i < spriteDogNum; ++i) {
        if (dogs[i].survive) {
            continue;
        }
        else {
            int nSpeed = rand() % baseSpeed / 2 + baseSpeed / 4;

            int h = HEIGHT / 10, w = WIDTH / 10;
            dogs[i].initilize(Pos(rand() % (WIDTH - w - 10) + w / 2, rand() % (HEIGHT - h - 10) + h / 2), h, w, nSpeed, images + 3);
        }
    }

}

void paintSprite() {
    //player
    player.drawSprite();

    //rat
    for (int i = 0; i < spriteRatNum; ++i) {
        rats[i].drawSprite();
    }

    //duck
    for (int i = 0; i < spriteDuckNum; ++i) {
        ducks[i].drawSprite();
    }

    //dog
    for (int i = 0; i < spriteDogNum; ++i) {
        dogs[i].drawSprite();
    }
}
