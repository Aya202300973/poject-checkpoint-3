#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1200, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 60,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = RED,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes

	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;
	struct {
		int bodyWdth = 200/4; int bodyHght = 75/4;
		int tireRadius = 25/4; int headLen = 30/4;



	}carShape;


	struct {
		int bodyWdth = 150; int bodyHght = 75;
	}houseShape;

	struct {
		int bodyWdth = 50; int bodyHght = 200;
		int haedRadius = bodyWdth / 2;
		int triLen = 50;

	}rocketShape;
	struct {
		int bodyheight = 200; int bodywdth = 75;
	}Penshape;
	struct {
		int baseWdth = 20/2, baseHeight = 80/2;
		int triwdth = 100/2;
	}tree;
}config;



enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,
	ITM_TREE,
	ITM_CAR,
	ITM_ROCKET,
	ITM_HOUSE,
	ITM_PEN,
	ITM_Save,
	ITM_Enlarge,
	ITM_Minimize,
	ITM_Hint,
	ITM_Rotate,
	ITM_Refresh,
	ITM_Select,
	ITM_Trash,
	ITM_FLIP,
	ITM_EXIT,
	ITM_CNT		//no. of toolbar items ==> This should be the last line in this enum

};
