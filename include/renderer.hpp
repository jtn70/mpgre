#pragma once
#include <iostream>

namespace mpgre
{
	class renderer
	{
	public:
		renderer(int number);
		~renderer();

		void mainLoop();
	};
}