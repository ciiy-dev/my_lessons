#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <typeinfo>
#include <ctime>

using namespace std;

// Вводим переменную, которая генерирует размера массива (от 0 до 100 элементов)
int SIZE = rand() % 100;
// Объявляем переменную для подсчёта кол-во итераций
int iterationNumber = 0;
// Максимальное возможное число в массиве
int maximumNumbers = 10000000;
void unicornElementMassiv(int arr[]);

int binarySearch_(int arr[], int key, int razmer) {
    // Если это первая итерация запускаем алгоритм с нуля 
    if (iterationNumber == 0)
        sort(arr, arr + razmer);
        bool flag = false;
        int mid;
    int l = 0;
    int r = (razmer) - 1;
    while ((l <= r) && (flag != true)) {
        mid = (r + l)/2;
        if (arr[mid] == key) flag = true;
        if (arr[mid] > key) r = mid - 1;
        else l = mid + 1;
    }
    // Если ключ найден в массиве
    if (flag) { 
        cout << "Индекс элемента " << key << " в массиве arr равен: " << mid << endl;
    }
    // Если нет, увеличивает счетчик итераций и генирует новый ключ, запускает новый стек до тех пор пока ключ не будет найден
    else {
        iterationNumber++;
        key = rand() % maximumNumbers + 1;
        return binarySearch_(arr,key,razmer);
    }
    return 0;
}

void unicornElementMassiv(int arr[]) {
    // Заполняем наш массив элементами
    for(int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % maximumNumbers + 1;
    }
    // Проверяем элементы на уникальность и меняем в обратном случае
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            while ((arr[i] == arr[j]) && (i != j))
                arr[j] = rand() % maximumNumbers + 1;
        }
        cout << arr[i] << endl;
    }
}

int main() {
    // Использует текущее время (на момент запуска), чтобы использовать алгоритм псевдослучайности
    srand(time(NULL));
    // Ставим русскую локаль
    setlocale(LC_ALL, "Rus");
    // Объявляем массив
    int arr[SIZE];
    // Запускаем функцию, которая заполнит наш массив уникальными числами
    unicornElementMassiv(arr); 
    // Генерируем псевдослучайный ключ
    int randomkey = rand() & maximumNumbers + 1;
    // Узнаем размер массива и помещаем его в константу
    const int razmer = sizeof(arr)/sizeof(arr[0]);
    // Запускаем функцию бинарного поиска псевдослучайного ключа в псевдослучайном массиве
    binarySearch_(arr,randomkey, razmer);
    cout << "Размер массива равен: " << razmer << endl;
    cout << "Количество итераций: " << iterationNumber << endl;
}