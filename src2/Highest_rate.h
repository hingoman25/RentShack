#ifndef HIGHEST_RATE_HIGHEST_RATE_H
#define HIGHEST_RATE_HIGHEST_RATE_H
#include <string>
#include <vector>
#include "Postsort.h"
#include "Info_type.h"

using namespace std;

//concrete strategy class derived from Postsort
class Highest_rate: public Postsort
{
  public:

  	Highest_rate(vector<Info_type*> post_list);

    //overridden sort method from Postsort, will output the post with the highest price
    //parameters: vector of pointers to Info_type objects 		
  	//return value: pointer to Info_type object
  	//precondition: vector of pointers to Info_type objects passed in, these Info_type objects should be Posts
  	//postcondition: returns pointer to Info_type object with the highest price
	Info_type* sort();

  private:
  	vector<Info_type*> post_list;

};
#endif //HIGHEST_RATE_HIGHEST_RATE_H