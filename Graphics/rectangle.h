#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#endif

class rectangle : public shape { 
/* nw ------ n ------ ne 
|                       | 
|                       |
|                       |               
w            c          e 
|                       | 
|                       |
|                       |
|                       |
 sw ------   s -----   se */

	point sw, ne;
public:
	point north() const { return point((sw.x+ne.x)/2,ne.y); };
	point south() const { return point((sw.x+ne.x)/2,sw.y); };
	point east()  const {return point(ne.x, (sw.y+ne.y)/2); };
	point west()  const {return point(sw.x, (sw.y+ne.y)/2); };
	point neast() const { return ne; };
	point seast() const {return point(ne.x, sw.y); };
	point nwest() const {return point(sw.x, ne.y); };
	point swest() const { return sw; };
	void move(int a, int b) { sw.x+=a; sw.y+=b; ne.x+=a; ne.y+=b; };
	void draw();
	rectangle(point,point);
};
