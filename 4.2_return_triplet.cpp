#include<iostream>
using namespace std;

void triplets(int a[],int n)
{
        int found=0;
        for(int i=0;i<n-1;i++)
        {
                for(int j=0;j<n-i-1;j++)
                {
                        if(a[j]>a[j+1])
                        {
                                int temp=a[j];
                                a[j]=a[j+1];
                                a[j+1]=temp;
                        }
                }
        }
        cout<<"Triplets:"<<endl;
        for(int i=0;i<n-2;i++)
        {
                while(a[i-1]==a[i])
                        i++;
                for(int j=i+1;j<n-1;j++)
                {
                        while(a[j-1]==a[j])
                                j++;
                        for(int k=j+1;k<n;k++)
                        {
                                while(a[k-1]==a[k])
                                        k++;
                                if(a[i]+a[j]+a[k]==0)
                                {
                                        cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                                        found =1;
                                }
                        }
                }
        }
        if(found==0)
                cout<<"No triplets exist\n";
}


int main()
{
        int n;
        cout<<"Enter size: ";
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
                cin>>a[i];
        triplets(a,n);
}


