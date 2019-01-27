#include <vector>
#include <random>
#include <iostream>

class MultiLayerPerceptron
{
public:
    int input_size;
    int hidden_size;
    int output_size;
    std::vector <double> X_train;
    std::vector <double> y_train;
    bool bias;
    double learning_rate;
    void set_weights();
    double dot_product(std::vector <double> data);
    void train(std::vector <double> X_train, std::vector <double> y_train, double learning_rate, int epochs, std::string activ);
    //  double predict(vector <double> saved_weights, double X_test);
private:
    std::vector <double> weights;
    std::vector <std::vector <double> > matrix1;
    std::vector <std::vector <double> > matrix2;
};

void MultiLayerPerceptron::set_weights()
{
    int input_size, hidden_size, output_size;
    printf("Enter size of input layer\n");
    scanf("%d", &input_size);
    printf("Enter size of hidden layer\n");
    scanf("%d", &hidden_size);
    printf("Enter size of output layer\n");
    scanf("%d", &output_size);

    for (int i = 0; i < input_size; ++i)
    {
        for (int j = 0; j < hidden_size; ++j)
        {
            weights.push_back(((double) rand() / (RAND_MAX)));
        }
        matrix1.push_back(weights);
    }
    weights.clear();
    for (int i = 0; i < hidden_size; ++i)
    {
        for (int j = 0; j < output_size; ++j)
        {
            weights.push_back(((double) rand() / (RAND_MAX)));
        }
        matrix2.push_back(weights);
    }
}

double MultiLayerPerceptron::dot_product(std::vector <double> data)
{
    double dot = 0;
    std::cout << data[0];
    std::cout << data[1];
    std::vector <double> dot_vec;
   // j = 0; j < column; ++j
    // std::cout << matrix1[0].size() << "\n";
    // std::cout << matrix1.size() << "\n";
    int j = 0;
    bool flag = true;
    for (int i = 0; i < matrix1[0].size(); ++i)
    {
        for (int j = 0; j < matrix1.size(); ++j)
        {
            dot += matrix1[0][j] * data[i];
            std::cout << "DATA[I]: " << data[i] << "\n";
            printf("MATRIX1[0][%d]: %f\n", j, matrix1[0][j]);
        }
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

void MultiLayerPerceptron::train(std::vector <double> X_train, std::vector <double> y_train, double learning_rate, int epochs, std::string activ)
{
    for (int i = 0; i < epochs; ++i)
    {
        for (int j = 0; j < X_train.size(); ++j)
        {
            for (int k = 0; k < input_size; ++k)
            {
//                weights[k] += learning_rate*(/*Prediction - label*/8)*X_train[j];
            }
        }
    }
//    for (int i = 0; i < weights.size(); ++i)
  //  {
    //    cout << "Train: " << weights[i] << endl;
    //}

}
