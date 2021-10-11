#include"acllib.h"
#include"sprite_base.h"
#include"sprite_player.h"
#include"sprite_rat.h"
#include"sprite_duck.h"
#include"sprite_dog.h"
#include<cstdio>
#include<ctime>


#define HEIGHT 900
#define WIDTH 1200

const int baseSpeed = 10;
const int spriteNum = 2;    //sprit种类
const int spriteRatNum = 5;
const int spriteDuckNum = 3;
const int spriteDogNum = 2;

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
        for (int j = 0; j < spriteRatNum; ++j) {
            if (rats[j].survive && player.collision(rats[j])) {
                rats[j].survive = false;
                player.addScore(rats[j].getScore());
            }
        }
        //meet duck
        for (int j = 0; j < spriteDuckNum; ++j) {
            if (ducks[j].survive && player.collision(ducks[j])) {
                ducks[j].survive = false;
                player.addScore(ducks[j].getScore());
            }
        }
        //meet dog
        for (int j = 0; j < spriteDogNum; ++j) {
            if (player.survive && player.collision(dogs[j])) {
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
        for (int i = 0; i < spriteDogNum; ++i) {
            dogs[i].move(key, HEIGHT, WIDTH, &player);
        }
    }
    else {
        //player
        player.move(key, HEIGHT, WIDTH);
    }
}

void createSprite() {
    //player
    if (!player.survive) {
        player.survive = true;

        int nSpeed = player.speed / 2 + rand() % baseSpeed + baseSpeed;
        player.initilize(Pos(rand() % WIDTH, rand() % HEIGHT), HEIGHT / 10, WIDTH / 10, nSpeed, images);
    }

    //rat
    for (int i = 0; i < spriteRatNum; ++i) {
        if (rats[i].survive) {
            continue;
        }
        else {
            rats[i].survive = true;

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
            ducks[i].survive = true;
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
            dogs[i].survive = true;

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
