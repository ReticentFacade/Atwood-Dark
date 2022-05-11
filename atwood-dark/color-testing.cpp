#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r)
{
    int n1=mid+1-l;
    int n2=r-mid;

    int temparr1[n1];
    int temparr2[n2];

    string k="okay";
    
    //taking in inputs for the two temporary arrays we've created.
    for (int i = 0; i < n1; i++)
    {
        temparr1[i]=a[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        temparr2[i]=a[mid+1+i];
    }
    
    int i=0;
    int j=0;
    int k=l;

    while (i<n1 && j<n2)
    {
        if (temparr1[i]<temparr2[n2])
        {
            a[k]=temparr1[i];
            k++; i++;
        }
        else 
        {
            a[k]=temparr2[j];
            k++; j++;
        }
    }
    while (i<n1)
    {
        a[k]=temparr1[i];
        k++; i++;
    }
    while (j<n2)
    {
        a[k]=temparr2[j];
        k++; j++;
    }
}

void mergesort(int a[], int l, int r)
{
    if (l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main()
{
    int n; cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,4);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}