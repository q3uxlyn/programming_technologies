// Класс массива динамической длины (наподобие класса vector из STL)
// Массив должен автоматически увеличивть свой размер при добавлении элементов,
// увеличение должно производиться с некоторым запасом.
// Методы для добавления и удаления элементов массива, для обращения к элментам, а также для сортировки массива.
// В идеале класс должен быть шаблонным, но можно сделать только для типа int.
#include <iostream>
#include "MyVector.h"

int main() {
    try {
        // Создание пустого вектора типа int
        MyVector<int> vec;
        std::cout << "Initial vector: " << vec << std::endl;

        // Добавление элементов в конец вектора
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(8);
        vec.push_back(1);
        std::cout << "After push_back: " << vec << std::endl;

        // Доступ к элементу по индексу с использованием оператора []
        std::cout << "Element at index 2: " << vec[2] << std::endl;

        // Изменение значения элемента по индексу
        vec[2] = 10;
        std::cout << "After modifying element at index 2: " << vec << std::endl;

        // Удалениее последнего элемента вектора
        vec.pop_back();
        std::cout << "After pop_back: " << vec << std::endl;

        // Создание копии вектора с использованием конструктора копирования
        MyVector<int> vec_copy = vec;
        std::cout << "Copied vector: " << vec_copy << std::endl;

        // Перемещение данных из vec в новый объект vec_moved
        MyVector<int> vec_moved = std::move(vec);
        std::cout << "Moved vector: " << vec_moved << std::endl;
        // После перемещения исходный вектор становится пустым
        std::cout << "Original vector after move: " << vec << std::endl;

        // Добавление элементов в новый вектор
        vec_moved.push_back(7);
        vec_moved.push_back(2);
        std::cout << "After adding more elements: " << vec_moved << std::endl;

        // Сортировка элементов вектора
        vec_moved.sort();
        std::cout << "After sorting: " << vec_moved << std::endl;

        // Вывод текущего размера вектора и его емкости
        std::cout << "Size: " << vec_moved.size() << ", Capacity: " << vec_moved.capacity() << std::endl;

        // Копирование данных из одного вектора в другой (оператор присваивания)
        MyVector<int> vec_assigned;
        vec_assigned = vec_moved;
        std::cout << "Assigned vector: " << vec_assigned << std::endl;

        // Перемещение данных (оператор перемещения)
        MyVector<int> vec_move_assign;
        vec_move_assign = std::move(vec_assigned);
        std::cout << "Move-assigned vector: " << vec_move_assign << std::endl;
        std::cout << "Assigned vector after move: " << vec_assigned << std::endl;

    } catch (const std::exception& e) {
        // Обработка исключений
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
