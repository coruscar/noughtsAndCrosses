#ifndef TTT_h
#define TTT_h

#include <vector>
#include "GlutApp.h"
//#include <cmath>
#include "GenerateCircleData.h"

class TTT {
private:
	//int position = 1;
	bool circle = false;
public:
    std::vector<Vec*> data;
	TTT(bool circle, Vec * v, int win) {
        data.clear();
        glClearColor(0.0, 0.0, 0.0, 1.0);
        if (win)
            glColor3f(0.0, 1.0, 0.0);
        else
            glColor3f(1.0, 1.0, 1.0);
        glLineWidth(50);
        
        
		if (circle) {
			generateCircleData(data, *v, .23, 100);
			glBegin(GL_LINE_STRIP);
            for (std::vector<Vec*>::iterator i = data.begin(); i != data.end(); i++) {
				glVertex2f((*i)->getX(), (*i)->getY());
			}
			glEnd();
		}
        
        
		else {
			float dis = 0.2;
			glBegin(GL_LINE_STRIP);
				glVertex2f(v->getX() - dis, v->getY() - dis);
				glVertex2f(v->getX() + dis, v->getY() + dis);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(v->getX() - dis, v->getY() + dis);
				glVertex2f(v->getX() + dis, v->getY() - dis);
			glEnd();
		}
	}

};

#endif /* TTT_h */