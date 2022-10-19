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


/*!
* \Функция сопоставления id и ФИО
* \param[in] id-сотрудника(текущее)
* \return значение ФИО соответствующее его id
*/
string MatchingIdAndName(int id_for_name);


/*!
* \Сохранение результатов в файл
* \return true
*/
bool SavingResultsToAFile();

/*!
* \Функция поиска начальников искомого сотрудника
* \param [in] node - указатель на элемент в XML-файле
* \param [in] findid - id сотрудника
*/
void SearchSuperiorsOfTheDesiredEmployee(XMLElement* node, int findid);

/*!
* \Проверка данных из txt - файла
* \param[in] s - строка из txt-файла
* return true
*/
bool isdigit(string s);

/*!
* \Получение id из txt-файла
* \param[in] file_txt -имя файла
* \return id - идентификационный номер сотрудника
* \throw - (Выбрасывает исключения в случае ошибок при работе с файлом)
*/
int GettingIdFromTxtFile(const char* file_txt);


/*!
* \Работа с xml файлом
* \param[in] file_xml -имя файла
* \return true
*/
bool WorkingWithXMLFile(const char* file_xml);

/*!
* \Прооверка на существование файла(для модульных тестов)
* \param[in] fname -имя файла
* \return 1
*/
int exists(const char* fname);