/*
 * author Andrew Tilisky
 */

#include "jsonnumber.hpp"

///not sure what the default value of a number would be
//JsonNumber::JsonNumber() {
//	_value = "";
//}

struct InvalidStringRepresentation: public exception {
	const char* what() const throw () {
		return "The string passed to the constructor isn't a valid representtion of a JSON number.";
	}
};

//JsonNumber::JsonNumber(const string string_representation) :
//		_value(::atof(_value.c_str())) {
//http://stackoverflow.com/questions/13340717/json-numbers-regular-expression
//	if (not regex_match(string_representation,
//			regex("-?(?:0|[1-9]\\d*)(?:\\.\\d+)?(?:[eE][+-]?\\d+)?")))
//		throw InvalidStringRepresentation();
//	_value = string_representation;
//}

JsonNumber::JsonNumber(const double value) :
		_value(value) {
//	std::ostringstream ss;
//	ss << value;
//	_value = ss.str();
}

//http://stackoverflow.com/questions/1012571/stdstring-to-float-or-double
//const double JsonNumber::parse() const {
//	return ::atof(_value.c_str());
//}

const string JsonNumber::representation() const {
	std::ostringstream ss;
	ss << _value;
	return ss.str();
}
