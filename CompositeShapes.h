#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{

	Rect* base;
	Rect* top;
	//int orientation=0;
	
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate(int orient)override;
	virtual void move(int dx, int dy)override;
	virtual void flip(int)override;
	virtual void resize(double)override;
};

class Car : public shape
{

	Rect* body;
	circle* tire1, * tire2;
	Equi_triangle* head;
	//int orientation = 0;
public:
	Car(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate(int orient)override;
	virtual void move(int dx, int dy)override;
	virtual void flip(int orient)override;
	virtual void resize(double)override;



};



class House :public shape {
	Rect* body;
	Equi_triangle* head; //int orientation = 0;
public:
	House(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate(int orient)override;
	virtual void move(int dx, int dy)override;
	virtual void resize(double)override;
	virtual void flip(int orient)override;
	
};

class Rocket :public shape {
	Rect* body; //int orientation = 0;
	circle* head;
	Equi_triangle* side1, * side2, * tail;
public:
	Rocket(game* r_pGame, point ref);
	virtual void draw()const;
	virtual void rotate(int orient)override;
	virtual void move(int dx, int dy)override;
	virtual void flip(int orient)override;
	virtual void resize(double)override;


};





class Pen : public shape {
	Rect* body;
	Equi_triangle* top;
	circle* base;

public:
	Pen(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void flip(int orient)override;
	virtual void move(int dx, int dy)override;
	virtual void rotate(int orient)override;
	virtual void resize(double factor)override;
};



class Tree : public shape
{
	Rect* base;
	Equi_triangle* tri1;
	Equi_triangle* tri2;
	Equi_triangle* tri3;
public:
	Tree(game* r_pGame, point ref);
	virtual void draw() const;
	virtual void rotate(int orient)override;
	virtual void flip(int orient)override;
	virtual void move(int dx, int dy)override;
	virtual void resize(double)override;
	

};


