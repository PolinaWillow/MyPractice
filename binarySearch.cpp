#include <iostream>
#include <cmath>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <fstream>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "binarySearch.h"
#include <unistd.h>
#include <stdio.h>


using namespace std;
//Глобальные переменные
const char alf[37] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                      'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                      'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6',
                      '7', '8', '9', '0'};

//Генерация элементов для файла Data
int GenerateDataFile(char* dataName, char** datamas, int Num){
    srand(0);
    *datamas = new char[Num];
    FILE* dataFile = fopen(dataName, "a+");
    char ch[1];
    char chn[1] = {'\n'};
    for (int i=0;i<Num;i++){
        ch[0]= alf[rand()%((37-0)+1)];
        int flagwrite = fwrite(ch, 1, 1, dataFile);
        if(flagwrite==0){
        //printf("Ошибка записи файла Data\n");
        }
        
        (*((*datamas)+i)) = ch[0];
    }
    fwrite(chn, 1, 1, dataFile);
    fclose(dataFile); 
    return 0; 
} 

//Генерация элементов для файла Find
int GenerateFindFile(char* findName, char* find){
    srand(0);
    FILE* findFile = fopen(findName, "a+");
    char ch[1]; 
    char chn[1] = {'\n'};
    ch[0]= alf[rand()%((37-0)+1)];
    int flagwrite = fwrite(ch, 1, 1, findFile);
    if(flagwrite==0){
        //printf("Ошибка записи искомого символа\n");
        return -1;
    }
    (*find)=ch[0];
    fwrite(chn, 1, 1, findFile);
    fclose(findFile);
    return 0;
} 

//Сортировка массива (вставкой)
int SortMas(char** datamas, int N){
    char key =0;
    for(int i=1; i<N;i++){
        key = *((*datamas)+i);
        int j=i-1;
        while((j>(-1))&(*((*datamas)+j)>key)){
            *((*datamas)+(j+1)) = *((*datamas)+j);
            j--;
        }
        *((*datamas)+(j+1))=key;
    }
    return 0;
}

//Алгоритм поиска
int BinarySearch(char* dataName, char* findName, char* resultName, int N){
    char* datamas; //Массив хранения данных поиска
    char find; //Искомый символ
    
    GenerateDataFile(dataName, &datamas, N);
    GenerateFindFile(findName, &find);

    //Сортировка
    SortMas(&datamas, N);

    clock_t timeStart = clock(); //Веремя начала поиска
    //Поиск
    int low =0;
    int high = N-1;
    int q=0;
    int flag = 0;
    while(low<high){
        q = (low+high)/2;
        if(find<*(datamas+q)) high =q;
        else {
            if(find>*(datamas+q)) low = q+1;
            else { 
                printf("Есть совпадение\n");
                flag=1;
                break;
            }
        }
    }
    if (flag ==0) printf("Нет совпадения\n");
    clock_t timeEnd = clock() - timeStart;

    //Запись результата
    if (WritingResult(resultName, &find, flag, N)==0) cout<<"Успешная запись результата\n";
    //Вывод статистики
    printf("\nДля N = %d  t = %f\n\n", N, double(timeEnd));
    
    for(int i=0; i<N;i++){
        delete &datamas[i];
    }
    delete datamas;
    return 0;
}

//Запись рузультата
int WritingResult(char* resultName, char* find, int flag, int num){
    string positive = "Есть совпатение";
    string negative = "Нет совпадения";
    char strintT[4] = {' ','N','o','\n'}; 
    char strintF[5] = {' ','Y', 'e', 's','\n'}; 
    char stringN[2] = {'N', '=',};
    //Создание файла с реультатами

    FILE* result = fopen(resultName, "a+");
    int flagwrite;
    if (flag ==0){ //Если нет совпадений
      flagwrite = fwrite(stringN, 2, 1, result);
      flagwrite = fputc(num, result);
      flagwrite = fwrite(strintT, 4, 1, result);
      //flagwrite = fputs(strintT, sizeof(strintT), result);
      
    }else{
        flagwrite = fwrite(stringN, 2, 1, result);
        flagwrite = putc(num, result);
        flagwrite = fwrite(strintF, 5, 1, result);
        //flagwrite = fputs(strintT, sizeof(strintT), result);
    }
    if(flagwrite==0){
        //printf("Ошибка записи");
        return 3;
    }
    fclose(result);
    return 0;
}