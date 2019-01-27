#include <math.h>
#include "activation.h"

using namespace std;

double Activation::relu(double x)
{
    if (x >= 0)
        return x;
    else
        return 0;
}

double Activation::softmax(double x)
{
    return 1 / (1 + exp(-x));
}

double Activation::tanh(double x)
{
    return (exp(x) - exp(-x))/ (exp(x) + exp(-x));
}

double Activation::relu_derative(double x)
{
    if (x >= 0)
        return 1;
    else
        return 0;
}

double Activation::softmax_derative(double x)
{
    return softmax(x) * (1 - softmax(x));
}

double Activation::tanh_derative(double x)
{
    return 1 - pow(tanh(x), 2);
}

