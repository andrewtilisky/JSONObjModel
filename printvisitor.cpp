/*
 * printvisitor.cpp
 *
 *  Created on: May 2, 2014
 *      Author: andrew
 */

#include "printvisitor.hpp"

void PrintVisitor::print(JsonValue* value) {
	value->accept(*this);
}

//void PrintVisitor::print_json_object(const JsonObject* value) const const {
//	cout << 'const {' << endl;
//
//	for (auto it = value->members().begin(); it != value->members().end(); ++it)
//		cout << "" "" << it->first << "" " :" << it->second->representation();
//
//	cout << '}' << endl;
//}

void PrintVisitor::visit(const JsonObject& object) {
//	printf("visiting object");
//	printf("\n%lu members\n", object.members().size());

	printf("{\n");

	unordered_map<string, JsonValue*> members = object.members();
	for (auto it = members.begin(); it != members.end(); ++it) {
		if (it != members.begin())
			printf(",\n");

		printf("    \"%s\": ", it->first.c_str());
		it->second->accept(*this);
	}
	printf("\n}");
}

void PrintVisitor::visit(const JsonArray& array) {
	printf("[\n");

	vector<const JsonValue*> members = array.members();
	for (auto it = members.begin(); it != members.end(); ++it) {
		if (it != members.begin())
			printf(",\n");

		(*it)->accept(*this);
	}
	printf("\n]");
}

void PrintVisitor::visit(const JsonString& string) {
//	printf("visiting string");
	printf("%s", string.representation().c_str());
}

void PrintVisitor::visit(const JsonNumber& number) {
//	printf("visiting number");
	printf("%s", number.representation().c_str());
}

void PrintVisitor::visit(const JsonNull& null) {
//	printf("visiting null");
	printf("%s", null.representation().c_str());
}

void PrintVisitor::visit(const JsonBool& json_bool) {
//	printf("visiting bool");
	printf("%s", json_bool.representation().c_str());
}

