class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int maxProd = INT_MIN ;
        for(int i=0;i<n;i++)
        {
            prod *= nums[i];
            maxProd = max(maxProd,prod);
            if(prod==0) prod=1;
        }
        prod = 1;
        for(int i=n-1;i>=0;i--)
        {
            prod *= nums[i];
            maxProd = max(maxProd,prod);
            if(prod==0) prod=1;
        }
        return maxProd;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0], l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            l =  (l) * nums[i];
            r =  (r) * nums[n - 1 - i];
            res = max(res, max(l, r));
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return res;
    }
};