#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	pGame = r_pGame;
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y +factor* config.sighShape.topHeight / 2 +factor* config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	//base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
	base=new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
	
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}

void Sign::rotate(int orient) {
	point topRef,baseRef;
	switch (orient) {

		case 0:
			topRef = RefPoint;
			baseRef = { RefPoint.x -factor* (config.sighShape.topHeight / 2) -factor* (config.sighShape.baseHeight / 2),RefPoint.y };
			base->setRefPoint(baseRef);
			top->rotate(0);
			base->rotate(0);
			orientation = 90;
			break;
		case 90:
			topRef = RefPoint;
			baseRef = { RefPoint.x,RefPoint.y - factor*config.sighShape.topHeight / 2 -factor* config.sighShape.baseHeight / 2 };
			base->setRefPoint(baseRef);
			top->rotate(90);
			base->rotate(90);
			orientation = 180;
			break;
		case 180:
			topRef = RefPoint;
			baseRef = { RefPoint.x + factor*(config.sighShape.topHeight / 2) +factor* (config.sighShape.baseHeight / 2),RefPoint.y };
			base->setRefPoint(baseRef);
			top->rotate(0);
			base->rotate(0);
			orientation = 270;
			break;
		case 270:
			topRef = RefPoint;
			baseRef = { RefPoint.x,RefPoint.y +factor* config.sighShape.topHeight / 2 +factor*config.sighShape.baseHeight / 2 };
			base->setRefPoint(baseRef);
			top->rotate(90);
			base->rotate(90);
			orientation = 0;



	}

	

}
void Sign::move(int dx, int dy) {
	base->move(dx, dy);
	top->move(dx, dy);
	this->RefPoint = top->getRef();




}


void Sign::flip(int orient)
{
	point topref, baseref;
	switch (orient) {
	case 0:
		topref = RefPoint;
		baseref = { RefPoint.x, RefPoint.y + factor*config.sighShape.topHeight / 2 + factor*config.sighShape.baseHeight / 2 };
		top->setRefPoint(topref);
		base->setRefPoint(baseref);
		top->flip(0); base->flip(0);
		orientation = 180;
		break;
	case 180:
		topref = RefPoint;
		baseref = { RefPoint.x, RefPoint.y -factor* config.sighShape.topHeight / 2 -factor* config.sighShape.baseHeight / 2 };
		top->setRefPoint(topref);
		base->setRefPoint(baseref);
		top->flip(0); base->flip(0);
		orientation = 0;
		break;
	case 90:
		topref = RefPoint;
		baseref = { RefPoint.y,RefPoint.x - factor*config.sighShape.topHeight / 2 -factor* config.sighShape.baseHeight / 2 };
		top->setRefPoint(topref);
		base->setRefPoint(baseref);
		top->flip(90); base->flip(90);
		orientation = 270;
		break;
	case 270:
		topref = RefPoint;
		baseref = { RefPoint.y,RefPoint.x + factor*config.sighShape.topHeight / 2 +factor* config.sighShape.baseHeight / 2 };
		top->setRefPoint(topref);
		base->setRefPoint(baseref);
		top->flip(90); base->flip(90);
		orientation = 90;
		break;
		
	}
	
}
void Sign::resize(double factor) {
	point baseref, topref;
	base->resize(factor);
	top->resize(factor);
	switch (orientation) {
	case 0:
		topref = RefPoint;
		baseref = { RefPoint.x,RefPoint.y - top->gethght() /2 - base->gethght() / 2 };
		base->setRefPoint(baseref);
		break;
	case 90:
		topref = RefPoint;
		baseref = { RefPoint.y + top->gethght() / 2 + base->gethght() / 2,RefPoint.y};
		
		top->setRefPoint(topref);
		base->setRefPoint(baseref);
		break;
	case 180:
		topref = RefPoint;
		baseref = { RefPoint.x,RefPoint.y + top->gethght() / 2 + base->gethght() / 2 };
		top->setRefPoint(topref);
		base->setRefPoint(baseref);
		break;
	case 270:
		topref = RefPoint;
		baseref = { RefPoint.y + top->gethght() / 2 + base->gethght() / 2,RefPoint.y };
		top->setRefPoint(topref);
		base->setRefPoint(baseref);
		break;

	}this->factor *= factor;

}


////////////////////////////////////class Car//////////////////////////////////
Car::Car(game* r_pGame, point ref) : shape(r_pGame, ref) {

	point bodyRef = ref;
	point tire1Ref = { ref.x - factor*config.carShape.bodyWdth / 4,ref.y +factor* config.carShape.bodyHght / 2 +factor* config.carShape.tireRadius };
	point tire2Ref = { ref.x + factor*config.carShape.bodyWdth / 4,ref.y + factor*config.carShape.bodyHght / 2 +factor* config.carShape.tireRadius };
	point headRef = { ref.x,ref.y -factor* config.carShape.bodyHght / 2 };
	body = new Rect(pGame, bodyRef, config.carShape.bodyHght, config.carShape.bodyWdth);
	tire1 = new circle(pGame, tire1Ref, config.carShape.tireRadius);
	tire2 = new circle(pGame, tire2Ref, config.carShape.tireRadius);
	head = new Equi_triangle(pGame, headRef, config.carShape.headLen);
}
void Car::draw()const {
	body->draw();
	tire1->draw();
	tire2->draw();
	head->draw();


	

}
void Car::rotate(int orient) {
	point bodyRef, tire1Ref, tire2Ref, headRef;
	switch (orient) {
	case 0:
		bodyRef = RefPoint;
		headRef = { RefPoint.x + factor*config.carShape.bodyHght / 2,RefPoint.y };
		tire1Ref = { RefPoint.x -factor*config.carShape.bodyHght / 2 -factor*config.carShape.tireRadius , RefPoint.y + factor* config.carShape.bodyWdth / 4 };
		tire2Ref = { RefPoint.x - factor*config.carShape.bodyHght / 2 -factor* config.carShape.tireRadius , RefPoint.y -factor* config.carShape.bodyWdth / 4 };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		body->rotate(0);
		tire1->draw();
		tire2->draw();
		head->rotate(orient);
		orientation = 90;
		break;
	case 90:
		bodyRef = RefPoint;
		headRef = { RefPoint.x , RefPoint.y + factor*config.carShape.bodyHght / 2 };
		tire1Ref = { RefPoint.x + factor*config.carShape.bodyWdth / 4,RefPoint.y -factor* config.carShape.bodyHght / 2 - factor*config.carShape.tireRadius };
		tire2Ref = {  RefPoint.x -factor* config.carShape.bodyWdth / 4 , RefPoint.y -factor* config.carShape.bodyHght / 2 - factor*config.carShape.tireRadius };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		body->rotate(90);
		tire1->draw();
		tire2->draw();
		head->rotate(orient);
		orientation = 180;
		break;
	case 180:
		bodyRef = RefPoint;
		headRef = { RefPoint.x - factor*config.carShape.bodyHght / 2,RefPoint.y };
		tire1Ref = { RefPoint.x + factor*config.carShape.bodyHght / 2 +factor* config.carShape.tireRadius , RefPoint.y +factor* config.carShape.bodyWdth / 4 };
		tire2Ref = { RefPoint.x +factor* config.carShape.bodyHght / 2 + factor*config.carShape.tireRadius , RefPoint.y - factor*config.carShape.bodyWdth / 4 };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		body->rotate(0);
		tire1->draw();
		tire2->draw();
		head->rotate(orient);
		orientation = 270;
		break;
	case 270:
		bodyRef = RefPoint;
		headRef = { RefPoint.x , RefPoint.y - factor*config.carShape.bodyHght / 2 };
		tire1Ref = { RefPoint.x + factor*config.carShape.bodyWdth / 4,RefPoint.y +factor* config.carShape.bodyHght / 2 +factor* config.carShape.tireRadius };
		tire2Ref = { RefPoint.x - factor*config.carShape.bodyWdth / 4 , RefPoint.y + factor*config.carShape.bodyHght / 2 + factor*config.carShape.tireRadius };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		body->rotate(90);
		tire1->draw();
		tire2->draw();
		head->rotate(orient);
		orientation = 0;
		break;


	}





}

void Car::flip(int orient) {
	point bodyRef, tire1Ref, tire2Ref, headRef;
	switch (orient) {
	case 0:
		bodyRef = RefPoint;
		headRef = { RefPoint.x , RefPoint.y +factor* config.carShape.bodyHght / 2 };
		tire1Ref = { RefPoint.x + factor*config.carShape.bodyWdth / 4,RefPoint.y -factor* config.carShape.bodyHght / 2 - factor*config.carShape.tireRadius };
		tire2Ref = { RefPoint.x -factor* config.carShape.bodyWdth / 4 , RefPoint.y - factor*config.carShape.bodyHght / 2 - factor*config.carShape.tireRadius };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		head->flip(0);
		tire1->flip(0);
		tire2->flip(0);
		body->flip(0);
		orientation = 180;
		break;
	case 90:
		bodyRef = RefPoint;
		headRef = { RefPoint.x - factor*config.carShape.bodyHght / 2,RefPoint.y };
		tire1Ref = { RefPoint.x + factor*config.carShape.bodyHght / 2 + factor*config.carShape.tireRadius , RefPoint.y + factor*config.carShape.bodyWdth / 4 };
		tire2Ref = { RefPoint.x +factor* config.carShape.bodyHght / 2 + factor*config.carShape.tireRadius , RefPoint.y - factor*config.carShape.bodyWdth / 4 };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		head->flip(90);
		tire1->flip(90);
		tire2->flip(90);
		body->flip(90);
		orientation = 270; break;
	case 180:
		bodyRef = RefPoint;
		headRef = { RefPoint.x , RefPoint.y -factor* config.carShape.bodyHght / 2 };
		tire1Ref = { RefPoint.x +factor* config.carShape.bodyWdth / 4,RefPoint.y +factor* config.carShape.bodyHght / 2 +factor* config.carShape.tireRadius };
		tire2Ref = { RefPoint.x -factor* config.carShape.bodyWdth / 4 , RefPoint.y +factor* config.carShape.bodyHght / 2 + factor*config.carShape.tireRadius };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		head->flip(180);
		tire1->flip(270);
		tire2->flip(270);
		body->flip(0);
		orientation = 0;
		break;
	case 270:
		bodyRef = RefPoint;
		headRef = { RefPoint.x + factor*config.carShape.bodyHght / 2,RefPoint.y };
		tire1Ref = { RefPoint.x - factor*config.carShape.bodyHght / 2 - factor*config.carShape.tireRadius , RefPoint.y +factor* config.carShape.bodyWdth / 4 };
		tire2Ref = { RefPoint.x - factor*config.carShape.bodyHght / 2 - factor*config.carShape.tireRadius , RefPoint.y -factor* config.carShape.bodyWdth / 4 };
		head->setRefPoint(headRef);
		tire1->setRefPoint(tire1Ref);
		tire2->setRefPoint(tire2Ref);
		head->flip(270);
		tire1->flip(270);
		tire2->flip(270);
		body->flip(90);
		orientation = 90;
		break;
	}



}

void Car::move(int dx, int dy) {

	body->move(dx, dy);
	head->move(dx, dy);
	tire1->move(dx, dy);
	tire2->move(dx, dy);
	this->setRefPoint(body->getRef());


}
/*void Car::resize(double factor)
{
	body->resize(factor);
	tire1->resize(factor);
	tire2->resize(factor);
	head->resize(factor);

	point bodyRef = RefPoint;
	point tire1Ref = { RefPoint.x - body->getwdth() / 4,RefPoint.y + body->gethght() /2+ tire1->getrad()  };
	tire1->setRefPoint(tire1Ref);
	point tire2Ref = { RefPoint.x + body->getwdth() / 4,RefPoint.y + body->gethght()/2 + tire2->getrad()  };
	tire2->setRefPoint(tire2Ref);
	point headRef = { RefPoint.x,RefPoint.y - body->gethght()/2 };
	head->setRefPoint(headRef);
	
	body->draw();
	tire1->draw();
	tire2->draw();
	head->flip(180);
	
	this->factor *= factor;
}*/
void Car::resize(double factor)
{
	point bodyref, tire1ref, tire2ref, headref;
	body->resize(factor);
	tire1->resize(factor);
	tire2->resize(factor);
	head->resize(factor);
	switch (orientation) {
	case 0:
		bodyref = RefPoint;
		body->setRefPoint(bodyref);
		tire1ref = { RefPoint.x - body->getwdth() / 4, RefPoint.y + body->gethght() / 2 + tire1->getrad() };
		tire1->setRefPoint(tire1ref);
		tire2ref = { RefPoint.x + body->getwdth() / 4, RefPoint.y + body->gethght() / 2 + tire2->getrad() };
		tire2->setRefPoint(tire2ref);
		headref = { RefPoint.x, RefPoint.y - body->gethght() / 2 };
		head->setRefPoint(headref);
		break;
	case 180:
		bodyref = RefPoint;
		body->setRefPoint(bodyref);
		headref = { RefPoint.x , RefPoint.y + body->gethght() / 2 };
		head->setRefPoint(headref);
		tire1ref = { RefPoint.x + body->getwdth() / 4,RefPoint.y - body->gethght() / 2 - tire1->getrad() };
		tire1->setRefPoint(tire1ref);
		tire2ref = { RefPoint.x - body->getwdth() / 4 , RefPoint.y - body->gethght() / 2 - tire1->getrad() };
		tire2->setRefPoint(tire2ref);
		break;
	case 90:
		bodyref = RefPoint;
		body->setRefPoint(bodyref);
		headref = { RefPoint.x + body->gethght() / 2,RefPoint.y };
		tire1ref = { RefPoint.x - body->gethght() / 2 - tire1->getrad() , RefPoint.y + body->getwdth() / 4 };
		tire2ref = { RefPoint.x - body->gethght() / 2 - tire1->getrad() , RefPoint.y - body->getwdth() / 4 };
		head->setRefPoint(headref);
		tire1->setRefPoint(tire1ref);
		tire2->setRefPoint(tire2ref);
		break;
		
	case 270:
		bodyref = RefPoint;
		body->setRefPoint(bodyref);
		headref = { RefPoint.x - body->gethght() / 2,RefPoint.y };
		tire1ref = { RefPoint.x + body->gethght() / 2 + tire1->getrad() , RefPoint.y + body->getwdth() / 4 };
		tire2ref = { RefPoint.x + body->gethght() / 2 + tire1->getrad() , RefPoint.y - body->getwdth() / 4 };
		head->setRefPoint(headref);
		tire1->setRefPoint(tire1ref);
		tire2->setRefPoint(tire2ref);
		break;
		
	}
	this->factor *= factor;

	
	




}




House::House(game* r_pGame, point ref) :shape(r_pGame, ref) {
	pGame = r_pGame;
	point bodyRef = ref;
	point triRef = {bodyRef.x,bodyRef.y-config.houseShape.bodyHght/2};
	body = new Rect(r_pGame, bodyRef, config.houseShape.bodyHght, config.houseShape.bodyWdth);
	head = new Equi_triangle(r_pGame, triRef,config.houseShape.bodyWdth, 0);

	



}
void House::draw() const {
	body->draw();
	head->draw();



}
void House::rotate(int orient) {
	switch (orient) {
		point bodyRef, triRef;
	case 0:
		bodyRef = RefPoint;
		triRef = { bodyRef.x + factor*config.houseShape.bodyHght/2,bodyRef.y };
		head->setRefPoint(triRef);
		head->rotate(orient);
		body->rotate(0);
		orientation = 90;
		break;
	case 90:
		bodyRef = RefPoint;
		triRef = { bodyRef.x,bodyRef.y + factor*config.houseShape.bodyHght / 2 };
		head->setRefPoint(triRef);
		body->rotate(90);
		head->rotate(orientation);
		orientation = 180;
		break;
	case 180:

		bodyRef = RefPoint;
		triRef = { bodyRef.x - factor*config.houseShape.bodyHght / 2,bodyRef.y };
		head->setRefPoint(triRef);
		head->rotate(orientation);
		body->rotate(0);
		orientation = 270;
		break;

	case 270:
		bodyRef = RefPoint;
		triRef = { bodyRef.x,bodyRef.y - factor*config.houseShape.bodyHght / 2 };
		head->setRefPoint(triRef);
		body->rotate(90);
		head->rotate(orientation);
		orientation = 0;

		break;
		


	}



}

void House::flip(int orient) {
	point bodyRef, triRef;
	switch (orient) {
	case 0:
		bodyRef = RefPoint;
		triRef = { bodyRef.x,bodyRef.y + factor * config.houseShape.bodyHght / 2 };
		head->setRefPoint(triRef);
		body->flip(0);
		head->flip(0);
		orientation = 180;
		break;
	case 90:
		bodyRef = RefPoint;
		triRef = { bodyRef.x - factor * config.houseShape.bodyHght / 2,bodyRef.y };
		head->setRefPoint(triRef);
		body->flip(90);
		head->flip(90);
		orientation = 270;
		break;
	case 180:
		bodyRef = RefPoint;
		triRef = { bodyRef.x,bodyRef.y - factor * config.houseShape.bodyHght / 2 };
		head->setRefPoint(triRef);
		body->flip(0);
		head->flip(180);
		orientation = 0;
		break;
	case 270:
		bodyRef = RefPoint;
		triRef = { bodyRef.x + factor * config.houseShape.bodyHght / 2,bodyRef.y };
		head->setRefPoint(triRef);
		head->flip(270);
		body->flip(90);
		orientation = 90;


	}




}
void House::resize(double factor)
{
	point headref, bodyRef;
	body->resize(factor);
	head->resize(factor);
	switch (orientation) {

	case 0:
		bodyRef = RefPoint;
		headref = { bodyRef.x,bodyRef.y - body->gethght() / 2 };
		head->setRefPoint(headref);
		break;
	case 90:
		bodyRef = RefPoint;
		headref = { bodyRef.x + body->gethght() / 2,bodyRef.y };
		head->setRefPoint(headref);
		break;
	case 180:
		bodyRef = RefPoint;
		headref = { bodyRef.x,bodyRef.y + body->gethght() / 2 };
		head->setRefPoint(headref);
		break;
	case 270:
		bodyRef = RefPoint;
		headref = { bodyRef.x - body->gethght() / 2,bodyRef.y };
		head->setRefPoint(headref);
		break;
	}this->factor *= factor;

}





void House::move(int dx, int dy) {
	head->move(dx, dy);
	body->move(dx, dy);
	this->setRefPoint(body->getRef());

}



Rocket::Rocket(game* r_pGame, point ref) :shape(r_pGame, ref) {
	point bodyRef = ref;
	point headRef = { bodyRef.x,bodyRef.y - config.rocketShape.bodyHght / 2 };
	point side1Ref = { bodyRef.x + config.rocketShape.bodyWdth / 2,bodyRef.y };
	point side2Ref = { bodyRef.x - config.rocketShape.bodyWdth / 2,bodyRef.y };
	point tailRef = { bodyRef.x,bodyRef.y + config.rocketShape.bodyHght / 2 };
	body = new Rect(r_pGame, bodyRef, config.rocketShape.bodyHght, config.rocketShape.bodyWdth);
	head = new circle(r_pGame, headRef, config.rocketShape.haedRadius);
	side1 = new Equi_triangle(r_pGame, side1Ref, config.rocketShape.triLen, 0);
	side2 = new Equi_triangle(r_pGame, side2Ref, config.rocketShape.triLen, 0);
	tail = new Equi_triangle(r_pGame, tailRef, config.rocketShape.triLen, 180);






}

void Rocket::draw() const {
	body->draw();
	head->draw();
	side1->draw();
	side2->draw();
	tail->draw();



}
void Rocket::rotate(int orient) {
	point bodyRef, headRef, side1Ref, side2Ref, tailRef;
	switch (orient) {
	case 0:
		bodyRef = RefPoint;
		headRef = { RefPoint.x + factor*config.rocketShape.bodyHght / 2,RefPoint.y };
		side1Ref = { RefPoint.x,RefPoint.y + factor*config.rocketShape.bodyWdth / 2 };
		side2Ref = { RefPoint.x,RefPoint.y - factor*config.rocketShape.bodyWdth / 2 };
		tailRef = { RefPoint.x - factor*config.rocketShape.bodyHght / 2,RefPoint.y };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		body->rotate(0);
		head->draw();
		side1->rotate(orient);
		side2->rotate(orient);
		tail->rotate(180);
		orientation = 90;
		break;
	case 90:
		bodyRef = RefPoint;
		headRef = {RefPoint.x,RefPoint.y+factor*config.rocketShape.bodyHght/2};
		side1Ref = { RefPoint.x - factor*config.rocketShape.bodyWdth / 2,RefPoint.y };
		side2Ref = { RefPoint.x + factor*config.rocketShape.bodyWdth / 2,RefPoint.y };
		tailRef = { RefPoint.x,RefPoint.y -factor* config.rocketShape.bodyHght / 2 };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		body->rotate(90);
		head->draw();
		side1->rotate(orient);
		side2->rotate(orient);
		tail->rotate(270);
		orientation = 180;
		break;
	case 180:

		bodyRef = RefPoint;
		headRef = { RefPoint.x -factor* config.rocketShape.bodyHght / 2,RefPoint.y };
		side1Ref = { RefPoint.x,RefPoint.y - factor*config.rocketShape.bodyWdth / 2 };
		side2Ref = { RefPoint.x,RefPoint.y +factor*config.rocketShape.bodyWdth / 2 };
		tailRef = { RefPoint.x + factor*config.rocketShape.bodyHght / 2,RefPoint.y };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		body->rotate(0);
		head->draw();
		side1->rotate(orient);
		side2->rotate(orient);
		tail->rotate(0);
		orientation = 270;
		break;
	case 270:
		bodyRef = RefPoint;
		headRef = { RefPoint.x,RefPoint.y -factor* config.rocketShape.bodyHght / 2 };
		side1Ref = { RefPoint.x +factor*config.rocketShape.bodyWdth / 2,RefPoint.y };
		side2Ref = { RefPoint.x - factor*config.rocketShape.bodyWdth / 2,RefPoint.y };
		tailRef = { RefPoint.x,RefPoint.y + factor*config.rocketShape.bodyHght / 2 };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		body->rotate(90);
		head->draw();
		side1->rotate(orient);
		side2->rotate(orient);
		tail->rotate(90);
		orientation = 0;
		break;
	}
	


}
void Rocket::flip(int orient) {
	point bodyRef, headRef, side1Ref, side2Ref, tailRef;
	switch (orient) {
	case 0:
		bodyRef = RefPoint;
		headRef = { RefPoint.x,RefPoint.y +factor* config.rocketShape.bodyHght / 2 };
		side1Ref = { RefPoint.x - factor*config.rocketShape.bodyWdth / 2,RefPoint.y };
		side2Ref = { RefPoint.x +factor* config.rocketShape.bodyWdth / 2,RefPoint.y };
		tailRef = { RefPoint.x,RefPoint.y - factor*config.rocketShape.bodyHght / 2 };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		head->flip(0);
		body->flip(0);
		side1->flip(0);
		side2->flip(0);
		tail->flip(180);
		orientation = 180;
		break;
	case 90:

		bodyRef = RefPoint;
		headRef = { RefPoint.x -factor* config.rocketShape.bodyHght / 2,RefPoint.y };
		side1Ref = { RefPoint.x,RefPoint.y - factor*config.rocketShape.bodyWdth / 2 };
		side2Ref = { RefPoint.x,RefPoint.y +factor* config.rocketShape.bodyWdth / 2 };
		tailRef = { RefPoint.x + factor*config.rocketShape.bodyHght / 2,RefPoint.y };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		head->flip(90);
		body->flip(90);
		side1->flip(90);
		side2->flip(90);
		tail->flip(270);
		orientation = 270;
		break;
	case 180:
		bodyRef = RefPoint;
		headRef = { RefPoint.x,RefPoint.y -factor* config.rocketShape.bodyHght / 2 };
		side1Ref = { RefPoint.x +factor* config.rocketShape.bodyWdth / 2,RefPoint.y };
		side2Ref = { RefPoint.x - factor*config.rocketShape.bodyWdth / 2,RefPoint.y};
		tailRef = { RefPoint.x,RefPoint.y +factor* config.rocketShape.bodyHght / 2 };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		head->flip(180);
		body->flip(0);
		side1->flip(180);
		side2->flip(180);
		tail->flip(0);
		orientation = 0;
		break;
	case 270:
		bodyRef = RefPoint;
		headRef = { RefPoint.x + factor*config.rocketShape.bodyHght / 2,RefPoint.y };
		side1Ref = { RefPoint.x,RefPoint.y + factor*config.rocketShape.bodyWdth / 2 };
		side2Ref = { RefPoint.x,RefPoint.y - factor*config.rocketShape.bodyWdth / 2 };
		tailRef = { RefPoint.x - factor*config.rocketShape.bodyHght / 2,RefPoint.y };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		head->flip(270);
		body->flip(90);
		side1->flip(270);
		side2->flip(270);
		tail->flip(90);
		orientation = 90;
		break;
		


	}
	



}
void Rocket::move(int dx, int dy) {
	body->move(dx, dy);
	head->move(dx, dy);
	side1->move(dx, dy);
	side2->move(dx, dy);
	tail->move(dx, dy);
	this->setRefPoint(body->getRef());
}



void Rocket::resize(double factor)
{
	point bodyref, headRef, tailRef, side1Ref, side2Ref;
	body->resize(factor);
	head->resize(factor);
	tail->resize(factor);
	side1->resize(factor);
	side2->resize(factor);
	switch (orientation) {
	case 0:
		bodyref = RefPoint;
		headRef = { RefPoint.x,RefPoint.y - body->gethght() / 2 };
		head->setRefPoint(headRef);
		side1Ref = { RefPoint.x + body->getwdth() / 2,RefPoint.y };
		side1->setRefPoint(side1Ref);
		side2Ref = { RefPoint.x - body->getwdth() / 2,RefPoint.y };
		side2->setRefPoint(side2Ref);
		tailRef = { RefPoint.x,RefPoint.y + body->gethght() / 2 };
		tail->setRefPoint(tailRef);
		break;
	case 90:
		bodyref = RefPoint;
		headRef = { RefPoint.x + body->gethght() / 2,RefPoint.y };
		side1Ref = { RefPoint.x,RefPoint.y + body->getwdth() / 2 };
		side2Ref = { RefPoint.x,RefPoint.y - body->getwdth() / 2 };
		tailRef = { RefPoint.x - body->gethght() / 2,RefPoint.y };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		break;
	case 180:
		bodyref = RefPoint;
		headRef = { RefPoint.x,RefPoint.y + body->gethght() / 2 };
		head->setRefPoint(headRef);
		side1Ref = { RefPoint.x - body->getwdth() / 2,RefPoint.y };
		side1->setRefPoint(side1Ref);
		 side2Ref = { RefPoint.x + body->getwdth() / 2,RefPoint.y };
		side2->setRefPoint(side2Ref);
		 tailRef = { RefPoint.x,RefPoint.y - body->gethght() / 2 };
		tail->setRefPoint(tailRef);
		break;
	case 270:
		bodyref = RefPoint;
		headRef = { RefPoint.x + body->gethght() / 2,RefPoint.y };
		side1Ref = { RefPoint.x,RefPoint.y + body->getwdth() / 2 };
		side2Ref = { RefPoint.x,RefPoint.y - body->getwdth() / 2 };
		tailRef = { RefPoint.x - body->gethght() / 2,RefPoint.y };
		head->setRefPoint(headRef);
		side1->setRefPoint(side1Ref);
		side2->setRefPoint(side2Ref);
		tail->setRefPoint(tailRef);
		break;
	}this->factor *= factor;


}









Pen::Pen(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	point bodyref = ref;
	point topref = { ref.x , ref.y - config.Penshape.bodyheight / 2 };
	point baseref = { ref.x,ref.y + config.Penshape.bodyheight / 2 };
	top = new Equi_triangle(pGame, topref, config.Penshape.bodywdth, 0);
	body = new Rect(pGame, bodyref, config.Penshape.bodyheight, config.Penshape.bodywdth);
	base = new circle(pGame, baseref, config.Penshape.bodywdth / 2);
}


void Pen::draw() const
{
	body->draw();
	top->draw();
	base->draw();
}




void Pen::flip(int orient)
{
	point refbase, refbody, reftop;
	switch (orient) {
	case 0:
		refbody = RefPoint;
		refbase = { RefPoint.x,RefPoint.y -factor* config.Penshape.bodyheight / 2 };
		reftop = { RefPoint.x,RefPoint.y +factor* config.Penshape.bodyheight / 2 };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		top->flip(orient);
		body->flip(0);
		base->flip(orient);

		orientation = 180;
		break;
	case 180:
		refbody = RefPoint;
		refbase = { RefPoint.x,RefPoint.y + factor*config.Penshape.bodyheight / 2 };
		reftop = { RefPoint.x,RefPoint.y -factor* config.Penshape.bodyheight / 2 };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		top->flip(orient);
		body->flip(0);
		base->flip(orient);
		orientation = 0;
		break;
	case 90:
		refbody = RefPoint;
		refbase = { RefPoint.x +factor* config.Penshape.bodyheight / 2, RefPoint.y };
		reftop = { RefPoint.x - factor*config.Penshape.bodyheight / 2, RefPoint.y };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		top->flip(orient);
		body->flip(90);
		base->flip(orient);
		orientation = 270;

		break;
	case 270:
		refbody = RefPoint;
		refbase = { RefPoint.x -factor* config.Penshape.bodyheight / 2, RefPoint.y };
		reftop = { RefPoint.x + factor*config.Penshape.bodyheight / 2, RefPoint.y };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		top->flip(orient);
		body->flip(90);
		base->flip(orient);
		orientation = 90;
		break;
	}
	
}



void Pen::move(int dx, int dy) {

	body->move(dx, dy);
	base->move(dx, dy);
	top->move(dx, dy);
	this->setRefPoint(body->getRef());




}


void Pen::rotate(int orient) {
	point refbase, refbody, reftop;
	switch (orient) {
	case 0:
		refbody = RefPoint;
		refbody = RefPoint;
		refbase = { RefPoint.x - factor * config.Penshape.bodyheight / 2, RefPoint.y };
		reftop = { RefPoint.x + factor * config.Penshape.bodyheight / 2, RefPoint.y };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		body->rotate(0);
		base->rotate(orient);
		top->rotate(orient);
		orientation = 90;
		break;
	case 90:
		refbody = RefPoint;
		refbase = { RefPoint.x,RefPoint.y - factor * config.Penshape.bodyheight / 2 };
		reftop = { RefPoint.x,RefPoint.y + factor * config.Penshape.bodyheight / 2 };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		body->rotate(90);
		top->rotate(orient);
		base->rotate(orient);
		orientation = 180;
		break;
	case 180:
		refbody = RefPoint;
		refbase = { RefPoint.x + factor * config.Penshape.bodyheight / 2, RefPoint.y };
		reftop = { RefPoint.x - factor * config.Penshape.bodyheight / 2, RefPoint.y };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		body->rotate(0);
		top->rotate(orient);
		base->rotate(orient);
		orientation = 270;
		break;
	case 270:
		refbody = RefPoint;
		refbase = { RefPoint.x,RefPoint.y + factor * config.Penshape.bodyheight / 2 };
		reftop = { RefPoint.x,RefPoint.y - factor * config.Penshape.bodyheight / 2 };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		body->rotate(90);
		top->rotate(orient);
		base->rotate(orient);
		orientation = 0;
		break;
		
	}








}
void Pen::resize(double factor)

{

	point refbody, refbase, reftop;
	body->resize(factor);
	top->resize(factor);
	base->resize(factor);
	switch (orientation) {
	case 0:
		refbody = RefPoint;
		refbase = { RefPoint.x,RefPoint.y +body->gethght()/2};
		reftop = { RefPoint.x,RefPoint.y - body->gethght()/2};
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		break;
	case 90:
		refbody = RefPoint;
		refbody = RefPoint;
		refbase = { RefPoint.x -body->gethght()/2, RefPoint.y};
		reftop = { RefPoint.x +body->gethght()/2, RefPoint.y};
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		break;
	case 180:
		refbody = RefPoint;
		refbase = { RefPoint.x,RefPoint.y -body->gethght()/2};
		reftop = { RefPoint.x,RefPoint.y + body->gethght() / 2 };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		break;
	case 270:
		refbody = RefPoint;
		refbase = { RefPoint.x + body->gethght() / 2, RefPoint.y };
		reftop = { RefPoint.x - body->gethght() / 2, RefPoint.y };
		body->setRefPoint(refbody);
		base->setRefPoint(refbase);
		top->setRefPoint(reftop);
		break;

	

	}
	this->factor *= factor;
}



Tree::Tree(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseRef = ref;
	point tri1Ref = { ref.x, ref.y -factor* config.tree.baseHeight / 2 - factor*config.tree.baseWdth };
	point tri2Ref = { ref.x, ref.y - factor*config.tree.baseHeight / 2 -factor* 2 * config.tree.baseWdth };
	point tri3Ref = { ref.x, ref.y - factor* config.tree.baseHeight / 2 -factor* 3 * config.tree.baseWdth };
	base = new Rect(pGame, baseRef, 2*config.tree.baseHeight, config.tree.baseWdth);
	tri1 = new Equi_triangle(pGame, tri1Ref, config.tree.triwdth);
	tri2 = new Equi_triangle(pGame, tri2Ref, config.tree.triwdth);
	tri3 = new Equi_triangle(pGame, tri3Ref, config.tree.triwdth);
}
void Tree::rotate(int orient) {
	point baseRef, tri1Ref, tri2Ref, tri3Ref;
	switch (orient) {
	case 0:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x + factor * config.tree.baseHeight / 2 + factor * config.tree.baseWdth ,RefPoint.y};
		tri2Ref = { RefPoint.x + factor * config.tree.baseHeight / 2 + factor * 2 * config.tree.baseWdth ,RefPoint.y};
		tri3Ref = { RefPoint.x + factor * config.tree.baseHeight / 2 + factor * 3 * config.tree.baseWdth,RefPoint.y };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->rotate(0);
		tri1->rotate(0);
		tri2->rotate(0);
		tri3->rotate(0);
		orientation = 90;
		break;
	case 90:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x,RefPoint.y + factor * config.tree.baseHeight / 2 + factor * config.tree.baseWdth };
		tri2Ref = { RefPoint.x,RefPoint.y + factor * config.tree.baseHeight / 2 + 2*factor * config.tree.baseWdth };
		tri3Ref = { RefPoint.x,RefPoint.y + factor * config.tree.baseHeight / 2 + 3*factor * config.tree.baseWdth };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->rotate(90);
		tri1->rotate(90);
		tri2->rotate(90);
		tri3->rotate(90);
		orientation = 180;
		break;
	case 180:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x - factor * config.tree.baseHeight / 2 - factor * config.tree.baseWdth ,RefPoint.y };
		tri2Ref = { RefPoint.x - factor * config.tree.baseHeight / 2 - factor * 2 * config.tree.baseWdth ,RefPoint.y };
		tri3Ref = { RefPoint.x - factor * config.tree.baseHeight / 2 - factor * 3 * config.tree.baseWdth,RefPoint.y };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->rotate(0);
		tri1->rotate(180);
		tri2->rotate(180);
		tri3->rotate(180);
		orientation = 270;
		break;
	case 270:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x,RefPoint.y - factor * config.tree.baseHeight / 2 - factor * config.tree.baseWdth };
		tri2Ref = { RefPoint.x,RefPoint.y - factor * config.tree.baseHeight / 2 - 2 * factor * config.tree.baseWdth };
		tri3Ref = { RefPoint.x,RefPoint.y - factor * config.tree.baseHeight / 2 - 3 * factor * config.tree.baseWdth };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->rotate(90);
		tri1->rotate(270);
		tri2->rotate(270);
		tri3->rotate(270);
		orientation = 0;
		break;



	}






}


void Tree::flip(int orient) {
	point baseRef, tri1Ref, tri2Ref, tri3Ref;
	switch (orient) {
	case 0:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x,RefPoint.y + factor * config.tree.baseHeight / 2 + factor * config.tree.baseWdth };
		tri2Ref = { RefPoint.x,RefPoint.y + factor * config.tree.baseHeight / 2 + 2 * factor * config.tree.baseWdth };
		tri3Ref = { RefPoint.x,RefPoint.y + factor * config.tree.baseHeight / 2 + 3 * factor * config.tree.baseWdth };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->flip(0);
		tri1->flip(0);
		tri2->flip(0);
		tri3->flip(0);
		orientation = 180;
		break;
	case 90:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x - factor * config.tree.baseHeight / 2 - factor * config.tree.baseWdth ,RefPoint.y };
		tri2Ref = { RefPoint.x - factor * config.tree.baseHeight / 2 - factor * 2 * config.tree.baseWdth ,RefPoint.y };
		tri3Ref = { RefPoint.x - factor * config.tree.baseHeight / 2 - factor * 3 * config.tree.baseWdth,RefPoint.y };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->flip(90);
		tri1->flip(90);
		tri2->flip(90);
		tri3->flip(90);
		orientation = 270;
		break;
	case 180:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x,RefPoint.y - factor * config.tree.baseHeight / 2 - factor * config.tree.baseWdth };
		tri2Ref = { RefPoint.x,RefPoint.y - factor * config.tree.baseHeight / 2 - 2 * factor * config.tree.baseWdth };
		tri3Ref = { RefPoint.x,RefPoint.y - factor * config.tree.baseHeight / 2 - 3 * factor * config.tree.baseWdth };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->flip(0);
		tri1->flip(180);
		tri2->flip(180);
		tri3->flip(180);
		orientation = 0;
		break;
	case 270:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x + factor * config.tree.baseHeight / 2 + factor * config.tree.baseWdth ,RefPoint.y };
		tri2Ref = { RefPoint.x + factor * config.tree.baseHeight / 2 + factor * 2 * config.tree.baseWdth ,RefPoint.y };
		tri3Ref = { RefPoint.x + factor * config.tree.baseHeight / 2 + factor * 3 * config.tree.baseWdth,RefPoint.y };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		base->flip(90);
		tri1->flip(270);
		tri2->flip(270);
		tri3->flip(270);
		orientation = 90;
		break;



	}
	






}
void Tree::draw() const
{
	base->draw();
	tri1->draw();
	tri2->draw();
	tri3->draw();
}
void Tree::move(int dx, int dy) {
	base->move(dx, dy);
	tri1->move(dx,dy);
	tri2->move(dx,dy);
	tri3->move(dx,dy);
	this->RefPoint = base->getRef();
	

}



void Tree::resize(double factor)
{
	point baseRef, tri1Ref, tri2Ref,tri3Ref;
	base->resize(factor);
	tri1->resize(factor);
	tri2->resize(factor);
	switch (orientation) {
	case 0:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x,RefPoint.y - base->gethght()/2 -base->getwdth()};
		tri2Ref = { RefPoint.x,RefPoint.y - base->gethght() / 2 - 2*base->getwdth()};
		tri3Ref = { RefPoint.x,RefPoint.y - base->gethght() / 2 - 3 *base->getwdth()};
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		break;
	case 90:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x + base->gethght()/2 + base->getwdth() ,RefPoint.y};
		tri2Ref = { RefPoint.x + base->gethght() / 2 + 2 * base->getwdth() ,RefPoint.y };
		tri3Ref = { RefPoint.x + base->gethght() / 2 +  3 * base->getwdth() ,RefPoint.y };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		break;
	case 180:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x,RefPoint.y +base->gethght()/2 + base->getwdth() };
		tri2Ref = { RefPoint.x,RefPoint.y + base->gethght() / 2 + 2 * base->getwdth() };
		tri3Ref = { RefPoint.x,RefPoint.y + base->gethght() / 2 + 3 * base->getwdth() };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		break;
	case 270:
		baseRef = RefPoint;
		tri1Ref = { RefPoint.x - base->gethght() / 2 - base->getwdth(),RefPoint.y };
		tri2Ref = { RefPoint.x - base->gethght() / 2 - 2 * base->getwdth(),RefPoint.y };
		tri3Ref = { RefPoint.x - base->gethght() / 2 - 3 * base->getwdth(),RefPoint.y };
		tri1->setRefPoint(tri1Ref);
		tri2->setRefPoint(tri2Ref);
		tri3->setRefPoint(tri3Ref);
		break;

	}this->factor *= factor;


}



