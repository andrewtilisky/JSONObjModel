/*
 * fileoutputFileOutputVisitor::visitor.cpp
 *
 *  Created on: May 3, 2014
 *      Author: andrew
 */

#include "fileoutputvisitor.hpp"

void FileOutputVisitor::writeToFile(const JsonValue* value,
		const string file_name) {
	myfile.open(file_name + ".json");
	value->accept(*this);
	myfile.close();
}

void FileOutputVisitor::visit(const JsonObject& object) {
	myfile << '{';

	unordered_map<string, JsonValue*> members = object.members();
	for (auto it = members.begin(); it != members.end(); ++it) {
		if (it != members.begin())
			myfile << ',';

		myfile << "\"" << it->first << "\":";
		it->second->accept(*this);
	}
	myfile << '}';
}

void FileOutputVisitor::visit(const JsonArray& array) {
	myfile << '[';

	vector<const JsonValue*> members = array.members();
	for (auto it = members.begin(); it != members.end(); ++it) {
		if (it != members.begin())
			myfile << ',';

		(*it)->accept(*this);
	}
	myfile << ']';
}

void FileOutputVisitor::visit(const JsonString& string) {
	myfile << string.representation();
}

void FileOutputVisitor::visit(const JsonNumber& number) {
	myfile << number.representation();
}

void FileOutputVisitor::visit(const JsonNull& null) {
	myfile << null.representation();
}

void FileOutputVisitor::visit(const JsonBool& json_bool) {
	myfile << json_bool.representation();
}
