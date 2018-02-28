#ifndef GenerateCircleData_h
#define GenerateCircleData_h
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
//#include "Vec.h"
using namespace std;

void generateCircleData(vector<vector<float>> &points, vector<float> &center, float radius, int resolution){
    // Clear the points vector to make sure it's empty before you start
    points.clear();
    
    // Provide the rest of the code here...
	for (double i = 0; i < 2*M_PI; i += 2*M_PI/resolution) {
		float xVal = center[0] + radius*cos(i);
		float yVal = center[1] + radius*sin(i);
        points[i] =  {xVal, yVal};
//		points.push_back(tempv);
	}
}

#endif
