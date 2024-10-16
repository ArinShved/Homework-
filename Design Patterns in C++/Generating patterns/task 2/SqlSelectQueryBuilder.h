#pragma once
#include <vector>
#include <string>

class SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder() = default;

	virtual SqlSelectQueryBuilder& AddColumn(const std::string& str);
	virtual SqlSelectQueryBuilder& AddWhere(const std::string& first, const std::string& second);
	virtual SqlSelectQueryBuilder& AddFrom(const std::string& str);
	virtual std::string buildQuery();
protected:
	std::string column = {};
	std::string from = {};
	std::pair<std::string, std::string> where = {};
}; 

class SqlSelectQueryBuilder_extended : public SqlSelectQueryBuilder {
public:
	SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& str);
	SqlSelectQueryBuilder& AddWhere(const std::string& first, const std::string& second) override;
	std::string buildQuery() override;
private:
	std::vector<std::string> column = {};
	std::vector<std::pair<std::string, std::string> > where = {};
};