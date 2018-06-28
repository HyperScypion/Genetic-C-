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
    double errors[2];
    double saved_weights[2];
    double node_1, node_2;
    double counted_value;
    double error;
    bool czy_przerwac = false;
    double fun(double value)
    {
        if(value<-1)
        {
            return -1;
        }
        else if(value > 1)
        {
            return 1;
        }
        else
        {
            return value;
        }
    }
    double mod(double value)
    {
        if(value < 0)
        {
            return -value;
        }
        else
        {
            return value;
        }
    }

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
            cout << "Number of iteration: " << i+1 <<endl;
            cout << "Weights: " << weights[0] << " | " <<  weights[1] << endl;
            for(int i=0; i<3; i++)
            {
                node_1 = fun(input_data_X[i] * weights[0]);
                node_2 = fun(input_data_Y[i] * weights[1]);
                counted_value = fun(node_1 + node_2);
                cout << "Prediction for " << input_data_X[i] << " " << input_data_Y[i] << " is " << counted_value << endl;
                errors[0] = output_data[i] - 0.5*((counted_value - node_1)*(counted_value - node_1));
                errors[1] = output_data[i] - 0.5*((counted_value - node_2)*(counted_value - node_1));
                cout << errors[0] << " " << errors[1] << endl;
                error = errors[0] + errors[1];
                if(error > 1)
                {
                    errors[0] /= 2;
                    errors[1] /= 2;
                }
                cout << "Error: " << error << endl;
                if(error!=0)
                {
                    weights[0] = errors[0];
                    weights[1] = errors[1];
                }
                if(error < 0.5 && i>10)
                {
                    czy_przerwac = true;
                    break;
                }
            }
            saved_weights[0] = weights[0];
            saved_weights[1] = weights[1];
            if(czy_przerwac == true)
            {
                break;
            }
        }
    }
    int predict(double x, double y)
    {
        cout << "Prediction for " << x << " " << y << " is ";
        if(fun(x * saved_weights[0] + y * saved_weights[1]) > 0.5)
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
