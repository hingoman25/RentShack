#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Sorting_client.h"
#include "Most_frequent.h"
#include "Highest_rate.h"

using namespace std;


int main() {

	ifstream ff;
	ff.open("items.txt");

	vector<string> titlePost_list;
	vector<string> itemDesc_list;
	vector<int> price_list;
	vector<Post*> post_list;

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


	for (int i=0; i < titlePost_list.size(); i++) {
		post_list.push_back(Info_type::make_Info_type("post","a","a","a",titlePost_list[i],itemDesc_list[i],price_list[i]));
	
	}


	Sorting_client* client = new Sorting_client();
	Post* most_freq_post = client->sort(new Most_frequent(post_list));
	Post* highest_rate_post = client->sort(new Highest_rate(post_list));

	cout << "Most frequent item: " <<endl;
	cout << most_freq_post->getPost() << endl;

	cout << "Most expensive rate: " <<endl;
	cout << highest_rate_post->getPost() <<endl;
	cout << highest_rate_post->getItemDesc() <<endl;
	cout << "$" << highest_rate_post->getPrice() <<"/hr" <<endl;


	return 0;


}


	






