//Email地址
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int i,j,count=0,stage=0,len;
    len=s.length();
    for(i=0;i<len;i++)
    {
        if(s[i]>'z'||s[i]<'a')
        {
            continue;
        }
        else
        {
            stage=0;
        }
        
        for(j=i;j<len;j++)
        {
            if(stage==0)
            {
                if(s[j]=='@')
                {
                    stage=1;
                    continue;
                }
                if(!(s[j]=='_'||(s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='z')))
                {
                    break;
                }
            }
            if(stage==1)
            {
                if(s[j]=='.')
                {
                    stage=2;
                    continue;
                }
                if(!((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='z')))
                {
                    break;
                }
            }
            if(stage==2)
            {
                if(s[j]>='a'&&s[j]<='z')
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}