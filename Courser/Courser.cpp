#include <iostream>
#include <fstream>
#include "dispersion.hpp"
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);

    string inputFilename;
    cout << "Введіть ім'я файлу:";
    cin >> inputFilename;

    ifstream inputFile(inputFilename);

    if (!inputFile.is_open()) {
        cout << "Неможливо відкрити файл: " << inputFilename << endl;
        return 1;
    }
    string outputFilename = "output.txt";
    ofstream outputFile(outputFilename);

    string operation;
    double result;
    double value;
    vector<double> inputData;
    for (; inputFile >> operation;) {
        inputData.clear();
        for (; inputFile >> value;) {
            inputData.push_back(value);
        }
        inputFile.clear();

        for (double val : inputData) {
            cout << val << " " << endl;
            outputFile << val << " " << endl;
        }

        GreaterDispersionCalculator greaterCalculator(inputData);
        LesserDispersionCalculator lesserCalculator(inputData);

        if (operation == "DISP>avg") {
            result = greaterCalculator++;
        }
        else if (operation == "DISP<avg") {
            result = lesserCalculator--;
        }
        else {
            cout << "Невідома операція: " << operation << endl;
            continue;
        }

        cout << "Результат для операції " << operation << ": " << result << endl;
        outputFile << "Результат для операції " << operation << ": " << result << endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
