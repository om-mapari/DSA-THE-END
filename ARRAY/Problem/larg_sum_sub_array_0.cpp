#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int check(int arr[],int n)
{
    int sum = 0;
    int max_len = 0;
    unordered_map<int,int> um;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == 0)
        {
            max_len = i+1;
        }
        else if(um.count(sum) == 1)
        {
            auto it = um.find(sum) ;
            max_len = i-(it->second);
        }
        else
        {
            um.insert({sum,i});
        }
    }
    return max_len;
    
}
vector<int> subarraySum(int arr[], int n, int s){
    int l = 0;
    int r = 0;
    int count = 0;
    vector<int> res;
    
    while (r<=n) {
        if (count == s) {
            res.push_back(l);
            res.push_back(r);
            return res;
        }
        if (l==r || count < s) {
            r++;
            count += arr[r-1];
        }
        else {
            l++;
            count -= arr[l-1];
        }
    }
    
    res.push_back(-1);
    return res;
}
int main()
{
    int arr[] = {1,-1,3,2,-2,-8,1,7,10,23};
    int arr2[] = {1,4,20,3,10,5};
    vector<int> v= subarraySum(arr2,6,33);
    for (auto &&i : v)
    {
        cout<<i<<" ";
    }
    
    // cout<<check(arr,10);
    return 0;
}