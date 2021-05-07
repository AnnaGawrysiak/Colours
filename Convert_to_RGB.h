#pragma once
#include <vector>
#include "RGB.h"
#include "HSV.h"

namespace Colour_Converter
{
	RGB Convert_to_RGB(double hue, double saturation, double value); // przerob na RGB typ zwracany

}
