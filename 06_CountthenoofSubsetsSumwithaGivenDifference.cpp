#include<bits/stdc++.h>		//DP: video no. 11 - Count the no. of subsets with a given diff.
using namespace std;
int countSubsetDiff(vector<int> &nums,int diff)
{
	int n= nums.size();
	int sum=0;
	//s1=sum of subset 1
	//s2=sum of subset 2
	// s1-s2=diff and also s1+s2=sum;
	//adding we get s1=(diff+sum)/2;

	for(int i=0;i<n;i++)
		sum+=nums[i];

	int s1=(diff+sum)/2;

	int t[n+1][s1+1];

	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<s1+1;j++)
		{
			if(i==0)
				t[i][j]=false;
			if(j==0)
				t[i][j]=true;
		}
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<s1+1;j++)
		{
			if(nums[i-1]<=j)
				t[i][j]=t[i-1][j-nums[i-1]] + t[i-1][j];
			else
				t[i][j]=t[i-1][j];
		}
	}

	return t[n][s1];
}

int main()
{
	int n;
	cin>>n;
	int diff;
	cin>>diff;

	vector<int> nums(n);
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		nums.push_back(a);
	}


	cout<<endl<<"The count of subsets with a given difference : "<<countSubsetDiff(nums,diff);
	cout<<endl;
	return 0;
}

