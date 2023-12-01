#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include<iostream>
using namespace std;


void partition(int*,int,int,int);


int* quick_sort(int* a, int n)
{
    int l=1;
    int r=n-1;
    partition(a,n,l,r);
    return a;
}


void partition(int* a,int n,int l,int r)
{

    int original_l=l;
    int original_r=r;


    int pivot=l-1;


    while(r>=l)
    {


            if(a[l]>a[pivot] && a[r]<a[pivot])
                swap(a[l],a[r]);
            else if(a[l]>a[pivot])
                r--;
            else
                l++;
    }

    swap(a[pivot],a[r]);
    pivot=r;


    int pivot_left=original_l-1;
    int l_left=pivot_left+1;
    int r_left=pivot-1;
    int n_left=r_left-l_left+2;

    int pivot_right=pivot+1;
    int l_right=pivot_right+1;
    int r_right=original_r;
    int n_right=r_right-pivot_right;



    if(n_left > 0)
        partition(a,n_left,l_left,r_left);
    if(n_right > 0)
        partition(a,n_right,l_right,r_right);
}

#endif // Quick_Sort
