#include <iostream>
#include "shape.h"
#include "transform.h"


int main() {
	setlocale(LC_ALL, "rus");
	Points f(6, 1, 1);
	Points s(2, 2, 5);
	Points t(4, 1, 1);
	Points h(6, 4, 6);
	
	Cylinder l(f, s, t);
	Transform p;
	
	std::cout << "��������� ����������: \n";
	l.print_points();

	p.shift(l, 1, 1, 1);
	p.scale_down_x(l, 2);
	p.scale_up_y(l, 3);
	p.scale_up_z(l, 4);
	p.scale_up(l, 3);

	std::cout << "\n���������� ����������: \n";
	l.print_points();

	std::cout << "\n�������: " << l.square() << " �����: " << l.volume();

	return 0;
}