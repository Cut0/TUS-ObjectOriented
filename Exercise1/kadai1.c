//学籍番号: 4619023 氏名:　加藤　零
#define NUM 100
#include <stdio.h>
long fibo(int k);
long fibCollection[100];  //フィボナッチ数列の結果を入れておくことで高速化する。
int main(void) {
    int k = 0, i = 0;
    for (i = 0; i < NUM; i++) fibCollection[i] = -1;
    printf("Please input number:");
    scanf("%d", &k);
    printf("Fibo(%d)=%ld\n", k, fibo(k));
    return 0;
}

long fibo(int pos) {
    if (pos == 0 || pos == 1) {
        fibCollection[pos] = pos;
        return pos;
    }
    if (fibCollection[pos] != -1) return fibCollection[pos];
    fibCollection[pos] = fibo(pos - 1) + fibo(pos - 2);
    return fibCollection[pos];
}