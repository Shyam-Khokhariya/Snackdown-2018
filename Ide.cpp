#include<iostream>
using namespace std;
int gcd(long int a,long int b)
{
    long int rem=b;
    while(rem!=0)
    {
        
        rem=b%a;
        b=a;
        a=rem;
    }
    return b;
}
int main()
{long int u;
cin>>u;
while(u>0)
{   long int n;
    cin>>n;
    long int a[n],b[n],i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>=2 && a[i]<=50)
            b[i]=a[i];
        else
            b[i]=-1;
    }
    long int conn[n][n],gc[n][n];
    for(i=0;i<n;i++)
    {
        for(long int j=i;j<n;j++)
        {
            conn[i][j]=conn[j][i]=0;
            gc[i][j]=gcd(b[i],b[j]);
            if(gc[i][j]==1)
            {
                conn[i][j]=conn[j][i]=1;
            }
        }
    }
    long int p=0,k=0,l=0,co[n],baki[n],no[51];
    for(i=0;i<50;i++)no[i]=0;
    for(i=0;i<n;i++)
    {
        long int cnt=0;
        for(long int j=0;j<n;j++)
        {
            if(conn[i][j]==1)
                cnt++;
        }
        if(cnt==0)
        {    
            baki[k]=i;k++;
            p++;
        }
        else
        {
            long int q=b[i];
            while(q<51)
            {
                no[q]=1;
                q+=b[i];
                
            }
        }
    }
    for(i=0;i<k;i++)
    {
        long int j,w;
        for(j=2;j<50;j++)
        {
            if(no[j]==0)
            {   w=j;
                long int z=2;
                while(j<51)
                {
                    no[j]=1;
                    j*=w;
                }   
                break;
            }
        }
        b[baki[i]]=w;
    }
    
    /*for(i=0;i<k;i++)
    {
        cout<<baki[i]<<"\t";
    }*/
    /*for(i=0;i<l;i++)
    {
        cout<<co[i];
    }*/
    cout<<p<<endl;
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<"\t";
    }
    cout<<endl;

    u--;
}    
    return 0;
}