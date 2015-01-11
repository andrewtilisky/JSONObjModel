/*
 * JsonBool.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: andrew
 */

#include "jsonbool.hpp"

//http://stackoverflow.com/questions/29383/converting-bool-to-text-in-c
JsonBool::JsonBool(const bool value) :
		_value(value) {
}

const string JsonBool::representation() const {
	return _value ? "true" : "false";
}
