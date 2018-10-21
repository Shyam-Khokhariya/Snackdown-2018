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
    int s[n+m-2]={0},l=0;
     int i,j,r[n*m],c[n*m],k=0;
    char str[n][m+1];
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
                
                for(int p=0;p<k-1;p++)
                {
                    l=mod(r[p]-r[k-1])+mod(c[p]-c[k-1]);
                    if(l<=n+m-2&&l>0)
                        s[l-1]++;
                }
            }
        }
    }
    for(i=0;i<n+m-2;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    t--;
        
    }return 0;
}