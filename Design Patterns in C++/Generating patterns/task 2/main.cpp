#include <iostream>

#include "SqlSelectQueryBuilder.h"


int main() {
	try {
		SqlSelectQueryBuilder builder_1;
		builder_1.AddColumn("name");
		builder_1.AddFrom("book");
		builder_1.AddWhere("name", "Ko");

		std::cout << builder_1.buildQuery() << std::endl;

		SqlSelectQueryBuilder_extended builder_2;
		builder_2.AddColumns({ "name", "age" });
		builder_2.AddFrom("book");
		builder_2.AddWhere("name", "Ko");
		builder_2.AddWhere("id", "2");

		std::cout << builder_2.buildQuery() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}