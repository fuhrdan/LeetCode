#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size()) return findMedianSortedArrays(b,a);
        int m=a.size(),n=b.size(),lo=0,hi=m,total=m+n;
        while(lo<=hi){
            int i=(lo+hi)/2,j=(total+1)/2-i;
            int al=i?a[i-1]:INT_MIN, ar=i<m?a[i]:INT_MAX;
            int bl=j?b[j-1]:INT_MIN, br=j<n?b[j]:INT_MAX;
            if(al<=br&&bl<=ar){ int left=max(al,bl); if(total&1)return left; return (left+min(ar,br))/2.0; }
            if(al>br) hi=i-1; else lo=i+1;
        }
        return 0;
    }
};
