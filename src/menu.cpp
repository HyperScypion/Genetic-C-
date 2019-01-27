#include "multilayerperceptron.h"
#include <stdio.h>
#include <cstdlib>

void menu()
{
    printf("\t\t\tSimple Neural Net\n");
    printf("1. Make network\n");
    printf("2. Train network\n");
    printf("3. Save network\n");
    printf("4. Load network\n");
    printf("5. Predict lables\n");
    printf("6. Help\n");
    printf("7. About author\n");
    int choice;
    MultiLayerPerceptron network;
            std::vector <double> data;
            data.push_back(2);
            data.push_back(2);
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            #ifdef WINDOWS
            std::system("cls");
            #else
            std::system("clear");
            #endif // WINDOWS
            network.set_weights();
            network.dot_product(data);
            break;
        case 2:
            #ifdef WINDOWS
            std::system("cls");
            #else
            std::system("clear");
            #endif // WINDOWS
            // network.train();
            break;
        case 3:
            #ifdef WINDOWS
            std::system("cls");
            #else
            std::system("clear");
            #endif // WINDOWS
            break;
        case 4:
            #ifdef WINDOWS
            std::system("cls");
            #else
            std::system("clear");
            #endif // WINDOWS
            break;
        case 5:
            #ifdef WINDOWS
            std::system("cls");
            #else
            std::system("clear");
            #endif // WINDOWS
            break;
        case 6:
            #ifdef WINDOWS
            std::system("cls");
            #else
            std::system("clear");
            #endif // WINDOWS
            printf("\t\t\tHELP\n");
            printf("1. Make network -> This function creates neural network.\n");
            printf("This function takes 3 arguments size of input, hidden and ouput layer\n");
            printf("2. Train network -> Takes two vectors, one of input data, and one of output labels.\n");
            printf("It trains the network using backpropagation algorithm\n");
            printf("3. Save network -> Saves the network weights to file\n");
            printf("4. Load network -> Loads the network weights from file\n");
            printf("5. Predict labels -> This function takes vector of data and return predicted lables\n");
            break;
        case 7:
            #ifdef WINDOWS
            std::system("cls");
            #else
            std::system("clear");
            #endif // WINDOWS
            printf("Author: Tomasz Derek Project name: Simple Neural Network in C++ \nNicolaus Copernicus University in Torun, 2019 all rights reserved\n");
            printf("Press Enter to exit\n");
            break;
        default:
            printf("Error: Bad usage");
            exit(1);
    }
}
