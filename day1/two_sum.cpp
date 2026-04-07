#include <bits/stdc++.h>
using namespace std ;

vector<int> twoSumOpt(vector<int>& nums, int target) {
    unordered_map<int,int> myMap ;
    int complement ;
    for(int i = 0; i < nums.size(); i++){
        complement = target - nums[i] ;
        if(myMap.find(complement) != myMap.end()){
            return {myMap[complement],i} ;
        }
        myMap[nums[i]] = i ;
    } 
    return {} ;
}

int main() {
    vector<int> arr = {2,7,11,15};
    int target = 9 ;

    vector<int> res = twoSumOpt(arr, target) ;
    for(int i : res){
        cout << i << " " ;
    }
    return 0 ;
}
