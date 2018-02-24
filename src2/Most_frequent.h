#ifndef MOST_FREQUENT_MOST_FREQUENT_H
#define MOST_FREQUENT_MOST_FREQUENT_H
#include <string>
#include <vector>
#include "Postsort.h"

using namespace std;

//concrete strategy class derived from Postsort
class Most_frequent: public Postsort {
	
	public:
		//constructor
		Most_frequent(vector<string> titlePost_list);

		
		//overriden sort method from Postsort, will output most frequently occuring item in list of posts
		//parameters: none 		
		//return value: none
		//precondition: the private member variable titlePost_list has been initialized with a vector<string> 
		//that should have been passed through the constructor
		//postcondition: most frequently occurring item in titlePost_list outputted
		void sort();

	private:

		vector<string> titlePost_list;

};
#endif //MOST_FREQUENT_MOST_FREQUENT_H