#ifndef USER_USER_H
#define USER_USER_H
#include <string>
#include "Info_type.h"

using namespace std;

//object created by Info_type factory
class User: public Info_type {

  public:

  	//constructor
  	User(string username, string email, string uid);

  	//returns value username is initialized to
  	//parameters: none
  	//return value: string username
  	//precondition: username has been initialized with string that should have been passed through the constructor
  	//postcondition: has returned a string that is the value username was set to
	string getUsername();

	//returns value email is initialized to
  	//parameters: none
  	//return value: string email
  	//precondition: email has been initialized with string that should have been passed through the constructor
  	//postcondition: has returned a string that is the value email was set to
	string getEmail();

	//returns value uid is initialized to
  	//parameters: none
  	//return value: string uid
  	//precondition: uid has been initialized with string that should have been passed through the constructor
  	//postcondition: has returned a string that is the value uid was set to
	string getUid();


	//parameters: none. precondition: none. postcondition/return value: returns a string "n/a".  
	string getTitlePost();
	//parameters: none. precondition: none. postcondition/return value: returns a string "n/a". 
	string getItemDesc();
	//parameters: none. precondition: none. postcondition/return value: returns 0. 
	int getPrice();


  private:
	string username;
	string email;
	string uid;
};

#endif //USER_USER_H