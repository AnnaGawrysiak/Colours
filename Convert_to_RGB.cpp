#include <iostream>
#include <vector>
#include "Convert_to_RGB.h"


RGB Colour_Converter::Convert_to_RGB(double hue, double saturation, double value)
{
	double chroma = (value / 100.0) * (saturation / 100.0);
	double rgb_min = (value / 100.0) - chroma;
	double intermediate = chroma * (1 - fabs(fmod(hue / 60.0, 2) - 1));

	RGB rgb_shade;

	if (hue >= 0 && hue < 60)
	{
		rgb_shade.red = (chroma + rgb_min) * 255;
		rgb_shade.green = (intermediate + rgb_min) * 255;
		rgb_shade.blue = rgb_min * 255;

		return rgb_shade;
	}
	else if (hue >= 60 && hue < 120)
	{
		rgb_shade.red = (intermediate + rgb_min) * 255;
		rgb_shade.green = (chroma + rgb_min) * 255;
		rgb_shade.blue = rgb_min * 255;

		return rgb_shade;
	}

	else if (hue >= 120 && hue < 180)
	{
		rgb_shade.red = rgb_min * 255,
		rgb_shade.green = (chroma + rgb_min) * 255;
		rgb_shade.blue = (rgb_min + intermediate) * 255;

		return rgb_shade;
	}

	else if (hue >= 180 && hue < 240)
	{
		rgb_shade.red = rgb_min * 255;
		rgb_shade.green = (intermediate + rgb_min) * 255;
		rgb_shade.blue = (rgb_min + chroma) * 255;

		return rgb_shade;
	}

	else if (hue >= 240 && hue < 300)
	{
		rgb_shade.red = (rgb_min + intermediate) * 255;
		rgb_shade.green = rgb_min * 255;
		rgb_shade.blue = (rgb_min + chroma) * 255;

		return rgb_shade;
	}

	else if (hue >= 300 && hue < 360)
	{
		rgb_shade.red = (rgb_min + chroma) * 255;
		rgb_shade.green = rgb_min * 255;
		rgb_shade.blue = (rgb_min + intermediate) * 255;

		return rgb_shade;
	}

	else
	{
		rgb_shade.red = rgb_min * 255;
		rgb_shade.green = rgb_min * 255;
		rgb_shade.blue = rgb_min * 255;

		return rgb_shade;
	}

	return rgb_shade;
}