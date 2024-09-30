#pragma once
#include <string>
#include <vector>
#include <iostream>

struct Points {
	int x, y, z;
	Points(int _x, int _y, int _z);
};

class Shape
{
public:
	virtual double const volume();
	virtual double const square();
	std::vector<Points> const get_points();
	void const print_points();
	void const change_x(int i, int pos);
	void const change_y(int i, int pos);
	void const change_z(int i, int pos);
protected:
	std::vector<Points> coordinates;
};

class Line : public Shape {
public:
	Line(Points& first, Points& second);
};

class Rectangle : public Shape {
public:
	Rectangle(Points& first, Points& second, Points& third, Points& fourth);
	double const square() override;
};

class Cube : public Shape {
public:
	Cube(Points& first, Points& second, Points& third, Points& fourth, 
		Points& fifth, Points& sixth, Points& seventh, Points& eighth);
	double const volume() override;
	double const square() override;
};

class Circle : public Shape {
public:
	Circle(Points& center, Points& ring);
	double const square() override;
};

class Cylinder : public Shape { 
public:
	Cylinder(Points& top_center, Points& bottom_center, Points& ring);
	double const volume() override;
	double const square() override;
};
