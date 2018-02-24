#include <string>
#include <vector>
#include "Postsort.h"

class Highest_rate: public Postsort
{
	void sort(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list);
};