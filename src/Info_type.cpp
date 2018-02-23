#include <string>
#include "Post.h"
#include "User.h"

using namespace std;

Info_type *Info_type::make_Info_type(string type, string& email, string& username, string& uid, string& titlePost, string& itemDesc, int& price){
		if (type == "post")
			return new Post(titlePost, itemDesc, price);
		if (type == "user")
			return new User();
}


