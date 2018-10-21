#include <iostream>
#include<string.h>
using namespace std;

int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return i; 
    } 
  
    return -1; 
} 


int main() 
{
    long int t;
    cin>>t;
    while(t>0)
    {
        long int n,tot=0;
        cin>>n;
        long int tim[n],flag=0;
        char word[n][21];
        for(long int i=0;i<n;i++)
        {
            cin>>word[i];
            tim[i]=0;
            int j=0;
            flag=0;
            while(word[i][j]!='\0')
            {
                word[i][j]=tolower(word[i][j]);
                j++;
            }
            j=0;
            while(j!=i)
            {
                if(isSubstring(word[i],word[j])!=-1)
                {
                    flag=1;
                    break;
                }
                j++;
            }
            j=0;
            while(word[i][j]!='\0')
            {
                if(j==0)
                    tim[i]+=2;
                else if(word[i][j-1]=='d'||word[i][j-1]=='f')
                {
                    if(word[i][j]=='d'||word[i][j]=='f')
                        tim[i]+=4;
                    else
                        tim[i]+=2;
                }
                else
                {
                    if(word[i][j]=='j'||word[i][j]=='k')
                        tim[i]+=4;
                    else
                        tim[i]+=2;
                }
                j++;
            }
            if(flag==1)
                tot+=(tim[i]/2);
            else
                tot+=tim[i];
          //  cout<<tim[i]<<endl;
        }
        cout<<tot<<endl;
	    t--;
    }
    return 0;
}
