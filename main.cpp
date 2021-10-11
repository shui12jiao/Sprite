#include "acllib.h"
#include"sprite_base.h"
#include"sprite_player.h"
#include"sprite_rat.h"
#include<cstdio>
#include<ctime>


#define HEIGHT 768
#define WIDTH 1024

const int baseSpeed = 10;
const int spriteNum = 2;    //sprit种类
const int spritePlayerNum = 2;
const int spriteRatNum = 5;

static SpritePlayer players[spritePlayerNum];
static SpriteRat rats[spriteRatNum];
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
    loadImage("jerry.bmp", images+1);
    loadImage("duck.jpg", images +2);

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
            players[i].initilize
            (Pos(rand() % WIDTH, rand() % HEIGHT), HEIGHT / 10, WIDTH / 10, rand() % 5 + players[i].speed + baseSpeed, &images[0]);
        }
        else {
            players[i].speed /= 2;
            players[i].survive = true;
        }
    }

    //rat
    for (int i = 0; i < spriteRatNum; ++i) {
        if (players[i].survive) {
            rats[i].initilize
            (Pos(rand() % WIDTH, rand() % HEIGHT), HEIGHT / 10, WIDTH / 10, rand() % 5 + rats[i].speed + baseSpeed, &images[1]);
        }
        else {
            rats[i].speed /= 2;
            rats[i].survive = true;
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
}
