#ifndef TTT_h
#define TTT_h


#include <vector>
#include "GlutApp.h"
//#include <cmath>
#include "GenerateCircleData.h"


using namespace std;


class TTT {
private:
	//int position = 1;
	bool circle = false;
public:

	TTT(bool circle, Vec * v) {
		vector<Vec*> data;
		

		if (circle) {
			generateCircleData(data, *v, .23, 100);
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glLineWidth(50);
			glBegin(GL_LINE_STRIP);

			for (vector<Vec*>::iterator i = data.begin(); i != data.end(); i++) {
				glVertex2f((*i)->getX(), (*i)->getY());
			}
			glEnd();
		}
		else {
			float dis = 0.2;
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glLineWidth(50);
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