#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include "pch.h"
#include "CppUnitTest.h"
#include "../LookUpBoss_NS/readXML.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestGettingIdFromTxtFile
{
	TEST_CLASS(TestGettingIdFromTxtFile)
	{
	public:

        /*�������� ������� bool isdigit(string s) - �������� ������ �� txt-�����*/
        
		//���������� �������� �������� ������
		TEST_METHOD(TheResultingValueIsANumber)
		{
			string sym = "7";
			bool res = true;
			bool exp_res = isdigit(sym);
			Assert::AreEqual(res, exp_res);
		}

		//���������� �������� �������� ������
		TEST_METHOD(TheResultingValueIsALetter)
		{
			string sym = "q";
			bool res = false;
			bool exp_res = isdigit(sym);
			Assert::AreEqual(res, exp_res);
		}

		//���������� �������� �������� ������� �������� ��� ����
		TEST_METHOD(TheResultingValueIsASetOfCharactersWithoutNumbers)
		{
			string sym = "U@U(*@U(#__ pdfp-+***";
			bool res = false;
			bool exp_res = isdigit(sym);
			Assert::AreEqual(res, exp_res);
		}

        //���������� �������� �������� ������� ��������
        TEST_METHOD(TheResultingVt)
        {
            string sym = "25 lnot789U@U(*@U(#*";
            bool res = false;
            bool exp_res = isdigit(sym);
            Assert::AreEqual(res, exp_res);
        }


        /*�������� ������� string MatchingIdAndName(int id_for_name) - ������� ������������� id � ���*/

        //���������� �� �������
        TEST_METHOD(InvalidId)
        {
            int id = 55;
            string res = "";
            string exp_Name = MatchingIdAndName(id);
            Assert::AreEqual(res, exp_Name);
        }

        //�������� ������ id
        TEST_METHOD(IdBorderCheck)
        {
            string result;
            string exp = "";
            for (int i = -10; i < 50; i++)
            {
                result = MatchingIdAndName(i);
                if ((i < 1) ||( i>31)) { Assert::AreEqual(result, exp); }
            }
        }

        //Id  ������, ������ �� ������
        TEST_METHOD(IdCorrectStringIsNotEmpty)
        {
            int id = 5;
            string res = "";
            string exp_Name = MatchingIdAndName(id);
            Assert::AreNotEqual(res, exp_Name);
        }
        

        /*�������� ������� void SearchSuperiorsOfTheDesiredEmployee(XMLElement* node, int findid) - ������� ������ ����������� �������� ����������*/
     
        /*�������� ���������� ���������� �������� �������(���������:������� �����)*/
        TEST_METHOD(FilePresence)
        {
            XMLDocument doc;
            doc.LoadFile("C:\\Users\\Sofya\\Desktop\\LookUpBoss_NS\\LookUpBoss_NS\\hierarchy_tree.xml");
            const char* txt_file = "C:\\Users\\Sofya\\Desktop\\LookUpBoss_NS\\LookUpBoss_NS\\id.txt";
            int id_from_txt = GettingIdFromTxtFile(txt_file);
            XMLElement* node = doc.FirstChildElement()->FirstChildElement("Department");
            SearchSuperiorsOfTheDesiredEmployee(node, id_from_txt);
            bool res = exists("C:\\Users\\Sofya\\Desktop\\LookUpBoss_NS\\LookUpBoss_NS\\output.txt");
            bool exp = false;
            Assert::AreNotEqual(res, exp);

        }


        /*�������� ������� bool WorkingWithXMLFile(const char* file_xml) - ������� ������ � xml-������*/

        //��� ����� �� �������
        TEST_METHOD(FileNotEntered)
        {
            const char* file_xml = "";
            bool res = false;
            bool exp_res = WorkingWithXMLFile(file_xml);
            Assert::AreEqual(res, exp_res);
        }

        //���� �� ������
        TEST_METHOD(XmlFileNotFound)
        {
            const char* file_xml = "C:\\Users\\Sofya\\Desktop\\LookUpBoss_NS\\LookUpBoss_NS\\XmlFileNotFound.xml";
            bool res = false;
            bool exp_res = WorkingWithXMLFile(file_xml);
            Assert::AreEqual(res, exp_res);
        }

        //���� ���������
        TEST_METHOD(FileIsCorrect)
        {
            const char* file_xml = "C:\\Users\\Sofya\\Desktop\\LookUpBoss_NS\\LookUpBoss_NS\\hierarchy_tree.xml";
            bool res = true;
            bool exp_res = WorkingWithXMLFile(file_xml);
            Assert::AreEqual(res, exp_res);
        }


	};
}
