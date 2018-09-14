#include <iostream>
using namespace std;

int num[10000];

int main()
{
    int N,T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i = 0;i < N;i++)
        {
            cin >> num[i];
        }

        for(int i = 0;i < N;i++)
        {
            for(;;)
            {
                if(num[i] != 0 && num[i+1] != 0)
                {
                    num[i]--;
                    num[i+1]--;
                }
                else if(num[i] == 0 || num[i+1] == 0)
                {
                    break;
                }
            }
        }
        int flag = 1;
        for(int i = 0;i < N;i++)
        {
            if(num[i] != 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
