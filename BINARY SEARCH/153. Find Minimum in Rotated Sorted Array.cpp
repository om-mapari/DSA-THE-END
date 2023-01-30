class Solution {
public:
    int findMin(vector<int>& v) {
        if(v.size()==0) return -1;
        if(v.front() < v.back()) return v.front(); 
        
        int n=v.size();
        int s=0,e=n-1;
        while(s<=e)
        {
            int mid = (s) + (e-s)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(v[mid]<=v[prev] and v[mid]<=v[next]) return v[mid];
            else if(v[mid]>=v[0]) s=mid+1;
            else if(v[mid]<=v[n-1]) e=mid-1;
        }
        return -1;
    }
};