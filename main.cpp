#include "acllib.h"
#include"sprite_base.h"
#include"sprite_player.h"
#include"sprite_rat.h"
#include"sprite_duck.h"
#include"sprite_dog.h"
#include<cstdio>
#include<ctime>


#define HEIGHT 900
#define WIDTH 1600

const int baseSpeed = 10;
const int spriteNum = 2;    //sprit种类
const int spritePlayerNum = 1;
const int spriteRatNum = 5;
const int spriteDuckNum = 3;
const int spriteDogNum = 2;

static SpritePlayer players[spritePlayerNum];
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
    sprintf_s(txt, "Score: %d", players->getScore());
    setTextSize(20);
    paintText(10, 10, txt);

    endPaint();
}

//---change
void spriteMove(int key) {
    if (key == 0) {
        //player
        for (int i = 0; i < spritePlayerNum; ++i) {
            //meet rat
            for (int j = 0; j < spriteRatNum; ++j) {
                if (rats[j].survive && players[i].collision(rats[j])) {
                    rats[j].survive = false;
                    players->addScore(rats[j].getScore());
                }
            }
            //meet duck
            for (int j = 0; j < spriteDuckNum; ++j) {
                if (ducks[j].survive && players[i].collision(ducks[j])) {
                    ducks[j].survive = false;
                    players->addScore(ducks[j].getScore());
                }
            }
            //meet dog
            for (int j = 0; j < spriteDogNum; ++j) {
                if (players[i].survive && players[i].collision(dogs[j])) {
                    players[i].survive = false;
                    players->setScore(players->getScore() / 2);
                }
            }
        }

        //rat
        for (int i = 0; i < spriteRatNum; ++i) {
            rats[i].move(key, HEIGHT, WIDTH);
        }
    }
    else {
        //player
        for (int i = 0; i < spritePlayerNum; ++i) {
            players[i].move(key, HEIGHT, WIDTH);
        }
    }
}

void createSprite() {
    //player
    for (int i = 0; i < spritePlayerNum; ++i) {
        if (players[i].survive) {
            continue;
        }
        else {
            players[i].survive = true;

            int nSpeed = players[i].speed / 2 + rand() % baseSpeed + baseSpeed;
            players[i].initilize(Pos(rand() % WIDTH, rand() % HEIGHT), HEIGHT / 10, WIDTH / 10, nSpeed, images);
        }
    }

    //rat
    for (int i = 0; i < spriteRatNum; ++i) {
        if (rats[i].survive) {
            continue;
        }
        else {
            rats[i].survive = true;

            int nSpeed = rats[i].speed / 2 + rand() % baseSpeed;
            if (rats[i].speed < 0) {
                nSpeed -= baseSpeed; 
            }
            else {
                nSpeed += baseSpeed;
            }
            int h = HEIGHT / 10, w = WIDTH / 10;
            rats[i].initilize(Pos(rand() % (WIDTH  - w - 10) + w / 2, rand() % (HEIGHT - h - 10) + h /2),h, w, nSpeed, images + 1);
        }
    }

    //duck
    for (int i = 0; i < spriteRatNum; ++i) {
        if (ducks[i].survive) {
            continue;
        }
        else {
            ducks[i].survive = true;

            int nSpeed = rand() % baseSpeed;
            if (ducks[i].speed < 0) {
                nSpeed -= baseSpeed / 2;
            }
            else {
                nSpeed += baseSpeed / 2;
            }
            int h = HEIGHT / 10, w = WIDTH / 10;
            ducks[i].initilize(Pos(rand() % (WIDTH - w - 10) + w / 2, rand() % (HEIGHT - h - 10) + h / 2), h, w, nSpeed, images + 2);
        }
    }

    //dog
    for (int i = 0; i < spriteRatNum; ++i) {
        if (dogs[i].survive) {
            continue;
        }
        else {
            dogs[i].survive = true;

            int nSpeed = rand() % baseSpeed + baseSpeed / 3;

            int h = HEIGHT / 10, w = WIDTH / 10;
            dogs[i].initilize(Pos(rand() % (WIDTH - w - 10) + w / 2, rand() % (HEIGHT - h - 10) + h / 2), h, w, nSpeed, images + 3);
        }
    }

}

void paintSprite() {
    //player
    for (int i = 0; i < spritePlayerNum; ++i) {
        players[i].drawSprite();
    }

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
