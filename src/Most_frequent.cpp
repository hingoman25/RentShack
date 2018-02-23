#include <cstdlib>
#include <map>
#include "Most_frequent.h"

using namespace std;


Post* Most_frequent::sort(vector<Post> post_list) { 

	map<Post*, int> m;

	for (int i = 0; i < post_list.size(); i++){

      map<Post*, int>::iterator it = m.find(post_list[i]);

      if (it == m.end())
        m.insert(pair<Post*, int>(post_list[i], 1));

      else
        m[post_list[i]] += 1;
     }

  	// find the max
  	map<string, int>::iterator it = m.begin();
  	for (map<Post*, int>::iterator it2 = m.begin(); it2 != m.end(); ++it2) {
      if (it2 -> second > it -> second)
      it = it2;
    }

    return it->first;

}

