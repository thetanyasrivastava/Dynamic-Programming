//https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
//Minimum sum partition
//T.C.= O(N * |sum of array elements| )
//S.C.= O(N * |sum of array elements| )

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	    
	    bool t[n+1][sum+1];
	    
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
	            if(arr[i-1] <= j)
	                t[i][j] = t[i-1][j-arr[i-1]] +  t[i-1][j];
	            else
	                t[i][j] = t[i-1][j];
	        }
	    }
	    
	    int mn=INT_MAX;
	    for(int j=0;j<(sum/2)+1;j++)
	    {
	        if(t[n][j]==true)
	            mn=min(mn,sum-2*j);
	    }
	    return mn;
	        
	} 
