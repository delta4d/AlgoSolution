#include<iostream>
#include<string>
using namespace std;
int main()
{
    string source, s[501];
    char command[100001];
    int i,k,N,n;
    scanf("%d",&N);
    while(N--) {
        scanf("%d",&n);
        getchar();
        source="";
        for(i=0;i<n;i++) {
            getline(cin, s[i]);
            source += s[i];
        }
        k=0;
        while(scanf("%c", &command[k])) {
            if(command[k]=='#')
                break;
            k++;
        }

        int pointer=0;
        int counter=0;
        for(i=0;i<k;i++) {
            if(command[i]=='G') {
                cout<<source[pointer];
                counter++;
                if(counter%80==0) {
                    cout<<endl;
                }
                source.erase(pointer,1);
                if(pointer>0)
                    pointer--;
            }
            else if(command[i]=='R') {
                if(pointer==0)
                    pointer=source.length()-1;
                else
                    pointer=0;
            }
        }
        cout<<endl;
        if(N!=0)
            cout<<endl;
    }
    return 0;
}
