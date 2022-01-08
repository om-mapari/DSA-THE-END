class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
    int up=0,down=0,result=0;
    for (size_t i = 1; i < arr.size(); i++)
    {
        if(down>0 && arr[i-1]<arr[i] || arr[i-1]==arr[i]) up = down = 0;
        if(arr[i-1]<arr[i]) up++;
        if(arr[i-1]>arr[i]) down++;
        if(up && down && up+down+1>result) result = up +down + 1;
    }
    return result;
    }
};