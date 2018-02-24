#ifndef HIGHEST_RATE_HIGHEST_RATE_H
#define HIGHEST_RATE_HIGHEST_RATE_H
#include <string>
#include <vector>
#include "Postsort.h"

using namespace std;

//concrete strategy class derived from Postsort
class Highest_rate: public Postsort
{
  public:
  	//constructor
  	Highest_rate(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list);


  	//overridden sort method from Postsort, will output the item with the highest price
  	//parameters: none 		
	//return value: none
	//precondition: the private member variables titlePost_list, itemDesc_list, and price_list
	//have been initialized with a vector<string>, vector<string>, and vector<int> respectively 
	//which all should have been passed through the constructor
	//postcondition: the item with the greatest value in price_list is outputted along with its
	//corresponding indeces from titlePost_list and itemDesc_list
	void sort();

  private:

  	vector<string> titlePost_list;
  	vector<string> itemDesc_list; 
  	vector<int> price_list;
};
#endif //HIGHEST_RATE_HIGHEST_RATE_H