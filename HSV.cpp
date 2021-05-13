#include "HSV.h"
#include <iostream>
#include <vector>

HSV::HSV()
{
	hue = 0;
	saturation = 0;
	value = 0;
}

HSV::HSV(double hue_, double saturation_, double value_)
{
	hue = hue_;
	saturation = saturation_;
	value = value_;
}

std::ostream& operator<<(std::ostream& os, const HSV& shade)
{
	os << " hue: " << shade.hue << ", saturation: " << shade.saturation << ", value: " << shade.value << std::endl;
	return os;
}

bool HSV::operator==(const HSV& rhs)
{
	if (hue == rhs.hue && saturation == rhs.saturation && value == rhs.value) 
		return true;

	return false;
}

double HSV::get_hue() const
{
	return hue;
}
double HSV::get_saturation() const
{
	return saturation;
}
double HSV::get_value() const
{
	return value;
}

HSV HSV::modify_hue(double hue_)
{
	HSV shade(hue_, saturation, value);

	return shade;
}

HSV HSV::modify_saturation(double saturation_)
{
	HSV shade(hue, saturation_, value);

	return shade;
}

HSV HSV::modify_value(double value_)
{
	HSV shade(hue, saturation, value_);

	return shade;
}
