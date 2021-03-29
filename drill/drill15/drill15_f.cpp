/*
    g++ drill15_f.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_f `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x_axis) { return 1; }
double slope(double x_axis) { return x_axis/2; }
double square(double x_axis) { return pow(x_axis,2); }
double sloping_cos(double x_axis) { return cos(x_axis) + slope(x_axis); }

int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{0,0}, 600, 600, "Function graphs"};

	int x_origo = 300, y_origo = 300;
	Point origo {x_origo, y_origo};
	double x_length = 400, y_length = 400;
	double x_scale = 20, y_scale = 20;
	Axis x_axis {Axis::x, Point{x_origo - x_length / 2, y_origo}, x_length, x_length / x_scale, "1 == 20 pixels"};
	Axis y_axis {Axis::y, Point{x_origo , y_origo + y_length / 2}, y_length, y_length / y_scale, "1 == 20 pixels"};
	x_axis.set_color(Color::red);
	y_axis.set_color(Color::red);

	double rmin = -10, rmax = 11;
	int points = 400;

	Function a {one, rmin, rmax, origo, points, x_scale, y_scale};

	Function b {slope, rmin, rmax, origo, points, x_scale, y_scale};
	Text t {Point{100,400},"x/2"};

	Function c {square, rmin, rmax, origo, points, x_scale, y_scale};

	Function d {cos, rmin, rmax, origo, points, x_scale, y_scale};
	d.set_color(Color::blue);

	Function e {sloping_cos, rmin, rmax, origo, points, x_scale, y_scale};

	win.attach(x_axis);
	win.attach(y_axis);
	win.attach(a);
	win.attach(b);
	win.attach(t);
	win.attach(c);
	win.attach(d);
	win.attach(e);

	win.wait_for_button();
}