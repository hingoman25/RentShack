#include <vector>
#include "Sorting_Client.h"

using namespace std;

Post* Sorting_Client::sort(Postsort sorting_method, vector<Post*> post_list){
	sorting_method.sort();
}