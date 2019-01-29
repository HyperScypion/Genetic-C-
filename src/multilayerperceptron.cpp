#include <vector>
#include <random>
#include <string>
#include <iostream>
#include "activation.h"
#include "multilayerperceptron.h"

void Perceptron::set_weights()
{
    for (int i = 0; i < input_size; ++i)
    {
        weights.push_back(((double) rand() / (RAND_MAX)));
    }
}

double Perceptron::forward_prop(std::vector <double> data, std::string activ)
{
    Activation activ_func;
    double dot_product;
    for (int i = 0; i < input_size; ++i)
    {
        dot_product += weights[i] * data[i];
    }
    if (activ == "relu")
    {
        return activ_func.relu(dot_product);
    }
    else if (activ == "softmax")
    {
        return activ_func.softmax(dot_product);
    }
    else if (activ == "tanh")
    {
        return activ_func.tanh(dot_product);
    }
}

void Perceptron::train(double learning_rate, int epochs, std::vector <double> data, std::vector <double> labels, std::string activ)
{
    double result;
    for (int i = 0; i < epochs; ++i)
    {
        std::cout << "Epoch " << i+1 << "\\" << epochs << "\n";
        result = forward_prop(data, activ);
        for (int j = 0; j < data.size(); ++j)
        {
            std::cout << "Old weight = " << weights[j] << " indeks wagi =  " << j <<" \n";
            weights[j] += learning_rate*(labels[0] - result)*data[j];
            std::cout << "New weight = " << weights[j] << " indeks wagi = " << j << " \n";
        }
    }
}

void Adaline::set_weights()
{
    for (int i = 0; i < input_size; ++i)
    {
        weights.push_back(((double) rand() / (RAND_MAX)));
    }
}

double Adaline::forward_prop(std::vector <double> data, std::string activ)
{
    Activation activ_func;
    double dot_product;
    for (int i = 0; i < input_size; ++i)
    {
        dot_product += weights[i] * data[i];
    }
    if (activ == "relu")
    {
        return activ_func.relu(dot_product);
    }
    else if (activ == "softmax")
    {
        return activ_func.softmax(dot_product);
    }
    else if (activ == "tanh")
    {
        return activ_func.tanh(dot_product);
    }
}

double Adaline::get_gradient(std::string activ, double weight)
{
    Activation activ_func;
    if (activ == "relu")
    {
        return activ_func.relu_derative(weight);
    }
    else if (activ == "softmax")
        return activ_func.softmax_derative(weight);
    else if (activ == "tanh")
        return activ_func.tanh_derative(weight);
}

void Adaline::train(double learning_rate, int epochs, std::vector <double> data, std::vector <double> labels, std::string activ)
{
    double result;
    for (int i = 0; i < epochs; ++i)
    {
        std::cout << "Epoch " << i+1 << "\\" << epochs << "\n";
        result = forward_prop(data, activ);
        for (int j = 0; j < data.size(); ++j)
        {
            std::cout << "Old weight = " << weights[j] << " indeks wagi =  " << j <<" \n";
            weights[j] -= learning_rate*get_gradient(activ, weights[j]);
            std::cout << "New weight = " << weights[j] << " indeks wagi = " << j << " \n";
        }
    }
}
