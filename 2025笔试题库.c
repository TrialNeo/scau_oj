// Created by Github@TrialNeo(shenpanpro@gmail.com) 
// Created Time 2026/1/13.

#include <math.h>
#include  <stdio.h>

char isPrime(unsigned int num) {
    if (!(num % 2) && num != 2) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    for (int i = 3; i < sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}


int T4Q14() {
    int n = 0;
    scanf("%d", &n);
    for (int i = n + 1; ; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}

int maain() {
    /*
     * 这个其实很好想，录入数的先后顺序是不变的
     * 直接分成3堆东西就行了 负数 0 正数
     */
    int n = 0, temp = 0;
    scanf("%d", &n);
    int pos[n], posCount = 0,
            neg[n], negCount = 0,
            zeroCount = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp < 0) {
            neg[negCount++] = temp;
            continue;
        }
        if (temp > 0) {
            pos[posCount++] = temp;
            continue;
        }
        zeroCount++;
    }
    printArr(neg, negCount);
    for (int i = 0; i < zeroCount; i++) {
        printf("0 ");
    }
    printArr(pos, posCount);
    return 0;
}
