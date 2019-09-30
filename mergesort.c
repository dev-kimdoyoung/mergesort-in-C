#include <stdio.h>
#include "boolean.h"

/**
 *  Function Prototype
 */
void mergeSort(const int arraySize, int originalArray[]);
void merge(int leftArraySize, int rightArraySize, const int leftArray[], const int RightArray[], int originalArray[]);       

int main() {
    int originalArray[8] = {27, 10, 12, 20, 25, 13, 15, 22};
    const int originalArraySize = sizeof(originalArray) / sizeof(int);
    mergeSort(originalArraySize, originalArray);

    for(int i = 0; i < originalArraySize; i++) {
        printf("%d ", originalArray[i]);
    }
    printf("\n");

    return 0;
}

void mergeSort(const int arraySize, int array[]) {
    if(arraySize > 1) {
        int leftArraySize = arraySize / 2;
        int rightArraySize = arraySize - leftArraySize;

        int leftArray[leftArraySize];
        int rightArray[rightArraySize];

        int index;
        // left Array 요소 copy
        for(index = 0; index < leftArraySize; index++) {
            leftArray[index] = array[index];
        }

        // right Array 요소 copy
        for(index = 0; index < rightArraySize; index++) {
            int originalArrayIndex = rightArraySize + index;
            rightArray[index] = array[originalArrayIndex];
        }

        mergeSort(leftArraySize, leftArray);
        mergeSort(rightArraySize, rightArray);
        merge(leftArraySize, rightArraySize, leftArray, rightArray, array);
    }
}

void merge(int leftArraySize, int rightArraySize, const int leftArray[], const int rightArray[], int originalArray[]) {
    int i = 0;
    int j = 0;
    int k = 0;

    // 왼쪽 또는 오른쪽 배열의 비교가 끝나기 전까지
    while((i != leftArraySize) && (j != rightArraySize)) {
        // 오른쪽 배열 값이 왼쪽 배열 값보다 크면 왼쪽 배열 값을 original Array에 대입
        if(leftArray[i] < rightArray[j]) {
            originalArray[k] = leftArray[i];
            i++;
        }
        else {
            originalArray[k] = rightArray[j];
            j++;
        }
        k++;
    }
    // 오른쪽에 정렬이 되지 않은 요소 모두 originalArray에 복사 
    if(i == leftArraySize) {
        while(j != rightArraySize) {
            originalArray[k] = rightArray[j];
            j++;
            k++;
        }
    }
    // 왼쪽에 정렬이 되지 않은 요소 모두 originalArray에 복사
    else {
        while(i != leftArraySize) {
            originalArray[k] = leftArray[i];
            i++;
            k++;
        }
    }
}
