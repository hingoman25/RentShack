#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Most_frequent.h"
#include "Highest_rate.h"

using namespace std;


int main(){
	
	ifstream ff;
	ff.open("items.txt");

	vector<string> titlePost_list;
	vector<string> itemDesc_list;
	vector<int> price_list;

	int line_count = 0;
	string line;


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
		  	price_list.push_back(price);
		}
		
	}


	Most_frequent* most_freq = new Most_frequent(titlePost_list);
	most_freq->sort();
	Highest_rate* highest_rate = new Highest_rate(titlePost_list, itemDesc_list, price_list);
	highest_rate->sort();


	return 0;

}