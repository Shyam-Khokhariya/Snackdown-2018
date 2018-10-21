#include<iostream>
using namespace std;
int gcd(long int a,long int b)
{
    if(a==1||b==1)
        return -1;
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
    long int a[n],b[n],i,index[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        index[i]=i;
    }
    for(i=0;i<n;i++)
    {

        for(long int j=i;j<n;j++)
        {
            if(b[i]<b[j])
            {
                long int temp=b[j],te=index[i];
                b[j]=b[i];
                b[i]=temp;
                index[i]=index[j];
                index[j]=te;
            }
        }
    }
/*
    for(i=0;i<n;i++)
    {
        cout<<b[i]<<"\t"<<index[i]<<"\n";

    }*/
    long int conn[n][n],gc;

    long int p=0,k=0,l=0,co[n],baki[n],no[51];
    for(i=2;i<=50;i++)no[i]=0;

    for(i=0;i<n;i++)
    {
        for(long int j=i;j<n;j++)
        {
            conn[i][j]=conn[j][i]=0;
            gc=gcd(b[i],b[j]);
            if(gc==1)
            {
                conn[i][j]=conn[j][i]=1;
            }
        }
        long int cnt=0;
        cout<<"gfs";
        for(long int j=0;j<n;j++)
        {
            if(conn[i][j]==1)
                cnt++;
        }
        if(cnt==0)
        {
            baki[k]=i;k++;
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
    //conn[0][0]=1;
    /*for(i=0;i<n;i++)
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
    }*/

    long int used[k];
    for(i=0;i<k;i++)
    {
        long int j,w;
        //if(i>0)
        //{
            long int y,t[k],r=b[baki[i]];
            for(y=0;y<n;y++)
            {
                t[y]=0;
                if(gcd(b[y],r)==1)
                {
                    t[y]=1;
                    break;
                }
            }

            if(t[y]==1&&y<n)
                continue;


        //}
        for(j=50;j>1;j--)
        {
            lable:  if(no[j]==0)
            {
                for(y=0;y<n;y++)
                {
                    t[y]=0;
                    if(gcd(b[y],j)==1)
                    {
                        t[y]=1;
                        break;
                    }
                }
                if(y==n)
                {
                    j++;goto lable;
                }
                w=j;
                long int z=2;
                while(j<51)
                {
                    no[j]=1;
                    j+=w;
                }
                break;
            }
        }
        used[i]=b[baki[i]];
        if(b[baki[i]]!=w)
        {
            b[baki[i]]=w;
            p++;
        }
    }
    cout<<p<<endl;
    long int v[n];
    for(i=0;i<n;i++)
    {
        v[index[i]]=b[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    u--;
}
    return 0;
}
