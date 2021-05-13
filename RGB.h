#pragma once
#include <vector>
#include <iostream>

class RGB
{
private:
	double red;
	double green;
	double blue;
public:
	RGB();
	RGB(double red_, double green_, double blue_);
	friend std::ostream& operator <<(std::ostream& sream, const RGB& shade);
	bool operator==(const RGB& rhs);
	double get_red() const;
	double get_green() const;
	double get_blue() const;
	RGB modify_red(double red_);
	RGB modify_green(double green_);
	RGB modify_blue(double blue_);
};

