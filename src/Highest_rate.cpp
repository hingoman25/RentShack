#include "Highest_rate.h"

Post* Highest_rate::sort(vector<Post> post_list) { 
  /* ****** Most expensive item ******  */
  int max = 0;     
  Post* max_item;                                                                                      
  for(int i = 0; i < post_list.size(); i++) {
    if (max < post_list[i].getPrice()) {
      max = post_list[i].getPrice();
      max_item = post_list[i];
    }
  }

  return max_item;
  
}
