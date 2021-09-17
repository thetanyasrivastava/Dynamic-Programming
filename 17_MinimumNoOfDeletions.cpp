//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1#
//T.C= O(|str|2)
//S.C= O(|str|2)

int minDeletions(string str, int n) { 
    //complete the function here 
    string t=str;
        reverse(t.begin(),t.end());
        
        //int m=str.length(); //here s.length=t.length so m=n
        int dp[1001][1001];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(str[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return n-dp[n][n];
} 
