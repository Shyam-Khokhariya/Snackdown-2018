#include<iostream>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test>0)
    {
        int n,i,l,j,k,t=0;
        cin>>n;
        int a[n],q=n+1;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            if(a[i]!=-1)
            {
                q=i;
                break;
            }
        }
        for(i=q+1;i<n;i++)
        {
            int flag=0,o=0;
            if(a[q]==a[i])
            {
                l=i-q;
                for(int p=i,k=q;p<n;p++,k++)
                {
                    if(k==l)
                        k=q;
                    if(a[p]==-1 && a[k]==-1)
                        continue;
                    else if(a[k]==-1)
                    {
                        a[k]=a[p];
                        continue;
                    }
                    else if(a[p]==-1)
                    {
                        a[p]=a[k];
                        continue;
                    }
                    if(a[k]!=a[p])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    o=1;
            }
            if(o==1)
            {   
                t=1;
                break;
            }
        }
        if(t==1)
            cout<<l<<endl;
    else if(q>n)
            cout<<"inf"<<endl;
        else
            cout<<"impossible"<<endl;
    
    test--;
    }
    return 0;
}
