#ifndef SORTING_CLIENT_H
#define SORTING_CLIENT_H
#include <vector>
#include "Most_frequent.h"
#include "Highest_rate.h"
#include "Info_type.h"

using namespace std;

//client class for strategy pattern
class Sorting_client
{
	public: 

		//sets sorting method passed, either Most_frequent or Highest_rate
		//parameters: pointer to a Postsort object
		//return type: none
		//precondition: a Postsort pointer is passed in, the pointer should be to an object that is Most_frequent 
		//or Highest_rate
		//postcondition: private member variable sortingMethod is set to the pointer passed in
		void set_sortingMethod(Postsort* sortingMethod);

		//invokes the sort function of either Most_frequent or Highest_rate on the Postsort pointer
		//depending on if the object is Most_frequent or Highest_rate
		//parameters: none
		//return type: pointer to Info_type object
		//precondition: sortingMethod has been set with the set_sortingMethod function
		//postcondition: returns the Info_type pointer obtained from performing the sort function
		//from either Highest_rate or Most_frequent
		Info_type* sort();


	private:
		Postsort* sortingMethod;

};

#endif // SORTING_CLIENT_H