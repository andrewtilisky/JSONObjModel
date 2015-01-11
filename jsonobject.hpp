/*
 * author Andrew Tilisky
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <unordered_map>
#include <iostream>

#include "jsonvalue.hpp"

using std::pair;
using std::unordered_map;
using std::string;

class JsonObject: public JsonValue {
public:
	JsonObject();
	JsonObject(const unordered_map<string, JsonValue*>);
//	JsonObject(string json_string);

	void AssignValue(const string, JsonValue*);
	const string representation() const;
	const unordered_map<string, JsonValue*> members() const;

	void accept(Visitor& v) const;
private:
	unordered_map<string, JsonValue*> _members;
};

#endif // OBJECT_HPP
