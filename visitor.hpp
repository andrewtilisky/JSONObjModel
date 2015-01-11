/*
 * Visitor.hpp
 *
 *  Created on: May 2, 2014
 *      Author: andrew
 */

#ifndef VISITOR_HPP_
#define VISITOR_HPP_

//class JsonNumber;
//class JsonString;
//class JsonBool;
//class JsonNull;
//class JsonArray;
//class JsonObject;
//class JsonValue;

#include "primitives/jsonbool.hpp"
#include "primitives/jsonnull.hpp"
#include "primitives/jsonnumber.hpp"
#include "primitives/jsonstring.hpp"
#include "jsonarray.hpp"
#include "jsonobject.hpp"

class Visitor {
public:
	virtual void visit(const JsonNumber&) = 0;
	virtual void visit(const JsonBool&) = 0;
	virtual void visit(const JsonNull&) = 0;
	virtual void visit(const JsonString&) = 0;
	virtual void visit(const JsonArray&) = 0;
	virtual void visit(const JsonObject&) = 0;

	virtual ~Visitor() {
	}
};

#endif /* VISITOR_HPP_ */
