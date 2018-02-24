#include <string>
#include "User.h"

using namespace std;

string User::getEmail(){
	return this->email;
}

string User::getUsername(){
	return this->username;
}

string User::getUID(){
	return this->uid;
}