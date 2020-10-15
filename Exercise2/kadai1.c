//学籍番号: 4619023 氏名:　加藤　零
#include <stdio.h>
int search(int, int, int*, int*, int, int, int (*)[*]);
int main(void) {
    const int num = 6;                                  // 荷物の総個数
    char object[num] = {'A', 'B', 'C', 'D', 'E', 'F'};  // 荷物の名前
    int v[num] = {700, 400, 800, 1000, 300, 500};       // 価値
    int w[num] = {3, 2, 4, 5, 2, 1};                    // 重量
    int limit_weight = 10;                              // 最大重量
    // ここに答を記述する（関数を利用しても良い）
    int searchedData[num + 1][limit_weight + 1];  //動的計画法の再帰関数のメモ用
    int i, j;
    for (i = 0; i < num + 1; i++)
        for (j = 0; j < limit_weight + 1; j++) searchedData[i][j] = -1;

    int result_value =
        search(0, limit_weight, v, w, num, limit_weight, searchedData);
    printf("合計金額%d円\n", result_value);

    for (i = 0; i < num; i++) {
        if (searchedData[i][limit_weight] !=
            searchedData[i + 1][limit_weight]) {
            limit_weight -= w[i];
            printf("%c:1個\n", object[i]);
        } else
            printf("%c:0個\n", object[i]);
    }
    return 0;
}

int search(int i, int j, int* v, int* w, int num, int limit,
           int searchedData[num + 1][limit + 1]) {
    int result = 0;
    if (searchedData[i][j] != -1) return searchedData[i][j];
    if (i != num) {
        if (j < w[i])
            result = search(i + 1, j, v, w, num, limit, searchedData);
        else {
            int includeI =
                    search(i + 1, j - w[i], v, w, num, limit, searchedData) +
                    v[i],
                excludeI = search(i + 1, j, v, w, num, limit, searchedData);
            result = includeI >= excludeI ? includeI : excludeI;
        }
    }
    searchedData[i][j] = result;
    return result;
}