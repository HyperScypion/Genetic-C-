#include <vector>
#include <iostream>
#include <string>


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
