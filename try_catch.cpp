#include<iostream>
using namespace std;
int main()
{
        int a, b, c, e;
        cout<<"Enter a and b";
        cin>>a>>b;

        try
        {
                if(b==0)
                throw e;
                c=a/b;
                cout<<c<<endl;
        }

        catch(int e)
        {
                cout<<"Divide by zero exponent";
        }
}


