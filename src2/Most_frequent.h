#ifndef MOST_FREQUENT_MOST_FREQUENT_H
#define MOST_FREQUENT_MOST_FREQUENT_H
#include <string>
#include <vector>
#include "Postsort.h"
#include "Info_type.h"

using namespace std;

//concrete strategy class derived from Postsort
class Most_frequent: public Postsort {
	
	public:

		//constructor
		Most_frequent(vector<Info_type*> post_or_user_list);
		
		//overridden sort method from Postsort, will output the post or user that appears most frequently
	    //parameters: vector of pointers to Info_type objects 		
	  	//return value: pointer to Info_type object
	  	//precondition: vector of pointers to Info_type objects passed in, these Info_type objects can be either Posts or Users
	  	//postcondition: returns pointer to Info_type object with title of post or username that appears most frequently 
		Info_type* sort();

	private: 
		vector<Info_type*> post_or_user_list;


};
#endif //MOST_FREQUENT_MOST_FREQUENT_H