#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <iterator>
#include "activation.h"
#include "multilayerperceptron.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector <double> data = {1, 1};
    vector <double> data2 = {1, 0};
    vector <double> data3 = {0, 1};
    vector <double> data4 = {0, 0};
    vector <double> lables = {1};
    vector <double> lables2 = {0};
    vector <double> lables3 = {0};
    vector <double> lables4 = {0};
    vector <double> test = {1, 0};
    if (argc < 2)
    {
        printf("./a.out -[Opcja]\n");
        exit(1);
    }
    Network *net;
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'a')
            {
                net = new Adaline;
            }
            else if (argv[i][1] == 'p')
            {
                net = new Perceptron;
            }

                printf("Podaj learning rate\n");
                cin >> net->learning_rate;
                printf("Podaj wielkosc wejscia\n");
                cin >> net->input_size;
                printf("Podaj ilosc epok\n");
                cin >> net->epochs;
                printf("Podaj funkcje aktywacji (lowecasem)\n");
                string activ_fnc;
                cin >> activ_fnc;
                net->set_weights();
                net->train(net->learning_rate, net->epochs, data, lables, activ_fnc);
                net->train(net->learning_rate, net->epochs, data2, lables2, activ_fnc);
                net->train(net->learning_rate, net->epochs, data3, lables3, activ_fnc);
                net->train(net->learning_rate, net->epochs, data4, lables4, activ_fnc);
                cout << "Predykcja = " << net->forward_prop(test, activ_fnc) << " Oczekiwane = " << test[0] << endl;
        }
    }
    return 0;
}
