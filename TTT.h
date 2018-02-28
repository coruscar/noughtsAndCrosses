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
    //vector<Vec*> data;
	TTT(bool circle, vector<float> &p) {
        //data.clear();
        
        vector<vector<float>> data;
		

		if (circle) {
			generateCircleData(data, p, .23, 100);
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glLineWidth(50);
			glBegin(GL_LINE_STRIP);
            
            for (int i = 0;i < data.size(); i++){
                glVertex2f(data[i][0], data[i][1]);
            }
//			for (vector<float>::iterator i = data.begin(); i != data.end(); i++) {
//				glVertex2f((*i)->getX(), (*i)->getY());
//			}
			glEnd();
		}
		else {
			float dis = 0.2;
			glClearColor(0.0, 0.0, 0.0, 1.0);
			glLineWidth(50);
			glBegin(GL_LINE_STRIP);
				glVertex2f(p[0] - dis, p[1] - dis);
				glVertex2f(p[0] + dis, p[1] + dis);
			glEnd();
			glBegin(GL_LINE_STRIP);
				glVertex2f(p[0] - dis, p[1] + dis);
				glVertex2f(p[0] + dis, p[1] - dis);
			glEnd();

		}
	}

};



#endif /* TTT_h */