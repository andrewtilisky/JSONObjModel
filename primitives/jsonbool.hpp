/*
 * JsonBool.h
 *
 *  Created on: Apr 29, 2014
 *      Author: andrew
 */

#ifndef JSONBOOL_H_
#define JSONBOOL_H_

#include "../jsonvalue.hpp"

using std::exception;

class JsonBool: public JsonValue {

public:
	JsonBool(const bool value);
	const string representation() const;

	void accept(Visitor& v) const;
private:
	bool _value;
};

#endif /* JSONBOOL_H_ */
