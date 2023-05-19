#include <iostream>
#include <fstream>
using namespace std;
int main()
{
        ifstream f;
        ofstream fout;
        string line;
        try
        {
                f.open("city.txt");
                if(f.fail())
                {
                        throw "FileNotFoundException";
                }
                fout.open("mycity.txt");
                while(getline(f,line))
                {
                        fout<<line<<endl;
                }
                cout<<"File copied successfully";
        }
        catch(...)
        {
                cout<<"File not found";
        }
}



