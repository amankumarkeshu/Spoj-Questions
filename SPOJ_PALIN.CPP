#include<bits/stdc++.h>
using namespace std;

char k[1000005];

int l,i,j,mid;

bool chkNine()
{
	cout<<"";
    for(i=0;i<l;i++)
    {
        if( k[i]!='9' ) return false;
    }
}

void nextPalin()
{

    int f=0;
    l=strlen(k);

    if(chkNine()) {
        memset(k,'0',l);
        k[0] ='1';
        k[l]='1';
        k[l+1]='\0';
        return;
    }

    // calc mid,i,j
    if(l%2==0)
    {
        i= ( l/2 )-1;
        j= l/2;
        mid= (l/2) -1;
    }
    else
    {
        i= ( l/2 )-1;
        j= (l/2 )+1;
        mid=l/2;
    }
    int a = i, b =j;
    //iteration of k[i] & k[j]
    for(; i>=0; i--,j++)
    {
        if(k[i] > k[j])
        {
            f=1;
            break;
        }
        else if ( k[i] < k[j] )
        {
            f=2;
            break;
        }
    }
    if(f==1)
    {
        for(; i>=0; i--,j++)
        {
            k[j]=k[i];
        }
    }
    else if(f==2||f==0)
    {
        int temp,c=1;
        if(l%2==0)
        {
            for(i=a,j=b; i>=0; i--,j++)
            {
                temp = (k[i]-48)+c ;
                c= temp /10;
                temp= temp%10;
                k[i]= temp+48;
                k[j]=k[i];
            }
        }
        else if(l%2!=0)
        {
            temp = (k[mid]-48)+c ;
            c= temp /10;
            temp= temp%10;
            k[mid]= temp+48;

            for(i=a,j=b; i>=0; i--,j++)
            {
                temp = (k[i]-48)+c ;
                c= temp /10;
                temp= temp%10;
                k[i]= temp+48;
                k[j]=k[i];
            }
        }
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        scanf("%[^\n]%*c",k);
        nextPalin();
        printf("%s\n",k);
    }

    return 0;
}
