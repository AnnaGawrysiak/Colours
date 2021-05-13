#include "Colour_Converter.h"
#include <vector>
#include <iostream>

HSV Colour_Converter::Convert_to_HSV(RGB& rgb)
{

	/*
	The RGB model makes use of the fact that when we mix these three primary colors, we will be able to
	achieve other colors. For that purpose, we represent these primary colors alone in three values
	(red, green, blue) respectively. Based on this combination, we can define other colors by bringing
	about the mix of the specified values. These individual values can range from 0, 255.
	*/
	// R, G, B values are divided by 255 to change the range from 0..255 to 0..1
	double red = rgb.get_red() / 255.0;
	double green = rgb.get_green() / 255.0;
	double blue = rgb.get_blue() / 255.0;
	
	double max_rgb = red > green ? (red > blue ? red : blue) : (green > blue ? green : blue);
	double min_rgb = red < green ? (red < blue ? red : blue) : (green < blue ? green : blue);

	double difference = max_rgb - min_rgb;

	// Hue calculation
	// if cmax and cmin equal 0, then h = 0
	HSV hsv_shade;

	if (max_rgb == 0 && min_rgb == 0)
	{
		hsv_shade = hsv_shade.modify_hue(0);
	}
	else if (max_rgb == red)
	{
		hsv_shade = hsv_shade.modify_hue(fmod(60 * ((green - blue) / difference) + 360, 360));
	}
	else if (max_rgb == green)
	{
		hsv_shade = hsv_shade.modify_hue(fmod(60 * ((blue - red) / difference) + 120, 360));
	}
	else if (max_rgb == blue)
	{
		hsv_shade = hsv_shade.modify_hue(fmod(60 * ((red - green) / difference) + 240, 360));
	}

	// Saturation computation :
	if (max_rgb == 0)
		hsv_shade = hsv_shade.modify_saturation(0);
	else
		hsv_shade = hsv_shade.modify_saturation((difference / max_rgb) * 100);

	// Value computation
	hsv_shade = hsv_shade.modify_value(max_rgb * 100);

	return hsv_shade;
}


RGB Colour_Converter::Convert_to_RGB(HSV& hsv)
{
	double chroma = (hsv.get_value() / 100.0) * (hsv.get_saturation() / 100.0);
	double rgb_min = (hsv.get_value() / 100.0) - chroma;
	double intermediate = chroma * (1 - fabs(fmod(hsv.get_hue() / 60.0, 2) - 1));

	RGB rgb_shade;

	if (hsv.get_hue() >= 0 && hsv.get_hue() < 60)
	{
		rgb_shade = rgb_shade.modify_red((chroma + rgb_min) * 255);
		rgb_shade = rgb_shade.modify_green((intermediate + rgb_min) * 255);
		rgb_shade = rgb_shade.modify_blue(rgb_min * 255);

		return rgb_shade;
	}
	else if (hsv.get_hue() >= 60 && hsv.get_hue() < 120)
	{
		rgb_shade = rgb_shade.modify_red((intermediate + rgb_min) * 255);
		rgb_shade = rgb_shade.modify_green((chroma + rgb_min) * 255);
		rgb_shade = rgb_shade.modify_blue(rgb_min * 255);

		return rgb_shade;
	}

	else if (hsv.get_hue() >= 120 && hsv.get_hue() < 180)
	{
		rgb_shade = rgb_shade.modify_red(rgb_min * 255),
		rgb_shade = rgb_shade.modify_green((chroma + rgb_min) * 255);
		rgb_shade = rgb_shade.modify_blue((rgb_min + intermediate) * 255);

		return rgb_shade;
	}

	else if (hsv.get_hue() >= 180 && hsv.get_hue() < 240)
	{
		rgb_shade = rgb_shade.modify_red(rgb_min * 255);
		rgb_shade = rgb_shade.modify_green((intermediate + rgb_min) * 255);
		rgb_shade = rgb_shade.modify_blue((rgb_min + chroma) * 255);

		return rgb_shade;
	}

	else if (hsv.get_hue() >= 240 && hsv.get_hue() < 300)
	{
		rgb_shade = rgb_shade.modify_red((rgb_min + intermediate) * 255);
		rgb_shade = rgb_shade.modify_green(rgb_min * 255);
		rgb_shade = rgb_shade.modify_blue((rgb_min + chroma) * 255);

		return rgb_shade;
	}

	else if (hsv.get_hue() >= 300 && hsv.get_hue() < 360)
	{
		rgb_shade = rgb_shade.modify_red((rgb_min + chroma) * 255);
		rgb_shade = rgb_shade.modify_green(rgb_min * 255);
		rgb_shade = rgb_shade.modify_blue((rgb_min + intermediate) * 255);

		return rgb_shade;
	}

	else
	{
		rgb_shade = rgb_shade.modify_red(rgb_min * 255);
		rgb_shade = rgb_shade.modify_green(rgb_min * 255);
		rgb_shade = rgb_shade.modify_blue(rgb_min * 255);

		return rgb_shade;
	}

	return rgb_shade;
}