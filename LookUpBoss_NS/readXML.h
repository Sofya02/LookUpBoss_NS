#pragma once
#include <iostream> //��� ������ � ����������� � ���������
#include <fstream> //��� ������ � ������� 
#include <string> //��� ������ getline
#include <exception> 
#include <vector>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

struct Person {
    string Name;//��� ����������
    int id = 0;//id ����������
};


/*!
* \������� ������������� id � ���
* \param[in] id-����������(�������)
* \return �������� ��� ��������������� ��� id
*/
string MatchingIdAndName(int id_for_name);


/*!
* \���������� ����������� � ����
* \return true
*/
bool SavingResultsToAFile();

/*!
* \������� ������ ����������� �������� ����������
* \param [in] node - ��������� �� ������� � XML-�����
* \param [in] findid - id ����������
*/
void SearchSuperiorsOfTheDesiredEmployee(XMLElement* node, int findid);

/*!
* \�������� ������ �� txt - �����
* \param[in] s - ������ �� txt-�����
* return true
*/
bool isdigit(string s);

/*!
* \��������� id �� txt-�����
* \param[in] file_txt -��� �����
* \return id - ����������������� ����� ����������
* \throw - (����������� ���������� � ������ ������ ��� ������ � ������)
*/
int GettingIdFromTxtFile(const char* file_txt);


/*!
* \������ � xml ������
* \param[in] file_xml -��� �����
* \return true
*/
bool WorkingWithXMLFile(const char* file_xml);

/*!
* \��������� �� ������������� �����(��� ��������� ������)
* \param[in] fname -��� �����
* \return 1
*/
int exists(const char* fname);