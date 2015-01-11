/*
 * author Andrew Tilisky
 */

#ifndef JSONSTRING_HPP
#define JSONSTRING_HPP

#include <iostream>

#include "../jsonvalue.hpp"

using std::string;

class JsonString: public JsonValue {
public:
//	JsonString();
	JsonString(const string value);
//	void print() const;
	const string representation() const;

	void accept(Visitor& v) const;
private:
	string _value;
};

#endif // JSONSTRING_HPP