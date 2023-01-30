class Solution {
public:
    
    int part(vector<int> &v, int s, int e)
    {
    int pindex = s;
    int pele = v[e];
    for (int i = s; i < e; i++)
    {
        if (v[i] > pele)
        {
            swap(v[pindex++], v[i]);
        }
    }
    swap(v[pindex], v[e]);
    return pindex;
    }
    
    void help (vector<int>& v,int s,int e ,int k,int &ans)
    {

           int p = part(v,s,e);
           cout<<" part = "<<p <<endl;
           for(auto i: v) cout<<i<< " " ;
           cout<<endl;
        
           if(p+1 == k)
           {
               ans = v[p];
               return ;
           }
           else if(p+1 > k)
            {
                help(v,s,p-1,k,ans);

            }
            else if(p+1 < k)
            {
                help(v,p+1,e,k,ans);
            }
        
    }
    
    int findKthLargest(vector<int>& v, int k) {
    
        int ans=0,s=0,e=v.size()-1;

        help(v,s,e,k,ans);
                
        return ans;
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int,vector<int> > pq;
        for(auto i: v) pq.push(i); // O(n)
        for(int i=0;i<k-1;i++) pq.pop(); // O(klog(n))
        return pq.top();
    }
    // smallest
    class Solution {
public:
    
    int part(vector<int> &v, int s, int e)
    {
    int pindex = s;
    int pele = v[e];
    for (int i = s; i < e; i++)
    {
        if (v[i] < pele)
        {
            swap(v[pindex++], v[i]);
        }
    }
    swap(v[pindex], v[e]);
    return pindex;
    }
    
    void help (vector<int>& v,int s,int e ,int k,int &ans)
    {

           int p = part(v,s,e);
           cout<<" part = "<<p <<endl;
           for(auto i: v) cout<<i<< " " ;
           cout<<endl;
        
           if(p+1 == k)
           {
               ans = v[p];
               return ;
           }
           else if(p+1 > k)
            {
                help(v,s,p-1,k,ans);

            }
            else if(p+1 < k)
            {
                help(v,p+1,e,k,ans);
            }
        
    }
    
    int findKthSmallest(vector<int>& v, int k) {
        k = v.size()-k+1;
        int ans=0,s=0,e=v.size()-1;

        help(v,s,e,k,ans);
                
        return ans;
    }
};
};