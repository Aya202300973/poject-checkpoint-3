#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddCar::operAddCar(game* r_pGame):operation(r_pGame) {


}
void operAddCar::Act() {
	
	window* pw = pGame->getWind();


	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;
	
	point CarShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Car(pGame, CarShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);


}
operFlip::operFlip(game* r_pGame) :operation(r_pGame) {


}
void operFlip::Act() {
	grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape()) {

		shape* psh = pGrid->getActiveShape();
		int orientation = psh->getOrientatiion();
		psh->flip(orientation);
	

	}


}
operResizeUp::operResizeUp(game* r_pGame) :operation(r_pGame) {
}
void operResizeUp::Act() {

	grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape()) {
		shape* psh = pGrid->getActiveShape();
		double factor = 2.0;
		psh->resize(factor);

	}
}
operResizeDown::operResizeDown(game* r_pGame) :operation(r_pGame) {

}
void operResizeDown::Act() {

	grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape()) {
		shape* psh = pGrid->getActiveShape();
		double factor = 0.5;
		psh->resize(factor);
	}


}



/*operAddPEN::operAddPEN(game* r_pGame) :operation(r_pGame)
{

}

void operAddPEN::Act()
{
	window* pw = pGame->getWind();
	grid* pg = pGame->getGrid();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape
	pg->deleteActiveShape();
	
	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the pen shape ref point
	point penShapeRef = { xGrid,yGrid };

	//create a pen shape
	shape* psh = new Pen(pGame, penShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}*/
operRotate::operRotate(game* r_pGame):operation(r_pGame) {


}
void operRotate::Act() {

	grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape()) {

		shape* psh = pGrid->getActiveShape();
		int orientation = psh->getOrientatiion();
		psh->rotate(orientation);


	}

}


operAddRocket::operAddRocket(game* r_pGame) :operation(r_pGame)
{
}

void operAddRocket::Act()
{
	window* pw = pGame->getWind();
	grid* pg = pGame->getGrid();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape
	pg->deleteActiveShape();

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the pen shape ref point
	point penShapeRef = { xGrid,yGrid };

	//create a pen shape
	shape* psh = new Rocket(pGame, penShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

operAddPEN::operAddPEN(game* r_pGame) :operation(r_pGame)
{

}

void operAddPEN::Act()
{
	window* pw = pGame->getWind();
	grid* pg = pGame->getGrid();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape
	pg->deleteActiveShape();

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the pen shape ref point
	point penShapeRef = { xGrid,yGrid };

	//create a pen shape
	shape* psh = new Pen(pGame, penShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operDEL::operDEL(game* r_pGame) : operation(r_pGame)
{
}

void operDEL::Act()
{
	grid* grid = pGame->getGrid();
	grid->deleteActiveShape();

}



operAddTree::operAddTree(game* r_pGame) :operation(r_pGame)
{

}

void operAddTree::Act()
{
	window* pw = pGame->getWind();
	grid* pg = pGame->getGrid();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape
	pg->deleteActiveShape();

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the pen shape ref point
	point treeShapeRef = { xGrid,yGrid };

	//create a pen shape
	shape* psh = new Tree(pGame, treeShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddHouse::operAddHouse(game* r_pGame) :operation(r_pGame)
{
}

void operAddHouse::Act()
{
	window* pw = pGame->getWind();
	grid* pg = pGame->getGrid();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape
	pg->deleteActiveShape();

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the pen shape ref point
	point penShapeRef = { xGrid,yGrid };

	//create a House shape
	shape* psh = new House(pGame, penShapeRef);

	//Add the shape to the grid
	pg->setActiveShape(psh);
}


operSave::operSave(game* r_pGame) :operation(r_pGame)
{
}

void operSave::Act()
{
}

operSelect::operSelect(game* r_pGame) :operation(r_pGame)
{
}

void operSelect::Act()
{
}
operRefresh::operRefresh(game* r_pGame) :operation(r_pGame)
{
}

void operRefresh::Act()
{
}

operHint::operHint(game* r_pGame) :operation(r_pGame)
{
}

void operHint::Act()
{
}