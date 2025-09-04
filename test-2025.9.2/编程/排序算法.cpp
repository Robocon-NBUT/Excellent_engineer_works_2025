#include<bits/stdc++.h>
using namespace std;
int num[10001];
void solve()
{
	int n;
	cin>>n;
	if(n<=0) return;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	sort(num,num+n);
	for(int i=0;i<n;i++)
	{
		cout<<num[i]<<" ";
	}
}
int main()
{
	solve();
	return 0;
}

