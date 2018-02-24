#include<string>
#include<vector>

using namespace std;

class Post: public Info_type
{
public: 
	Post(string titlePost, string itemDesc, int price);
	string getTitlePost();
	string getItemDesc();
	int getPrice();

private:
	string titlePost;
	string itemDesc;
	int price;
	
};