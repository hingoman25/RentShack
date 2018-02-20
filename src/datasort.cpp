#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(){

	ifstream ff;
	ff.open("items.txt");

	vector<string> titlePost_list;
	vector<string> itemDesc_list;
	vector<int> price_list;
	int line_count = 0;
	string line;
	map<string, int> m;


	while(!ff.eof()) {

		getline(ff, line);
		line_count++;
		if(line_count % 4 == 1){
			titlePost_list.push_back(line);
		}
		if(line_count % 4 == 2){
			itemDesc_list.push_back(line);
		}
		if(line_count % 4 == 3){
			int price = stoi(line);
			price_list.push_back(line);
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

    cout << it->first << endl;


    // find the most expensive item
    /*string exp_item
    for (int i = 0; i < price_list.size(); i++){
    	if (i == 0)*/

    





    return 0;
}