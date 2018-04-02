#include <iostream>
#include <vector>
#include <random>

using namespace std;

void create_weights(int counter)
{
    vector <double> weights;
    double temp;
    for(int i=0; i<counter; i++)
    {
        temp = (rand()/(double)RAND_MAX * 1)+0;
        weights.push_back(temp);
    }
    for(int j=0; j<counter; j++)
    {
        cout<<weights[j]<<endl;
    }
}

int activation_function(double x)
{
    if(x>0)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

void take_the_inputs(int counter)
{
    double temp;
    vector <double> input;
    for(int i=0; i<counter; i++)
    {
        cin>>temp;
        input.push_back(temp);
    }
}

int counter_of_inputs;

int main()
{
    cin>>counter_of_inputs;
    //take_the_inputs(counter_of_inputs);
    create_weights(counter_of_inputs);
    return 0;
}
