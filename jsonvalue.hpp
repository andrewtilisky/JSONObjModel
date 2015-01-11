/*
 * author Andrew Tilisky
 */

#ifndef JSONVALUE_HPP
#define JSONVALUE_HPP

#include <iostream>

//#include "visitor.hpp"
//class Visitor;

using std::string;
using std::cout;

class JsonValue {
public:
//	JsonValue();
//	JsonValue(const string value);
	virtual ~JsonValue() = 0;
	virtual const string representation() const = 0;

	virtual void accept(class Visitor& v) const = 0;
private:
};

#endif // JSONVALUE_HPP
