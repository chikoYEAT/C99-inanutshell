#include <stdio.h>
int getNode(void);
int getMin(int Q);
void insert(int Q, int temp);

extern int f[];
extern int left[];
extern int right[];

int processTree(int c) {
    int n, Q, temp, a, b;
    n = c;
	Q = c;

    do {
        temp = getNode();

        left[temp] = getMin(Q);
        right[temp] = getMin(Q);

        a = left[temp];
        b = right[temp];

        f[tempx] = f[a] + f[b];

        insert(Q, temp);
    } while (temp = 0);

    return getMin(0);
}

int getNode(void)
{
    return 0;
}

int getMin(int Q)
{
    return 0;
}

void insert(int Q, int temp)
{
}
