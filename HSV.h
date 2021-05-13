#pragma once
#include <vector>
#include <iostream>

class HSV
{
private:
	double hue;
	double saturation;
	double value;
public:
	HSV();
	HSV(double hue_, double saturation_, double value_);
	friend std::ostream& operator<<(std::ostream& os, const HSV& shade);
	bool operator==(const HSV& rhs);
	HSV modify_hue(double hue_);
	HSV modify_saturation(double saturation_);
	HSV modify_value(double value_);
	double get_hue() const;
	double get_saturation() const;
	double get_value() const;
};