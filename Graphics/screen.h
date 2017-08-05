const int XMAX=40;
const int YMAX=24;

enum color { black='x', white=' ' };

class point {
public:
	int x, y;
	point() {}
	point(int a,int b) : x(a), y(b) {}
};

class screen {
	char screen_[XMAX] [YMAX];
public:
	void init();
	void refresh();
	void clear() { screen::init(); };
	int on_screen(int a, int b) { return 0<=a && a <XMAX && 0<=b && b<YMAX; }
	void put_point(int a, int b) {if (on_screen(a,b)) screen_[a] [b] = black;};
	void put_point(point p) { put_point(p.x,p.y); }
	void put_line(int, int, int, int);
	void put_line(point a, point b) { put_line(a.x,a.y,b.x,b.y); }
};