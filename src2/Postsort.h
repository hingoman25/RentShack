#ifndef POSTSORT_POSTSORT_H
#define POSTSORT_POSTSORT_H
#include <string>
#include <vector>

using namespace std;

//abstract strategy class
class Postsort
{
public:
	//constructor
	Postsort(){}
	//destructor
	virtual ~Postsort(){}
	//sort method that will be overridden by subclasses
	virtual void sort()=0;
};
#endif //POSTSORT_POSTSORT_H