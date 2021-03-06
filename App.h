#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "Rect.hpp"
#include <vector>
#include "Vec.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;



public:
    std::vector<Rect *> rVec; // Rectangle Vector
    std::vector<Vec *> pPos; // Possible Positions
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);

    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void recContains(Rect * r, float x, float y);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    int checkWin(int dA[]);
    int sumSq(int a);
    int three(int a, int b, int c);

    bool singleplayer = false;

    
    bool gameOver = false;
    int displayArr[9];
    int playArr[9];
    int playerTurn = 1;
    //Rect * r1;
    //Rect * r2;
};

#endif
