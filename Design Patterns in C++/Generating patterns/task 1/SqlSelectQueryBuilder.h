#pragma once
#include <vector>
#include <string>

class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder() = default;

	SqlSelectQueryBuilder& AddColumn(const std::string& str);
	SqlSelectQueryBuilder& AddWhere(const std::string& first, const std::string& second);
	SqlSelectQueryBuilder& AddFrom(const std::string& str);
	std::string buildQuery() const;
private:
	std::string column = {};
	std::string from = {};
	std::vector<std::pair<std::string, std::string> > where = {};
};