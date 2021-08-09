#include <iostream>

void swap(size_t* a, size_t* b) {
    size_t tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(size_t* arr, const size_t SIZE){
    for(size_t i = 1; i < SIZE; i++){
        size_t k = i;
        while(k > 0 && arr[k - 1] < arr[k]){
            swap(&arr[k], &arr[k - 1]);
            k -= 1;
        }
    }
}

////////////////////////////////////////////////

int hashSum(char* str){
    size_t idx = 0;
    int sum = 0;
    while(1){
        if(str[idx] == '\0') break;
        sum += (int)str[idx++];
    }
    return sum;
}

int howManyCoins(size_t* arr, size_t SIZE, size_t MAX){
    size_t count = 0;
    size_t x = 0;
    size_t idx = 0;
    insertionSort(arr, SIZE);

    while(1){
        if(x == MAX) break;
        if(idx > SIZE - 1) return -1;
        if(arr[idx] == 0) idx++;
        size_t tmp = x + arr[idx];
        if(tmp <= MAX){
            x = tmp;
            count++;
        } else{
            idx++;
        }
    }

    return count;
};

int main() {

    char str_0[] = "Hello world! This is string!";
    char str_1[1000] = "Hello world! This is string!";
    char str_2[] = "\0";
    char str_3[] = "";


    std::cout << hashSum(str_0);
    std::cout << std::endl;
    std::cout << hashSum(str_1);
    std::cout << std::endl;
    std::cout << hashSum(str_2);
    std::cout << std::endl;
    std::cout << hashSum(str_3);
    std::cout << std::endl;


    const size_t SIZE = 5;
    const size_t MAX = 98;
    size_t arrNominalOfCoins[SIZE] = {50, 10, 5, 2, 1};
    std::cout << "Coins = " << howManyCoins(arrNominalOfCoins, SIZE, MAX) << std::endl;
    size_t arrNominalOfCoins_1[SIZE] = {50, 10, 5, 2, 0};
    std::cout << "Coins = " << howManyCoins(arrNominalOfCoins_1, SIZE, MAX) << std::endl;
    size_t arrNominalOfCoins_2[SIZE] = {1, 2, 5, 10, 50};
    std::cout << "Coins = " << howManyCoins(arrNominalOfCoins_2, SIZE, MAX) << std::endl;
    size_t arrNominalOfCoins_3[SIZE] = {2, 4, 5, 3, 1};
    std::cout << "Coins = " << howManyCoins(arrNominalOfCoins_3, SIZE, MAX) << std::endl;

    return 0;
}
