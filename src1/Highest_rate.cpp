#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Highest_rate.h"

using namespace std;

void Highest_rate::sort(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list) { 
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
