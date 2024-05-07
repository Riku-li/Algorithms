#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int contador = 0;

    vector<int> billetes;
    billetes.push_back(100);
    billetes.push_back(20);
    billetes.push_back(10);
    billetes.push_back(5);
    billetes.push_back(1);

    for (int i = 0; i < billetes.size(); i++)
    {
        while (n >= billetes[i])
        {
            contador++;
            n -= billetes[i];
        }
    }
    cout << contador;
}