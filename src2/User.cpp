#include <string>
#include "User.h"

using namespace std;

User::User(string username_passed, string email_passed, string uid_passed){
	username = username_passed;
	email = email_passed;
	uid = uid_passed;
}

string User::getEmail(){
	return email;
}

string User::getUsername(){
	return username;
}

string User::getUid(){
	return uid;
}

string User::getTitlePost(){
	return "n/a";
}

string User::getItemDesc(){
	return "n/a";
}

int User::getPrice(){
	return 0;
}