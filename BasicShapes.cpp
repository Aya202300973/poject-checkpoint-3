#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth):shape(r_pGame,ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	switch (orientation) {
	case 0:
		upperLeft.x = RefPoint.x - wdth / 2;
		upperLeft.y = RefPoint.y - hght / 2;
		lowerBottom.x = RefPoint.x + wdth / 2;
		lowerBottom.y = RefPoint.y + hght / 2;
		

		break;
	case 90:
		upperLeft.x = RefPoint.x - hght / 2;
		upperLeft.y = RefPoint.y -wdth / 2;
		lowerBottom.x = RefPoint.x +hght / 2;
		lowerBottom.y = RefPoint.y + wdth / 2;
		
		break;

	}
	if(orientation==90||orientation==0)
	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);

}

point Rect::getRef()const {
	return RefPoint;
}
void Rect::rotate(int orient) {
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	switch (orient) {
	case 0:
		orientation = 90;
		upperLeft.x = RefPoint.x - hght / 2;
		upperLeft.y = RefPoint.y - wdth / 2;
		lowerBottom.x = RefPoint.x + hght / 2;
		lowerBottom.y = RefPoint.y + wdth / 2;
		

		break;
	case 90:
		orientation = 0;
		upperLeft.x = RefPoint.x - wdth / 2;
		upperLeft.y = RefPoint.y - hght / 2;
		lowerBottom.x = RefPoint.x + wdth / 2;
		lowerBottom.y = RefPoint.y + hght / 2;
		

		break;
	}
	if(orientation==0||orientation==90)
	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);

}
void Rect::flip(int orient) {
	orientation = orient;
	this->draw();

}

void Rect::move(int dx, int dy) {

	this->RefPoint.x += dx;
	this->RefPoint.y += dy;




}


void Rect::resize(double factor)
{
	wdth *= factor;
	hght *= factor;
}

int Rect::getwdth() const
{
	return wdth;
}

int Rect::gethght() const 
{
	return hght;
}



////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r):shape(r_pGame,ref)
{
	rad = r;
}

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}
void circle::flip(int orient) {
	this->draw();
}

void circle::move(int dx, int dy) {
	this->RefPoint.x += dx;
	this->RefPoint.y += dy;


}

void circle::resize(double factor)
{
	rad *= factor;
}
int circle::getrad() const
{
	return rad;
}
////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here

Equi_triangle::Equi_triangle(game* r_pGame, point ref, int len, int r_Angle) :shape(r_pGame, ref) {
	this->len = len;
	orientation = r_Angle;

}

void Equi_triangle::draw() const {
	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point* pArr = nullptr;
	pArr = orientationn();
	pW->DrawTriangle(pArr[0].x, pArr[0].y, pArr[1].x, pArr[1].y, pArr[2].x,pArr[2].y, FILLED);


}
point Equi_triangle::getRef()const {
	return RefPoint;
}
void Equi_triangle::rotate(int rAngle) {

	switch (rAngle) {
	case 0:
		orientation = 90;
		
		break;
	case 90:
		orientation = 180;

		break;
	case 180:
		orientation = 270;
		

		break;
	case 270:
		orientation = 0;
		
		break;
		

	}
	this->draw();

}
void Equi_triangle::flip(int orient) {
	switch (orient) {
	case 0:
		orientation = 180;
		
		break;
	case 90:
		orientation = 270;
		break;
	case 180:
		orientation = 0;

		break;
	case 270:
		orientation = 90;
		break;



	}
	this->draw();

}


void Equi_triangle::move(int dx, int dy) {

	this->RefPoint.x += dx;
	this->RefPoint.y += dy;


}
void Equi_triangle::resize(double factor)
{
	len *= factor;
}


int Equi_triangle::getlen() const
{
	return len;
}

Equi_triangle::~Equi_triangle() {
	delete pArr;
	pArr = nullptr;


}

