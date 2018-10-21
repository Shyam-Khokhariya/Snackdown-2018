#include <iostream>
using namespace std;
int check_desc(long int a[],long int n)
{
    int p = a[n-1]; 
    for(long int i=n-1;i>-0;i--) 
    { 
        long int r = a[i]; 
        if (r > p) 
           return 0; 
        p = r; 
    } 
  
    return 1; 

}
int main() 
{
    long int t;
    cin>>t;
    while(t>0)
    {
        long int n;
        cin>>n;
        long int a[n],flag=0,temp;
        for(long int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(long int i=0;i<n-1;i++)
        {
            temp=a[0];
            for(long int j=0;j<n-1;j++)
            {
                a[j]=a[j+1];
            }
            a[n-1]=temp;
            
            if(check_desc(a,n)==1)
            {
                flag=1;
                break;
            }
            
        }
        if(flag==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
	    t--;
    }
    return 0;
}
