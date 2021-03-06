//
// impressionistUI.h
//
// The user interface part for the program.
//


#include <FL/fl_ask.h>

#include <math.h>

#include "impressionistUI.h"
#include "impressionistDoc.h"

/*
//------------------------------ Widget Examples -------------------------------------------------
Here is some example code for all of the widgets that you may need to add to the 
project.  You can copy and paste these into your code and then change them to 
make them look how you want.  Descriptions for all of the widgets here can be found 
in links on the fltk help session page.

//---------Window/Dialog and Menubar-----------------------------------
	
	//----To install a window--------------------------
	Fl_Window* myWindow = new Fl_Window(600, 300, "MyWindow");
		myWindow->user_data((void*)(this));	// record self to be used by static callback functions
		
		// install menu bar
		myMenubar = new Fl_Menu_Bar(0, 0, 600, 25);
		Fl_Menu_Item ImpressionistUI::myMenuItems[] = {
			{ "&File",		0, 0, 0, FL_SUBMENU },
				{ "&Load...",	FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load },
				{ "&Save...",	FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save }.
				{ "&Quit",			FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
				{ 0 },
			{ "&Edit",		0, 0, 0, FL_SUBMENU },
				{ "&Copy",FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_copy, (void *)COPY },
				{ "&Cut",	FL_ALT + 'x', (Fl_Callback *)ImpressionistUI::cb_cut, (void *)CUT },
				{ "&Paste",	FL_ALT + 'v', (Fl_Callback *)ImpressionistUI::cb_paste, (void *)PASTE },
				{ 0 },
			{ "&Help",		0, 0, 0, FL_SUBMENU },
				{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
				{ 0 },
			{ 0 }
		};
		myMenubar->menu(myMenuItems);
    m_mainWindow->end();

	//----The window callback--------------------------
	// One of the callbacks
	void ImpressionistUI::cb_load(Fl_Menu_* o, void* v) 
	{	
		ImpressionistDoc *pDoc=whoami(o)->getDocument();

		char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
		if (newfile != NULL) {
			pDoc->loadImage(newfile);
		}
	}


//------------Slider---------------------------------------

	//----To install a slider--------------------------
	Fl_Value_Slider * mySlider = new Fl_Value_Slider(10, 80, 300, 20, "My Value");
	mySlider->user_data((void*)(this));	// record self to be used by static callback functions
	mySlider->type(FL_HOR_NICE_SLIDER);
    mySlider->labelfont(FL_COURIER);
    mySlider->labelsize(12);
	mySlider->minimum(1);
	mySlider->maximum(40);
	mySlider->step(1);
	mySlider->value(m_nMyValue);
	mySlider->align(FL_ALIGN_RIGHT);
	mySlider->callback(cb_MyValueSlides);

	//----The slider callback--------------------------
	void ImpressionistUI::cb_MyValueSlides(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyValue=int( ((Fl_Slider *)o)->value() ) ;
	}
	

//------------Choice---------------------------------------
	
	//----To install a choice--------------------------
	Fl_Choice * myChoice = new Fl_Choice(50,10,150,25,"&myChoiceLabel");
	myChoice->user_data((void*)(this));	 // record self to be used by static callback functions
	Fl_Menu_Item ImpressionistUI::myChoiceMenu[3+1] = {
	  {"one",FL_ALT+'p', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)ONE},
	  {"two",FL_ALT+'l', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)TWO},
	  {"three",FL_ALT+'c', (Fl_Callback *)ImpressionistUI::cb_myChoice, (void *)THREE},
	  {0}
	};
	myChoice->menu(myChoiceMenu);
	myChoice->callback(cb_myChoice);
	
	//-----The choice callback-------------------------
	void ImpressionistUI::cb_myChoice(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI *)(o->user_data()));
		ImpressionistDoc* pDoc=pUI->getDocument();

		int type=(int)v;

		pDoc->setMyType(type);
	}


//------------Button---------------------------------------

	//---To install a button---------------------------
	Fl_Button* myButton = new Fl_Button(330,220,50,20,"&myButtonLabel");
	myButton->user_data((void*)(this));   // record self to be used by static callback functions
	myButton->callback(cb_myButton);

	//---The button callback---------------------------
	void ImpressionistUI::cb_myButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI* pUI=((ImpressionistUI*)(o->user_data()));
		ImpressionistDoc* pDoc = pUI->getDocument();
		pDoc->startPainting();
	}


//---------Light Button------------------------------------
	
	//---To install a light button---------------------
	Fl_Light_Button* myLightButton = new Fl_Light_Button(240,10,150,25,"&myLightButtonLabel");
	myLightButton->user_data((void*)(this));   // record self to be used by static callback functions
	myLightButton->callback(cb_myLightButton);

	//---The light button callback---------------------
	void ImpressionistUI::cb_myLightButton(Fl_Widget* o, void* v)
	{
		ImpressionistUI *pUI=((ImpressionistUI*)(o->user_data()));

		if (pUI->myBool==TRUE) pUI->myBool=FALSE;
		else pUI->myBool=TRUE;
	}

//----------Int Input--------------------------------------

    //---To install an int input-----------------------
	Fl_Int_Input* myInput = new Fl_Int_Input(200, 50, 5, 5, "&My Input");
	myInput->user_data((void*)(this));   // record self to be used by static callback functions
	myInput->callback(cb_myInput);

	//---The int input callback------------------------
	void ImpressionistUI::cb_myInput(Fl_Widget* o, void* v)
	{
		((ImpressionistUI*)(o->user_data()))->m_nMyInputValue=int( ((Fl_Int_Input *)o)->value() );
	}

//------------------------------------------------------------------------------------------------
*/

//------------------------------------- Help Functions --------------------------------------------

//------------------------------------------------------------
// This returns the UI, given the menu item.  It provides a
// link from the menu items to the UI
//------------------------------------------------------------
ImpressionistUI* ImpressionistUI::whoami(Fl_Menu_* o)	
{
	return ( (ImpressionistUI*)(o->parent()->user_data()) );
}


//--------------------------------- Callback Functions --------------------------------------------

//------------------------------------------------------------------
// Brings up a file chooser and then loads the chosen image
// This is called by the UI when the load image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_load_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
	if (newfile != NULL) {
		pDoc->loadImage(newfile);
	}
}


void ImpressionistUI::cb_load_another_image(Fl_Menu_* o, void* v){
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
	if (newfile != NULL) {
		pDoc->loadAnotherImage(newfile);
	}
}
void ImpressionistUI::cb_load_edge_image(Fl_Menu_* o, void* v){
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName() );
	if (newfile != NULL) {
		pDoc->loadEdgeImage(newfile);
	}
}

void ImpressionistUI::cb_load_dissolve_image(Fl_Menu_* o, void* v) {
	ImpressionistDoc *pDoc = whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Open File?", "*.bmp", pDoc->getImageName());
	if (newfile != NULL) {
		pDoc->loadDissolveImage(newfile);
	}
}

void ImpressionistUI::cb_swap(Fl_Menu_* o, void* v){
	ImpressionistDoc *pDoc = whoami(o)->getDocument();
	pDoc->swapImage();
}


//------------------------------------------------------------------
// Brings up a file chooser and then saves the painted image
// This is called by the UI when the save image menu item is chosen
//------------------------------------------------------------------
void ImpressionistUI::cb_save_image(Fl_Menu_* o, void* v) 
{
	ImpressionistDoc *pDoc=whoami(o)->getDocument();

	char* newfile = fl_file_chooser("Save File?", "*.bmp", "save.bmp" );
	if (newfile != NULL) {
		pDoc->saveImage(newfile);
	}
}

//-------------------------------------------------------------
// Brings up the paint dialog
// This is called by the UI when the brushes menu item
// is chosen
//-------------------------------------------------------------
void ImpressionistUI::cb_brushes(Fl_Menu_* o, void* v) 
{
	whoami(o)->m_brushDialog->show();
}

//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas(Fl_Menu_* o, void* v)
{
	ImpressionistDoc* pDoc=whoami(o)->getDocument();

	pDoc->clearCanvas();
}

void ImpressionistUI::cb_colors(Fl_Menu_ *o, void *v) {
	whoami(o)->m_colorsDialog->show();
}

//------------------------------------------------------------
// Causes the Impressionist program to exit
// Called by the UI when the quit menu item is chosen
//------------------------------------------------------------
void ImpressionistUI::cb_exit(Fl_Menu_* o, void* v) 
{
	whoami(o)->m_mainWindow->hide();
	whoami(o)->m_brushDialog->hide();

}

void ImpressionistUI::cb_orginal_image(Fl_Menu_* o, void* v)
{
	ImpressionistDoc* pDoc=whoami(o)->getDocument();
	pDoc->switchOriginalImage();

}

void ImpressionistUI::cb_edge_image(Fl_Menu_* o, void* v)
{
	ImpressionistDoc* pDoc=whoami(o)->getDocument();
	pDoc->switchEdgeImage();
}

void ImpressionistUI::cb_another_image(Fl_Menu_* o, void* v)
{
	ImpressionistDoc* pDoc=whoami(o)->getDocument();
	pDoc->switchAnotherImage();
}

void ImpressionistUI::cb_filterKernal(Fl_Menu_ *o, void *v) {
	whoami(o)->m_filterHeightInput->value("1");
	whoami(o)->m_filterWidthInput->value("1");
	whoami(o)->m_filterSizeDialog->show();
}


//-----------------------------------------------------------
// Brings up an about dialog box
// Called by the UI when the about menu item is chosen
//-----------------------------------------------------------
void ImpressionistUI::cb_about(Fl_Menu_* o, void* v) 
{
	fl_message("Impressionist FLTK version for COMP4411, Fall 2015");
}

void ImpressionistUI::cb_undo(Fl_Menu_ *o, void *v) {
	ImpressionistDoc *pDoc = whoami(o)->getDocument();
	pDoc->undo();
}

//------- UI should keep track of the current for all the controls for answering the query from Doc ---------
//-------------------------------------------------------------
// Sets the type of brush to use to the one chosen in the brush 
// choice.  
// Called by the UI when a brush is chosen in the brush choice
//-------------------------------------------------------------
void ImpressionistUI::cb_brushChoice(Fl_Widget* o, void* v)
{
	ImpressionistUI* pUI=((ImpressionistUI *)(o->user_data()));
	ImpressionistDoc* pDoc=pUI->getDocument();

	int type=(int)v;
	pDoc->setBrushType(type);
	
	switch (type) {
		case BRUSH_POINTS:
		case BRUSH_CIRCLES:
		case BRUSH_SCATTERED_POINTS:
		case BRUSH_SCATTERED_CIRCLES:
		case BRUSH_TRIANGLE:
		case BRUSH_SCATTERED_TRIANGLE:
			pUI->m_BrushLineWidthSlider->deactivate();
			pUI->m_BrushLineAngleSlider->deactivate();
			pUI->m_BrushStrokeDirectionChoice->deactivate();
			pUI->m_edge_clipping->deactivate();
			pUI->m_another_gradient->deactivate();
			break;
		case BRUSH_LINES:
		case BRUSH_SCATTERED_LINES:
			pUI->m_BrushLineWidthSlider->activate();
			pUI->m_BrushLineAngleSlider->activate();
			pUI->m_BrushStrokeDirectionChoice->activate();
			pUI->m_edge_clipping->activate();
			pUI->m_another_gradient->activate();
			break;
		default:
			break;
	}
}

void ImpressionistUI::cb_strokeDirection(Fl_Widget *o, void *v) {
	ImpressionistUI* pUI = ((ImpressionistUI *)(o->user_data()));
	ImpressionistDoc* pDoc = pUI->getDocument();
	int direction = (int)v;
	pDoc->setBrushStrokeDirection(direction);
}

//------------------------------------------------------------
// Clears the paintview canvas.
// Called by the UI when the clear canvas button is pushed
//------------------------------------------------------------
void ImpressionistUI::cb_clear_canvas_button(Fl_Widget* o, void* v)
{
	ImpressionistDoc * pDoc = ((ImpressionistUI*)(o->user_data()))->getDocument();

	pDoc->clearCanvas();
}


//-----------------------------------------------------------
// Updates the brush size to use from the value of the size
// slider
// Called by the UI when the size slider is moved
//-----------------------------------------------------------
void ImpressionistUI::cb_sizeSlides(Fl_Widget* o, void* v)
{
	((ImpressionistUI*)(o->user_data()))->m_nSize=int( ((Fl_Slider *)o)->value() ) ;
}


void ImpressionistUI::cb_lineWidthSlides(Fl_Widget *o, void *v) {
	((ImpressionistUI*)(o->user_data()))->m_nLineWidth = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_lineAngleSlides(Fl_Widget *o, void *v) {
	((ImpressionistUI*)(o->user_data()))->m_nLineAngle = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_alphaSlides(Fl_Widget *o, void *v) {
	((ImpressionistUI*)(o->user_data()))->m_nAlpha = double(((Fl_Slider *)o)->value());
	// printf("Alpha: %.02f", ((ImpressionistUI*)(o->user_data()))->m_nAlpha);
}
void ImpressionistUI::cb_spaceSlides(Fl_Widget *o, void *v) {
	((ImpressionistUI*)(o->user_data()))->m_nSpace = int(((Fl_Slider *)o)->value());
}

void ImpressionistUI::cb_edgeThresholdSlides(Fl_Widget *o, void *v) {
	((ImpressionistUI*)(o->user_data()))->m_nEdgeThreshold = double(((Fl_Slider *)o)->value());
}


void ImpressionistUI::cb_edge_clipping(Fl_Widget *o, void *v) {
	ImpressionistUI *pUI=((ImpressionistUI*)(o->user_data()));

	if (pUI->m_is_edge_clipping == 1){
		pUI->m_is_edge_clipping = 0;
	}else{
		pUI->m_is_edge_clipping = 1;
	}
	//printf("cb_edge_clipping,%d\n", pUI->m_is_edge_clipping);
}


void ImpressionistUI::cb_another_gradient(Fl_Widget *o, void *v) {
	ImpressionistUI *pUI=((ImpressionistUI*)(o->user_data()));

	if (pUI->m_is_another_gradient == 1){
		pUI->m_is_another_gradient = 0;
	}else{
		pUI->m_is_another_gradient = 1;
	}
	//printf("cb_another_gradient,%d\n", pUI->m_is_another_gradient);
}


void ImpressionistUI::cb_sizeRand(Fl_Widget *o, void *v) {
	ImpressionistUI *pUI=((ImpressionistUI*)(o->user_data()));

	if (pUI->m_is_size_rand == 1){
		pUI->m_is_size_rand = 0;
	}else{
		pUI->m_is_size_rand = 1;
	}
	//printf("cb_sizeRand,%d\n", ((ImpressionistUI*)(o->user_data()))->m_is_size_rand);
}

void ImpressionistUI::cb_paintButton(Fl_Widget *o, void *v) {
	ImpressionistUI* pUI = ((ImpressionistUI *)(o->user_data()));
	pUI->m_isPaint = true;
	pUI->m_paintView->paintCanvas();
	pUI->m_isPaint = false;

}

void ImpressionistUI::cb_doItButton(Fl_Widget *o, void *v) {
	ImpressionistUI *pUI = ((ImpressionistUI*)(o->user_data()));
	pUI->getDocument()->createEdgeImage();
	pUI->getDocument()->switchEdgeImage();
}

void ImpressionistUI::cb_colorSelects(Fl_Widget *o, void *v) {
	((ImpressionistUI*)(o->user_data()))->m_nRed = double(((Fl_Color_Chooser *)o)->r());
	((ImpressionistUI*)(o->user_data()))->m_nGreen = double(((Fl_Color_Chooser *)o)->g());
	((ImpressionistUI*)(o->user_data()))->m_nBlue = double(((Fl_Color_Chooser *)o)->b());
}

void ImpressionistUI::cb_setFilterKernalSize(Fl_Widget *o, void *v) {
	ImpressionistUI *pUI = (ImpressionistUI*)o->user_data();
	int width = atoi(pUI->m_filterWidthInput->value());
	int height = atoi(pUI->m_filterHeightInput->value());
	if (width <= 0 || height <= 0) {
		fl_message("Width or Height cannot be less than 0");
		return;
	} else {
		pUI->m_filterSizeDialog->hide();
		pUI->m_nFilterWidth = width;
		pUI->m_nFilterHeight = height;
		pUI->m_filterKernalDialog = new Fl_Window(60 + 30 * width + 10 * (width - 1), 60 + 30 * width + 10 * (width - 1) + 50, "Filter Kernal");
		pUI->m_filterKernalEntries.clear();
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				Fl_Input *filterEntry = new Fl_Input(60 + 30 * i + 10 * i, 30 * j + 10 * j, 30, 30, "");
				filterEntry->value("1.0");
				pUI->m_filterKernalEntries.push_back(filterEntry);
			}
		}
		pUI->m_applyFilterKernalButton = new Fl_Button(0, 60 + 30 * width + 10 * (width - 1) + 20, 50, 20, "Apply");
		pUI->m_applyFilterKernalButton->user_data((void *)(pUI));
		pUI->m_applyFilterKernalButton->callback(cb_applyFilterKernal);
		pUI->m_filterKernalDialog->end();
		pUI->m_filterKernalDialog->show();
	}
}

void ImpressionistUI::cb_applyFilterKernal(Fl_Widget *o, void *v) {
	ImpressionistUI *pUI = (ImpressionistUI*)o->user_data();
	pUI->m_dFilterKernal = new double[pUI->m_nFilterWidth * pUI->m_nFilterHeight];
	for (int j = 0; j < pUI->m_nFilterHeight; j++) {
		for (int i = 0; i < pUI->m_nFilterWidth; i++) {
			printf(pUI->m_filterKernalEntries[i + j * pUI->m_nFilterHeight]->value());
			pUI->m_dFilterKernal[i + j * pUI->m_nFilterHeight] = atof(pUI->m_filterKernalEntries[i + j * pUI->m_nFilterHeight]->value());
		}
	}
	pUI->getDocument()->applyFilterKernal();
}

//---------------------------------- per instance functions --------------------------------------

//------------------------------------------------
// Return the ImpressionistDoc used
//------------------------------------------------
ImpressionistDoc* ImpressionistUI::getDocument()
{
	return m_pDoc;
}

//------------------------------------------------
// Draw the main window
//------------------------------------------------
void ImpressionistUI::show() {
	m_mainWindow->show();
	m_paintView->show();
	m_origView->show();
}

//------------------------------------------------
// Change the paint and original window sizes to 
// w by h
//------------------------------------------------
void ImpressionistUI::resize_windows(int w, int h) {
	m_paintView->size(w,h);
	m_origView->size(w,h);
}

//------------------------------------------------ 
// Set the ImpressionistDoc used by the UI to 
// communicate with the brushes 
//------------------------------------------------
void ImpressionistUI::setDocument(ImpressionistDoc* doc)
{
	m_pDoc = doc;

	m_origView->m_pDoc = doc;
	m_paintView->m_pDoc = doc;
}

//------------------------------------------------
// Return the brush size
//------------------------------------------------
int ImpressionistUI::getSize()
{
	return m_nSize;
}

boolean ImpressionistUI::getIsPaint(){
	return m_isPaint;
}
void ImpressionistUI::setIsPaint(boolean is){
	m_isPaint = is;
}

//-------------------------------------------------
// Set the brush size
//-------------------------------------------------
void ImpressionistUI::setSize( int size )
{
	m_nSize=size;

	if (size<=40) 
		m_BrushSizeSlider->value(m_nSize);
}

int ImpressionistUI::getLineWidth() {
	return m_nLineWidth;
}

void ImpressionistUI::setLineWidth(int width) {
	m_nLineWidth = width;
	if (width <= 40) {
		m_BrushLineWidthSlider->value(m_nLineWidth);
	}
}

int ImpressionistUI::getLineAngle() {
	return m_nLineAngle;
}

void ImpressionistUI::setLineAngle(int angle) {
	m_nLineAngle = angle % 360;
	m_BrushLineAngleSlider->value(m_nLineAngle);
}

double ImpressionistUI::getAlpha() {
	return m_nAlpha;
}

void ImpressionistUI::setAlpha(double alpha) {
	m_nAlpha = alpha;
	if (m_nAlpha <= 1.0) {
		m_BrushLineAngleSlider->value(m_nAlpha);
	}
}

int ImpressionistUI::getSpace(){
	return m_nSpace;
}
int ImpressionistUI::getEdgeThreshold(){
	return m_nEdgeThreshold;
}
boolean ImpressionistUI::getIsEdgeClipping(){
	return m_is_edge_clipping;
}
boolean ImpressionistUI::getIsAnotherGradient(){
	return m_is_another_gradient;
}

boolean ImpressionistUI::getIsRandSize(){
	return m_is_size_rand;
}

double ImpressionistUI::getRed() {
	return m_nRed;
}

double ImpressionistUI::getGreen() {
	return m_nGreen;
}

double ImpressionistUI::getBlue() {
	return m_nBlue;
}

int ImpressionistUI::getFilterHeight() {
	return m_nFilterHeight;
}

int ImpressionistUI::getFilterWidth() {
	return m_nFilterWidth;
}

double* ImpressionistUI::getFilterKernal() {
	return m_dFilterKernal;
}

// Main menu definition
Fl_Menu_Item ImpressionistUI::menuitems[] = {
	{ "&File",		0, 0, 0, FL_SUBMENU },
		{ "&Load Image...",	        FL_ALT + 'l', (Fl_Callback *)ImpressionistUI::cb_load_image },
		{ "&Save Image...",	        FL_ALT + 's', (Fl_Callback *)ImpressionistUI::cb_save_image },
		{ "&Load Another Image...",	FL_ALT + 't', (Fl_Callback *)ImpressionistUI::cb_load_another_image },
		{ "&Load Edge Image...",	FL_ALT + 'f', (Fl_Callback *)ImpressionistUI::cb_load_edge_image },
		{ "&Load Dissolve Image...", FL_ALT + 'f', (Fl_Callback *)ImpressionistUI::cb_load_dissolve_image },
		{ "&Swap",	                FL_ALT + 'g', (Fl_Callback *)ImpressionistUI::cb_swap },
		{ "&Brushes...",	        FL_ALT + 'b', (Fl_Callback *)ImpressionistUI::cb_brushes },
		{ "&Undo...", FL_ALT + 'u', (Fl_Callback *)ImpressionistUI::cb_undo },
		{ "&Clear Canvas",          FL_ALT + 'c', (Fl_Callback *)ImpressionistUI::cb_clear_canvas, 0, FL_MENU_DIVIDER },
		{ "&Colors...",             FL_ALT + 'k', (Fl_Callback *)ImpressionistUI::cb_colors },
		{ "&Filter Kernal...", FL_ALT + 'k', (Fl_Callback *)ImpressionistUI::cb_filterKernal },
		{ "&Quit",			        FL_ALT + 'q', (Fl_Callback *)ImpressionistUI::cb_exit },
		{ 0 },
	// TODO: Add menu callback

	{ "&Display",	0, 0, 0, FL_SUBMENU },
		{ "&Original Image", FL_ALT + 'o', (Fl_Callback *)ImpressionistUI::cb_orginal_image },
		{ "&Edge Image", FL_ALT + 'e', (Fl_Callback *)ImpressionistUI::cb_edge_image },
		{ "&Another Image", FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_another_image  },
		{ 0 },
	{ "&Options",	0, 0, 0, FL_SUBMENU },
		{ "&Faster", FL_ALT + 'f', 0 },
		{ "&Safer", FL_ALT + 's', 0 },
		{ 0 },
	{ "&Help",		0, 0, 0, FL_SUBMENU },
		{ "&About",	FL_ALT + 'a', (Fl_Callback *)ImpressionistUI::cb_about },
		{ 0 },

	{ 0 }
};

// Brush choice menu definition
Fl_Menu_Item ImpressionistUI::brushTypeMenu[NUM_BRUSH_TYPE+1] = {
  {"Points",			   FL_ALT+'p', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_POINTS},
  {"Lines",				   FL_ALT+'l', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_LINES},
  {"Circles",			   FL_ALT+'c', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_CIRCLES},
  {"Scattered Points",	   FL_ALT+'q', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_POINTS},
  {"Scattered Lines",	   FL_ALT+'m', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_LINES},
  {"Scattered Circles",	   FL_ALT+'d', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_CIRCLES},
  {"Triangle",			   FL_ALT+'t', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_TRIANGLE},
  {"Scattered Triangle",   FL_ALT+'y', (Fl_Callback *)ImpressionistUI::cb_brushChoice, (void *)BRUSH_SCATTERED_TRIANGLE },
  {0}
};

Fl_Menu_Item ImpressionistUI::brushStrokeDirectionMenu[NUM_STROKE_DIRECTION + 1] = {
	{"Slider/Right Mouse", FL_ALT+'s', (Fl_Callback *)ImpressionistUI::cb_strokeDirection, (void *)STROKE_DIRECTION_SLIDER},
	{"Gradient",           FL_ALT+'g', (Fl_Callback *)ImpressionistUI::cb_strokeDirection, (void *)STROKE_DIRECTION_GRADIENT},
	{"Brush Direction",    FL_ALT+'b', (Fl_Callback *)ImpressionistUI::cb_strokeDirection, (void *)STROKE_DIRECTION_BRUSH_DIRECTION},
	{0}
};



//----------------------------------------------------
// Constructor.  Creates all of the widgets.
// Add new widgets here
//----------------------------------------------------
ImpressionistUI::ImpressionistUI() {
	// Create the main window
	m_mainWindow = new Fl_Window(600, 300, "Impressionist");
		m_mainWindow->user_data((void*)(this));	// record self to be used by static callback functions
		// install menu bar
		m_menubar = new Fl_Menu_Bar(0, 0, 600, 25);
		m_menubar->menu(menuitems);

		// Create a group that will hold two sub windows inside the main
		// window
		Fl_Group* group = new Fl_Group(0, 25, 600, 275);

			// install paint view window
			m_paintView = new PaintView(300, 25, 300, 275, "This is the paint view");//0jon
			m_paintView->box(FL_DOWN_FRAME);

			// install original view window
			m_origView = new OriginalView(0, 25, 300, 275, "This is the orig view");//300jon
			m_origView->box(FL_DOWN_FRAME);
			m_origView->deactivate();

		group->end();
		Fl_Group::current()->resizable(group);
    m_mainWindow->end();

	// init values

	m_nSize = 10;
	m_nLineWidth = 1;
	m_nSpace = 4;
	m_nEdgeThreshold = 200;
	m_nLineAngle = 0;
	m_nAlpha = 1.0;
	m_nGreen = 1.0;
	m_nRed = 1.0;
	m_nBlue = 1.0;
	m_is_edge_clipping = 1;
	m_is_another_gradient = 0;
	m_is_size_rand = 1;
	m_isPaint = false;
	m_nFilterHeight = 1;
	m_nFilterHeight = 1;

	// brush dialog definition
	m_brushDialog = new Fl_Window(400, 325, "Brush Dialog");
		// Add a brush type choice to the dialog
		m_BrushTypeChoice = new Fl_Choice(50,10,150,25,"&Brush");
		m_BrushTypeChoice->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushTypeChoice->menu(brushTypeMenu);
		m_BrushTypeChoice->callback(cb_brushChoice);

		m_ClearCanvasButton = new Fl_Button(240,10,150,25,"&Clear Canvas");
		m_ClearCanvasButton->user_data((void*)(this));
		m_ClearCanvasButton->callback(cb_clear_canvas_button);

		// Add stroke direction to the dialog
		m_BrushStrokeDirectionChoice = new Fl_Choice(110, 45, 160, 25, "&Stroke Direction");
		m_BrushStrokeDirectionChoice->user_data((void *)(this));
		m_BrushStrokeDirectionChoice->menu(brushStrokeDirectionMenu);
		m_BrushStrokeDirectionChoice->callback(cb_strokeDirection);
		m_BrushStrokeDirectionChoice->deactivate();

		// Add brush size slider to the dialog 
		m_BrushSizeSlider = new Fl_Value_Slider(10, 80, 300, 20, "Size");
		m_BrushSizeSlider->user_data((void*)(this));	// record self to be used by static callback functions
		m_BrushSizeSlider->type(FL_HOR_NICE_SLIDER);
        m_BrushSizeSlider->labelfont(FL_COURIER);
        m_BrushSizeSlider->labelsize(12);
		m_BrushSizeSlider->minimum(1);
		m_BrushSizeSlider->maximum(40);
		m_BrushSizeSlider->step(1);
		m_BrushSizeSlider->value(m_nSize);
		m_BrushSizeSlider->align(FL_ALIGN_RIGHT);
		m_BrushSizeSlider->callback(cb_sizeSlides);

		// Add line width slider to the dialog
		m_BrushLineWidthSlider = new Fl_Value_Slider(10, 110, 300, 20, "Line Width");
		m_BrushLineWidthSlider->user_data((void *)(this));
		m_BrushLineWidthSlider->type(FL_HOR_NICE_SLIDER);
		m_BrushLineWidthSlider->labelfont(FL_COURIER);
		m_BrushLineWidthSlider->labelsize(12);
		m_BrushLineWidthSlider->minimum(1);
		m_BrushLineWidthSlider->maximum(40);
		m_BrushLineWidthSlider->step(1);
		m_BrushLineWidthSlider->value(m_nLineWidth);
		m_BrushLineWidthSlider->align(FL_ALIGN_RIGHT);
		m_BrushLineWidthSlider->callback(cb_lineWidthSlides);
		m_BrushLineWidthSlider->deactivate();

		// Add line angle slider to the dialog
		m_BrushLineAngleSlider = new Fl_Value_Slider(10, 140, 300, 20, "Line Angle");
		m_BrushLineAngleSlider->user_data((void *)(this));
		m_BrushLineAngleSlider->type(FL_HOR_NICE_SLIDER);
		m_BrushLineAngleSlider->labelfont(FL_COURIER);
		m_BrushLineAngleSlider->labelsize(12);
		m_BrushLineAngleSlider->minimum(0);
		m_BrushLineAngleSlider->maximum(359);
		m_BrushLineAngleSlider->step(1);
		m_BrushLineAngleSlider->value(m_nLineAngle);
		m_BrushLineAngleSlider->align(FL_ALIGN_RIGHT);
		m_BrushLineAngleSlider->callback(cb_lineAngleSlides);
		m_BrushLineAngleSlider->deactivate();

		// Add alpha sliders to the dialog
		m_BrushAlphaSlider = new Fl_Value_Slider(10, 170, 300, 20, "Alpha");
		m_BrushAlphaSlider->user_data((void *)(this));
		m_BrushAlphaSlider->type(FL_HOR_NICE_SLIDER);
		m_BrushAlphaSlider->labelfont(FL_COURIER);
		m_BrushAlphaSlider->labelsize(12);
		m_BrushAlphaSlider->minimum(0.0);
		m_BrushAlphaSlider->maximum(1.0);
		m_BrushAlphaSlider->step(0.01);
		m_BrushAlphaSlider->value(m_nAlpha);
		m_BrushAlphaSlider->align(FL_ALIGN_RIGHT);
		m_BrushAlphaSlider->callback(cb_alphaSlides);

		m_edge_clipping = new Fl_Light_Button(10,200,150,25,"&Edge Clipping");
		m_edge_clipping->user_data((void*)(this));	// record self to be used by static callback functions
		m_edge_clipping->callback(cb_edge_clipping);
		m_edge_clipping->deactivate();
		m_edge_clipping->set();
		
		m_another_gradient = new Fl_Light_Button(230, 200, 150,  25, "&Another Gradient");
		m_another_gradient->user_data((void*)(this));	// record self to be used by static callback functions
		m_another_gradient->callback(cb_another_gradient);
		m_another_gradient->deactivate();


		// Fl_Group* group2 = new Fl_Group(10, 230, 300, 20);

		m_SpaceSlider = new Fl_Value_Slider(10, 230, 150, 20, "Spacing");
		m_SpaceSlider->user_data((void *)(this));
		m_SpaceSlider->type(FL_HOR_NICE_SLIDER);
		m_SpaceSlider->labelfont(FL_COURIER);
		m_SpaceSlider->labelsize(12);
		m_SpaceSlider->minimum(1.0);
		m_SpaceSlider->maximum(16.0);
		m_SpaceSlider->step(1.0);
		m_SpaceSlider->value(m_nSpace);
		m_SpaceSlider->align(FL_ALIGN_RIGHT);
		m_SpaceSlider->callback(cb_spaceSlides);

		m_SizeRandButton = new Fl_Light_Button(220, 230, 100,  25, "&Size Rand.");
		m_SizeRandButton->user_data((void*)(this));	// record self to be used by static callback functions
		m_SizeRandButton->callback(cb_sizeRand);
		m_SizeRandButton->set();

		m_PaintButton = new Fl_Button(330,230,50,25,"&Paint");
		m_PaintButton->user_data((void*)(this));
		m_PaintButton->callback(cb_paintButton);

		// group2->end();

		// Fl_Group* group3 = new Fl_Group(10, 260, 250, 20);

		m_EdgeThresholdSlider = new Fl_Value_Slider(10, 260, 200, 25, "Edge Threadhold");
		m_EdgeThresholdSlider->user_data((void *)(this));
		m_EdgeThresholdSlider->type(FL_HOR_NICE_SLIDER);
		m_EdgeThresholdSlider->labelfont(FL_COURIER);
		m_EdgeThresholdSlider->labelsize(12);
		m_EdgeThresholdSlider->minimum(0.0);
		m_EdgeThresholdSlider->maximum(500.0);
		m_EdgeThresholdSlider->step(1.0);
		m_EdgeThresholdSlider->value(m_nEdgeThreshold);
		m_EdgeThresholdSlider->align(FL_ALIGN_RIGHT);
		m_EdgeThresholdSlider->callback(cb_edgeThresholdSlides);

		m_DoItButton = new Fl_Button(330,260,50,25,"&Do it");
		m_DoItButton->user_data((void*)(this));
		m_DoItButton->callback(cb_doItButton);

		// group3->end();
		


    m_brushDialog->end();	

	m_colorsDialog = new Fl_Window(300, 300, "Color Selector");
	// Add color chooser to the color dialog
	m_colorChooser = new Fl_Color_Chooser(0, 0, 250, 250, "Color Blending");
	m_colorChooser->user_data((void *)(this));
	m_colorChooser->rgb(1.0f, 1.0f, 1.0f);
	m_colorChooser->callback(cb_colorSelects);
	m_colorsDialog->end();

	// Filter Kernal
	m_filterSizeDialog = new Fl_Window(300, 300, "Filter Size");
	m_filterWidthInput = new Fl_Int_Input(55, 10, 100, 30, "Width:");
	m_filterWidthInput->labelfont(FL_COURIER);
	m_filterWidthInput->labelsize(12);
	m_filterWidthInput->value("1");
	m_filterHeightInput = new Fl_Int_Input(55, 70, 100, 30, "Height:");
	m_filterHeightInput->labelfont(FL_COURIER);
	m_filterHeightInput->labelsize(12);
	m_filterHeightInput->value("1");
	m_filterSizeSetButton = new Fl_Button(50, 130, 50, 24, "Set");
	m_filterSizeSetButton->user_data((void *)(this));
	m_filterSizeSetButton->callback(cb_setFilterKernalSize);
	m_filterSizeDialog->end();
}
