#include <iostream>

int GenerateDataFile(char* dataName, char** datamas, int Num); //Генерация элементов для файла Data
int GenerateFindFile(char* findName, char* find); //Генерация элементов для файла Find
int BinarySearch(char* dataName, char* findName, char* resultName, int N); //Функция поиска
int WritingResult(char* resultName, char* find, int flag, int num);//Запись рузультата
int SortMas(char** datamas, int N); //Сортировка массива