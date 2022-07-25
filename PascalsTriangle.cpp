class Solution {
public:
    vector<int>f(vector<int>curr,vector<int>prev)
    {
        int m=prev.size();
        int n=curr.size();
        
        curr[0]=1;
        
        for(int i=0;i<m-1;i++)
        {
            curr[i+1]=prev[i]+prev[i+1];
        }
        
        curr[n-1]=1;
        
        return curr;
        
    }
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        ans.push_back({1});
        ans.push_back({1,1});
        if(numRows==1)
        {
            ans.pop_back();
            return ans;
        }
        if(numRows==2)
        {
            return ans;
        }
        for(int i=3;i<=numRows;i++)
        {   
            vector<int>temp(i,0);
            
            
            
            ans.push_back(f(temp,ans[i-2]));
        }
        return ans;
    }
};
