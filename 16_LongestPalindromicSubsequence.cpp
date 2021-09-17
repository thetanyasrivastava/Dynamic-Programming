//https://leetcode.com/problems/longest-palindromic-subsequence/
//T.C. = O(m*n)
//S.C. = O(m*n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //Pattern LCS - Palindrome
        string t=s;
        reverse(t.begin(),t.end());
        
        int m=s.length(); //here s.length=t.length so m=n
        int dp[1001][1001];
        
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
        
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[m][m];
    }
};
