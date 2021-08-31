class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n=nums.size();
        int sum=0;
        //s1=sum of subset 1
	    //s2=sum of subset 2
	    // s1-s2=S and also s1+s2=sum;
	    //adding we get s1=(S+sum)/2;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
            
       
          if(sum<S || (S+sum)%2!=0)
             return 0;
            //S+sum should be even to get divided into subsets
        
        int s1=(S+sum)/2;
        
        if(s1<0)
            return 0;
        
        int t[n+1][s1+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<s1+1;j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
      

        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<s1+1;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        
        return t[n][s1];
    }
};
