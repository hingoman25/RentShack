#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

class Postsort
{
public:
	Postsort(){}
	virtual void sort(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list)=0;
};

class Most_frequent: public Postsort {

	public:

	Most_frequent(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list){};

	void sort(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list){
		map<string, int> m;

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


	  cout << "Most frequent item: " <<endl;
  	  cout << it->first << endl;
	}

};

class Highest_rate: public Postsort
{
	public:

	Highest_rate(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list){};

	void sort(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list) { 
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
};

/*class Sorting_client
{
public:
	void sort(Postsort sorting_method){
	sorting_method.sort(vector<string> titlePost_list, vector<string> itemDesc_list, vector<int> price_list);
}

};*/


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

	/*Sorting_client* client = new Sorting_client();
	Most_frequent most_f = new Most_frequent(titlePost_list, itemDesc_list, price_list);
	client->sort(new Most_frequent(titlePost_list, itemDesc_list, price_list));
	client->sort(new Highest_rate(titlePost_list, itemDesc_list, price_list));*/

	Most_frequent* most_freq = new Most_frequent(titlePost_list, itemDesc_list, price_list);
	most_freq->sort(titlePost_list, itemDesc_list, price_list);
	Highest_rate* highest_rate = new Highest_rate(titlePost_list, itemDesc_list, price_list);
	highest_rate->sort(titlePost_list, itemDesc_list, price_list);


	/*cout << endl; 
	Info_type* info;
	Post* post = info->make_Info_type("post", "bike", "fixie", 6);
	cout << post->getPrice() << endl;*/

	return 0;

}