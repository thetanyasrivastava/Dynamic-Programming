//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {

                    // Code here
        int m=a.size();
        int n=b.size();
        
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
                for(int j=0;j<n+1;j++)
                {
                if(i==0||j==0)
                        dp[i][j]=0;
                }
        }
        
        for(int i=1;i<m+1;i++)
        {
                for(int j=1;j<n+1;j++)
                {
                if(a[i-1]==b[j-1])
                        dp[i][j]= 1 + dp[i-1][j-1];
                else
                        dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
        }
        
        vector<int> res;

        int i=m, j=n;
        while(i>0 && j>0)
        {
                if(a[i-1]==b[j-1])
                {
                        res.push_back(a[i-1]);
                        i--;
                        j--;
                }
                else
                {
                if(dp[i][j-1] > dp[i-1][j])
                        j--;
                else
                        i--;
                }
        }
        
        
        reverse(res.begin(),res.end());
        return res;
                
}
