#include <vector>
using namespace std;

class DispersionCalculator {
private:
    vector<double> data;
public:
    DispersionCalculator();
    DispersionCalculator(vector<double>& inputData);
    vector<double>& getData();
    void setData(vector<double>& inputData);
    double calculateAverage();
    ~DispersionCalculator();
protected:
    virtual double calculateDispersion() = 0;

};

class GreaterDispersionCalculator : public DispersionCalculator {
public:
    GreaterDispersionCalculator();
    GreaterDispersionCalculator(vector<double>& inputData);
    double calculateDispersion()  override;
    double operator++(int)
    {
        return calculateDispersion();
    }
};

class LesserDispersionCalculator : public DispersionCalculator {
public:
    LesserDispersionCalculator();
    LesserDispersionCalculator(vector<double>& inputData);
    double calculateDispersion()  override;
    double operator--(int)
    {
        return calculateDispersion();
    }
};
