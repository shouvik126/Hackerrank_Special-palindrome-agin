#include<iostream>
#include<string>
#include<vector>
using namespace std;
long long substrCount(int n,string s)
{
    long long ans=0;
    vector<long long>temp(n);
    for(int i=0;i<s.size();i++)
    {
        temp[i]=1;
    }
    int i=0,j=i+1;
    while(j<s.size())
    {
        if(s[i]==s[j])
        {
            temp[i]+=1;
            j++;
            if(j==s.size())
            {
               for(int k=i+1;k<j;k++)
                {
                    temp[k]=temp[k-1]-1;
                }
            }
        }
        else
        {
            for(int k=i+1;k<j;k++)
            {
                temp[k]=temp[k-1]-1;
            }
            i=j;
            j=j+1;
        }
    }
    //////////////////////////////////
    i=0;
    int temp_ans=0;
    for(int m=1;m<s.size()-1;m++)
    {
        for(int n=m-1,k=m+1;n>=0 && k<s.size();n--,k++)
        {
            if(n<m-1 && s[n]!=s[n+1])
                break;
            if(s[n]==s[k] && s[m]!=s[n])
                temp_ans++;
            else
                break;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        //cout<<temp[i]<<" ,";
        ans+=temp[i];
    }
    return ans+temp_ans;
}
int main()
{
    long long n;
    cin>>n;
    string s;
    cin>>s;
    long long ans=substrCount(n,s);
    cout<<ans;
    return 0;
}
