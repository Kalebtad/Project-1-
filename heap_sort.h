#ifndef Heap_Sort_H
#define Heap_Sort_H
#include<iostream>
#include<cmath>
using namespace std;



void fix_top_down(int*, int, int);


int* heap_sort(int* nodes,int n)
{

    for (int i=(n/2)-1; i>=0;i--)
        fix_top_down(nodes,i,n);


    while(n>0)
    {
        swap(nodes[0] , nodes[n-1]);
        n--;
        fix_top_down(nodes,0, n);
    }

    return nodes;
}

void fix_top_down(int* nodes, int i, int n)
{

    int parent = i;
    int left_child = 2*i+1;
    int right_child = 2*i+2;

    if(left_child<n && nodes[left_child]>nodes[parent])
        parent = left_child;

    if(right_child<n && nodes[right_child]>nodes[parent])
        parent = right_child;

    if(parent!=i) {
        swap(nodes[i], nodes[parent]);
        fix_top_down(nodes,parent,n);
    }
}



#endif
