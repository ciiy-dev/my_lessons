#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    
    int const SIZE = 10;
    int arr[SIZE];
    int result = 0;

    for(int i = 0; i < SIZE; ++i)
    {
        arr[i] = rand() % 20 + 1;
    }

    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            while ((arr[i] == arr[j]) && (i != j))
                arr[j] = rand() % 20 + 1;
        }
        cout << arr[i] << endl;
    }

    for(int i = 0; i < 1; ++i)
    {
        result = arr[i];
        for(int j = 0; j < SIZE; ++j)
        {
            if (result <= arr[j])
                continue;
            else
                result = arr[j];
        }
    }
    cout << "Наименьший элемент массива: " << result << endl;
}

