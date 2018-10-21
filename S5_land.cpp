#include<iostream>
using namespace std;
long int mod(long int a)
{
    if(a<0)
        return -a;
    return a;
}
int main()
{
    int t;
    cin>>t;
    while(t>0)
    { int n,m;
    cin>>n>>m;
     int i,j,r[n*m],c[n*m],k=0;
    char str[n][m];
    for(i=0;i<n;i++)
    {
        cin>>str[i];
        for(j=0;j<m;j++)
        {
            if(str[i][j]=='1')
            {
                r[k]=i+1;
                c[k]=j+1;
                k++;
            }
        }
    }
     int d[k],l=0;
    for(i=0;i<k-1;i++)
    {
        for(j=i+1;j<k;j++)
        {
            //cout<<r[i]<<" "<<r[j]<<"\t"<<c[i]<<" "<<c[j]<<"\n";
            d[l]=mod(r[j]-r[i])+mod(c[j]-c[i]);
            if(d[l]<=n+m-2)
                l++;
        }
    }
     int s[n+m-2];
    for(i=0;i<n+m-2;i++)
    {
        s[i]=0;
        for(j=0;j<l;j++)
        {
            if(d[j]==i+1)
                s[i]++;
        }
        cout<<s[i]<<" ";
    }
    cout<<endl;
    t--;
        
    }return 0;
}