/*
    g++ ppp12_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o ppp12_1 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	Simple_window win {Point{100,100}, 600, 400, "My Window"};

	Rectangle rectangle {Point{300,300}, 100, 50};
	rectangle.set_color(Color::blue);

	Polygon poly;
	poly.add(Point{450,300});
	poly.add(Point{550,300});
	poly.add(Point{550,350});
	poly.add(Point{450,350});
	poly.set_color(Color::red);

	win.attach(rectangle);
	win.attach(poly);
	win.wait_for_button();
}