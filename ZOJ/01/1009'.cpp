#include<stdio.h>
#include<string.h>
char rotor[3][27],inverseRotor[3][27],cryptographs[10000],plaintext[10000];
int rotateNum[3],m;
void init()
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<m; j++)
            inverseRotor[i][rotor[i][j]-'A']='a'+j;
        inverseRotor[i][m]=0;
        rotateNum[i]=0;
    }
}
void rotate()
{
    char inverseRotort[27];
    int i,k;
    rotateNum[0]++;
    strcpy(inverseRotort,inverseRotor[0]);
    for(i=0; i<m; i++)
    {
        k=i-1;
        if(k<0)
            k+=m;
        k=inverseRotort[k]-'a'+1;
        if(k>=m)
            k-=m;
        inverseRotor[0][i]='a'+k;
    }
    if(rotateNum[0]<m)
        return ;
    rotateNum[0]-=m;
    rotateNum[1]++;
    strcpy(inverseRotort,inverseRotor[1]);
    for(i=0; i<m; i++)
    {
        k=i-1;
        if(k<0)
            k+=m;
        k=inverseRotort[k]-'a'+1;
        if(k>=m)
            k-=m;
        inverseRotor[1][i]='a'+k;
    }

    if(rotateNum[1]<m)
        return ;
    rotateNum[1]-=m;
    strcpy(inverseRotort,inverseRotor[2]);
    for(i=0; i<m; i++)
    {
        k=i-1;
        if(k<0)
            k+=m;
        k=inverseRotort[k]-'a'+1;
        if(k>=m)
            k-=m;
        inverseRotor[2][i]='a'+k;
    }
}
void display()
{
    int i;
    for(i=0; i<3; i++)
        printf("%s\n",inverseRotor[i]);
    printf("\n");
}
int main()
{
    freopen("f:\\in.txt","r",stdin);
    freopen("f:\\res.txt", "w", stdout);
    int n,caseNum=0,i,j,kl;
    char c;
    while(scanf("%d",&m)&&m)
    {
        caseNum++;
        if(caseNum>1)
            printf("\n");
        printf("Enigma %d:\n",caseNum);
        for(i=0; i<3; i++)
            scanf("%s",rotor[i]);
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",cryptographs);
            kl=strlen(cryptographs);
            init();
            for(i=0; i<kl; i++)
            {
                c=cryptographs[i];
                for(j=2; j>=1; j--)
                    c=inverseRotor[j][c-'A']-'a'+'A';
                c=inverseRotor[0][c-'A'];
                plaintext[i]=c;
                rotate();
            }
            plaintext[kl]=0;
            printf("%s\n",plaintext);
        }
    }
    return 0;
}
