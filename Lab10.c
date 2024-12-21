#include <stdio.h>
#define MAX 100

struct Employee {
    int k;
    char n[50];
};

struct Employee ht[MAX];
int ts;

void init() {
    for (int i = 0; i < MAX; i++) ht[i].k = -1;
}

int hash(int k) {
    return k % ts;
}

void insert(int k, char n[]) {
    int idx = hash(k);
    while (ht[idx].k != -1) {
        idx = (idx + 1) % ts;
    }
    ht[idx].k = k;
    for (int i = 0; n[i] != '\0' && i < 49; i++) {
        ht[idx].n[i] = n[i];
    }
    ht[idx].n[49] = '\0';
}

void display() {
    for (int i = 0; i < ts; i++) {
        if (ht[i].k != -1)
            printf("Idx %d: Key = %d, Name = %s\n", i, ht[i].k, ht[i].n);
        else
            printf("Idx %d: Empty\n", i);
    }
}

int main() {
    int n;
    printf("Enter table size (max size %d): ", MAX);
    scanf("%d", &ts);

    if (ts > MAX) ts = MAX;

    init();

    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        int k;
        char name[50];
        printf("Enter key and name for employee %d: ", i + 1);
        scanf("%d", &k);
        getchar();
        gets(name);
        insert(k, name);
    }

    display();

    return 0;
}

/*

OUTPUT  :

Enter table size (max size 100): 7 
Enter number of employees: 5
Enter key and name for employee 1: 1256 ram
Enter key and name for employee 2: 1452 sham
Enter key and name for employee 3: 9845 raju
Enter key and name for employee 4: 6374 adi
Enter key and name for employee 5: 4778 lal
Idx 0: Key = 4778, Name = lal
Idx 1: Empty
Idx 2: Empty
Idx 3: Key = 1256, Name = ram
Idx 4: Key = 1452, Name = sham
Idx 5: Key = 9845, Name = raju
Idx 6: Key = 6374, Name = adi

*/