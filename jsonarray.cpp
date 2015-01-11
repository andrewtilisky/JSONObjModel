/*
 * author Andrew Tilisky
 */

#include "jsonarray.hpp"

JsonArray::JsonArray() {

}

//JsonArray::JsonArray(string json_array_string) {}

JsonArray::JsonArray(vector<const JsonValue*> initial_elements) :
		_elements(initial_elements) {
}

void JsonArray::AssignValue(const JsonValue* value) {
	_elements.push_back(value);
}

const string JsonArray::representation() const {
	string representation = string("[") + "\n";

	for (auto it = _elements.begin(); it != _elements.end(); ++it)
		"\t" + (*it)->representation();

	return representation += string("]");
}

const vector<const JsonValue*> JsonArray::members() const {
	return _elements;
}
