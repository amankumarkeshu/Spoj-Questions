#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int min4(int m1,int m2,int m3,int m4)
{
    return min(min(m1,m2) , min(m3,m4));
}

int main()
{
    int t,n,count,temp;
    cin>>t;
    char c;
    while(t--)
    {
        cin>>n;
        int a[n][n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>c;
                if(c=='.')
                    a[i][j] = 0;
                else
                    a[i][j] = 1;
            }
        }

        int preX[n][n] , postX[n][n];
        int preY[n][n] , postY[n][n];

        for(int i=0;i<n;i++)
        {
            count = 0;
            for(int j=0;j<n;j++)
            {
                preX[i][j] = count;
                if(a[i][j] == 0)
                    count=0;
                else
                    count++;
            }
            
            count = 0;
            for(int j=n-1 ; j>=0;j--)
            {
                postX[i][j] = count;
                if(a[i][j] == 0)
                    count = 0;
                else
                    count++;
            }
            
            count = 0;
            for(int j=0;j<n;j++)
            {
                preY[j][i] = count;
                if(a[j][i] == 0)
                    count=0;
                else
                    count++;
            }
            
            count = 0;
            for(int j=n-1 ; j>=0;j--)
            {
                postY[j][i] = count;
                if(a[j][i] == 0)
                    count = 0;
                else
                    count++;
            }

        }

        count = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                //cout<<i<<" "<<j<<" : "<<preX[i][j]<<" "<<postX[i][j]<<" "<<preY[i][j]<<" "<<postY[i][j]<<endl;
                if(a[i][j]==1)
                {
                    temp = min4(preX[i][j] , postX[i][j], preY[i][j], postY[i][j]) + 1;
                    if(temp>count)
                        count = temp;
                }
            }
        }

        cout<<count<<endl;
    }
    
	return 0;
}
