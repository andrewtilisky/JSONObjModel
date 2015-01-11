/*
 * author Andrew Tilisky
 */

#ifndef JSONARRAY_HPP
#define JSONARRAY_HPP

#include "jsonvalue.hpp"

#include <vector>

using std::pair;
using std::vector;
using std::string;

class JsonArray: public JsonValue {
public:
	JsonArray();
	JsonArray(vector<const JsonValue*>);
//	JsonArray(string json_array_string);

	void AssignValue(const JsonValue*);
	const string representation() const;
	const vector<const JsonValue*> members() const;

	void accept(Visitor& v) const;
private:
	vector<const JsonValue*> _elements;
};

#endif // JSONARRAY_HPP
