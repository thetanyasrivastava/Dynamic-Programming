class Solution {
public:
    
    //concept used- Minimum subset sum difference - DP
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += stones[i];
        
        bool t[n+1][sum + 1];
        
        //Initialization
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j]=false;
                if(j==0)
                    t[i][j]=true;
            }
        }
        
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(stones[i-1]<=j)
                    t[i][j] = t[i-1][j-stones[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }    
        
        // vector<int> v;
        // int i=n;
        int mn=INT_MAX;
        for(int j=0;j<(sum/2)+1;j++)
        {
            if(t[n][j]==true)
                mn=min(mn,sum-2*j);
                //v.push_back(t[i][j]);
        }
        
        // int mn=INT_MAX;
        // for(int i=0;i<v.size();i++)
        //     mn=min(mn,sum-2*v[i]);
        
        return mn;
            
        
    }
};
