/*
 * author Andrew Tilisky
 */

#include "jsonstring.hpp"

/*
 * empty string makes sense as a default value
 * but if that's what the user wants they can
 * pass one to the other constructor.
 */
//JsonString::JsonString() {
//	_value = "\"\"";
//}
JsonString::JsonString(const string value) :
		_value(value) {
}

const string JsonString::representation() const {
	return "\"" + _value + "\"";
}
