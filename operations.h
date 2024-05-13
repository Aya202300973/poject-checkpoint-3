#pragma once

class game;
/////////////////////////////////// class operation  //////////////////
//Base class of all operations supported by the application
class operation
{
protected:
	game* pGame;	//pointer to the game class
public:
	operation(game* r_pGame);

	//Function Act:
	//Implements the action that should be taken by this operation
	//Should be overriden by derived classes
	virtual void Act() = 0;
};
/////////////////////////////////// class operAddSign  //////////////////
//Responsible for 
//1- collectign data about a new Sign shape to add
//2- Adding the new shape to the list of shapes (throgh the grid class)
class operAddSign:public operation
{
public:
	operAddSign(game* r_pGame);
	virtual void Act();
};
class operAddCar :public operation {

public:
	operAddCar (game* r_pGame);
	virtual void Act()override;


};
class operFlip :public operation {

public:
	operFlip(game* r_pGame);
	virtual void Act()override;



};


class operResizeUp : public operation {

public:
	operResizeUp(game* r_pGame);
	virtual void Act()override;


};
class operResizeDown : public operation {

public:
	operResizeDown(game* r_pGame);
	virtual void Act()override;


};
class operRotate : public operation {

public:
	operRotate(game* r_pGame);
	virtual void Act()override;


};


class operAddRocket :public operation {
public:
	operAddRocket(game* r_pGame);
	virtual void Act()override;

};
class operAddPEN :public operation {
public:
	operAddPEN(game* r_pGame);
	virtual void Act();
};

class operDEL : public operation
{
public:
	operDEL(game* r_pGame);
	virtual void Act();


};


class operAddTree :public operation {
public:
	operAddTree(game* r_pGame);
	virtual void Act();
};


class operAddHouse :public operation {
public:
	operAddHouse(game* r_pGame);
	virtual void Act()override;

};


class operSave :public operation {

public:
	operSave(game* r_pGame);
	virtual void Act()override;
};
class operSelect :public operation {

public:
	operSelect(game* r_pGame);
	virtual void Act()override;
};
class operRefresh :public operation {

public:
	operRefresh(game* r_pGame);
	virtual void Act()override;
};
class operHint :public operation {

public:
	operHint(game* r_pGame);
	virtual void Act()override;
};