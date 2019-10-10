#include <iostream>
using namespace std;
long MaxCaloriesBurnt(long calories[][1000],int n,int m)
{
    long boy_Start[1000][1000]={0},boy_Reverse[1000][1000]={0},girl_Start[1000][1000]={0},girl_Reverse[1000][1000]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
                boy_Start[i][j] = calories[i][j];
            else if(i==0)
                boy_Start[i][j] = calories[i][j] + boy_Start[i][j-1];
            else if(j==0)
                boy_Start[i][j] = calories[i][j] + boy_Start[i-1][j];
            else
                boy_Start[i][j] = calories[i][j] + max(boy_Start[i-1][j],boy_Start[i][j-1]);
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==n-1 && j==m-1)
                boy_Reverse[i][j] = calories[i][j];
            else if(i==n-1)
                boy_Reverse[i][j] = calories[i][j] + boy_Reverse[i][j+1];
            else if(j==m-1)
                boy_Reverse[i][j] = calories[i][j] + boy_Reverse[i+1][j];
            else
                boy_Reverse[i][j] = calories[i][j] + max(boy_Reverse[i+1][j],boy_Reverse[i][j+1]);
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(i==n-1 && j==0)
                girl_Start[i][j] = calories[i][j];
            else if(i==n-1)
                girl_Start[i][j] = calories[i][j] + girl_Start[i][j-1];
            else if(j==0)
                girl_Start[i][j] = calories[i][j] + girl_Start[i+1][j];
            else
                girl_Start[i][j] = calories[i][j] + max(girl_Start[i+1][j],girl_Start[i][j-1]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(i==0 && j==m-1)
                girl_Reverse[i][j] = calories[i][j];
            else if(i==0)
                girl_Reverse[i][j] = calories[i][j] + girl_Reverse[i][j+1];
            else if(j==m-1)
                girl_Reverse[i][j] = calories[i][j] + girl_Reverse[i-1][j];
            else
                girl_Reverse[i][j] = calories[i][j] + max(girl_Reverse[i-1][j],girl_Reverse[i][j+1]);
        }
    }

    long ans1=0,ans2,ans3;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
            ans2 = boy_Start[i-1][j] + boy_Reverse[i+1][j] + girl_Start[i][j-1] + girl_Reverse[i][j+1];
            ans3 = boy_Start[i][j-1] + boy_Reverse[i][j+1] + girl_Start[i+1][j] + girl_Reverse[i-1][j];
            ans1 = max(ans1,max(ans2,ans3));
        }
    }

    return ans1;

}
int main()
{
    int n,m;
    cin>>n>>m;

    long calories[1000][1000];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>calories[i][j];
        }
    }

    cout<<MaxCaloriesBurnt(calories,n,m);

}
