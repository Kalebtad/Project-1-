 #include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include "quick_sort.h"
#include "radix_sort.h"
#include "heap_sort.h"
#include "insert_sort.h"
using namespace std;

void print_array(int* , int);

int main() {

    using chrono::nanoseconds;
    random_device rd;
    mt19937 gen(rd());



    int max_times = 100;
    int max_size=100000;
    int min_size=10;
    int increment=10;
    int random_max=10000;
    int stop_worst=10000;

    uniform_int_distribution<int> dist(0, random_max);


    auto start = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();

    ofstream dataFile("data.csv");
    dataFile << "Size, Quick Avg, Radix Avg, Heap Avg, Insert Avg, Quick Sorted, Radix Sorted, Heap Sorted, Insert sorted\n";

    nanoseconds sum_quick(0),avg_quick(0);
    nanoseconds sum_radix(0),avg_radix(0);
    nanoseconds sum_heap(0),avg_heap(0);
    nanoseconds sum_insert(0),avg_insert(0);


    nanoseconds sum_quick_sorted(0),avg_quick_sorted(0);
    nanoseconds sum_radix_sorted(0),avg_radix_sorted(0);
    nanoseconds sum_heap_sorted(0),avg_heap_sorted(0);
    nanoseconds sum_insert_sorted(0),avg_insert_sorted(0);



    int* sorted_array=new int[max_size];
    for(int i=0;i<max_size;i++)
        sorted_array[i]=i;


    for (int n = min_size ; n <= max_size ; n += increment) {
        int *random_array=new int[n];
        int* a=new int[n];


        for (int times = 0 ; times < max_times ; times++) {

            for (int j = 0 ; j < n ; j++) {
                random_array[j] = dist(gen);
            }

            copy(random_array,random_array+n,a);

            start = chrono::steady_clock::now();
            quick_sort(a,n);

            end = chrono::steady_clock::now();
            nanoseconds time_quick(end - start);
            sum_quick += time_quick;


            if(n<stop_worst)
            {

                copy(sorted_array,sorted_array+n,a);

                start = chrono::steady_clock::now();
                quick_sort(a,n);

                end = chrono::steady_clock::now();
                nanoseconds time_quick_sorted(end - start);
                sum_quick_sorted += time_quick_sorted;

                copy(sorted_array,sorted_array+n,a);

                start = chrono::steady_clock::now();
                radixSort(a,n);

                end = chrono::steady_clock::now();
                nanoseconds time_radix_sorted(end - start);
                sum_radix_sorted += time_radix_sorted;



                copy(sorted_array,sorted_array+n,a);

                start = chrono::steady_clock::now();
                heap_sort(a,n);

                end = chrono::steady_clock::now();
                nanoseconds time_heap_sorted(end - start);
                sum_heap_sorted += time_heap_sorted;


                copy(sorted_array,sorted_array+n,a);

                start = chrono::steady_clock::now();
                insert_sort(a,n);

                end = chrono::steady_clock::now();
                nanoseconds time_insert_sorted(end - start);
                sum_insert_sorted += time_insert_sorted;
            }


            copy(random_array,random_array+n,a);

            start = chrono::steady_clock::now();
            radixSort(a,n);

            end = chrono::steady_clock::now();
            nanoseconds time_radix(end - start);
            sum_radix += time_radix;



            copy(random_array,random_array+n,a);

            start = chrono::steady_clock::now();
            heap_sort(a,n);

            end = chrono::steady_clock::now();
            nanoseconds time_heap(end - start);
            sum_heap += time_heap;



            copy(random_array,random_array+n,a);

            start = chrono::steady_clock::now();
            insert_sort(a,n);

            end = chrono::steady_clock::now();
            nanoseconds time_insert(end - start);
            sum_insert += time_insert;

        }


        avg_quick = sum_quick / max_times;
        avg_radix = sum_radix / max_times;
        avg_heap = sum_heap / max_times;
        avg_insert = sum_insert / max_times;

        if(n<stop_worst)
        {
            avg_quick_sorted = sum_quick_sorted / max_times;
            avg_radix_sorted = sum_radix_sorted / max_times;
            avg_heap_sorted = sum_heap_sorted / max_times;
            avg_insert_sorted = sum_insert_sorted / max_times;
        }

        cout << "SIZE:"<<n<<"\t\t"<<"QUICK AVG:\t"<<avg_quick.count()<<endl;
        cout << "SIZE:"<<n<<"\t\t"<<"RADIX AVG:\t"<<avg_radix.count()<<endl;
        cout << "SIZE:"<<n<<"\t\t"<<"HEAP AVG:\t"<<avg_heap.count()<<endl;
        cout << "SIZE:"<<n<<"\t\t"<<"INSERT AVG:\t"<<avg_insert.count()<<endl;
        if(n<stop_worst)
        {
            cout << "SIZE:"<<n<<"\t\t"<<"QUICK SORTED:\t"<<avg_quick_sorted.count()<<endl;
            cout << "SIZE:"<<n<<"\t\t"<<"RADIX SORTED:\t"<<avg_radix_sorted.count()<<endl;
            cout << "SIZE:"<<n<<"\t\t"<<"HEAP SORTED:\t"<<avg_heap_sorted.count()<<endl;
            cout << "SIZE:"<<n<<"\t\t"<<"INSERT SORTED:\t"<<avg_insert_sorted.count()<<endl;
        }
        else
        {
            cout << "SIZE:"<<n<<"\t\t"<<"QUICK SORTED:\t"<<"STOPPED"<<endl;
            cout << "SIZE:"<<n<<"\t\t"<<"RADIX SORTED:\t"<<"STOPPED"<<endl;
            cout << "SIZE:"<<n<<"\t\t"<<"HEAP SORTED:\t"<<"STOPPED"<<endl;
            cout << "SIZE:"<<n<<"\t\t"<<"INSERT SORTED:\t"<<"STOPPED"<<endl;
        }
        cout<<endl;

        //Write the data to CSV file

        dataFile << n << "," << avg_quick.count();
        dataFile << "," << avg_radix.count();
        dataFile << "," << avg_heap.count();
        dataFile << "," << avg_insert.count();

        if(n<stop_worst)
        {
            dataFile << "," << avg_quick_sorted.count();
            dataFile << "," << avg_radix_sorted.count();
            dataFile << "," << avg_heap_sorted.count();
            dataFile << "," << avg_insert_sorted.count();
        }
        else
        {
            dataFile << ",,,";
        }
        dataFile<<"\n";

        delete [] a;
        delete [] random_array;

        //Increment size of array based on current size
        if(n<100)
            increment=10;
        else if(n<1000)
            increment=100;
        else if(n<10000)
            increment=1000;
        else
            increment=10000;
    }
}

void print_array(int* a , int n)
{
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
