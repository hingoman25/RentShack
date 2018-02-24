#include "Info_type.h"
#include <string>

using namespace std;

Info_type::Info_type(){}

Post* Info_type::make_Info_type(string type, string& titlePost, string& itemDesc, int& price){
		if (type == "post")
			return new Post(titlePost, itemDesc, price);
		if (type == "user")
			return new User();
}



