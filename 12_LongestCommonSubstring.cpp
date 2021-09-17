//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
//T.C.= O(n*m) S.C. = O(n*m)



class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int t[1001][1001];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        
        int maxi=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                    maxi=max(maxi,t[i][j]);
                }
                else
                    t[i][j]=0;
            }
        }
        return maxi;
    }
};
