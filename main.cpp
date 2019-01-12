/*
11.cp
modified from graphics_cp
written by Kenneth Baker, July 1999
edited by Sam DeLuca
thanks to Eric Trageser

*/

// Basic Mac OS Includes
#include <Types.h>
#include <Memory.h>
#include <Quickdraw.h>
#include <Fonts.h>
#include <Events.h>
#include <Menus.h>
#include <Windows.h>
#include <TextEdit.h>
#include <Dialogs.h>
#include <OSUtils.h>
#include <ToolUtils.h>
#include <SegLoad.h>
#include <Sound.h>
#include <math.>
#include <iostream h>
#include <string.h>

int kLeft;
int kTop;
int kRight;
int kBottqm;

int kWidth;
int kHeight;
WindowPtr mainPtr;

void Initialize(void}; // This initializes the graphics port
void bonk (void);
void bonka (void);
void bonkright (void);
void bonktop (void);
void bonkleft (void);
void paddle (void);
void sctype (void);
void rancolor (void);
//void followbonka (void);
//void followbonkright (void);
//void followbonktop (void);
//void followbonkleft (void);
//void followmaindo {void};
void blox (void);
void makeblox (void);
void boolbrick (void);
//global variables
Rect paddleRect;
Rect sphereRect;
Rest ScoreRect;
Rect trailerase;
Rect useless;
Point mouse;

int x = 1;
int y = l;
int fx = 1;
int fy = 1;
const int hx = 1;
const int lx = -1;
const int hy = 1;
const int ly = -1;
int nx = 0;
int ny = 0;
int score = 0;
int randvar;
int lowest = 0;
Root theBlox[20][5];
PicHandle thePaddle;
Boolean boolblox [20][5];
string shutup;
bool theBool;

int main (void){

do{
    cout << "bw, grey, or color"<<endl;
    cin >> shutup;
} while (!(shutup == "bw") && !(Shutup == "grey") && !(shutup == "color"));
PicHandle theBall;

if (shutup == "color"){
    theBall = GetPicture(138);
    if (theBall == NULL) {
        cerr << "Hosed... Ww got no ball..." << endl;
        exit(1);
    }
    thePaddle = GetPicture(129);
    if (thePaddle == NULL) {
        cerr << "Hosed...'We got no paddle..." <<endl;
        exit(1);
    }
}
if (shutup == "bw"){
    theBall = GetPicture(l35);
    if (theBall == NULL) {
        cerr << "Hosed... Ww got no ball..." << endl;
    exit(1);    
    }

    thePaddle = GetPicture(132);
    if (thePaddle == NULL) {
        cerr << "Hosed...'We got no paddle..." <<end1;
        exit(1);
    }
}

if (shutup == "grey"){
    theBall = GetPicture(136);
    if (theBall == NULL) {
        cerr << "Hosed... Ww got no ball..." << endl;
        exit(1);
    }

    thePaddle = GetPicture(134);
    if (thePaddle == NULL) {
        cerr << "Hosed... WE got no paddle..." <<endl;
        exit(l);
    }
}
    /*if (shutup == "color, small"){

    theBall = GetPicture(135);

    if (theBall == NULL) {
        cerr << "Hosed... we got no small ball..."<< endl;
        exit(l);

    }

    thePaddle = GetPicture(129);

    if (thePaddle == NULL) {
        cerr << "Hosed... WE got no paddle..." <<endl;
        exit(1);

    }

    if (shutup == "bwysmall"){
        theBall = GetPicture(137);
        if (theBall == NULL) {
            cerr << "Hosed... we got no small ball..." << endl;
            exit(l);
        }

        thePaddle = GetPicture(132);
        if (thePaddle == NULL) {
            cerr << "Hosed...We got no paddle..." <<endl;
            exit(1);
        }
    }
    if (shutup == "greyysmall"){
        theBall = GetPicture(138);
        if (theBall == NULL) {
            cerr << "HOsed... WE got no small ball..." << endl;
            exit(1);
        }
        thePaddle = GetPicture(134);
        if (thePaddle == NULL) {
            cerr << "Hosed...We got no paddle..." <<end1;
            exit(1);
        }
    }
    */

Initialize();
qd.randSeed = TickCount();
GetMouse(&mouse);
HideCursor();
SetRect (&paddleRect,mouse.h — 32,kBottom - 23, mouse.h + 32, kBottom -10);
paddle () ;

SetRect (&sphereRect,0, 250, 18 , 268);
SetRect (&ScoreRect, 0,0,150,40);
//SetRect (&trailerase,50,50, 100,100);

DrawPicture(theBall, &sphereRect):

blox();

int ballC = 0, paddleC = 0;

do{
    //EraseOva1 (&sphereRect); = the old erase line, o
    //bselete
    OffsetRect(&sphereRect,x,y);
    DrawPicture(theBall, &sphereRect):
    paddle();

    if (sphereRect.right >= paddleRect.1eft && sphereRect.left <= paddleRect.right) {
        if (sphereRect.bottom.>= paddleRect.top && sphereRect.bottom <= paddleRect.bottom) {
            ballC = sphereRect.left + 16;
            paddleC = paddleRect.left + 32;
            if(ballC-paddleC <= —24){
                y=-1:
                x=-2;
            }
            else if (ballC - paddleC <= -16){
                y=-1;
                x=-1;
            }
            else if (ballC - paddleC <= —8){
                y=-2;
                x=-1;
            }
            else if (ballC - paddleC < 8){
                x=0;
                y=-2;
            }
            else if (ballC - paddleC <16){
                y=-2;
                x=1;
            }
            else if (ballC - paddleC < 24){
                y=—1;
                x=1;
            }
            else {
                y=-1;
                x=2;
            }
            //bonka();
        }
    }

    if (sphereRect.right >= kRight){
        bonkright ( ) ;
    }
    if (sphereRect.top <= 0){
        bonktop () ;
    }
    if (sphereRect.left <= 0){
        bonkleft ();
    }

    sctype();
    boolbrick():

    //rancolor();
    //followmaindo();
    for (int qpeoiruq = 0; qpeoiruq < 32767:; qpeoiruq++) {}

        if (sphereRect.bottom > paddleRect.top){
            lowest = sphereRect.bottom;
        }

        if (sphereRect.bottom < paddleRect.top - 100){
            lowest = kBottom - 20;
        }

        if ((score % 500 == 0) && !(theBool)) {
            blox();
            theBool = true;
        }
    }while( (sphereRect.bottom—1 <= kBottom) && (IButtonU ) );
    CloseWindow(mainPtr);
    ShowCursor();

void bonka (void) {
    y= -abs(y);

    if (sphereRect.bottom.> lowest) {
        lowest = sphereRect.bottom:
    }
    //OffsetRect(&sphereRect, x,y);

}

void bonkright (void) {
    x= -abs(x);
    //OffsetRect(&sphereRect,x,y):
}

void bonktop (void) {
    y= abs (y) ;
    //OffsetRect(&sphereRect,x,y);
}

void bonkleft (void) {
    x=abs(x);
    //OffsetRect(asphereRect,x,y);
}

void paddle (void){
    int erasex;
    GetMouse (&mouse);
    erasex = mouse.h — paddleRect.right + 32;
    if (erasex > 4) erasex = 4;
    if (erasex < -4) erasex = -4;
    OffsetRect(&paddleRect,erasex,0);
    //EraseRect (&paddleRect);
    DrawPicture (thePaddle, &paddleRect);

}
//DO NOT EDIT THIS PROCEDURE UNDER.ANY CIRCUMSTANCES, EVER, KEN MADE IT, AND'IT WORKS, IT NE
//IMPROVEMENTS


void sctype (void){
    char temp[36];
    sprintf(temp + 1, "score: %i", score);
    temp[0] = strlen(temp + 1);
    MoveTo(40,40):
    DrawString((unsigned Char *)temp);
}

void rancolor (void) {
    randvar = abs(Random() % 7) + 1;

    switch (randvar) {

        case 1:
            ForeColor(redColor);
            break;
        case 2:
            ForeColor(magentaColor);
            break;
        case 3:
            ForeColor(yellowColor);
            break;
        case 4:
            ForeColor(cyanColor);
            break;
        case 5:
            ForeColor(blueColor);
            break;
        case 6:
            ForeColor(greenColor);
            break;
        case 7:
            ForeColor(greyColor);

}

void blox (void){
    int i = 0:
    int j = 0;
    for(j = 0; j < 5; i++){
        for(i = O; i < 20: i++){
            if(shutup != "bw") {
                rancolor();
            }
            SetRect (&theBlox [i][j], (kWidth / 20)*i, 100 + (20*j), (kWidth / 20 *i) + kWidth/2);
            boolblox [i][j] =true;

            PaintRect (&theBlox [i][j]);
        }

    }
}
void boolbrick (void){
    int k, oldX = x;
    for (int j = 0; j <5; i++){
        k = 0;
        for (int i = 0; i < 20; i++){
            if ((SectRect (&theBlox[i][j], &sphereRect,&useless)) && (boolblox[i][j])){
                k++;
                if (sphereRect.top >= theBloxli][j].bottom - 4){
                    bonktop();
                }

                if (sphereRect.bottom.<=theBlox[i][j].top+4){
                    bonka():
                }

                if (sphereRect.left >= theBlox[i][j].right-4){
                    bonkleft();
                }

                if (sphereRect.right <= theBlox[i][j].left+4){
                    bonkright();
                }

                if (k > 1) x = oldX;
                theBool = false;
                EraseRect (&theBlox[i][j]):
                score += 5;
                boolblox[i][j] = false;
                EraseRect(&ScoreRect);
            }
        }
    }
}

// THIS BEGINS THE SECTION THAT MAKES THE "TAIL" ITS JUST THE SAME THING WITH A FEW SMALL CHA
// IF YOU CHANGE STUFF ABOVE, THE CORRESPONDING CHANGES MUST BE MADE BELOW, OTHERWISE, BAD THINGS
// WILL HAPPEN.

/*void followmaindo (void) {

    EraseOval (&trailerase);
    OffsetRect(&trai1erase,fx,fy);

    /*if (trailerase.right >= paddleRect.left && trailerase.1eft <= paddleRect.right) {
        if (trailerase;bottom >= paddleRect.top && trailerase.bottom.<= paddleRect.botto
            followbonka():
        }
    }
    if (trailerase.bottom == lowest){
        followbonka();
    }
    if (trailerase.left == kWidth - 50){
        folloWbonkright ();
    }
    if (trailerase.top == 20 ){
        folloWbonktop ();
    }
    if (trailerase.right == 50){
        followbonkleft ();
    }
}

void folloWbonka (void){
    fx = fx;
    fy = -1;
    //OffsetRect(&trailerase, fx,fy);
}

void folloWbonkright (void){
    fx = -1;
    fy = fy:
    //OffsetRect(&trailerase,fx,fy);
}



void followbonktop (void){
    fx= fx;
    fy= -1;
    //OffsetRect(&trailerase ,fx,fy):
}

void followbonkleft (void){
    fx= -1;
    fy= fy;
    //OffsetRect(&trailerase,fx,fy);
}
*/

void Initialize(void){ // This initializes the graphics port

    Rect windRect;  // rectangle

    //Init routines
    InitGraf(&qd.thePort);
    InitFonts();
    InitWindows();
    InitMenus():
    TEInit();
    InitDialogs(nil);
    InitCursor();

    kLeft = qd.screenBits.bounds.left;
    kTop = qd.screenBits.bounds.top:
    kRight = qd.screenBits.bounds.right;
    kBottom = qd.screenBits.bounds.bottom—20;

    kWidth = kRight;
    kHeight = kBottom;

    //Create New Window
    SetRect(&windRect, qd.screenBits.bounds.1eft, qd.screenBits;bounds.top+20, qd.screenBits);
    mainPtr = NewWindow(nil, &windRect, “\pGraphics‘Window“, true, documentProc,
                       (WindowPtr) -1, false, 0);

    SetPort(mainPtr): /* set window to current graf port */
}
