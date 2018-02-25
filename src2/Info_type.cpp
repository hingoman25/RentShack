#include <string>
#include "Info_type.h"
#include "User.h"
#include "Post.h"

using namespace std;


Info_type *Info_type::make_Info_type(string type, string titlePost, string itemDesc, int price, string username, string email, string uid){
		if (type == "post")
			return new Post(titlePost, itemDesc, price, username, email, uid);
		if (type == "user")
			return new User(username, email, uid);
		else
			return NULL;

}


