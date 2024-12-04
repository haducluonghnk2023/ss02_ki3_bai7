#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;

    printf("Nhap so phan tu cua mang (0 < n <= 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So phan tu khong hop le!\n");
        return 0;
    }

    int arr[n];
    
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Nhap gia tri k: ");
    scanf("%d", &k);

    qsort(arr, n, sizeof(int), compare);


    int left = 0, right = n - 1;
    int found = 0;

//    printf("Cac cap so co tong %d là:\n", k);
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == k) {
        	if (!found) {
                printf("Cac cap so co tong %d la:\n", k);  
                found = 1;
            }
            printf("%d %d\n", arr[left], arr[right]);
            found = 1;
            left++;  // Di chuy?n con tr? trái
            right--; // Di chuy?n con tr? ph?i
        } else if (sum < k) {
            left++;  // Tang con tr? trái
        } else {
            right--; // Gi?m con tr? ph?i
        }
    }

    if (!found) {
        printf("Khong tim thay cap so nao co tong bang %d\n", k);
    }

    return 0;
}

