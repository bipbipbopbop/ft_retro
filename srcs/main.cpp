#include <iostream>
#include "Renderer.hpp"

int		main(void)
{
//	std::cout << "hello world\n";
	Renderer	r;

	while (1)
	{
		r.handleEvent();
	}
	return 0;
}