#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include <utility>
#include <ctime>

using namespace std;

void section2(int A[], int size);
void section3a(int A[], int size);
void section3b(int A[], int size);
void section4(int A[], int size);
void section5(int A[], int size);
void section6(int A[], int size);
void section7a(int A[], int size, int x);
void section7b(int A[], int size, int x);
void section8(int A[], int size);

int main()
{
    // п.ПЕРВЫЙ--------------------------------------------------------------------------------
    setlocale(LC_ALL, "Russian");
    const int N = 100;
    int unsorted_array[N];
    bool answer;
    do
    {
        cout << "Section №1" << endl;
        srand(time(0));
        for (int& x : unsorted_array)
            x = rand() % 199 - 99;
        for (int x : unsorted_array)
            cout << x << ' ';
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // копия массива N - будет отсортирована
    int sorted_array[N];
    for (int i = 0; i < N; i++)
        sorted_array[i] = unsorted_array[i];

    // п.ВТОРОЙ--------------------------------------------------------------------------------
    do
    {
        cout << "Section №2" << endl;
        section2(sorted_array, N);
        for (int x : sorted_array)
            cout << x << ' ';
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // п.ТРЕТИЙ--------------------------------------------------------------------------------
    do
    {
        cout << "Section №3" << endl;
        section3a(unsorted_array, N);
        section3b(sorted_array, N);
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // п.ЧЕТВЕРТЫЙ-------------------------------------------------------------------------------- 
    do
    {
        cout << "Section №4" << endl;
        section4(sorted_array, N);
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // п.ПЯТЫЙ--------------------------------------------------------------------------------
    do
    {
        cout << "Section №5" << endl;
        section5(sorted_array, N);
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // п.ШЕСТОЙ--------------------------------------------------------------------------------
    do
    {
        cout << "Section №6" << endl;
        section6(sorted_array, N);
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // п.СЕДЬМОЙ--------------------------------------------------------------------------------
    do
    {
        cout << "Section №7" << endl;
        int X;
        cout << "Введите число ";
        cin >> X;
        section7a(sorted_array, N, X); // бинарный поиск
        section7b(sorted_array, N, X); //перебор
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);

    // п.ВОСЬМОЙ--------------------------------------------------------------------------------
    do
    {
        cout << "Section №8" << endl;
        section8(sorted_array, N);
        cout << endl;
        cout << "Повтор? 1 - Да, 0 - Нет ";
        cin >> answer;
        cout << endl;
    } while (answer);
    return 0;
}

void section2(int A[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < size - 1 - i; j++)
            if (A[j] > A[j + 1])
            {
                std::swap(A[j], A[j + 1]);
                flag = false;
            }
        if (flag) break;
    }
}

void section3a(int A[], int size)
{
    auto start = chrono::high_resolution_clock::now();
    int min = A[0], max = A[0];
    for (int i = 0; i < size - 1; i++)
    {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Max " << max << ", Min " << min << endl;
    cout << "Время поиска в неотсортированном массиве: " << duration.count() * 1000 << "ms." << endl;
}
void section3b(int A[], int size)
{
    auto start = chrono::high_resolution_clock::now();
    int min = A[0], max = A[size - 1];
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Время поиска в отсортированном массиве: " << duration.count() * 1000 << "ms." << endl;
}

void section4(int A[], int size)
{
    int average = (A[0] + A[size - 1]) / 2, count = 0;
    cout << "Среднее значение: " << average << endl;
    for (int i = 0; i < size; i++)
    {
        if (A[i] == average)
        {
            count++;
            cout << average << '[' << i << "] ";
        }
        if (A[i] > average) break;
    }
    cout << endl;
    cout << "Количество чисел равных ср.знач. " << count << endl;
}

void section5(int A[], int size)
{
    int number, value;
    cout << "Введите число ";
    cin >> number;
    for (int i = 0; i < size; i++)
        if (A[i] >= number)
        {
            value = i;
            break;
        }
    cout << "Количество чисел меньше заданного: " << value << endl;

}

void section6(int A[], int size)
{
    int number, value;
    cout << "Введите число ";
    cin >> number;
    for (int i = 0; i < size; i++)
        if (A[size - 1 - i] <= number)
        {
            value = i;
            break;
        }
    cout << "Количество чисел больше заданного: " << value << endl;
}

void section7a(int A[], int size, int x)
{
    int L = 0, R = size, mid;
    auto start = chrono::high_resolution_clock::now();
    while (L < R - 1)
    {
        mid = (L + R) / 2;
        if (x < A[mid]) R = mid;
        else L = mid;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    if (A[L] == x)
        cout << "Найден" << endl;
    else
        cout << "Не найден" << endl;
    cout << "Время бинарного поиска: " << duration.count() * 1000 << "ms." << endl;
}
void section7b(int A[], int size, int x)
{
    bool found = false;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
        if (A[i] == x)
        {
            found = true;
            break;
        }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << "Время перебора: " << duration.count() * 1000 << "ms." << endl;
}

void section8(int A[], int size)
{
    int index1, index2;
    cout << "Индексы: ";
    cin >> index1 >> index2;
    auto start = chrono::high_resolution_clock::now();
    std::swap(A[index1], A[index2]);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    for (int i = 0; i < size; i++)
        cout << A[i] << ' ';
    cout << endl;
    cout << "Время замены: " << duration.count() * 1000 << "ms." << endl;
}