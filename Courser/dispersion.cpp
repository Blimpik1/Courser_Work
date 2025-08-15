#include "dispersion.hpp"
using namespace std;

DispersionCalculator::DispersionCalculator() 
{
    data = vector<double>();

}

DispersionCalculator::DispersionCalculator( vector<double>& inputData)
{
    data = inputData;
}

  vector<double>& DispersionCalculator::getData()  
 {
    return data;
}

void DispersionCalculator::setData( vector<double>& inputData) {
    data = inputData;
}

double DispersionCalculator::calculateAverage() {
    double sum = 0.0;
    for (int value : getData()) {
        sum += static_cast<double>(value);
    }
    return sum / getData().size();
}

DispersionCalculator::~DispersionCalculator() 
{
}

/***/

GreaterDispersionCalculator::GreaterDispersionCalculator() : DispersionCalculator(){}

GreaterDispersionCalculator::GreaterDispersionCalculator( vector<double>& inputData)
    : DispersionCalculator(inputData) {}

double GreaterDispersionCalculator::calculateDispersion()  {
    double average = calculateAverage();
    double sumSquaredDeviations = 0.0;
    int count = 0;

    for (double value : getData()) {
        if (value > average) {
            double deviation = value - average;
            sumSquaredDeviations += deviation * deviation;
            count++;
        }
    }

    if (count > 1) {
        return sumSquaredDeviations / (count - 1);
    }

    return 0.0; 
}

/***/

LesserDispersionCalculator::LesserDispersionCalculator() : DispersionCalculator()  {}

LesserDispersionCalculator::LesserDispersionCalculator( vector<double>& inputData)
    : DispersionCalculator(inputData) {}

double LesserDispersionCalculator::calculateDispersion()  {
    double average = calculateAverage();
    double sumSquaredDeviations = 0.0;
    int count = 0;

    for (double value : getData()) {
        if (value < average) {
            double deviation = value - average;
            sumSquaredDeviations += deviation * deviation;
            count++;
        }
    }

    if (count > 1) {
        return sumSquaredDeviations / (count - 1);
    }

    return 0.0; 
}
