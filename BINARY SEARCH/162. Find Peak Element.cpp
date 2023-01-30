class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n=v.size();
        if(n==1)  return 0;
        if(n==2)  return (v[0]>v[1])? 0:1;
        
        int s=0,e=n-1;
        while(s<=e)
        {
            int m = (s+e)/2;
            if(m>0 && m<n-1)
            {
                if(v[m+1]<v[m] && v[m-1]<v[m]) return m;
                else if(v[m+1]>v[m]) s=m+1;
                else e=m-1;
            }
            else if(m==0) return (v[0]>v[1])? 0:1;
            else if(m==n-1) return (v[n-1]>v[n-2])? n-1:n-2;
        }
        return -1;
    }
};