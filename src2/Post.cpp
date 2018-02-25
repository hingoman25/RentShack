#include <string>
#include "Post.h"

using namespace std;


Post::Post(string titlePost_passed, string itemDesc_passed, int price_passed, string username_passed, string email_passed, string uid_passed){

	titlePost = titlePost_passed;
	itemDesc = itemDesc_passed;
	price = price_passed;
	username = username_passed;
	email = email_passed;
	uid = uid_passed;

}

string Post::getTitlePost(){
	return titlePost;
}

string Post::getItemDesc(){
	return itemDesc;
}

int Post::getPrice(){
	return price;
}

string Post::getUsername(){
	return username;
}

string Post::getEmail(){
	return email;
}

string Post::getUid(){
	return uid;
}








