#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> maxSubarray(vector<int> arr) {
    int maxx;
    if(arr.empty())
        maxx =  0;
    
    if(arr.size() == 1)
        maxx = arr[0];
    
    int csum = arr[0]; 
    int osum = arr[0]; 
    int subsum = arr[0];
    for(int i=1; i<arr.size(); i++)
    {
        subsum = max(subsum + arr[i] , max(arr[i], subsum));
        csum = max(csum+arr[i], arr[i]);          
        osum = max(osum, csum);
    }
    maxx = osum;
    vector<int> maxArr(arr.size());
    maxArr[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxArr[i] = max(maxArr[i-1] + arr[i], max(maxArr[i-1], arr[i]));
    }
    int maxx2 = maxArr[arr.size() - 1];
    return vector<int>{maxx, subsum};
}