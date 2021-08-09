#include <iostream>

int hashSum(char* str){
    size_t idx = 0;
    int sum = 0;
    while(1){
        if(str[idx] == '\0') break;
        sum += (int)str[idx++];
    }
    return sum;
}

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

    return 0;
}
