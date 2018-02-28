#include "App.h"
#include <vector>
#include "TTT.h"


//#define t1 pPos.push_back(new Vec(-.7, .7, 0)); // 1
//#define t2 pPos.push_back(new Vec(0, .7, 0)); // 2
//#define t3 pPos.push_back(new Vec(.7, .7, 0)); // 3
//
//#define t4 pPos.push_back(new Vec(-.7, 0, 0)); // 4
//#define t5 pPos.push_back(new Vec(0, 0, 0)); // 5
//#define t6 pPos.push_back(new Vec(.7, 0, 0)); // 6
//
//#define t7 pPos.push_back(new Vec(-.7, -.7, 0)); // 7
//#define t8 pPos.push_back(new Vec(0, -.7, 0)); // 8
//#define t9 pPos.push_back(new Vec(.7, -.7, 0)); // 9

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
    

    pPos = {{-.7, .7},{0,.7},{.7, .7},{-.7, 0},{0, 0},{.7, 0},{-.7, -.7},{0, -.7},{.7, -.7}};
    
//    pPos.push_back(new Vec(-.7, .7, 0)); // 1
//	pPos.push_back(new Vec(0, .7, 0)); // 2
//	pPos.push_back(new Vec(.7, .7, 0)); // 3
//
//	pPos.push_back(new Vec(-.7, 0, 0)); // 4
//	pPos.push_back(new Vec(0, 0, 0)); // 5
//	pPos.push_back(new Vec(.7, 0, 0)); // 6
//
//	pPos.push_back(new Vec(-.7, -.7, 0)); // 7
//	pPos.push_back(new Vec(0, -.7, 0)); // 8
//	pPos.push_back(new Vec(.7, -.7, 0)); // 9

}

void basicRec(float x, float y, float w, float h) {
	//glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x, y - h);
		glVertex2f(x + w, y - h);
		glVertex2f(x + w, y);
	glEnd();
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

    
    printf("contense of displayArr[] {");
    for (int k = 0; k < 9; k++) { //hardcoded for because it was overflowing with sizeof
        printf("%d, ",displayArr[k]);
        //std::cout << "displayArr[" << k << "] = " << displayArr[k] << std::endl;
    }
    printf("}\n");
    if (!pPos.empty()){
    for (int j = 0; j <= 9; j++){
        if (displayArr[j] == 1){
            //printf("Trying to draw a pPos[j]->getX()%f", pPos[j]->getX());

            TTT(0, pPos[j]); // x
        }
        if (displayArr[j] == 2){
            TTT(1, pPos[j]); // o
        }
    }
    }
    
    
//    std::cout << "pPos[0]->getX() = " << pPos[0]->getX() << std::endl;
//    int j = 0;
//    for (vector<Vec*>::iterator i = pPos.begin(); i != pPos.end(); i++) {
//        
//        for (int k = 0; k <= 9; k++) { //hardcoded for because it was overflowing with sizeof
//            std::cout << "displayArr[" << k << "] = " << displayArr[k] << std::endl;
//        }
//        if (displayArr[j] == 1){
//            TTT(0, *i); // x
//        }
//        if (displayArr[j] == 2){
//            TTT(1, *i); // o
//        }
//
//        j++;
//    }

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
        
        //play by yourself mode
		if (rVec[i]->contains(x,y)) {
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

    ////recContains(rVec.front(), x, y);
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
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
