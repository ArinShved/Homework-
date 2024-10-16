#include <iostream>
#include <string>

#include "SqlSelectQueryBuilder.h"


int main() {
	try {
		SqlSelectQueryBuilder test;
		test.AddColumn("name");
		test.AddColumn("age");
		test.AddFrom("book");
		test.AddWhere("name", "Ko");
		test.AddWhere("id", "7");

		std::cout << test.buildQuery();
		
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}