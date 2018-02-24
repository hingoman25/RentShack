#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Highest_rate.h"

using namespace std;

Highest_rate::Highest_rate(vector<string> titlePost_list_passed, vector<string> itemDesc_list_passed, vector<int> price_list_passed){

	titlePost_list = titlePost_list_passed;
	itemDesc_list = itemDesc_list_passed;
	price_list = price_list_passed;

};

void Highest_rate::sort() { 
  /* ****** Most expensive item ******  */
   	int max = 0;
  	string temp_titlePost;
	string temp_itemDesc;
	                                                                                                
	for(int i = 0; i < titlePost_list.size(); i++) {
		if (max < price_list[i]) {
	      max = price_list[i];
	      temp_titlePost = titlePost_list[i];
	      temp_itemDesc = itemDesc_list[i];
	    }
	}

    cout << "Most expensive rate: " <<endl;
    cout << temp_titlePost <<endl;
    cout << temp_itemDesc <<endl;
    cout << "$" << max <<"/hr" <<endl;
  
}
