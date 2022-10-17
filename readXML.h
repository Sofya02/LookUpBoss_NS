#pragma once
#include <iostream> //Для работы с клавиатурой и монитором
#include <fstream> //для работы с файлами 
#include <string> //для работы getline
#include <exception> 
#include <vector>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

struct Person {
    string Name;//ФИО сотрудника
    int id = 0;//id сотрудника
};


/*!Функция сопоставления id и ФИО
*
* \param[in] id-сотрудника(текущее)
* return значение ФИО соответствующее его id
*/
string MatchingIdAndName(int id_for_name);
//Сохранение результатов в файл
bool SavingResultsToAFile();

/*!
* \Функция поиска начальников искомого сотрудника*****
*
* \param [in] node - указатель на элемент в XML-файле
* \param [in] findid - id сотрудника
*/
void SearchSuperiorsOfTheDesiredEmployee(XMLElement* node, int findid);

//проверка данных из txt-файла
bool isdigit(string s);

/*Получение id из txt-файла*/
int GettingIdFromTxtFile(const char* file_txt);


/*Работа с xml файлом*/
bool WorkingWithXMLFile(const char* file_xml);

/*Прооверка на существование файла*/
int exists(const char* fname);