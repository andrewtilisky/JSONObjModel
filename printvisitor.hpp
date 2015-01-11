/*
 * printvisitor.hpp
 *
 *  Created on: May 2, 2014
 *      Author: andrew
 */

#ifndef PRINTVISITOR_HPP_
#define PRINTVISITOR_HPP_

#include "visitor.hpp"

#include <iostream>
#include <unordered_map>

using std::endl;
using std::cout;
using std::pair;
using std::unordered_map;

class PrintVisitor: public Visitor {
public:
	void print(JsonValue* value);
private:
//	void print_json_object(const JsonObject& value);
	void visit(const JsonObject& value);
	void visit(const JsonArray& value);
	void visit(const JsonString& value);
	void visit(const JsonNumber& value);
	void visit(const JsonNull& value);
	void visit(const JsonBool& value);
};

#endif /* PRINTVISITOR_HPP_ */
