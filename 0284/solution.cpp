#include <iterator>
using namespace std;class PeekingIterator:public Iterator{int cache;bool has;public:PeekingIterator(const vector<int>&nums):Iterator(nums){has=Iterator::hasNext();if(has)cache=Iterator::next();}int peek(){return cache;}int next(){int r=cache;has=Iterator::hasNext();if(has)cache=Iterator::next();return r;}bool hasNext()const{return has;}};
