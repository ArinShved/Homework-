#pragma once

class BadLength : public std::exception {
public:
	const char* what() const override;
};

int function(std::string str, int forbidden_length);