#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Most_frequent.h"

using namespace std;

Most_frequent::Most_frequent(vector<Info_type*> post_or_user_list_passed) {
    post_or_user_list = post_or_user_list_passed;
}


Info_type* Most_frequent::sort() { 

  vector<string> target_list;

  if (post_or_user_list[0]->getTitlePost() != "n/a"){

    for (int i=0; i < post_or_user_list.size(); i++){
       target_list.push_back(post_or_user_list[i]->getTitlePost());
    }

  } else { 

    for (int i=0; i < post_or_user_list.size(); i++){
       target_list.push_back(post_or_user_list[i]->getUsername());
    }

  }

	map<string, int> m;

	for (int i = 0; i < target_list.size(); i++){

      map<string, int>::iterator it = m.find(target_list[i]);

      if (it == m.end())
        m.insert(pair<string, int>(target_list[i], 1));

      else
        m[target_list[i]] += 1;
  }

  // find the max
  map<string, int>::iterator it = m.begin();
  for (map<string, int>::iterator it2 = m.begin(); it2 != m.end(); ++it2) {
      if (it2 -> second > it -> second)
      it = it2;
  }

  for (int i=0; i < post_or_user_list.size(); i++){
        if (post_or_user_list[i]->getTitlePost() == it->first)
          return post_or_user_list[i];
        if (post_or_user_list[i]->getUsername() == it->first)
          return post_or_user_list[i];
  }

  return NULL;

}

