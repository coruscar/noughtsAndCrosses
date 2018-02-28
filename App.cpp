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
    
    for (int i = 0; i < sizeof(App::displayArr); i++) {App::displayArr[i]=0;}
	//rVec.push_back(new Rect(0.0, 0.0, .4, .4));
	//rVec.push_back(new Rect(.3, .4, .5, .6));
    
    
//    //black square rendering
//    //TODO change to rect object later
//    //glClearColor(0.0, 0.0, 0.0, 1.0);
//    glColor3f(0.5, 0.5, 1.0);
//    basicRec(-.3, 1 , .6, .6);
//    basicRec(-1, 1 , .6, .6);
//    basicRec(.4, 1 , .6, .6);
//    
//    basicRec(-.3, .3 , .6, .6);
//    basicRec(-1, .3 , .6, .6);
//    basicRec(.4, .3 , .6, .6);
//    
//    basicRec(-.3, -.4 , .6, .6);
//    basicRec(-1, -.4 , .6, .6);
//    basicRec(.4, -.4 , .6, .6);
    
    rVec.push_back(new Rect(-.3, 1, .6, .6));
    rVec.push_back(new Rect(-1, 1 , .6, .6));
    rVec.push_back(new Rect(.4, 1 , .6, .6));
    
    rVec.push_back(new Rect(-.3, .3 , .6, .6));
    rVec.push_back(new Rect(-1, .3 , .6, .6));
    rVec.push_back(new Rect(.4, .3 , .6, .6));
    
    rVec.push_back(new Rect(-.3, -.4 , .6, .6));
    rVec.push_back(new Rect(-1, -.4 , .6, .6));
    rVec.push_back(new Rect(.4, -.4 , .6, .6));
    
    

    pPos.push_back(new Vec(-.7, .7, 0)); // 1
	pPos.push_back(new Vec(0, .7, 0)); // 2
	pPos.push_back(new Vec(.7, .7, 0)); // 3

	pPos.push_back(new Vec(-.7, 0, 0)); // 4
	pPos.push_back(new Vec(0, 0, 0)); // 5
	pPos.push_back(new Vec(.7, 0, 0)); // 6

	pPos.push_back(new Vec(-.7, -.7, 0)); // 7
	pPos.push_back(new Vec(0, -.7, 0)); // 8
	pPos.push_back(new Vec(.7, -.7, 0)); // 9

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
    
//    //black square rendering
//    //TODO change to rect object later
//    //glClearColor(0.0, 0.0, 0.0, 1.0);
//    glColor3f(0.5, 0.5, 1.0);
//    basicRec(-.3, 1 , .6, .6);
//    basicRec(-1, 1 , .6, .6);
//    basicRec(.4, 1 , .6, .6);
//    
//    basicRec(-.3, .3 , .6, .6);
//    basicRec(-1, .3 , .6, .6);
//    basicRec(.4, .3 , .6, .6);
//    
//    basicRec(-.3, -.4 , .6, .6);
//    basicRec(-1, -.4 , .6, .6);
//    basicRec(.4, -.4 , .6, .6);
    
    
    // Set Color
    glColor3f(1.0, 1.0, 1.0);

    
//    std::vector<Vec *> aPos; //actual positions vector
    
//    for (int i = 0; i < sizeof(displayArr) - 1; i++ ){
//        if (displayArr[i] == 0){
//            //don't print
//            continue;
//        } else if (displayArr[i] == 1){
//            pPos[i]->setCircle(false);
//            aPos.push_back(pPos[i]);
//            //print X
//        } else if (displayArr[i] == 2){
//            pPos[i]->setCircle(true);
//            aPos.push_back(pPos[i]);
//            //print O
//        } else {
//            continue;
//        }
//    }
    
    std::cout << "pPos[0]->getX() = " << pPos[0]->getX() << std::endl;
    int j = 0;
    for (vector<Vec*>::iterator i = pPos.begin(); i != pPos.end(); i++) {
        
        for (int k = 0; k < sizeof(App::displayArr); k++) {
            std::cout << "App::displayArr[k]" << App::displayArr[k] << std::endl;
        }
        if (displayArr[j] == 1){
            TTT(0, *i); // x
        }
        if (displayArr[j] == 2){
            TTT(1, *i); // o
        }

        j++;
    }

	std::cout << "rVec.size() = " << rVec.size() << std::endl;
	for (int i = 0; i < rVec.size(); i++)
		rVec[i]->build();
    

	//App::rVec[0]->build;
	//App::rVec[1]->build;


	//rVec[0]->build();
    //rVec[1]->build();
    
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
    

	bool found = 0;

	// swap the rectanges
	for (int i = rVec.size() - 1; i >= 0; i--) {
		if (rVec[i]->contains(x,y)) {
            //pPos[i]->setCircle(!pPos[i]->getCircle());
            
            //if x turn
            displayArr[i] = 1;
            
            std::swap(rVec[i], rVec.front());
            
			found = 1;
            App::draw();
		}
	}
	//deselect if needed
	for (int i = rVec.size() - 1; i >= 0; i--) {
		if (found) {
            displayArr[i] = 0;
			rVec[i]->color = 0;
		}
	}

    ////recContains(rVec.front(), x, y);
    // Redraw the scene
    redraw();
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
