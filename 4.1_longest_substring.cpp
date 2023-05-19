#include<iostream>
#include<string>
using namespace std;

bool unique(string str, int i, int j)
{
        int visited[256]={0};
        for(int k=i;k<=j;k++)
        {
                if(visited[str[k]]==1)
                        return false;
                visited[str[k]]=1;
        }
        return true;
}

void longest(string str)
{
        int n = str.length();
        int p=0,q=0;
        int m = 0;
        for(int i=0;i<n;i++)
        {
       4         for(int j=0;j<n;j++)
                {
                        if(unique(str,i,j))
                        {
                                if(m<j-i+1)
                                {
                                        m=j-i+1;
                                        p=i;
                                        q=j;
                                }
                                break;
                        }
                }
        }
        cout<<"Longest substring:"<<str.substr(p,m)<<endl;
        cout<<"Length:"<<m<<endl;
}

int main()
{
        string str;
        cout<<"Enter string:";
        cin>>str;
        cout<<str<<endl;
        longest(str);
        return 0;
}





