/*
 * author Andrew Tilisky
 */

#ifndef JSONNUMBER_HPP
#define JSONNUMBER_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>     /* atof */
#include <regex>
#include <exception>

#include "../jsonvalue.hpp"

using std::string;
using std::stringstream;
using std::regex;
using std::exception;

class JsonNumber: public JsonValue {
public:
//	JsonNumber();
//	JsonNumber(const string value);
	JsonNumber(const double value);

	const string representation() const;

	void accept(Visitor& v) const;
private:
	double _value;
//	const double parse() const;
};

#endif // JSONNUMBER_HPP