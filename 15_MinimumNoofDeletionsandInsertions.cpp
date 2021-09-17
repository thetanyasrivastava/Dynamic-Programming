//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1#
//T.C. = O(|str1|*|str2|)
//S.C. = O(|str1|*|str2|)


int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    
	    int m=str1.length();
	    int n=str2.length();
	    int dp[1001][1001];
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
		            if(str1[i-1]==str2[j-1])
		                dp[i][j]= 1 + dp[i-1][j-1];
		            else
		                dp[i][j]= max(dp[i-1][j], dp[i][j-1]); 
		        }
		    }
		  
		int lcs=dp[m][n];
	    return (m-lcs)+(n-lcs);  //m+n-2lcs
	} 
