#ifndef POSTSORT_POSTSORT_H
#define POSTSORT_POSTSORT_H
#include <string>
#include <vector>
#include "Info_type.h"

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
	virtual Info_type* sort()=0;
};
#endif //POSTSORT_POSTSORT_H