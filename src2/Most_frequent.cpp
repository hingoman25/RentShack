#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Most_frequent.h"

using namespace std;

Most_frequent::Most_frequent(vector<string> titlePost_list_passed){

    titlePost_list = titlePost_list_passed;

}


void Most_frequent::sort() { 

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

