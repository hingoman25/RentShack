#include <vector>
#include "Sorting_client.h"

using namespace std;

void Sorting_client::set_sortingMethod(Postsort* sortingMethod_passed){
	sortingMethod = sortingMethod_passed;
}

Info_type* Sorting_client::sort(){
	return sortingMethod->sort();
}