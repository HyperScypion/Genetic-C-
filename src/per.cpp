#include <iostream>
#include <vector>
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
    for (int i = 1; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'a')
            {
                Adaline ada;
                printf("Podaj learning rate\n");
                cin >> ada.learning_rate;
                printf("Podaj wielkosc wejscia\n");
                cin >> ada.input_size;
                printf("Podaj ilosc epok\n");
                cin >> ada.epochs;
                printf("Podaj funkcje aktywacji (lowecasem)\n");
                string activ_fnc;
                cin >> activ_fnc;
                ada.set_weights();
                ada.train(ada.learning_rate, ada.epochs, data, lables, activ_fnc);
                ada.train(ada.learning_rate, ada.epochs, data2, lables2, activ_fnc);
                ada.train(ada.learning_rate, ada.epochs, data3, lables3, activ_fnc);
                ada.train(ada.learning_rate, ada.epochs, data4, lables4, activ_fnc);
                cout << "Predykcja = " << ada.forward_prop(test, activ_fnc) << " Oczekiwane = " << test[0] << endl;
            }
            else if (argv[i][1] == 'p')
            {
                Perceptron per;
                printf("Podaj learning rate\n");
                cin >> per.learning_rate;
                printf("Podaj wielkosc wejscia\n");
                cin >> per.input_size;
                printf("Podaj ilosc epok\n");
                cin >> per.epochs;
                printf("Podaj funkcje aktywacji (lowecasem)\n");
                string activ_fnc;
                cin >> activ_fnc;
                per.set_weights();
                per.train(per.learning_rate, per.epochs, data, lables, activ_fnc);
                per.train(per.learning_rate, per.epochs, data2, lables2, activ_fnc);
                per.train(per.learning_rate, per.epochs, data3, lables3, activ_fnc);
                per.train(per.learning_rate, per.epochs, data4, lables4, activ_fnc);
                cout << "Predykcja = " << per.forward_prop(test, activ_fnc) << " Oczekiwane = " << test[0] << endl;
            }
        }
    }
    return 0;
}

