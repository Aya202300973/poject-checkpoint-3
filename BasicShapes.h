//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect:public shape
{
	int hght, wdth; int orientation = 0;	//height and width of the recangle
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	virtual void draw() const;
	virtual void rotate(int orient)override;
	point getRef()const;
	virtual void move(int dx, int dy)override;
	virtual void flip(int) override;
	virtual void resize(double factor) override;
	int getwdth() const;
	int gethght() const;


};


////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle
	int rad;
public:	
	circle(game* r_pGame, point ref, int r);	//add more parameters for the constructor if needed
	virtual void draw() const;
	virtual void move(int dx, int dy)override;
	virtual void flip(int)override;
	virtual void resize(double factor)override;
	int getrad()const;
};


class Equi_triangle : public shape {
	int len; point* pArr=nullptr;

public:
	Equi_triangle(game* r_pGame, point ref, int len, int r_Angle = 0);
	~Equi_triangle();
	virtual void draw() const;
	virtual void rotate(int rAngle);
	point getRef()const;
	virtual void flip(int orient) override;
	virtual void move(int dx, int dy)override;
	virtual void resize(double factor)override;
	void setOrientation(int o) {
	}
	int getlen() const;
	point* orientationn() const {
		point* pArr = new point[3];
		int op1 = len / 2, op3 = sqrt(3) / 2 * len;
		switch (orientation) {
		case 90:
			pArr[0].x = RefPoint.x;
			pArr[0].y = RefPoint.y + op1;
			pArr[1].x = RefPoint.x;
			pArr[1].y = RefPoint.y - op1;
			pArr[2].x = RefPoint.x + op3;
			pArr[2].y = RefPoint.y;
			return pArr;
			//rotationAngle = 90;
			//pW->DrawTriangle(x1, y1, x2, y2, x3, y3);
		case 180:
			pArr[0].x = RefPoint.x + op1;
			pArr[0].y = RefPoint.y;
			pArr[1].x = RefPoint.x - op1;
			pArr[1].y = RefPoint.y;
			pArr[2].x = RefPoint.x;
			pArr[2].y = RefPoint.y + op3;
			//rotationAngle = 180;
			//pW->DrawTriangle(x1, y1, x2, y2, x3, y3);
			return pArr;
		case 270:
			pArr[0].x = RefPoint.x;
			pArr[0].y = RefPoint.y + op1;
			pArr[1].x = RefPoint.x;
			pArr[1].y = RefPoint.y - op1;
			pArr[2].x = RefPoint.x - op3;
			pArr[2].y = RefPoint.y;
			//rotationAngle = 270;
			//pW->DrawTriangle(x1, y1, x2, y2, x3, y3);
			return pArr;
		case 0:
			pArr[0].x = RefPoint.x + op1;
			pArr[0].y = RefPoint.y;
			pArr[1].x = RefPoint.x - op1;
			pArr[1].y = RefPoint.y;
			pArr[2].x = RefPoint.x;
			pArr[2].y = RefPoint.y - op3;
			//rotationAngle = 0;
			//pW->DrawTriangle(x1, y1, x2, y2, x3, y3);

			return pArr;

		}


	};





};


