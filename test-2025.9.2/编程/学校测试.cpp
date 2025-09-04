#include<iostream>
#include<vector>
using namespace std;
void Sorted(vector<double> & arr,int n)
{ for(int i=0;i<n-1;i++)
  { for(int j=0;j<n-1-i;j++)
    {if(arr[j]>arr[j+1])
     { double temp=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=temp;
	 }
	}
  }
  for(int i=0;i<n;i++)
  {cout<<arr[i]<<" ";
  }
}
int main()
{ int n;
  vector<double>arr;
  cin>>n;
  for(int i=0;i<n;i++)
  { double x;
    cin>>x;
    arr.push_back(x);
  }
  Sorted(arr,n);
  return 0;
}