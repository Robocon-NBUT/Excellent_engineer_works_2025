#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0)); 
    unsigned int numbers[5];
    ofstream fout("input.txt");
    cout<<"д�� input.txt �� unsigned int ��ֵΪ: ";
    for(int i=0;i<5;i++)
	{
        numbers[i]=rand();
        fout<<numbers[i];
        cout<<numbers[i];
        if (i!=4)
		{
            fout<<" ";
            cout<<" ";
        }
    }
    fout.close();
    cout<<endl;
    
    ifstream fin("input.txt");
    unsigned int value;
    float sum=0.0;
    int count=0;
    while (fin>>value&&count<5)
	{
        sum+=value;
        count++;
    }
    fin.close();

    float mean=sum/count;

    ofstream fout2("output.txt");
    fout2<<fixed<<setprecision(2)<<mean;
    fout2.close();

    cout<<"�� input.txt ��ȡ������ƽ��ֵΪ��float32��: ";
    cout<<fixed<<setprecision(2)<<mean<<endl;
    return 0;
}
