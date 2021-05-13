#pragma once
#include <vector>
#include <iostream>
#include "HSV.h"
#include "RGB.h"

namespace Colour_Converter
{
	HSV Convert_to_HSV(RGB& rgb); 
	RGB Convert_to_RGB(HSV& hsv); 
}
