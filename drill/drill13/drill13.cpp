/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	Simple_window win{Point{100,100}, 800, 1000, "DRILL13"};

	Lines negyzet;

	for (int i = 100; i < 800; i+=100)
	{
		negyzet.add(Point{i,0},Point{i,800});
		negyzet.add(Point{0,i},Point{800,i});
	}

	win.attach(negyzet);

	Vector_ref<Rectangle> piros_negyzet;

	for(int i=0;i<8;i++)
	{
		piros_negyzet.push_back(new Rectangle {Point{i*100,i*100}, 100, 100});
		piros_negyzet[i].set_fill_color(Color::red);
		win.attach(piros_negyzet[i]);
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
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			win.wait_for_button();
			if (j<7)
			{
				logo.move(100,0);
			}else
			{
				logo.move(-700,100);
			}
		}
	}
	win.wait_for_button();
	
}