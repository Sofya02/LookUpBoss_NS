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


/*!������� ������������� id � ���
*
* \param[in] id-����������(�������)
* return �������� ��� ��������������� ��� id
*/
string MatchingIdAndName(int id_for_name);
//���������� ����������� � ����
bool SavingResultsToAFile();

/*!
* \������� ������ ����������� �������� ����������*****
*
* \param [in] node - ��������� �� ������� � XML-�����
* \param [in] findid - id ����������
*/
void SearchSuperiorsOfTheDesiredEmployee(XMLElement* node, int findid);

//�������� ������ �� txt-�����
bool isdigit(string s);

/*��������� id �� txt-�����*/
int GettingIdFromTxtFile(const char* file_txt);


/*������ � xml ������*/
bool WorkingWithXMLFile(const char* file_xml);

/*��������� �� ������������� �����*/
int exists(const char* fname);