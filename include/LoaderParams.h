#pragma once

#include <iostream>

struct LoaderParams
{
	const std::string path;
	const std::string id;
	const int width;
	const int height;
	const int x;
	const int y;
	const int numberOfFrames;
};
