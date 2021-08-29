//Perfect Sum Problem
//https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#
//T.C. = O(N*sum)
//S.C. = O(N*sum)


class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % 1000000007;
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
	}
	  
};
