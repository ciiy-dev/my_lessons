#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <ctime>

using namespace std;
const int SIZE = 10;
void unicornElementMassiv(int arr[])
{
    srand(time(NULL));

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
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int arr[SIZE];
    int key;
    unicornElementMassiv(arr);
    sort(arr, arr + 10);
    cout << "Введите ключ который будете искать: ";
    cin >> key;
    bool flag = false;
    int mid;
    int l = 0;
    int r = SIZE - 1;
    while ((l <= r) && (flag != true)) {
        mid = (r + l)/2;
        if (arr[mid] == key) flag = true;
        if (arr[mid] > key) r = mid - 1;
        else l = mid + 1;
    }

    if (flag) 
    { 
        cout << "Индекс элемента " << key << " в массиве равен: " << mid;
    }
    else
    {
        cout << "Извините, но такого элемента в массиве нет." << endl;
    }
}