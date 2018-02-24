#include <string>

using namespace std;

class User
{
	public:

	User(){};
	string username; 
	string uid; 
	string email;
	string getUsername();
	string getEmail(); 
	string getUID(); 
};

class Post
{
	public:

	Post(string titlePost_passed, string itemDesc_passed, int price_passed){ 
		titlePost = titlePost_passed;
		itemDesc = itemDesc_passed; 
		price = price_passed; 
	}

	string getTitlePost(){ return this->titlePost;} 
	string getItemDesc(){ return this->itemDesc;}
	int getPrice(){ return this->price; }

	private:
	string titlePost; 
	string itemDesc;
	int price; 
	

};

class Info_type
{
public:
	Info_type(){};
	Post* make_Info_type(string type, string titlePost, string itemDesc, int price);

};



