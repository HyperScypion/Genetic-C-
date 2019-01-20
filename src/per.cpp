#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <iterator>

using namespace std;

class MultiLayerPerceptron
{
public:
    int input_size;
    int hidden_size;
    int output_size;
    double X_train;
    double y_train;
    vector <double> weights;
    void set_weights(int input_size, int hidden_size, int output_size);
    //double dot_product(vector <double> weights, double X_train[]);
    //void train(vector <double> dot, double y_train[]);
    //void predict(vector <double> saved_weights, double X_test);
};

void MultiLayerPerceptron::set_weights(int input_size, int hidden_size, int output_size)
{
    printf("Generowanie wag\n");
    double first_matrix[input_size][hidden_size];
    double second_matrix[hidden_size][output_size];
    for (int i = 0; i < input_size; ++i)
    {
	for (int j = 0; j < hidden_size; ++j)
	{
        	first_matrix[i][j] = ((double) rand() / (RAND_MAX));
	}
    }
    printf("Pierwsza macierz wag\n");
    for (int i = 0; i < input_size; ++i)
    {
	for (int j = 0; j < hidden_size; ++j)
	{
        	cout << first_matrix[i][j] << "   ";
	}
	cout << endl;
    }
    // Druga macierz //
    for (int i = 0; i < hidden_size; ++i)
    {
	for (int j = 0; j < output_size; ++j)
	{
		second_matrix[i][j] = ((double) rand() / (RAND_MAX));
	}
    }
    printf("Druga macierze wag\n");
    for (int i = 0; i < hidden_size; ++i)
    {
	for (int j = 0; j < output_size; ++j)
	{
		cout << second_matrix[i][j] << "   ";
	}
	cout << endl;
    }


}
/*
double MultiLayerPerceptron::dot_product(vector <double> weights, double input[])
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

void MultiLayerPerceptron::train(vector <double> X_train, double labels[])
{
    for (int i = 0; i < X_train.size(); ++i)
    {
        printf("DATATATATATATATA");
    }

}

void MultiLayerPerceptron::predict(vector <double> saved_weights, double X_test)
{

}
*/
int main()
{
    MultiLayerPerceptron per;
    printf("Podaj wielkosc wejscia\n");
    cin >> per.input_size;
    printf("Podaj wielkosc warstwy ukrytej\n");
    cin >> per.hidden_size;
    printf("Podaj wielkosc wyjscia\n");
    cin >> per.output_size;
    per.set_weights(per.input_size, per.hidden_size, per.output_size);
    vector <double> data = {1, 2, 3};
    double data2[] = {1, 2, 3};

    //per.dot_product(per.weights, data2);
    return 0;
}

