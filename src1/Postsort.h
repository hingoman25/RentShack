#include <string>
#include <vector>

using namespace std;

class Postsort
{
public:
	Postsort(){}
	virtual ~Postsort(){}
	virtual void sort(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list)=0;
};