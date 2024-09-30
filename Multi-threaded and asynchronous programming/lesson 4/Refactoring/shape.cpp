#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>

Points::Points(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};


double const Shape::volume() {
	return 0;

};

double const Shape::square() {
	return 0;

};

void const Shape::print_points() {
	for (auto i : coordinates)
		std::cout << i.x << " " << i.y << " " << i.z << "\n";
};

void const Shape::change_x(int i, int pos) {
	if (pos < coordinates.size()) {
		coordinates[pos].x = i;
	}
};

void const Shape::change_y(int i, int pos){
	if (pos < coordinates.size()) {
		coordinates[pos].y = i;
	}
};

void const Shape::change_z(int i, int pos) {
	if (pos < coordinates.size()) {
		coordinates[pos].z = i;
	}
};

std::vector<Points> const Shape::get_points() {
	return coordinates;
}



Line::Line(Points& first, Points& second) {
	coordinates = { first, second };
};



Rectangle::Rectangle(Points& first, Points& second, Points& third, Points& fourth)  {
	coordinates = { first, second, third, fourth };
};

double const Rectangle::square() {
	double height = abs(coordinates[1].y - coordinates[0].y);
	double lenght = abs(coordinates[1].x - coordinates[0].x);
	return height * lenght;
};



Cube::Cube(Points& first, Points& second, Points& third, Points& fourth,
	Points& fifth, Points& sixth, Points& seventh, Points& eighth) {
	coordinates = { first, second, third, fourth, fifth, sixth, seventh, eighth };
};

double const Cube::volume() {
	double height = abs(coordinates[1].y - coordinates[0].y);
	double lenght = abs(coordinates[1].x - coordinates[0].x);
	double width =  abs(coordinates[1].z - coordinates[0].z);
	return height * lenght * width;
};
double const Cube::square() {
	double height = abs(coordinates[1].y - coordinates[0].y);
	double lenght = abs(coordinates[1].x - coordinates[0].x);
	double width =  abs(coordinates[1].z - coordinates[0].z);
	return 2 * ( height * width + height * lenght + width * lenght);
};


Circle::Circle(Points& center, Points& ring) {
	coordinates = {center, ring};
};

double const Circle::square() {
	double radius = coordinates[1].x - coordinates[0].x;
	return M_PI * radius * radius;
};


Cylinder::Cylinder(Points& top_center, Points& bottom_center, Points& ring){
	coordinates = { top_center, bottom_center, ring };
};

double const Cylinder::volume() {
	double radius = coordinates[2].x - coordinates[1].x;
	double cylind_height = coordinates[1].y - coordinates[0].y;
	return M_PI * radius * radius * cylind_height;

};

double const Cylinder::square() { 
	double radius = coordinates[2].x - coordinates[1].x;
	double cylind_height = coordinates[1].y - coordinates[0].y;
	return M_PI * radius * radius + 2 * radius * cylind_height;

};
