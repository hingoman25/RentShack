#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void find_highest_rate(int num_items, vector<int> price_list, vector<string> titlePost_list, vector<string> itemDesc_list); 

int main(){

	ifstream ff;
	ff.open("items.txt");

	vector<string> titlePost_list;
	vector<string> itemDesc_list;
	vector<int> price_list;
	int line_count = 0;
	string line;
	int num_items = 0; 
	map<string, int> m;


	while(!ff.eof()) {

		getline(ff, line);
		line_count++;
		if(line_count % 4 == 1){
		  num_items++; 
		  titlePost_list.push_back(line);
		}
		if(line_count % 4 == 2){
			itemDesc_list.push_back(line);
		}
		if(line_count % 4 == 3){
		  int price = stoi(line);
		  //cout << "just the price: " << price << "price plus three test if int" << (price + 3) << endl; 
		  price_list.push_back(price);
		}
		

	}


	// find the most frequently occuring item

	// count occurrences of every string in post list
	for (int i = 0; i < titlePost_list.size(); i++){

      map<string, int>::iterator it = m.find(titlePost_list[i]);

      if (it == m.end())
        m.insert(pair<string, int>(titlePost_list[i], 1));

      else
        m[titlePost_list[i]] += 1;
     }

  	// find the max
  	map<string, int>::iterator it = m.begin();
  	for (map<string, int>::iterator it2 = m.begin(); it2 != m.end(); ++it2) {
      if (it2 -> second > it -> second)
      it = it2;
    }

    cout <<"Most common item: " + it->first << endl;
    
    find_highest_rate(num_items, price_list, titlePost_list, itemDesc_list); 
    





    return 0;
}


void find_highest_rate(int num_items, vector<int> price_list, vector<string> titlePost_list, vector<string> itemDesc_list) { 
  /* ****** Most expensive item ******  */
  int max = 0;
  string temp_titlePost;
  string temp_itemDesc;
  //cout << "number of items" << num_items <<endl;                                                                                                 
  for(int i = 0; i < num_items; i++) {
    if (max < price_list[i]) {
      max = price_list[i];
      temp_titlePost = titlePost_list[i];
      temp_itemDesc = itemDesc_list[i];
    }
  }

  cout << "Most expensive rate: " <<endl;
  cout << temp_titlePost <<endl;
  cout <<temp_itemDesc <<endl;
  cout << "$" <<max <<"/hr" <<endl;
  return; 
} 
