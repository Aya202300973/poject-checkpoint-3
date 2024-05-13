#include "game.h"
#include "gameConfig.h"



game::game()
{

	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
	scoreandlevel(0, 1, 5);
}


game::~game()
{
	delete pWind;
	delete shapesGrid;
}


int game::getscore()const
{
	return score;
}

int game::getlevel()const
{
	return level;
}

int game::getlives()const
{
	return lives;
}

void game::setscore(int sc)
{
	score = sc;
}

void game::setlevel(int lev)
{
	level = lev;
}

void game::setlives(int liv)
{
	lives = liv;
}

//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y) 
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{	
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}

operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op=nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		break;
	case ITM_CAR:
		op = new operAddCar(this);
		break;
	case ITM_FLIP:
		op = new operFlip(this);
		break;
	case ITM_Enlarge:
		op = new operResizeUp(this);
		break;
	case ITM_Minimize:
		op = new operResizeDown(this);
		break;
	case ITM_Rotate:
		op = new operRotate(this);
		break;
	case ITM_ROCKET:
		op = new operAddRocket(this);
		break;
	case ITM_PEN:
		op = new operAddPEN(this);
		break;
	case ITM_Trash:
		op = new operDEL(this);
		break;
	case ITM_TREE:
		op = new operAddTree(this);
		break;
	case ITM_HOUSE:
		op = new operAddHouse(this);
		break;

	}
	return op;
}


//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar
	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}

void game::scoreandlevel(int score, int level, int lives)
{
	int x = ITM_CNT * config.toolbarItemWidth;
	int y = 0.5 * config.toolBarHeight;
	pWind->SetPen(BLACK);
	pWind->SetFont(11, BOLD, BY_NAME, "Arial");
	string msg = "your score is " + to_string(score) + " your level is " + to_string(level) + " your lives are " + to_string(lives);
	pWind->DrawString(x, y, msg);

	
}
void game::handleKeyPress(char K) {
	if (!shapesGrid || !shapesGrid->getActiveShape()) return;

	int Step = 50;
	shape* activeShape = shapesGrid->getActiveShape();
	
	switch (K) {
	case 8: //up
		activeShape->move(0, -Step);
		break;
	case 2://down 
		activeShape->move(0, Step);
		break;
	case 4: //right 
		activeShape->move(-Step, 0);
		break;
	case 6://left 
		activeShape->move(Step, 0);
		break;
	}

	shapesGrid->draw();
}

void game::printItm(toolbarItem clickedItem) const {
	string msg;
	switch (clickedItem)
	{

	case ITM_SIGN:
		msg = "You clicked item: Sign";
			printMessage(msg);
		break;
	case ITM_TREE:
		msg = "You clicked item: Tree";
		printMessage(msg);
		break;
	case ITM_CAR:
		msg = "You clicked item: Car";
		printMessage(msg);
		break;
	case ITM_ROCKET:
		msg = "You clicked item: Rocket";
		printMessage(msg);
		break;
	case ITM_HOUSE:
		msg = "You clicked item: House";
		printMessage(msg);
		break;
	case ITM_PEN:
		msg = "You clicked item: Pen";
		printMessage(msg);
		break;
	case ITM_Save:
		msg = "You clicked item: Save";
		printMessage(msg);
		break;
	case ITM_Enlarge:
		msg = "You clicked item: Resize Up";
		printMessage(msg);
		break;
	case ITM_Minimize:
		msg = "You clicked item: Resize Down";
		printMessage(msg);
		break;
	case ITM_Hint:
		msg = "You clicked item: Hint";
		printMessage(msg);
		break;
	case ITM_Rotate:
		msg = "You clicked item: Rotate";
		printMessage(msg);
		break;
	case ITM_Refresh:
		msg = "You clicked item: Refresh";
		printMessage(msg);
		break;
	case ITM_Select:
		msg = "You clicked item: Select";
		printMessage(msg);
		break;
	case ITM_Trash:
		msg = "You clicked item: Delete";
		printMessage(msg);
		break;
	case ITM_FLIP:
		msg = "You clicked item: Flip";
		printMessage(msg);
		break;
	case ITM_EXIT:
		msg = "You clicked item: Exit";
		printMessage(msg);
		break;
	case ITM_CNT:
		msg = "You clicked item: Count";
		printMessage(msg);
		break;
	default:
		break;
	}



}






void game::run()
{

	point ref = { config.RefX,config.RefY };
	//shapesGrid->clearGridArea();
	//p->flip(270);

	toolbarItem clickedshape = ITM_CNT;

	pWind->ChangeTitle("- - - SHAPE HUNT (CIE 101 / CIE202 - project) - - -");

	char K;
	do {
		int x, y;

			//while (pWind->GetKeyPress(K)) {
			//keytype ktype = pWind->GetKeyPress(K);
			//if(ktype==ARROW)
			//handleKeyPress(K);
		//}
		while (keytype key=pWind->GetKeyPress(K)) {
			if (key == ARROW)
				handleKeyPress(K);
				pWind->FlushKeyQueue();
		}
		if (pWind->GetMouseClick(x, y)) {
			if (y >= 0 && y < 60) {
				clickedshape = gameToolbar->getItemClicked(x);
				printItm(clickedshape);
				operation* op = createRequiredOperation(clickedshape);
				if (op)

					op->Act();
				shapesGrid->draw();

			}
			pWind->FlushMouseQueue();




		}


	} while (clickedshape != ITM_EXIT);
}