#include <iostream>
#include "SqlSelectQueryBuilder.h"

int main() {
	try {
		SqlSelectQueryBuilder_comparison test;
		test.AddColumns({ "name" });
		test.AddFrom("book");
		test.AddWhere("name", "Ko");
		test.AddWhere("id", "7");
		test.AddWhereCondition({ "count", "9" }, ">");
		std::cout << test.buildQuery() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}