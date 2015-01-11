/*
 * author Andrew Tilisky
 */

#include <iostream>
#include <cstdio>
#include <exception>

#include "primitives/jsonnumber.hpp"
#include "primitives/jsonstring.hpp"
#include "jsonobject.hpp"
#include "jsonarray.hpp"

#include "printvisitor.hpp"
#include "fileoutputvisitor.hpp"

using std::exception;
//using std::tr1::unordered_map;
//using std::string;

//typedef unordered_map<std::string, std::string> stringmap;

bool WikipediaObjectString() {
	try {
//		string wikipedia_example_string = string("{")
//				+ "\"firstName\": \"John\",\"lastName\": \"Smith\","
//				+ "\"age\": 25,\"address\": {"
//				+ "\"streetAddress\": \"21 2nd Street\","
//				+ "\"city\": \"New York\",\"state\": \"NY\","
//				+ "\"postalCode\": \"10021\"},\"phoneNumber\": ["
//				+ "{\"type\": \"home\",\"number\": \"212 555-1234\""
//				+ "},{\"type\": \"fax\","
//				+ "\"number\": \"646 555-4567\"}],\"gender\":{"
//				+ "\"type\":\"male\"}}";
		//    cout << full_test_string << endl;
//		JsonObject wikipeda_example_object(wikipedia_example_string);

		//prepared initializer list for appropriate JsonObject constructor
//		const unordered_map<string, JsonValue*> members = { { string(
//				"firstName"), new JsonString("John") }, { string("lastName"),
//				new JsonString("Smith") }, { string("isAlive"), new JsonBool(
//				true) }, { string("age"), new JsonNumber(25) }, { string(
//				"height_cm"), new JsonNumber(167.64) }, };

		//seeing if one gigantic initializer list can
		//replicate wikipedia's example of a json object
		JsonObject json_object(
				{ { string("firstName"), new JsonString("John") }, { string(
						"lastName"), new JsonString("Smith") }, { string(
						"isAlive"), new JsonBool(true) }, { string("age"),
						new JsonNumber(25) }, { string("height_cm"),
						new JsonNumber(167.64) }, { string("address"),
						new JsonObject(
								{ { string("streetAddress"), new JsonString(
										"21 2nd Street") }, { string("city"),
										new JsonString("New York") }, { string(
										"state"), new JsonString("NY") }, {
										string("postalCode"), new JsonString(
												"10021-3100") }, }) },
						{ string("phoneNumbers"),
							new JsonArray({
								new JsonObject(
								{
									{ string("type"),
											new JsonString(
													"home") },
									{ string("number"),
											new JsonString(
													"212 555-1234") } }),
								new JsonObject(
								{
									{ string("type"),
											new JsonString(
													"fax") },
									{ string("number"),
											new JsonString(
													"646 555-4567") } }) }) } });
		PrintVisitor printer;
		printer.print(&json_object);

		FileOutputVisitor fileout;
		fileout.writeToFile(&json_object, "wikipediaobject");
	} catch (exception& e) {
		printf("%s\n", e.what());
		return true;
	}
	return false;
}

bool EmptyObjects() {
	try {
		JsonObject empty_object;
		PrintVisitor printer;
		printer.print(&empty_object);

//		JsonString empty_string;
//		printf("Printing empty string\n%s\n",
//				empty_string.representation().c_str());

//		JsonNumber default_number;
//		printf("Printing default number\n%s\n",
//				default_number.representation().c_str());

	} catch (exception& e) {
		printf("%s\n", e.what());
		return true;
	}
	return false;
}

int main() {
	unsigned char errors = 0;

//	errors += EmptyObjects();
	errors += WikipediaObjectString();

	printf("\n%d errors\n", errors);
	return errors;
}

