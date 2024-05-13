#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
void shape::move(int dx, int dy) {
	RefPoint.x += dx;
	RefPoint.y += dy;
}
void shape::flip(int orient) {



}
void shape::resize(double factor) {



}
void shape::rotate(int orient) {

}