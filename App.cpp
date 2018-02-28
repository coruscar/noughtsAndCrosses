#include "App.h"
#include <vector>
#include "TTT.h"


App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
    for (int i = 0; i < 9; i++) {displayArr[i] = 0;}
    for (int i = 0; i < 9; i++) {playArr[i] = 1;}
    
    
    
    rVec.push_back(new Rect(-1, 1 , .6, .6)); // 1
    rVec.push_back(new Rect(-.3, 1, .6, .6)); // 2
    rVec.push_back(new Rect(.4, 1 , .6, .6)); // 3
    
    rVec.push_back(new Rect(-1, .3 , .6, .6)); // 4
    rVec.push_back(new Rect(-.3, .3 , .6, .6)); // 5
    rVec.push_back(new Rect(.4, .3 , .6, .6)); // 6
    
    rVec.push_back(new Rect(-1, -.4 , .6, .6)); // 7
    rVec.push_back(new Rect(-.3, -.4 , .6, .6)); // 8
    rVec.push_back(new Rect(.4, -.4 , .6, .6)); // 9
    
    
    pPos.push_back(new Vec(-.7, .7)); // 1
    pPos.push_back(new Vec(0, .7)); // 2
    pPos.push_back(new Vec(.7, .7)); // 3
    
    pPos.push_back(new Vec(-.7, 0)); // 4
    pPos.push_back(new Vec(0, 0)); // 5
    pPos.push_back(new Vec(.7, 0)); // 6
    
    pPos.push_back(new Vec(-.7, -.7)); // 7
    pPos.push_back(new Vec(0, -.7)); // 8
    pPos.push_back(new Vec(.7, -.7)); // 9
    
}

void basicRec(float x, float y, float w, float h) {
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x, y - h);
    glVertex2f(x + w, y - h);
    glVertex2f(x + w, y);
    glEnd();
}

void basicLine(float x, float y){
    
}

int App::sumSq(int a) {
    int mS[9] = {8,1,6,3,5,7,4,9,2}; //TODO move magic square somewhere central
    return displayArr[a]*mS[a];
}

int App::checkWin(int dA[]){ //returns 0 if nobody won, 1 if player 1, 2 if player 2
    
    if (gameOver)
        return 0;
    
    int sum = 0;
    for (int i = 0; i < 10; i = i + 3){
        sum = sumSq(i) + sumSq(i+1) +sumSq(i+2);
        if (sum == 15){
            displayArr[i] = 3; displayArr[i+1] = 3; displayArr[i+2] = 3;
            return 1;
        }
        if (sum == 30){
            displayArr[i] = 4; displayArr[i+1] = 4; displayArr[i+2] = 4;
            return 2;
        }
    }
    sum = sumSq(0) + sumSq(4) + sumSq(8);
    if (sum == 15){
        displayArr[0] = 3; displayArr[4] = 3; displayArr[8] = 3;
        return 1;
    }
    if (sum == 30){
        displayArr[0] = 4; displayArr[4] = 4; displayArr[8] = 4;
        return 2;
    }
    
    sum = sumSq(2) + sumSq(4) + sumSq(6);
    if (sum == 15){
        displayArr[2] = 3; displayArr[4] = 3; displayArr[6] = 3;
        return 1;
    }
    if (sum == 30){
        displayArr[2] = 4; displayArr[4] = 4; displayArr[6] = 4;
        return 2;
    }
    
    sum = sumSq(0) + sumSq(3) + sumSq(6);
    if (sum == 15){
        displayArr[0] = 3; displayArr[3] = 3; displayArr[6] = 3;
        return 1;
    }
    if (sum == 30){
        displayArr[0] = 4; displayArr[3] = 4; displayArr[6] = 4;
        return 2;
    }
    
    sum = sumSq(1) + sumSq(4) + sumSq(7);
    if (sum == 15){
        displayArr[1] = 3; displayArr[4] = 3; displayArr[7] = 3;
        return 1;
    }
    if (sum == 30){
        displayArr[1] = 4; displayArr[4] = 4; displayArr[7] = 4;
        return 2;
    }
    
    sum = sumSq(2) + sumSq(5) + sumSq(8);
    if (sum == 15){
        displayArr[2] = 3; displayArr[5] = 3; displayArr[8] = 3;
        return 1;
    }
    if (sum == 30){
        displayArr[2] = 4; displayArr[5] = 4; displayArr[8] = 4;
        return 2;
    }
    
    
    return 0;
}

void App::draw() {
    
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    //glClearColor(0.0, 0.0, 0.0, 1.0);//try to set bg to white
    //glClearColor(1.0, 1.0, 1.0, 0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    
    //board rendering
    glColor3f(1.0, 1.0, 1.0);
    basicRec(-.4, 1, .1, 2);
    basicRec(.3, 1, .1, 2);
    
    basicRec(-1, .4, 2, .1);
    basicRec(-1, -.3, 2, .1);
    
    // Set Color
    glColor3f(1.0, 1.0, 1.0);
    
    
    printf("displayArr[] {");
    for (int k = 0; k < 9; k++) { //hardcoded for because it was overflowing TODO fix
        printf("%d, ",displayArr[k]);
        //std::cout << "displayArr[" << k << "] = " << displayArr[k] << std::endl;
    }
    printf("}\n");
    
    
    
    if (!(pPos.empty())){
        for (int j = 0; j < 9; j++){
            if (displayArr[j] == 1){
                //printf("Trying to draw a pPos[j]->getX()%f", pPos[j]->getX());
                TTT(0, pPos[j],0); // x
            }
            if (displayArr[j] == 2){
                TTT(1, pPos[j],0); // o
            }
            //should only happen if game is over
            if (displayArr[j] == 3){
                printf("This should be printed once on index = %d\n",j);
                TTT(0, pPos[j],1); //colored x
            }
            //should only happen if game is over
            if (displayArr[j] == 4){
                TTT(1, pPos[j],1); //colored o
            }
        }
    }
    
    int winVar = checkWin(displayArr);
    if(winVar != 0 && gameOver == false){
        printf("%d wins! \n",winVar);
        
        gameOver = true;
        redraw();
    }
    
    
    //std::cout << "rVec.size() = " << rVec.size() << std::endl;
    for (int i = 0; i < rVec.size(); i++)
        rVec[i]->build();
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}
//void App::recContains(Rect * r, float x, float y){
//    if(r->contains(x,y)){
//        r->color = 1;
//        r->build();
//    } else
//        r->color = 0;
//}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    for (int i = 0 ; i < 9; i++) { //hardcoded because overflow problems
        
        //friends
        if (!singleplayer){
            if (rVec[i]->contains(x,y) && !gameOver) {
                if (playerTurn && playArr[i] == 1){
                    printf("We're on rVec[%d]\n",i);
                    displayArr[i] = 1;
                    //App::draw();
                } else if (!playerTurn && playArr[i] == 1){
                    displayArr[i] = 2;
                }
                playArr[i] = 0;
                playerTurn = !playerTurn;
            }
        }
        //ai
        if (singleplayer){
            if (rVec[i]->contains(x,y) && !gameOver) {
                if (playArr[i] == 1){
                    displayArr[i] = 1;
                }
                playArr[i] = 0;
                //printf("what's going on \n");
                int count = 0;
                for (int j = 0; j < 9; j++) {if (playArr[j] == 1)count ++;}
                
                if (count > 1){
                    for (int j = 0; j < 9 ;j++){
                        if (playArr[j] == 1 && rand() % 2 == 0){
                            //printf("we did it \n");
                            
                            displayArr[j] = 2;
                            playArr[j] = 0;
                            break;
                        }
                        if (playArr[8] == 0 && j == 8)
                            j = 0;
                    }
                }
            }
        }
    }
    // Redraw the scene
    redraw(); //TODO should I readd this?
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        singleplayer = !singleplayer;
        // Exit the app when Esc key is pressed
        //exit(0);
    }
}
