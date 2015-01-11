/*
 * JsonNull.cpp
 *
 *  Created on: Apr 29, 2014
 *      Author: andrew
 */

#include "jsonnull.hpp"

#include <iostream>

using std::string;

JsonNull::JsonNull() {

}

const string JsonNull::representation() const {
	return "null";
}

