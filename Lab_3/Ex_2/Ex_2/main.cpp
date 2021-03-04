#include "Canvas.h"
#include <iostream>

int main()
{
	Canvas art(80, 30);
	art.DrawCircle(10, 5, 12, 'a');
	art.Print();
	
	return 0;
}