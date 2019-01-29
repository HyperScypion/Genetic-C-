#include <vector>
#include <iostream>
#include <string>

class Network
{
public:
    int input_size;
    int epochs;
    double learning_rate;
    void set_weights();
    virtual void train(double learning_rate, int epochs, std::vector <double> data, std::vector <double> labels, std::string activ);
    double forward_prop(std::vector <double> data, std::string activ);
private:
    std::vector <double> weights;
};

class Perceptron:public Network
{
};

class Adaline:public Network
{
public:
    void train(double learning_rate, int epochs, std::vector <double> data, std::vector <double> labels, std::string activ);
    double get_gradient(std::string activ, double weight);
};
