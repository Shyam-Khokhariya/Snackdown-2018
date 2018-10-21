#include<iostream>
#include<algorithm>
using namespace std;

int coprime(int a, int b) {

    if ( __gcd(a, b) == 1)
    	return 1;
    else
        return 0;
}

int main()
{
	long int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,tot_edges=0,count=0;
		cin>>n;
		int a[n],b[n],visited[n]={0};
		for(i=0;i<n;i++)
			cin>>a[i];
		tot_edges=(n*(n-1))/2;
		for(i=0;i<n;i++)
		{
			if(coprime(a[i],a[i+1]))
			{
				b[i]=a[i];
				b[i+1]=a[i+1];
				visited[i]=1;
				visited[i+1]=1;
			}
			else
				b[i]=a[i];
		}
		for(i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				j=i+1;
				if(!coprime(a[i],a[i+j]))j++;
				if(j==n)break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				visited[i]=1;
				if(a[i]>a[i+1])
				{
					b[i]=a[i]-(a[i]-a[i+1]-1);
				}
				else
					b[i]=a[i+1]-(a[i+1]-a[i]-1);
				count++;
			}
		}
		cout<<count<<endl;
		for(i=0;i<n;i++)cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
