//Binary Search
// Write a program to find if a element exists in a SORTED array at first time and at what position otherwise print -1
// For example-          array: 5  6  4  2  8
//                element_find: 4 
//                         ans: 3

// Time Complexity: - O(N)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(NULL);    // For fast input output
    
    int i,n;   
    cin>>n;
    int a[n],element_find;   
    for(i=0;i<n;i++)cin>>a[i];         // Taking input of array elements
    cin>>element_find;

    int ans=-1;
    int l=0,r=n-1;

    while(l<r)
    {
        int mid= (l+r)/2;
        if(a[mid]>=element_find)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    if(a[l]==element_find)
    {
        ans=l+1;
    } 
    cout<<ans;
}




