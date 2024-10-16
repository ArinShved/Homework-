#include "SqlSelectQueryBuilder.h"


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& str) {
		column = str;
		return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& first, const std::string& second) {
		std::pair<std::string, std::string> condition = { first, second };
		where.push_back(condition);
		return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& str) {
		from = str;
		return *this;
}

std::string SqlSelectQueryBuilder::buildQuery() const {
		std::string query;

		if (column.empty()) {
			query += "SELECT * ";
		}
		else {
			query += "SELECT " + column;
		}

		query += " FROM " + from;

		if (where.empty()) {
			query += ";";
			return query;
		}
		else {
			query += " WHERE ";
			for (auto& i : where) {
				query += i.first + " = " + i.second;
				query += " AND ";
			}
			query.erase(query.size() - 5);
			query += "; ";
			return query;
		}
	}
