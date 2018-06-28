#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

class Perceptron
{
public:
    double input_data_X[3] = {1, 0, 1};
    double input_data_Y[3] = {0, 0, 1};
    double output_data[3] = {0, 0, 1};
    double weights[2];
    double saved_weights[2];
    double counted_value;
    double error;
    double stochastic_gradient_descent(double predict_value, int id)
    {
        error = predict_value - output_data[id];

    }
    int learn()
    {
        srand(time(NULL));
        for(int i=0; i<2; i++)
        {
           weights[i] = ((double)rand()/(RAND_MAX));
        }
        for(int i=0; i<1000; i++)
        {
            cout << "Weights: " << weights[0] << " | " <<  weights[1] << endl;
            for(int i=0; i<3; i++)
            {
                counted_value = input_data_X[i] * weights[0] + input_data_Y[i] * weights[1];
                cout << "Prediction for " << input_data_X[i] << " " << input_data_Y[i] << " is " << counted_value << endl;
                error = output_data[i] - counted_value;
                cout << "Error: " << error << endl;
                double new_weight = output_data[i] - 0.5*(error*error);
                cout << "New weight " << new_weight << endl;
                if(error!=0)
                {
                    weights[0] = new_weight;
                    weights[1] = new_weight;
                }
            }
        }
        saved_weights[0] = weights[0];
        saved_weights[1] = weights[1];
    }
    int predict(double x, double y)
    {
        cout << "Prediction for " << x << " " << y << " is ";
        if(x * saved_weights[0] + y * saved_weights[1] > 0.5)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }

    }
};

int main()
{
    Perceptron perceptron;
    perceptron.learn();
    perceptron.predict(1, 1);
    perceptron.predict(0, 1);
    perceptron.predict(1, 0);
    perceptron.predict(0, 0);
    return 0;
}
