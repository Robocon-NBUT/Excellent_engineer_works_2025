#include<bits/stdc++.h>
using namespace std;
//����ͳ���е����� 
vector<vector<bool>> p(10,vector<bool>(10,true)); 
//����ͳ���е�����
vector<vector<bool>> l(10,vector<bool>(10,true)); 
//����ͳ��С�����е�����
vector<vector<bool>> square(10,vector<bool>(10,true));
void out(int n,vector<vector<int>>&dp){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	exit(0);//��ֹ���� 
}
void dfs(int n,int x,int y,vector<vector<int>>& dp){
	if(dp[x][y]!=0){
		if(x==n&&y==n){
			out(n,dp);
		}else{
			if(y==n){
				dfs(n,x+1,1,dp);
			}else{
				dfs(n,x,y+1,dp);
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			int w=sqrt(n);
			//(x-1)/w*w+(y-1)/w+1��ʾ����ı�� 
			if(p[x][i]&&l[y][i]&&square[(x-1)/w*w+(y-1)/w+1][i]){
				dp[x][y]=i;
				//��� 
				p[x][i]=false;
				l[y][i]=false;
				square[(x-1)/w*w+(y-1)/w+1][i]=false;
				if(x==n&&y==n){
			    out(n,dp);
		        }else{
		        	if(x==n&&y==n){
			            out(n,dp);
			            return;
	            	}else{
		         	    if(y==n){
			        	    dfs(n,x+1,1,dp);
			            }else{
				            dfs(n,x,y+1,dp);
			            }
		            }
		        }
		        //���� 
		        dp[x][y]=0;
		        p[x][i]=true;
				l[y][i]=true;
				square[(x-1)/w*w+(y-1)/w+1][i]=true;
			}
		}
	}
} 
int main()
{
	int n,w;
	cin>>n;
	w=sqrt(n);
	vector<vector<int>> dp(n+2,vector<int>(n+2,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int num;
			cin>>num;
			dp[i][j]=num;
			if(num!=0){
				p[i][num]=false;
				l[j][num]=false;
				square[(i-1)/w*w+(j-1)/w+1][num]=false;
			}
		}
	}
	dfs(n,1,1,dp);
	return 0;
}
