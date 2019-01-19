#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <iterator>

using namespace std;

class Perceptron
{
public:
    int input_size;
    double X_train;
    double y_train;
    vector <double> weights;
    void set_weights(int input_size);
    double dot_product(vector <double> weights, double X_train[]);
    void train(vector <double> dot, double y_train[]);
    void predict(vector <double> saved_weights, double X_test);
};

void Perceptron::set_weights(int input_size)
{
    printf("Generowanie wag\n");
    for (int i = 0; i < input_size; ++i)
    {
        weights.push_back(((double) rand() / (RAND_MAX)));
    }
    for (int i = 0; i < input_size; ++i)
    {
        cout << weights[i] << endl;
    }

}

double Perceptron::dot_product(vector <double> weights, double input[])
{
    double dot = 0;
    for (int i = 0; i < weights.size(); ++i)
    {
        dot += weights[i] * input[i];
    }
    printf("Dot: %.2f\n", dot);
    if (dot > 1)
    {
        dot = 1;
        return 1;
    }
    else
    {
        dot = -1;
        return -1;
    }
}

void Perceptron::train(vector <double> X_train, double labels[])
{
    for (int i = 0; i < X_train.size(); ++i)
    {
        printf("DATATATATATATATA");
    }

}

void Perceptron::predict(vector <double> saved_weights, double X_test)
{

}

int main()
{
    Perceptron per;
    printf("Podaj wielkosc wejscia\n");
    cin >> per.input_size;
    per.set_weights(per.input_size);
    vector <double> data = {1, 2, 3};
    double data2[] = {1, 2, 3};

    per.dot_product(per.weights, data2);
    return 0;
}

