/*
 * fileoutputvisitor.hpp
 *
 *  Created on: May 3, 2014
 *      Author: andrew
 */

#ifndef FILEOUTPUTVISITOR_HPP_
#define FILEOUTPUTVISITOR_HPP_

#include "visitor.hpp"

#include <fstream>

using std::ofstream;

class FileOutputVisitor: public Visitor {
public:
//	FileOutputVisitor(const string file_name);
	void writeToFile(const JsonValue* value, const string file_name);
private:
	void visit(const JsonObject& value);
	void visit(const JsonArray& value);
	void visit(const JsonString& value);
	void visit(const JsonNumber& value);
	void visit(const JsonNull& value);
	void visit(const JsonBool& value);
	ofstream myfile;
};

#endif /* FILEOUTPUTVISITOR_HPP_ */
