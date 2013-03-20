#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word
{
    char s[101];
    int probability;
};
word dictionary[1000],d[1000];
int cmp ( const void *a , const void *b )
{
    return strcmp( ((word*)a)->s,((word*)b)->s );
}
char trans(char c)  //转换函数
{
    if(c>='a'&&c<='c')
        return '2';
    else if(c>='d'&&c<='f')
        return '3';
    else if(c>='g'&&c<='i')
        return '4';
    else if(c>='j'&&c<='l')
        return '5';
    else if(c>='m'&&c<='o')
        return '6';
    else if(c>='p'&&c<='s')
        return '7';
    else if(c>='t'&&c<='v')
        return '8';
    else
        return '9';
}
int main()
{
    freopen("in.txt","r",stdin);
    int caseNum,q,n,m,i,j,p,len,maxPro,sumPro;
    char s[102],ans[101],preS[101];
    scanf("%d",&caseNum);
    for(q=1; q<=caseNum; q++)
    {
        printf("Scenario #%d:\n",q);
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%s %d",dictionary[i].s,&dictionary[i].probability);
        qsort(dictionary,n,sizeof(dictionary[0]),cmp);//对字典中的条目按字典序排列
        scanf("%d",&m);
        for(i=1; i<=m; i++)
        {
            scanf("%s",s);
            len=strlen(s);
            memcpy(d,dictionary,sizeof(dictionary[0])*n);
            for(j=0; j<len-1; j++)
            {
                for(p=0; p<n; p++)
                {
                    if(d[p].s[0]==0) //d[p].s[0]==0表示第p个条目已被排除
                        continue;
                    if(strlen(d[p].s)<j+1||trans(d[p].s[j])!=s[j])//长度不够或序列不对
                    {
                        d[p].s[0]=0;
                        continue;
                    }
                }
                maxPro=-1;   //最大频率
                ans[0]=0;   //存储频率最大的单词前缀
                sumPro=0;   //当前频率
                for(p=0; p<n; p++)
                {
                    if(d[p].s[0]==0)
                        continue;
                    if(sumPro==0)//找到的第一个单词前缀
                    {
                        strncpy(preS,d[p].s,j+1);
                        preS[j+1]=0;//当前单词前缀
                        sumPro+=d[p].probability;
                        if(sumPro>maxPro)//当前频率大于最大频率
                        {
                            maxPro=sumPro;
                            strcpy(ans,preS);
                        }
                    }
                    else if(strncmp(d[p].s,preS,j+1)==0)//和前面的单词前缀相同
                    {
                        sumPro+=d[p].probability;
                        if(sumPro>maxPro)
                        {
                            maxPro=sumPro;
                            strcpy(ans,preS);
                        }
                    }
                    else        //和前面的单词前缀不同
                    {
                        strncpy(preS,d[p].s,j+1);
                        preS[j+1]=0;
                        sumPro=d[p].probability;
                        if(sumPro>maxPro)
                        {
                            maxPro=sumPro;
                            strcpy(ans,preS);
                        }
                    }
                }
                if(maxPro==-1)      //为-1，没找到
                    printf("MANUALLY\n");
                else        //找到合法的单词前缀
                    printf("%s\n",ans);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}