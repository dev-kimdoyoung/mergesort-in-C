#include <stdio.h>

#define MAXARRAYSIZE 8      // 배열의 최대 크기
/**
*  Function Prototype
*/
void mergeSort(const int arraySize, int originalArray[]);
void merge(int leftArraySize, int rightArraySize, const int leftArray[], const int rightArray[], int originalArray[]);       

int main() {
    int originalArray[MAXARRAYSIZE] = {27, 10, 12, 20, 25, 13, 15, 22};
    int originalSize = sizeof(originalArray) / sizeof(int);     // 배열의 크기

    printf("정렬 전 : ");

    for(int i = 0; i < originalSize; i++) {
        printf("%d ", originalArray[i]);
    }
    printf("\n");
    mergeSort(originalSize, originalArray);

    printf("정렬 후 : ");
    for(int i = 0; i < originalSize; i++) {
        printf("%d ", originalArray[i]);
    }
    printf("\n");
    printf("정렬 완료!!\n");
    return 0;
}
void mergeSort(const int arraySize, int originalArray[]) {
    if(arraySize > 1) {
        int leftArraySize = arraySize / 2;
        int rightArraySize = arraySize - leftArraySize;

        int leftArray[leftArraySize];
        int rightArray[rightArraySize];

        // original 배열을 절반으로 나누어 왼쪽, 오른쪽 배열로 따로 저장하기

        for(int i = 0; i < leftArraySize; i++) {
            leftArray[i] = originalArray[i];
        }

        for(int i = 0; i < rightArraySize; i++) {
            int temp = rightArraySize + i;
            rightArray[i] = originalArray[temp];
        }
        mergeSort(leftArraySize, leftArray);
        mergeSort(rightArraySize, rightArray);
        merge(leftArraySize, rightArraySize, leftArray, rightArray, originalArray);
    }
}

void merge(int leftArraySize, int rightArraySize, const int leftArray[], const int rightArray[], int originalArray[]) {
    int leftIterator = 0;
    int rightIterator = 0;
    int original = 0;

    while(leftIterator != leftArraySize && rightIterator != rightArraySize) {
        // rightArray가 leftArray보다 크면 leftArray 요소를 original에 insert
        if(leftArray[leftIterator] < rightArray[rightIterator]) {
            originalArray[original] = leftArray[leftIterator];
            leftIterator++;
            original++;
        }
        // leftArray가 rightArray보다 크면 rightArray 요소를 original에 insert
        else {
            originalArray[original] = rightArray[rightIterator];
            rightIterator++;
            original++;
        }
    }

    while(leftIterator != leftArraySize) {
    originalArray[original] = leftArray[leftIterator];
    leftIterator++;
    original++;
    }

    while(rightIterator != rightArraySize) {
        originalArray[original] = rightArray[rightIterator];
        rightIterator++;
        original++;
    }
}
