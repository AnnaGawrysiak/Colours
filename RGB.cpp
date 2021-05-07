#include "RGB.h"
#include <iostream>
#include <vector>

RGB::RGB()
{
	red = -1;
	green = -1;
	blue = -1;
}

RGB::RGB(double red_, double green_, double blue_)
{
	red = red_;
	green = green_;
	blue = blue_;
}

std::ostream& operator <<(std::ostream& stream, const RGB& shade)
{
	stream << " red: " << shade.red << ", green: " << shade.green << ", blue: " << shade.blue << std::endl;

	return stream;
}

bool RGB::operator==(const RGB& rhs)
{
	if (red == rhs.red && green == rhs.green && blue == rhs.blue)
		return true;

	return false;
}