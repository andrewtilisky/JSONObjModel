/*
 * visitor.cpp
 *
 *  Created on: May 3, 2014
 *      Author: andrew
 */

#include "visitor.hpp"

void JsonBool::accept(Visitor& v) const {
	v.visit(*this);
}

void JsonNull::accept(Visitor& v) const {
	v.visit(*this);
}

void JsonNumber::accept(Visitor& v) const {
	v.visit(*this);
}

void JsonString::accept(Visitor& v) const {
	v.visit(*this);
}

void JsonArray::accept(Visitor& v) const {
	v.visit(*this);
}

void JsonObject::accept(Visitor& v) const {
	v.visit(*this);
}
