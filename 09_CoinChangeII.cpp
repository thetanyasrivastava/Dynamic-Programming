//https://leetcode.com/problems/coin-change-2/


class Solution {
public:
    //Method - 1: Recursion (Brute Force)
    
    
    //Method - 2: Memoization (Top-down)
    //T.C. = O(n * amount)
    //S.C. = O(1)
    /*int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> t(n+1,vector<int> (amount+1,-1));
        return solve(coins,t,amount,n);
    }
    int solve(vector<int> &coins,vector<vector<int>>& t,int amount,int n)
    {
        if(n==0)
            return 0;
        if(amount==0)
            return 1;
        if(t[n][amount]!=-1)
            return t[n][amount];
        
        if(coins[n-1]<=amount)
            return t[n][amount]=solve(coins,t,amount,n-1) + solve(coins,t,amount-coins[n-1],n);
        
        return t[n][amount]=solve(coins,t,amount,n-1);
        
    }*/
    
    
    //Method - 3: Tabulation (Bottom - Up)
    //T.C. = O(n * amount)
    //S.C. = O(1)
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int t[n+1][amount+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                    t[i][j]=t[i-1][j] + t[i][j-coins[i-1]];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][amount];
    }
};
