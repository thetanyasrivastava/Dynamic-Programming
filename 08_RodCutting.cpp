https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#//
//T.C. = O(N^2) S.C. = O(N) 

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int length[n];
        for(int i=0;i<n;i++)
            length[i]=i+1;
        
        //int size=sizeof(length)/sizeof(int);
        int size=n;
        int t[n+1][size+1];
        //memset(t,-1,sizeof(t));
        //return solve(price,length,n,size,t);
        
    //base condition is either we don't have money/no price or no rod to cut
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<size+1;j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<size+1;j++)
            {
                if(length[i-1]<=j)
                {
                    t[i][j]=max(price[i-1] + t[i][j-length[i-1]] , t[i-1][j]);
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][size];
    }
    
    /*int solve(int price[],int length[],int n,int size,int t[][])
    {
        if(n==0 || size==0)
            return 0;
        if(t[n][size]!=-1)
            return t[n][size];
        
        if(length[n-1]<=size)
            return t[n][size]=max(price[n-1]+solve(price,length,n,size-length[n-1],t) ,
                solve(price,length,n-1,size,t));
        else
            return t[n][size]=solve(price,length,n-1,size,t);
    }*/
};
