#include "transform.h"

void Transform::shift(Shape& figure, int _x, int _y, int _z)
{
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_x(figure.get_points()[i].x + _x, i);
		figure.change_y(figure.get_points()[i].y + _y, i);
		figure.change_z(figure.get_points()[i].z + _z, i);
	}
};


void Transform::scale_up_x(Shape& figure, int _x) {
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_x(figure.get_points()[i].x * _x, i);
	}
};

void Transform::scale_down_x(Shape& figure, int _x) {
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_x(figure.get_points()[i].x / _x, i);
	}
};


void Transform::scale_up_y(Shape& figure, int _y) {
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_y(figure.get_points()[i].y * _y, i);
	}
};

void Transform::scale_down_y(Shape& figure, int _y) {
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_y(figure.get_points()[i].y / _y, i);
	}
};


void Transform::scale_up_z(Shape& figure, int _z) {
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_z(figure.get_points()[i].z * _z, i);
	}
};

void Transform::scale_down_z(Shape& figure, int _z) {
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_z(figure.get_points()[i].z / _z, i);
	}
};


void Transform::scale_up(Shape& figure, int n){
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_x(figure.get_points()[i].x * n, i);
		figure.change_y(figure.get_points()[i].y * n, i);
		figure.change_z(figure.get_points()[i].z * n, i);
	}
};

void Transform::scale_down(Shape& figure, int n){
	for (int i = 0; i < figure.get_points().size(); i++) {
		figure.change_x(figure.get_points()[i].x / n, i);
		figure.change_y(figure.get_points()[i].y / n, i);
		figure.change_z(figure.get_points()[i].z / n, i);
	}
};
