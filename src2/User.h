include<string>

using namespace std;

class User: public Info_type
{
public:
	string getEmail();
	string getUsername();
	string getUID();

private:
	string email;
	string username;
	string uid;
};