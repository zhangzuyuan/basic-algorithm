#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char T[20000];
char P[20000];
int f[20000]={0};
void getf(char tmp[],int len)
{
	int j=0;
	int k=-1;
	f[j] = k;
	while(j<len-1)
	{
		if(k==-1||tmp[j]==tmp[k])
		{
			k++;j++;
			f[j]=k;
		}
		else
			k=f[k];
	}
}
int KMP(char T[],int lenT,char P[],int lenP)
{
	int q=0,w=0;
	while(q<lenT&&w<lenP)
	{
		if(w==-1||T[q]==P[w])
		{
			q++;
			w++;
		}
		else
		{
			w=f[w];
		}
	}
	if(w==lenP) return q-w;
	return -1;
}
int main()
{
	cin>> T>>P;
	int lenT = strlen(T);
	int lenP = strlen(P);
	//cout<<lenT<<endl<<lenP<<endl;
	getf(P,lenP);
	//for(int i=0;i<lenP;++i)
	//{
	//	cout<<f[i]<<" ";
	//}
	cout<<KMP(T,lenT,P,lenP)<<endl;
	return 0;
} 
