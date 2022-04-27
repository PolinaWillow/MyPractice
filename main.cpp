#include <iostream>
#include <cmath>
#include <time.h>
#include <ctime>
#include "binarySearch.h"
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    setlocale(LC_ALL, "rus");
 
    char* function = argv[1];
    char* dataName = argv[2];
    char* findName = argv[3];
    char* resultName = argv[4];
    int numberOfElements = stoi(argv[5]);

    if(strcmp("BinarySearch", function)==0){
        if(BinarySearch(dataName, findName, resultName, numberOfElements)==0){
            printf("Поиск окончен\n");
        } else {
            printf("Ошибка поиска\n");
        }     
    }
    return 0;
}