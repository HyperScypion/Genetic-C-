#include <iostream>
#include <thread>
#include <random>

using namespace std;

int dna_length=15;
int population_size=10;
int generation=0;
int parent[10][15]={0};

void make_population(int population_size, int dna_length)
{
    int parent[population_size][dna_length]={0};
    for(int i=0; i<population_size; i++)
    {
        for(int j=0; j<dna_length; j++)
        {
            parent[i][j] = rand() %2;
        }
    }
}
void fitness(int *parent)
{
    const int 15;
}

int main()
{
    cout << "Hello world!" << endl;
    //std::thread first (make_parents, 5, 2);
    make_population(population_size, dna_length);
   /* for(int i=0; i<population_size; i++)
    {
        for(int j=0; j<dna_length; j++)
        {
            cout<<parent[i][j];
        }
        cout<<endl;
    }
    */

    return 0;
}
