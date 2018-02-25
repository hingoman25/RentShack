#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Highest_rate.h"

using namespace std;

Highest_rate::Highest_rate(vector<Info_type*> post_list_passed) {
	post_list = post_list_passed;
}

Info_type* Highest_rate::sort() { 
  /* ****** Most expensive item ******  */
 
   	Info_type* max_post;

	for(int i = 0; i < post_list.size(); i++) {
		if (i == 0) 
			max_post = post_list[i];
		if (max_post->getPrice() < post_list[i]->getPrice())
	      max_post = post_list[i];
	}

	return max_post;
  
}
