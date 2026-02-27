#include <math.h>
#include <stdio.h>

int main() {
    // 这个其实是计算公式
    float d,p,r;
    scanf(" %f%f%f",&d,&p,&r);
    float m = log10( p / (p-d * r)) / log10(1+r);
    printf("%.1f", m);

}