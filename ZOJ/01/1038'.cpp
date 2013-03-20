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
char trans(char c)  //ת������
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
        qsort(dictionary,n,sizeof(dictionary[0]),cmp);//���ֵ��е���Ŀ���ֵ�������
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
                    if(d[p].s[0]==0) //d[p].s[0]==0��ʾ��p����Ŀ�ѱ��ų�
                        continue;
                    if(strlen(d[p].s)<j+1||trans(d[p].s[j])!=s[j])//���Ȳ��������в���
                    {
                        d[p].s[0]=0;
                        continue;
                    }
                }
                maxPro=-1;   //���Ƶ��
                ans[0]=0;   //�洢Ƶ�����ĵ���ǰ׺
                sumPro=0;   //��ǰƵ��
                for(p=0; p<n; p++)
                {
                    if(d[p].s[0]==0)
                        continue;
                    if(sumPro==0)//�ҵ��ĵ�һ������ǰ׺
                    {
                        strncpy(preS,d[p].s,j+1);
                        preS[j+1]=0;//��ǰ����ǰ׺
                        sumPro+=d[p].probability;
                        if(sumPro>maxPro)//��ǰƵ�ʴ������Ƶ��
                        {
                            maxPro=sumPro;
                            strcpy(ans,preS);
                        }
                    }
                    else if(strncmp(d[p].s,preS,j+1)==0)//��ǰ��ĵ���ǰ׺��ͬ
                    {
                        sumPro+=d[p].probability;
                        if(sumPro>maxPro)
                        {
                            maxPro=sumPro;
                            strcpy(ans,preS);
                        }
                    }
                    else        //��ǰ��ĵ���ǰ׺��ͬ
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
                if(maxPro==-1)      //Ϊ-1��û�ҵ�
                    printf("MANUALLY\n");
                else        //�ҵ��Ϸ��ĵ���ǰ׺
                    printf("%s\n",ans);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}