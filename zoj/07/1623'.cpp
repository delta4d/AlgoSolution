//if-else��������˱Ƚϴ���߼�����
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findstr(int start, char* s, char* t)
{
    int len = strlen(s);
    char* p = strstr(s+start,t);
    if(p == NULL)
        return -1;
    else
        return p-s;

}

inline void up(char& c)
{
    if(c>='a' && c<='z')
    {
        c = c+'A'-'a';
    }
}

void compile(char* s)
{
    int len = strlen(s);
    int count = 0;
    int start = 0;
    while(true)
    {
        int p1 = findstr(start,s,"/*");
        int p2 = findstr(start,s,"//");
        int p3 = findstr(p1+2,s,"*/");//һ��ʼ��int p3 = findstr(start,s,"//");���´�����WA�����簡����
        if((p1 != -1 && p3 != -1) && (p2 == -1 || p2 > p1))//������p1������/*ע�͡������ж����if������ʹ��һ��if�жϼ򵥵�
        {
            count++;
            for(int i=p1;i<=p3;i++)
            {
                up(s[i]);
            }
            start = p3+2;
        }
        else if(p2 != -1) //��start��ʼ������p2������//ע�ͣ�����ֱ�����з���һֱ��ע��
        {
            int last = findstr(p2+1,s,"\n");
            count++;
            for(int i = p2;i<last;i++)
            {
                up(s[i]);
            }
            start = last+1;
        }
        else
        {
            break;
        }
    } 
    printf("%d\n%s\n",count,s);
}

int main()
{
    int N;
    int lines;
    int len;
    char s[100000];
    char tmp[1000];
    long alllines=0;
    scanf("%d",&N);
    while(N--)
    {
        strcpy(s, "");
        scanf("%d",&lines);
        alllines+=lines;
        gets(tmp);
        for(int i=0;i<lines;i++)
        {
            gets(tmp);
            len = strlen(tmp);
            tmp[len]='\n';
            tmp[len+1] = '\0';
            strcat(s,tmp);
        }
        compile(s);
    }
}