#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif

rectangle::rectangle(point a, point b) {
	if (a.x <= b.x) {
		if (a.y <= b.y) {
			sw = a;
			ne = b;
		}
  		else {
	     	sw = point(a.x,b.y);
	     	ne = point(b.x,a.y);
		}
	} else {
  		if (a.y <= b.y) {
     		sw = point(b.x,a.y);
     		ne = point(a.x,b.y);
		} else {
			sw = b;
			ne = a;
		}
	}
}

void rectangle::draw(screen& scr) {
     point nw(sw.x,ne.y);
     point se(ne.x,sw.y);
     scr.put_line(nw,ne);
     scr.put_line(ne,se);
     scr.put_line(se,sw);
     scr.put_line(sw,nw);
}
