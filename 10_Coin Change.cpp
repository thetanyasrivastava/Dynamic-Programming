//https://leetcode.com/problems/coin-change/


class Solution {
public:
    //Method - 2: Memoization (Top-down)
    //T.C. = O(n * amount)
    //S.C. = O(1)
  /*  int coinChange(vector<int>& coins, int amount){
        int n=coins.size();
        vector<vector<int>> t(n+1,vector<int> (amount+1,-1));
        
        int ans=solve(coins,t,amount,n);
        // if(ans==INT_MAX-1)
        //     return -1;
        // return ans;
        
        return ans == INT_MAX-1 ? -1 : ans;
    }
    
    int solve(vector<int> &coins,vector<vector<int>>& t,int amount,int n)
    {
        if(amount==0)
            return 0;
        if(n==0)
            return INT_MAX-1;
        if(t[n][amount]!=-1)
                return t[n][amount];
        
        if(coins[n-1]<=amount)
        return t[n][amount] = min( solve(coins,t,amount,n-1),  1+solve(coins,t,amount-coins[n-1],n));
        
        return t[n][amount]=solve(coins,t,amount,n-1);
        
    }*/
    
    
    //Method - 3: Tabulation (Bottom - Up)
    //T.C. = O(n * amount)
    //S.C. = O(1) 
        
    int coinChange(vector<int>& coins, int amount) {
        //Part - 1 Initialization I - when i==0 , j==0
        //Part - 2 Initialization II - for 2nd row
        //Part - 3 Code Variation
        
        int n = coins.size();
        int t[n+1][amount+1];
        
        //Part -1
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                
                if(j==0)
                    t[i][j]=0;
                if(i==0)
                    t[i][j]=INT_MAX-1;
                
            }
        }
        
        //Part - 2 (if not included part 2, then also it is working fine)
        int j=1;
        for(int i=1;j<amount+1;j++)
        {
            if(j%coins[0]==0){
                t[i][j]=j/coins[0];
                //cout<<t[i][j]<<endl;
            }
                
            else
                t[i][j]=INT_MAX-1;
        }
        
        
        //Part - 3
        
        for(int i=2;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j){
                    t[i][j]=min(t[i-1][j] , 1+t[i][j-coins[i-1]]);
                    //cout<<t[i][j]<<endl;
                }
                else{
                    t[i][j]=t[i-1][j];
                    //cout<<"else "<<i<<j<<" "<<t[i][j]<<endl;
                }
                    
            }
        }
        
        if(t[n][amount]==INT_MAX-1)
            return -1;
        return t[n][amount];
    }
    
};
