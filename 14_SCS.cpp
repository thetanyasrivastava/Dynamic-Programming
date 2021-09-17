//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#:~:text=Input%3A%20X%20%3D%20efgh%2C%20Y,length%20of%20the%20required%20string.
//T.C. =  O(Length(X) * Length(Y))
//S.C. =  O(Length(X) * Length(Y))

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
      
		    
		    int dp[101][101];
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
		            if(X[i-1]==Y[j-1])
		                dp[i][j]= 1 + dp[i-1][j-1];
		            else
		                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
		        }
		    }
		    
		    //dp[m][n]=LCS
		    return m+n-dp[m][n];
    }
};
