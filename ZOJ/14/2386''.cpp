#define MAX 500000
int temp[MAX];
int in[MAX];
__int64 sum;
void merge(int *a,int l,int mid,int r)
{
    int i=l,j=mid+1;
    int k=0;
    while (i<=mid&&j<=r)
    {
        if (a[i]<=a[j])
        {
            temp[k++]=a[i];
            i++;
        }
        else
        {
            temp[k++]=a[j];
            j++;
            sum+=mid-i+1;
        }
    }

    while (j<=r)
    {
        temp[k++]=a[j];
        j++;
    }

    while (i<=mid)
    {
        temp[k++]=a[i];
        i++;
    }
    for (i=0;i<=r-l;i++)
        a[i+l]=temp[i];
}


void mergesort(int *a,int left,int right)
{
    if (left<right)
    {
        int mid=(right+left)>>1;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}


int main()
{
    int n;

    while (scanf("%d",&n)&&n)
    {
        int m=0,k=n;
        sum=0;
        while (k--)
        {
            scanf("%d",&in[m++]);
        }
        mergesort(in,0,n-1);
        printf("%I64d\n",sum);
    }
    return 1;
}
