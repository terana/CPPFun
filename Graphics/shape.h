#ifndef SCREEN_H
#define SCREEN_H
#include "screen.h"
#endif

class shape;

static shape* list;

class shape {
public:
     shape* next;
     shape() { next = list; list = this; }
     virtual point north() const = 0;
     virtual point south() const = 0;
     virtual point east() const = 0;
     virtual point west() const = 0;
     virtual point neast() const = 0;
     virtual point seast() const = 0;
     virtual point nwest() const = 0;
     virtual point swest() const = 0;
     virtual void draw() = 0;
     virtual void move(int, int) = 0;
};

static void shape_refresh() {
     screen_clear();
     for (shape* p = list; p; p=p->next) p->draw();
     screen_refresh();
}

static void stack(shape* p, const shape* q) // поместить p над q 
{
     point n = q->north();
     point s = p->south();
     p->move(n.x-s.x,n.y-s.y+1);
}

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



class line : public shape {
  /*
отрезок прямой ["w", "e" ]
north() определяет точку - `` выше центра отрезка и так далеко на север, как самая его северная точка''
  */
     point w, e;
public:
     point north() const { return point((w.x+e.x)/2,e.y<w.y?w.y:e.y); };
     point south() const { return point((w.x+e.x)/2,e.y<w.y?e.y:w.y); };
     point east()  const { return point(e.x, (w.y + e.y)/2) ;};
     point west()  const { return point(w.x, (w.y + e.y)/2) ;};
     point neast() const { return point(e.x, e.y<w.y?w.y:e.y); };
     point seast() const { return point(e.x, e.y<w.y?e.y:w.y); };
     point nwest() const { return point(w.x, e.y<w.y?w.y:e.y); };
     point swest() const { return point(w.x, e.y<w.y?e.y:w.y); };
     void move(int a, int b) { w.x +=a; w.y +=b; e.x +=a; e.y +=b; };
     void draw() { put_line(w,e); };
     line(point a, point b) { w = a; e = b; };
     line(point a, int l) { w = point(a.x+l-1,a.y); e = a; };
};