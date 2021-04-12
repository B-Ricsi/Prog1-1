/*
    g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o drill16 `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	const int xmax = 1366, ymax = 768;
	Lines_window win{Point{100,100}, xmax, ymax, "lines"};


	return gui_main();
}
