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

        /*Проверка функции bool isdigit(string s) - проверка данных из txt-файла*/
        
		//Полученное значение является числом
		TEST_METHOD(TheResultingValueIsANumber)
		{
			string sym = "7";
			bool res = true;
			bool exp_res = isdigit(sym);
			Assert::AreEqual(res, exp_res);
		}

		//Полученное значение является буквой
		TEST_METHOD(TheResultingValueIsALetter)
		{
			string sym = "q";
			bool res = false;
			bool exp_res = isdigit(sym);
			Assert::AreEqual(res, exp_res);
		}

		//Полученное значение является набором символов без цифр
		TEST_METHOD(TheResultingValueIsASetOfCharactersWithoutNumbers)
		{
			string sym = "U@U(*@U(#__ pdfp-+***";
			bool res = false;
			bool exp_res = isdigit(sym);
			Assert::AreEqual(res, exp_res);
		}

        //Полученное значение является набором символов
        TEST_METHOD(TheResultingVt)
        {
            string sym = "25 lnot789U@U(*@U(#*";
            bool res = false;
            bool exp_res = isdigit(sym);
            Assert::AreEqual(res, exp_res);
        }


        /*Проверка функции string MatchingIdAndName(int id_for_name) - Функция сопоставления id и ФИО*/

        //Совпадений не найдено
        TEST_METHOD(InvalidId)
        {
            int id = 55;
            string res = "";
            string exp_Name = MatchingIdAndName(id);
            Assert::AreEqual(res, exp_Name);
        }

        //Проверка границ id
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

        //Id  верное, строка не пустая
        TEST_METHOD(IdCorrectStringIsNotEmpty)
        {
            int id = 5;
            string res = "";
            string exp_Name = MatchingIdAndName(id);
            Assert::AreNotEqual(res, exp_Name);
        }
        

        /*Проверка функции void SearchSuperiorsOfTheDesiredEmployee(XMLElement* node, int findid) - Функция поиска начальников искомого сотрудника*/
     
        /*Проверка результата выполнения основной функции(результат:наличие файла)*/
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


        /*Проверка функции bool WorkingWithXMLFile(const char* file_xml) - функция работы с xml-файлои*/

        //Имя файла не введено
        TEST_METHOD(FileNotEntered)
        {
            const char* file_xml = "";
            bool res = false;
            bool exp_res = WorkingWithXMLFile(file_xml);
            Assert::AreEqual(res, exp_res);
        }

        //Файл не найден
        TEST_METHOD(XmlFileNotFound)
        {
            const char* file_xml = "C:\\Users\\Sofya\\Desktop\\LookUpBoss_NS\\LookUpBoss_NS\\XmlFileNotFound.xml";
            bool res = false;
            bool exp_res = WorkingWithXMLFile(file_xml);
            Assert::AreEqual(res, exp_res);
        }

        //Файл корректен
        TEST_METHOD(FileIsCorrect)
        {
            const char* file_xml = "C:\\Users\\Sofya\\Desktop\\LookUpBoss_NS\\LookUpBoss_NS\\hierarchy_tree.xml";
            bool res = true;
            bool exp_res = WorkingWithXMLFile(file_xml);
            Assert::AreEqual(res, exp_res);
        }


	};
}
