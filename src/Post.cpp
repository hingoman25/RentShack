#include "Post.h"

using namespace std;

Post::Post(string titlePost_passed, string itemDesc_passed, int price_passed){
	titlePost = titlePost_passed;
	itemDesc = itemDesc_passed;
	price = price_passed;
}

string Post::getTitlePost(){
	return this.titlePost;
}

string Post::getItemDesc(){
	return this.itemDesc;
}

string Post::getPrice(){
	return this.price;
}








