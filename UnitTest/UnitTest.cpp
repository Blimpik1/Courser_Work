#include "pch.h"
#include "CppUnitTest.h"
#include "..\Courser\dispersion.hpp"
#include <iostream>
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest
{
    TEST_CLASS(DispersionCalculatorTests)
    {
    public:
       TEST_METHOD(GETERANDSETER)
        {
                    std::ofstream tempFile("temp_input_file.txt");
                    tempFile << "DISP>avg \n 1 2 3 \n";  
                    tempFile.close();

                    std::ifstream inputFile("temp_input_file.txt");
                    std::string operation;
                    double value;
                    vector<double> inputData;

                    for (; inputFile >> operation;) {
                        inputData.clear();
                        for (; inputFile >> value;) {
                            inputData.push_back(value);
                        }
                        inputFile.clear();

                        GreaterDispersionCalculator dispersionCalculator;

                        Assert::IsTrue(dispersionCalculator.getData().empty(), L"Невірні дані у гетері DispersionCalculator");
                   
                        dispersionCalculator.setData(inputData);

                        Assert::IsTrue(inputData == dispersionCalculator.getData(), L"Невірні дані у гетері DispersionCalculator");
                    }
                    remove("temp_input_file.txt");
                }
        
        TEST_METHOD(DispersionCalculatorCalculateAverage)
        { 
            std::vector<double> inputData = { 1, 2, 3, 4, 5 };
            GreaterDispersionCalculator dispersionCalculator(inputData);
            double calculatedAverage = dispersionCalculator.calculateAverage();
            Assert::AreEqual(3.0, calculatedAverage, L"Невірне середнє значення");
        }
        };


    TEST_CLASS(GreaterDispersionCalculatorTests)
    {
    public:
        TEST_METHOD(GreaterDispersionCalculatorDefaultConstructor)
        {
                GreaterDispersionCalculator greaterCalculator;
                Assert::IsTrue(greaterCalculator.getData().empty(), L"Невірні дані у конструкторі GreaterDispersionCalculator");
                Assert::AreEqual(0, static_cast<int>(greaterCalculator.getData().size()), L"Невірний розмір у конструкторі GreaterDispersionCalculator");
            }

        TEST_METHOD(GreaterDispersionCalculatorConstructor)
        {
            std::ofstream tempFile("temp_input_file.txt");
            tempFile << "DISP>avg\n1 2 3\n";
            tempFile.close();

            std::ifstream inputFile("temp_input_file.txt");
            std::string operation;
            double value;
            vector<double> inputData;
            for (; inputFile >> operation;) {
                inputData.clear();
                for (; inputFile >> value;) {
                    inputData.push_back(value);
                }
                inputFile.clear();

                GreaterDispersionCalculator greaterCalculator(inputData);

                Assert::IsTrue(greaterCalculator.getData() == inputData, L"Невірні дані у конструкторі GreaterDispersionCalculator");

                Assert::AreEqual(3, static_cast<int>(greaterCalculator.getData().size()), L"Невірний розмір у конструкторі GreaterDispersionCalculator");
            }

            remove("temp_input_file.txt");
        }
        TEST_METHOD(GreaterCalculator)
        {
            
            std:ofstream tempFile("temp_input_file.txt");
            tempFile << "DISP>avg \n 1 2 3 \n";  
            tempFile.close();

            std::ifstream inputFile("temp_input_file.txt");
            std::string operation;
          

            double value;
            vector<double> inputData;
            for (; inputFile >> operation;) {
                inputData.clear();
                for (; inputFile >> value;) {
                    inputData.push_back(value);
                }
                inputFile.clear();

                GreaterDispersionCalculator greaterCalculator(inputData);
                if (operation == "DISP>avg") {
                    double result = greaterCalculator.calculateDispersion();
                    Assert::AreEqual(0.0, result, L"Невірний розрахунок дисперсії");
                }
            }
            remove("temp_input_file.txt");
        }
        TEST_METHOD(IncrementOperatorplus)
        {          
            std::ofstream tempFile("temp_input_file.txt");
            tempFile << "DISP>avg  \n -6 22 30 12 1\n";  
            tempFile.close();

            std::ifstream inputFile("temp_input_file.txt");
            std::string operation;

            double value;
            vector<double> inputData;
            for (; inputFile >> operation;) {
                inputData.clear();
                for (; inputFile >> value;) {
                    inputData.push_back(value);
                }
                inputFile.clear();

                GreaterDispersionCalculator greaterCalculator(inputData);
                if (operation == "DISP>avg") {
                    double result = greaterCalculator++;
                    Assert::AreEqual(217.66, result, L"Невірний результат після використання оператора ++");
                }
            }

            remove("temp_input_file.txt");
      
        }
    };

    TEST_CLASS(LesserDispersionCalculatorTests)
    {
    public:
        TEST_METHOD(LesserDispersionCalculatorDefaultConstructor)
        {

            LesserDispersionCalculator lesserCalculator;

            Assert::IsTrue(lesserCalculator.getData().empty(), L"Невірні дані у конструкторі LesserDispersionCalculator");

            Assert::AreEqual(0, static_cast<int>(lesserCalculator.getData().size()), L"Невірний розмір у конструкторі LesserDispersionCalculator");
        }
        TEST_METHOD(LesserDispersionCalculatorConstructor)
        {
  
            std::ofstream tempFile("temp_input_file.txt");
            tempFile << "DISP<avg  \n 5 10 30 50 60 \n";  
            tempFile.close();

            std::ifstream inputFile("temp_input_file.txt");
            std::string operation;

            double value;
            vector<double> inputData;
            for (; inputFile >> operation;) {
                inputData.clear();
                for (; inputFile >> value;) {
                    inputData.push_back(value);
                }
                inputFile.clear();

                LesserDispersionCalculator lesserCalculator(inputData);

                Assert::IsTrue(inputData == lesserCalculator.getData(), L"Невірні дані у конструкторі LesserDispersionCalculator");
             
          
            }

            remove("temp_input_file.txt");
        }
        TEST_METHOD(LesserCalculator)
        {

        std:ofstream tempFile("temp_input_file.txt");
            tempFile << "DISP>avg \n 10 20 30 40 50 77 \n";
            tempFile.close();


            std::ifstream inputFile("temp_input_file.txt");
            std::string operation;
            double value;
            vector<double> inputData;
            for (; inputFile >> operation;) {
                inputData.clear();
                for (; inputFile >> value;) {
                    inputData.push_back(value);
                }
                inputFile.clear();

                GreaterDispersionCalculator lesserCalculator(inputData);
                if (operation == "DISP<avg") {
                    double result = lesserCalculator.calculateDispersion();
                    Assert::AreEqual(577.042, result, L"Невірний розрахунок дисперсії");
                }
            }

            remove("temp_input_file.txt");
        }
        TEST_METHOD(IncrementOperatorminus)
        {

            std::ofstream tempFile("temp_input_file.txt");
            tempFile << "DISP<avg \n -6 22 30 12 1\n";
            tempFile.close();


            std::ifstream inputFile("temp_input_file.txt");
            std::string operation;
            double value;
            vector<double> inputData;
            for (; inputFile >> operation;) {
                inputData.clear();
                for (; inputFile >> value;) {
                    inputData.push_back(value);
                }
                inputFile.clear();

               LesserDispersionCalculator lesserCalculator(inputData);
                if (operation == "DISP<avg") {
                    double result = lesserCalculator--;
                    Assert::AreEqual(433.48, result, L"Невірний результат після використання оператора --");
                }
            }

            remove("temp_input_file.txt");
        }
    };
}