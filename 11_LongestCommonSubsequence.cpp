//https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    
    //Method -1 Recursion  (TLE)  
        // "pmjghexybyrgzczy"
        // "hafcdqbgncrcbihkd"
    
    /*int longestCommonSubsequence(string text1, string text2) {
        
        return lcs(text1,text2,text1.length(),text2.length());
    }
    
    int lcs(string &X,string &Y,int n,int m)
    {
        //Base Condition
        if(n==0 || m==0)
            return 0;
        
        //choice diagram
        if(X[n-1]==Y[m-1])  //if matched
            return 1 + lcs(X,Y,n-1,m-1);
        //else
        return max(lcs(X,Y,n,m-1) , lcs(X,Y,n-1,m));
    }*/
    
    
    
    //Method -2 Memoization (Top Down) T.C. = O(n*m) S.C. = O(n*m)
    
    /*int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(); 
        int m=text2.length();
        
        vector<vector<int>> t(n+1,vector<int> (m+1,-1));
        return lcs(text1,text2,t,n,m);
    }
    
    int lcs(string &X,string &Y,vector<vector<int>> &t,int n,int m)
    {
        //Base Condition
        if(n==0 || m==0)
            return 0;
        if(t[n][m]!=-1)
            return t[n][m];
        
        //choice diagram
        if(X[n-1]==Y[m-1])  //if matched
            return t[n][m] = 1 + lcs(X,Y,t,n-1,m-1);
        //else
        return t[n][m] = max(lcs(X,Y,t,n,m-1) , lcs(X,Y,t,n-1,m));
    }*/
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        
        //vector<vector<int>> t(n+1,vector<int> (m+1,-1));
        int t[1001][1001];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                    t[i][j]= 1 + t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n][m];
    }
};
