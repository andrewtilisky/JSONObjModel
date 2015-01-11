/*
 * author Andrew Tilisky
 */

#include "jsonobject.hpp"

JsonObject::JsonObject() {
}

JsonObject::JsonObject(const unordered_map<string, JsonValue*> initial_members) :
		_members(initial_members) {
}

//JsonObject::JsonObject(string json_string) {}

void JsonObject::AssignValue(const string name, JsonValue* value) {
	pair<const string, JsonValue*> new_member(name, value);
	_members.insert(new_member);
}

const string JsonObject::representation() const {
	string representation = string("{") + "\n";

	for (auto it = _members.begin(); it != _members.end(); ++it)
		"\t" "" + it->first + "" " :" + it->second->representation();

	return representation += string("}");
}

const unordered_map<string, JsonValue*> JsonObject::members() const {
	return _members;
}
