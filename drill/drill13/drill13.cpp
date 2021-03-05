/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win{Point{100,100}, 800, 1000, "DRILL13"};


Vector_ref<Rectangle> negyzet;

	for(int i = 0; i < 8; ++i)
	{
		negyzet.push_back(new Rectangle{Point{i*100,i*100}, 100, 100});
		negyzet[negyzet.size()-1].set_fill_color(Color::red);
		win.attach(negyzet[negyzet.size()-1]);
	}
	Vector_ref<Image> img;
	img.push_back(new Image(Point{0,200}, "image.jpg"));
	img.push_back(new Image(Point{0,400}, "imageb.jpg"));
	img.push_back(new Image(Point{0,600}, "imagec.jpg"));

	img[0].set_mask(Point{100,100},200,200);
	img[1].set_mask(Point{100,100},200,200);
	img[2].set_mask(Point{100,100},200,200);
	
	Image logo {Point{0,0},"logo2.jpeg"};
	win.attach(logo);

	win.attach(img[0]);
	win.attach(img[1]);
	win.attach(img[2]);
	int x,y=0;
	while(win.wait_for_button())
	{
		if (x<=700 && y<=700)
		{
			logo.move(100,100);
			x+=100;
			y+=100;
		}else
		{
			logo.move(-800,-800);
			x=0;
			y=0;
		}
	}
	
}