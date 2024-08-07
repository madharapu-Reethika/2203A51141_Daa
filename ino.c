#include <stdio.h>
#include <stdlib.h>
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);
void sortAscending(int arr[], int size) {
    int i, j, temp;
    for (i=1;i<size;i++) {
        temp = arr[i];
        j=i-1;
        while (j>=0 && arr[j]>temp) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
void sortDescending(int arr[], int size) {
    int i,j,temp;
    for (i=1;i<size;i++) {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]<temp) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1] =temp;
    }
}
int main() {
    int *times;
    int i,SIZE;
    char choice;
    printf("Enter the number of times: ");
    if (scanf("%d", &SIZE) !=1) { 
        printf("Invalid input for number of times!\n");
        return 1;
    }
    times=(int*)malloc(SIZE * sizeof(int));
    if (times == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter time to reach destination:\n");
    for (i=0; i<SIZE; i++) {
        if (scanf("%d", &times[i]) != 1) { 
            printf("Invalid input for time!\n");
            free(times); 
            return 1;
        }
    }
    printf("Sort in ascending or descending order? (a/d): ");
    scanf(" %c", &choice);
    if (choice == 'a') {
        sortAscending(times, SIZE);
    } else if (choice == 'd') {
        sortDescending(times, SIZE);
    } else {
        printf("Invalid choice!\n");
        free(times); 
        return 1;
    }
    printf("Sorted times:\n");
    for (i =0; i <SIZE; i++) {
        printf("%d\n", times[i]);
    }
    free(times); 
    return 0;
}
