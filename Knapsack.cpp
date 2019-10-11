#include<iostream>
#include<climits>
using namespace std;
long Knapsack(int price[],int size[],long dp[][2001],int n,int i,int capacity)
{

    if(capacity <= 0)
    {
        return 0;
    }

    if(i>=n)
        return 0;


    if(dp[capacity][i] != -1)
        return dp[capacity][i];


    long op1 = 0,op2 = 0;

    if(capacity >= size[i])
        op1 = Knapsack(price,size,dp,n,i+1,capacity - size[i]) + price[i];
    op2 = Knapsack(price,size,dp,n,i+1,capacity);

    dp[capacity][i] = max(op1,op2);
    return max(op1,op2);


}
int main()
{
    int capacity,n;
    cin>>capacity>>n;
    int size[20001],price[2001];
    long dp[2001][2001];
    for(int i=0;i<n;i++)
        cin>>size[i]>>price[i];

    for(int i=0;i<=capacity;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j] = -1;
    }

    cout<<Knapsack(price,size,dp,n,0,capacity);
}
