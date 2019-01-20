#include <iostream>

using namespace std;


class Activation
{
public:
    double relu(double x);
    double softmax();
};
double Activation::relu(double x)
{
    if (x > 0)
    {
        printf("%f", x);
        return x;
    }
    else
    {
        printf("%f", x);
        return 0;
    }
}

double Activation::softmax()
{

}



int main()
{
    Activation ac;
    ac.relu(5);
}
