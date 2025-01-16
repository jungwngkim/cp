// 스터디 관련 주석
// 본 코드가 22학번 유현준 학우의 코드와 비슷한 것은
// 제가 유현준 학우의 질문에 대답해주기 위해서이며
// 아이디어 또는 코드를 베껴서 부당한 이익을 취함이
// 아님을 미리 알리는 바입니다.

#include <stdio.h>
#include <stdlib.h>

int size;

int compare(const void *argu1, const void *argu2) {
    return *(int *)argu1 - *(int *)argu2;
}  // 직접 제작이 필요함

// 선물 충전하고 큐소트 하는 함수
void charge(int *arr, int input) {
    for (int i = 0; i < input; i++) {
        scanf("%d", &arr[size + i]);
    }
    qsort(arr, size + input, sizeof(int), compare);
    // printf("%d %d\n", arr[size + input - 1], arr[size + input - 2]);
}

// 배열상 가장 높은 가치를 프린팅 해주는 함수
void give(int *arr) {
    if (size != 0) {
        printf("%d\n", arr[size - 1]);
        size--;
    } else {
        printf("-1\n");
    }
}

int main() {
    int input_num;
    scanf("%d", &input_num);
    int *arr = (int *)malloc(sizeof(int) * 500000);
    for (int i = 0; i < input_num; i++) {
        int input;
        scanf("%d", &input);
        if (input == 0) {
            give(arr);
        } else {
            charge(arr, input);
            size += input;
        }
    }
    return 0;
}