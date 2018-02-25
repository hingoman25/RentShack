#ifndef INFO_TYPE_INFO_TYPE_H
#define INFO_TYPE_INFO_TYPE_H
#include <string>

using namespace std;

//factory for User and Post objects
class Info_type
{

  public:

  	//method to create Post or User objects
  	//parameters: string specifying the type of object to create, string for the title for a Post object, 
  	//string for the description for a Post object, int for the price of a Post object,
  	//string for the username for both User and Post objects, string for the email for both User and Post objects,
  	//string for the uid for both User and Post objects
  	//return value: User or Post object
  	//precondition: proper parameters given
  	//postcondition: User or Post object returned with respective member variables initialized
  	//with applicable parameters passed in the function

	static Info_type *make_Info_type(string type, string titlePost, string itemDesc, int price, string username, string email, string uid);

	//functions to be implemented in subclasses
	virtual string getTitlePost() = 0;
	virtual string getItemDesc() = 0;
	virtual int getPrice() = 0;
	virtual string getUsername() = 0;
	virtual string getEmail() = 0;
	virtual string getUid() = 0;

};

#endif //INFO_TYPE_INFO_TYPE_H



