#include <iostream>
#include<string.h>
using namespace std;
/*
int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
  
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return i; 
    } 
  
    return -1; 
} 

*/
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
            flag=0;
            long int j=0;
            while(j!=i)
            {
                if(strcmp(word[i],word[j])==0)
                {   
                    tim[i]=tim[j]/2;
                    break;
                }
                j++;
            }
            if(tim[i]==0)
            {
                long int l=strlen(word[i]);
                tim[i]=2*l;
                for(long int j=1;j<l;j++)
                {
                    if((word[i][j-1]=='d'||word[i][j-1]=='f') && (word[i][j]=='d'||word[i][j]=='f'))
                        tim[i]+=2;
                    else if((word[i][j-1]=='j'||word[i][j-1]=='k') && (word[i][j]=='j'||word[i][j]=='k'))
                        tim[i]+=2;
                }
            }
            tot+=tim[i];
            //cout<<tim[i]<<endl;
        }
        cout<<tot<<endl;
	    t--;
    }
    return 0;
}