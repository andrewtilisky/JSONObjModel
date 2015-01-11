/*
 * JsonNull.h
 *
 *  Created on: Apr 29, 2014
 *      Author: andrew
 */

#ifndef JSONNULL_H_
#define JSONNULL_H_

#include "../jsonvalue.hpp"

class JsonNull: public JsonValue {
public:
	JsonNull();
	const string representation() const;

	void accept(Visitor& v) const;
};

#endif /* JSONNULL_H_ */
