#include "acllib.h"
#include"sprite_base.h"
#include"sprite_player.h"
#include"sprite_rat.h"
#include<cstdio>
#include<ctime>
#include<utility>

using std::pair;
using std::make_pair;

#define HEIGHT 600
#define WIDTH 800

const int spriteNum = 2;    //sprit种类
const int spritePlayerNum = 1;
const int spriteRatNum = 10;

static SpritePlayer players[spritePlayerNum];
static SpriteRat rats[spriteRatNum];
static pair<SpriteBase*,int> sprites[spriteNum] = { make_pair(players,spritePlayerNum), make_pair(rats,spriteRatNum) };
static ACL_Image images[spriteNum];

static bool gameOver = false;
static bool pause = false;

void createSprite(pair<SpriteBase*, int> tSprites, ACL_Image* img);
void paintSprite(pair<SpriteBase*,int> tSprites);
void timerEvent(int id);
void keyEvent(int key, int event);
void paint();

int Setup() {
    srand((unsigned)time(NULL));

    initWindow("sprite game", DEFAULT, DEFAULT, WIDTH, HEIGHT);

    loadImage("tom.bmp", images);
    loadImage("jerry.bmp", images+1);
    loadImage("duck.jpg", images +2);

    for (int i = 0; i < spriteNum; ++i) {
        createSprite(sprites[i], &images[i]);
    }

    registerTimerEvent(timerEvent);
    registerKeyboardEvent(keyEvent);
    startTimer(0, 20);
    startTimer(1, 100);

    return 0;
}

void paint() {
    beginPaint();
    clearDevice();

    for (int i = 0; i < spriteNum; ++i) {
        paintSprite(sprites[i]);
    }

    char txt[20];
    sprintf_s(txt, "Score: %d", players->getScore());

    setTextSize(20);
    paintText(10, 10, txt);


    endPaint();
}

void keyEvent(int key, int event) {
    if (event != KEY_DOWN) { return; }

    for (int i = 0; i < spritePlayerNum; ++i) {
        if (players[i].survive) {
            players[i].move(key,HEIGHT,WIDTH);
        }
    }

    //for (int i = 0; i < nowNum; ++i){
    //	if (autosprite[i])
    //	{
    //		if (usr->collision(autosprite[i]->getRect()))
    //		{
    //			int s = autosprite[i]->getScore();
    //			if (usr)usr->addScore(s);
    //			delete(autosprite[i]);
    //			autosprite[i] = NULL;
    //		}
    //	}
    //}

    paint();
}

void timerEvent(int id) {
    //switch (id) {
    //case 0: {
    //    for (int i = 0; i < nowNum; ++i)
    //        if (autosprite[i]) {
    //            rect ur = usr->getRect();
    //            autosprite[i]->move(ur);

    //        }
    //}
    //    break;
    //case 1:
    //    if (nowNum < maxNum)
    //    {
    //        createData(autosprite);
    //    }
    //    break;
    //}

    paint();
}

void createSprite(pair<SpriteBase*, int> tSprites, ACL_Image* img) {
    for (int i = 0; i < tSprites.second; ++i) {
        tSprites.first[i].initilize
        (Pos(rand() % WIDTH,rand() % HEIGHT), WIDTH / 10, HEIGHT / 10, rand() % (HEIGHT / 15  + WIDTH / 15) + 1, img);
    }
}

void paintSprite(pair<SpriteBase*, int> tSprites) {
    for (int i = 0; i < tSprites.second; ++i) {
        tSprites.first[i].drawSprite();
    }
}
