#include <vector>
#include "Post.h"
#include "Postsort.h"

using namespace std;

class Sorting_client
{
	public: Post* sort(Postsort sorting_method, vector<Post*> post_list);
};