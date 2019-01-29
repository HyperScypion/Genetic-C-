#include <vector>
#include <iostream>
#include <string>

class Perceptron
{
public:
    int input_size;
    int epochs;
    double learning_rate;
    void set_weights();
    double forward_prop(std::vector <double> data, std::string activ);
    void train(double learning_rate, int epochs, std::vector <double> data, std::vector <double> labels, std::string activ);
private:
    std::vector <double> weights;
};

class Adaline
{
public:
    int input_size;
    int epochs;
    double learning_rate;
    void set_weights();
    double forward_prop(std::vector <double> data, std::string activ);
    double get_gradient(std::string activ, double weight);
    void train(double learning_rate, int epochs, std::vector <double> data, std::vector <double> labels, std::string activ);
private:
    std::vector <double> weights;
};
