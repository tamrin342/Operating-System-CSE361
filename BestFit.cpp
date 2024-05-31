#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nofBlocks,nofRequst,val,pos,index,f,minimum;
    cout  << " Enter the Number of Blocks : " ;
    cin >> nofBlocks ;
    int memoryBlock[nofBlocks];

    cout << "Enter Block Sizes : " ;
    for(int i=0; i<nofBlocks; i++)
        cin >>memoryBlock[i] ;

    cout  << " Enter the Number of Memory Requests : " ;
    cin >> nofRequst ;
    int memoryRequest[nofRequst];
    for(int i=0; i<nofRequst; i++)
    {
        cin>>memoryRequest[i];
    }
    int table[nofBlocks+1][nofRequst]={0};


    for(int i=0; i<nofRequst; i++)//inserted memory requests in the first row of matrix
        table[0][i]=memoryRequest[i];

    for(int j=0; j<nofRequst; j++)
    {
        f=0;
        minimum = INT_MAX;
         for(int k=0; k<nofBlocks; k++)
            {
                if(memoryRequest[j]<=memoryBlock[k])
                {
                    val = memoryBlock[k]-memoryRequest[j];
                    if(val<minimum)
                    {
                        minimum = val;
                        pos=k+1;
                    }
                    f=1;
                }
            }
            memoryBlock[pos-1]=minimum;
            if(f==0) {
            index = j;
            goto print;}

        for(int i=1; i<nofBlocks+1; i++)
        {
            if(i==pos) table[i][j] = minimum;
            else table[i][j] = memoryBlock[i-1];

        }
    }

    print:
        int sum=0;
    for(int i=0; i<nofBlocks; i++)
    {
        sum=sum+table[i+1][index-1];
    }

    for(int i=0; i<nofBlocks+1; i++)
    {
        for(int j=0; j<nofRequst; j++)
        {
            cout<<table[i][j]<< " ";
        }
        cout<<endl;
    }

    if(f==0) cout<<"Free Space = "<<sum;
    else return 0;
}

