#include "acllib.h"
#include"sprite_base.h"
#include"sprite_player.h"
#include<vector>

#define HEIGH 1600
#define WIDTH 900

const int spriteNum = 1;
//---
const int spriteRat = 10;
//---

static SpritePlayer player;
//template<typename T>
//static vector<vector<T>> sprites = {
//    vetor<>{}
//}
static bool gameOver;
static bool pause;

template<typename T>
void createData(T** tSprite);
void timerEvent(int id);
void keyEvent(int key, int event);
void paint();

int Setup() {
    //winRect.x = DEFAULT;
    //winRect.y = DEFAULT;
    //winRect.width = winWidth;
    //winRect.height = winHeight;
    //initWindow("auto sprite", DEFAULT, DEFAULT, winWidth, winHeight);
    //srand((unsigned)time(NULL));

    //loadImage("jerry.bmp", &img);
    //loadImage("tom.bmp", &imgUsr);
    //loadImage("duck.jpg", &imgHeart);
    ////autosprite[nowNum++] = new CAutoSprite(x, y, autoWidth, autoHeight, dx, dy, &img, winRect);
    //createData(autosprite);
    //createData(&usr);
    registerTimerEvent(timerEvent);
    registerKeyboardEvent(keyEvent);
    //startTimer(0, 40);
    //startTimer(1, 1000);
    //return 0;
}

void paint() {
    //beginPaint();
    //clearDevice();
    //int i = 0;
    //for (i = 0; i < nowNum; ++i)
    //{
    //	if (autosprite[i])
    //	{
    //		autosprite[i]->drawSprite();
    //	}
    //}
    //if (usr)
    //{
    //	usr->drawSprite();

    //	char txt[10];
    //	sprintf_s(txt, "%d", usr->getScore());
    //	setTextSize(20);
    //	paintText(10, 10, txt);
    //}
    //endPaint();
}

void keyEvent(int key, int event) {
    //if (event != KEY_DOWN)return;
    //if (usr)usr->move(key);
    //for (int i = 0; i < nowNum; ++i)
    //{
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
    //paint();
}

void timerEvent(int id) {
    //int i = 0;
    //switch (id)
    //{
    //case 0:
    //    for (i = 0; i < nowNum; ++i)
    //        if (autosprite[i])
    //        {
    //            rect ur = usr->getRect();
    //            autosprite[i]->move(ur);

    //        }

    //    break;
    //case 1:
    //    if (nowNum < maxNum)
    //    {
    //        createData(autosprite);
    //    }
    //    break;
    //}//end switch
    //paint();
}

template<typename T>
void createData(T** tSprite) {
    /*int x = rand() % winWidth - autoWidth;
    if (x < 0)x = 0;
    int y = rand() % winHeight - autoHeight;
    if (y < 0)y = 0;
    int dx = rand() % 5 + 1;
    int dy = rand() % 5 + 1;
    int t = rand() % 100;
    if (t < 80)
        autosprite[nowNum++] = new CAutoSprite(x, y, autoWidth, autoHeight, dx, dy, &img, winRect, 1);
    else
        autosprite[nowNum++] = new CAvoidSprite(x, y, autoWidth, autoHeight, dx, dy, &imgHeart, winRect, 5);*/

        //void createData(CUsrSprite** usr){
        //    int x = rand() % winWidth - autoWidth;
        //    if (x < 0)x = 0;
        //    int y = rand() % winHeight - autoHeight;
        //    if (y < 0)y = 0;
        //    int dx = 5;
        //    int dy = 5;
        //    *usr = new CUsrSprite(x, y, usrWidth, usrHeight, dx, dy, &imgUsr, winRect);
        //
        //}
}