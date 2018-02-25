#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Most_frequent.h"
#include "Highest_rate.h"
#include "Info_type.h"
#include "User.h"
#include "Post.h"
#include "Sorting_client.h"

using namespace std;


int main(){

	ifstream ff;
	ff.open("items.txt");

	vector<string> titlePost_list;
	vector<string> itemDesc_list;
	vector<int> price_list;
	vector<string> username_list;
	vector<string> email_list;
	vector<string> uid_list;

	int line_count = 0;
	string line;


	while(!ff.eof()) {

		getline(ff, line);
		line_count++;
		if(line_count % 7 == 1){
		  	titlePost_list.push_back(line);
		}
		if(line_count % 7 == 2){
			itemDesc_list.push_back(line);
		}
		if(line_count % 7 == 3){
		  	int price = stoi(line);
		  	price_list.push_back(price);
		}
		if(line_count % 7 == 4){
			username_list.push_back(line);
		}
		if(line_count % 7 == 5){
			email_list.push_back(line);
		}
		if(line_count % 7 == 6){
			uid_list.push_back(line);
		}
		
	}


	vector<Info_type*> post_list;
	vector<Info_type*> user_list;

	for (int i=0; i < titlePost_list.size(); i++) {
		post_list.push_back(Info_type::make_Info_type("post", titlePost_list[i], itemDesc_list[i], price_list[i], username_list[i], email_list[i], uid_list[i]));
		user_list.push_back(Info_type::make_Info_type("user", titlePost_list[i], itemDesc_list[i], price_list[i], username_list[i], email_list[i], uid_list[i]));
	}

	

	Most_frequent* most_freq = new Most_frequent(post_list);
	Highest_rate* highest_rate = new Highest_rate(post_list);

	Sorting_client sorting_client;
	sorting_client.set_sortingMethod(most_freq);
	Info_type* most_freq_post = sorting_client.sort();

	sorting_client.set_sortingMethod(highest_rate);
	Info_type* highest_rate_post = sorting_client.sort();

	most_freq = new Most_frequent(user_list);
	sorting_client.set_sortingMethod(most_freq);
	Info_type* most_freq_user = sorting_client.sort();




	cout << "Most frequent item: " << endl;
	cout << most_freq_post->getTitlePost() << endl;

	cout << "Most expensive rate: " << endl;
    cout << highest_rate_post->getTitlePost() << endl;
    cout << highest_rate_post->getItemDesc() << endl;
    cout << "$" << highest_rate_post->getPrice() << "/hr" << endl;
    cout << highest_rate_post->getUsername() << endl;
    cout << highest_rate_post->getEmail() << endl;
    cout << highest_rate_post->getUid() << endl;

    cout << "Most frequent user: " << endl;
    cout << most_freq_user->getUsername() << endl;
    cout << most_freq_user->getEmail() << endl;
    cout << most_freq_user->getUid() << endl;
	



	return 0;

}