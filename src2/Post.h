#ifndef POST_POST_H
#define POST_POST_H
#include <string>
#include "Info_type.h"

using namespace std;

//object created by Info_type factory
class Post: public Info_type {

  public:

  	//constructor
  	Post(string titlePost, string itemDesc, int price, string username, string email, string uid);


  	//returns value titlePost is initialized to
  	//parameters: none
  	//return value: string titlePost
  	//precondition: titlePost has been initialized with string that should have been passed through the constructor
  	//postcondition: has returned a string that is the value titlePost was set to
  	string getTitlePost();


  	//returns value itemDesc is initialized to
  	//parameters: none
  	//return value: string itemDesc
  	//precondition: itemDesc has been initialized with string that should have been passed through the constructor
  	//postcondition: has returned a string that is the value itemDesc was set to
	string getItemDesc();


	//returns value price is initialized to
  	//parameters: none
  	//return value: int price
  	//precondition: price has been initialized with int that should have been passed through the constructor
  	//postcondition: has returned an int that is the value price was set to
	int getPrice();


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


  private:
	string titlePost;
	string itemDesc;
	int price;

	string username;
	string email;
	string uid;
	
};

#endif //POST_POST_H
