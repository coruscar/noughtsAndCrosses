#ifndef Rect_hpp
#define Rect_hpp

#include <iostream>
#include <stdio.h>
#include "GlutApp.h"


class eleBase{
public:
    float x,y,w,h;
    int color = 0;
    
    
    void build(){
        if(color == 1) {
            glColor3f(1.0,1.0,0.0); // RedGreen
        } else if (color == 2) {
            glColor3f(0.0, 0.0, 1.0); // Blue
        } else if (color == 3) {
            glColor3f(1.0, 1.0, 1.0); //White
        } else {
            glColor3f(0.0,0.0,0.0); // Black
        }
        glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x, y-h);
            glVertex2f(x+w,y-h);
            glVertex2f(x+w, y);
        glEnd();
    }
};


class Rect: public eleBase {
    
public:
    Rect() {
        x=0; y=0; w=0; h=0;
    }
    
    Rect(float x, float y, float w, float h){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        color = 0;
    }
    
    Rect(float x, float y, float w, float h, int color){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->color = color;
    }
    
    bool contains(float x, float y){
        if(x>=this->x && x<=(this->x+w) && y <= this->y && y>=(this->y-h))
            return true;
        else {
            return false;
        }
    }
    ~Rect();
};

//class cirSqu: public Rect{
//    
//    
//    
//    
//};

#endif /* Rect_hpp */
