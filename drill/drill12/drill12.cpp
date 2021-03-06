/*
    g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main(){
	

	Simple_window win {Point{100,100}, 600, 400, "My window"};
  
	/*Axis*/

	Axis xa{Axis::x, Point{50,400}, 300, 10, "x tengely"};
	Axis ya{Axis::y, Point{50,400}, 300, 10, "y tengely"};
	ya.set_color(Color::yellow);
	ya.label.set_color(Color::green);

	Function sine {sin,0,8,Point{50,350}, 500, 50, 50};
	sine.set_color(Color::red);

	/*Polygon*/

	Polygon poly;
	poly.add(Point{350,250});
	poly.add(Point{400,150});
	poly.add(Point{600,250});
	poly.set_color(Color::yellow);

	/*Closed polyline*/

	Closed_polyline poly_rect;
	poly_rect.add(Point{50,0});
	poly_rect.add(Point{150,0});
	poly_rect.add(Point{150,50});
	poly_rect.add(Point{50,50});
	poly_rect.add(Point{0,25});
	poly_rect.set_color(Color::blue);
	poly_rect.set_style(Line_style(Line_style::dash,3));

	/*Rectangle*/

	Rectangle tegla{Point{300,300}, 200, 50};
	tegla.set_fill_color(Color::black);

	/*Text*/

	Text t {Point{300,300}, "Text... Text... Text..."};
	t.set_font(Font::times_bold);
	t.set_font_size(15);
	t.set_color(Color::red);

	/*Image*/

	Image ii {Point{0,0},"image.jpg"};

	/*Circle*/

	Circle c {Point{600,300},50};
	Mark m {Point{600,300},'x'};

	/*x,y*/

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};


	win.attach(ii);
	win.attach(c);
	win.attach(m);
	win.attach(t);
	win.attach(sizes);
	win.attach(poly_rect);
	win.attach(tegla);
	win.attach(poly);
	win.attach(sine);
	win.attach(xa);
	win.attach(ya);


	win.wait_for_button();
	return 0;
	}