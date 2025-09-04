#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector<int> v;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	for(int i=0;i<n-1;i++)
	{
		if(v[i]>v[i+1])
		{
			int a;
			a=v[i];
			v[i]=v[i+1];
			v[i+1]=a;
		}
		for(int j=0;j<n-i-1;j++){
			if(v[j]>v[j+1]){
				int b;
				b=v[j];
				v[j]=v[j+1];
				v[j+1]=b;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
