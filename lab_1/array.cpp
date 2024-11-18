// В массиве целых чисел найти число положительных элементов,
// стоящих перед минимальным элементом (левее минимального)

#include <iostream> // библиотека ввода вывода
#include <cstdlib> // библиотека генерации случайных чисел
#include <ctime> // библиотека работы с функцией времени

// возвращает количество положительных элементов
int countPosBeforeMin(const int arr[], int size) {
    // если массив пустой - возвращаем 0
    if (size == 0) {
        return 0;
    }

    int minIndex = 0; // индекс минимального элемента
    int minValue = arr[0]; // значение минимального элемента

    // поиск минимального элемента и его индекса в массиве
    for(int i = 1; i < size; ++i) {
        if(arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
    }

    // подсчет положительных элементов до минимального элемента
    int count = 0;
    for(int i = 0; i < minIndex; ++i) {
        if(arr[i] > 0) {
            ++count;
        }
    }

    return count;
}

// выводит содержимое массива на экран
void printArray(const int arr[], int size) {
    std::cout << "{ ";
    for(int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "}";
}

int main() {
    // инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "Тестирование на встроенных массивах:\n";

    // Тест 1: массив с разными значениями
    int arr1[] = {3, -1, 4, 0, -2, 5};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    std::cout << "Массив 1: ";
    printArray(arr1, size1);
    std::cout << "\nКоличество положительных элементов перед минимальным элементом: "
              << countPosBeforeMin(arr1, size1) << "\n\n";

    // Тест 2: массив с отрицательными значениями
    int arr2[] = {-5, -3, -1, -4, -2};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    std::cout << "Массив 2: ";
    printArray(arr2, size2);
    std::cout << "\nКоличество положительных элементов перед минимальным элементом: "
              << countPosBeforeMin(arr2, size2) << "\n\n";

    // Тест 3: массив с положительными значениями
    int arr3[] = {10, 20, 30, 5, 40, 50};
    int size3 = sizeof(arr3)/sizeof(arr3[0]);
    std::cout << "Массив 3: ";
    printArray(arr3, size3);
    std::cout << "\nКоличество положительных элементов перед минимальным элементом: "
              << countPosBeforeMin(arr3, size3) << "\n\n";

    // Тест 4: массив с несколькими одинаковыми минимальными элементами
    int arr4[] = {2, 3, 1, 4, 1, 5};
    int size4 = sizeof(arr4)/sizeof(arr4[0]);
    std::cout << "Массив 4: ";
    printArray(arr4, size4);
    std::cout << "\nКоличество положительных элементов перед первым минимальным элементом: "
              << countPosBeforeMin(arr4, size4) << "\n\n";

    std::cout << "Работа с динамическим массивом:\n";
    int dynamicSize;
    std::cout << "Введите количество элементов динамического массива: ";
    std::cin >> dynamicSize;

    if(dynamicSize <= 0) {
        std::cerr << "Размер массива должен быть положительным.\n";
        return 1;
    }

    // создание динамического массива
    int* dynamicArr = new int[dynamicSize];

    // заполнение случайными числами в диапазоне от -100 до 100
    std::cout << "Сгенерированный динамический массив: { ";
    for(int i = 0; i < dynamicSize; ++i) {
        dynamicArr[i] = (std::rand() % 31) - 20;
        std::cout << dynamicArr[i] << " ";
    }
    std::cout << "}\n";

    int dynamicCount = countPosBeforeMin(dynamicArr, dynamicSize);
    std::cout << "Количество положительных элементов перед минимальным элементом: "
              << dynamicCount << "\n";

    // освобождение памяти, выделенной под динамический массив
    delete[] dynamicArr;

    return 0;
}