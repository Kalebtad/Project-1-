#ifndef INSERT_SORT_H_INCLUDED
#define INSERT_SORT_H_INCLUDED

void
insert_sort(int *a, int n) {
    for (int i = 1 ; i < n ; i++) {
        int val = a[i];
        int cur = i;
        while ( (cur > 0) && a[cur - 1] > val ) {
            a[cur] = a[cur - 1];
            cur--;
        }
        a[cur] = val;
    }
}

#endif
