﻿// mpgre1.cpp : Defines the entry point for the application.
//

#include <iostream>

#include "test.hpp"
#include "renderer.hpp"

using namespace std;

int main(int, char **)
{

	mpgre::renderer app(1);

	app.mainLoop();

}
