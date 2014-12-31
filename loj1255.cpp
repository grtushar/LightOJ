using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int T[1000010],l1,l2,occur;
char str[1000010],str2[1000010];


void failure()
{
    T[0]=0;
    int k=0;

    for(int q=2;q<=l1;q++)
    {
        while(k>0&&str[k]!=str[q-1])
        {
            k=T[k];
        }

        if(str[k]==str[q-1])
            k++;
        T[q]=k;
    }
}

void kmp()
{
    int q=0;
    for(int i=0;i<l2;i++)
    {
        while(q>0&&str[q]!=str2[i])
            q=T[q];

        if(str[q]==str2[i])
            q++;
        if(q==l1)
            occur++;
    }
}

int main()
{
    int t,Case=1;
    scanf("%d",&t);
    getchar();

    while(t--)
    {
        occur=0;
        gets(str2);
        gets(str);
        l1=strlen(str);
        l2=strlen(str2);

        failure();
        kmp();
        printf("Case %d: %d\n",Case++,occur);
    }
    return 0;
}
