#include"sprite_duck.h"

void SpriteDuck::move(int key, int HEIGHT, int WIDTH, const SpriteBase* sprite) {


}

int SpriteDuck::getScore() {
    return score;
}

bool SpriteDuck::danger(const SpriteBase* sprite) {
	double x = pos.x, y = pos.y, h = height, w = width;
	double xx = sprite->pos.x, yy = sprite->pos.y, hh = sprite->height, ww = sprite->width;

	double dist = (x - xx) * (x - xx) + (y - yy) * (y - yy);
	double limit = (h + hh) * (h + hh) + (w + ww) * (w + ww);

	if (dist < limit) {
		return true;
	}
	else {
		return false;
	}
}
