#include <string>

using namespace std;

class Info_type
{
public:
	static Info_type *make_Info_type(string type, string& email, string& username, string& uid, string& titlePost, string& itemDesc, int& price);

};