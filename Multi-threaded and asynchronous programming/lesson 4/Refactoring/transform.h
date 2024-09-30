#pragma once
#include"shape.h"

class Transform
{
public:
	void shift(Shape& figure, int _x, int _y, int _z);

	void scale_up_x(Shape& figure, int _x);
	void scale_down_x(Shape& figure, int _x);

	void scale_up_y(Shape& figure, int _y);
	void scale_down_y(Shape& figure, int _y);

	void scale_up_z(Shape& figure, int _z);
	void scale_down_z(Shape& figure, int _z);

	void scale_up(Shape& figure, int s);
	void scale_down(Shape& figure, int s);


};

