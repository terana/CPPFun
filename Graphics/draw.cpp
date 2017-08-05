#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif

class face_shape : public rectangle {
	line* l_eye;
	line* r_eye;
	line* mouth;
public:
  face_shape(point, point);
  void draw(screen& scr);
  void move(int, int);
};

face_shape::face_shape(point a, point b) : rectangle(a,b) {
     int ll = neast().x-swest().x+1;
     int hh = neast().y-swest().y+1;
     l_eye = new line(point(swest().x+2,swest().y+hh*3/4),2);
     r_eye = new line(point(swest().x+ll-4,swest().y+hh*3/4),2);
     mouth = new line(point(swest().x+2,swest().y+hh/4),ll-4);
}

void face_shape::draw(screen& scr) {
     rectangle::draw(scr);
     int a = (swest().x+neast().x)/2;
     int b = (swest().y+neast().y)/2;
     scr.put_point(point(a,b));
}

void face_shape::move(int a, int b) {
     rectangle::move(a,b);
     l_eye->move(a,b);
     r_eye->move(a,b);
     mouth->move(a,b);
}


int main() {
	screen scr;
	scr.init();
	shape* p1 = new rectangle(point(0,0),point(10,10));
	shape* p2 = new line(point(0,15),17);
	shape* p3 = new face_shape(point(15,10),point(27,18));
	p3->move(-10,-10);
	stack(p2,p3);
	stack(p1,p2);
	shape_refresh(scr);
     return 0;
}