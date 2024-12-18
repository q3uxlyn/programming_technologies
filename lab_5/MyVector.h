#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data_; // Указатель на динамический массив элементов
    size_t size_; // Текущее количество элементов в векторе
    size_t capacity_; // Максимальная емкость вектора (размер выделенной памяти)

    // Метод для изменения размера массива
    void resize(size_t new_capacity);

public:
    MyVector(); // Конструктор по умолчанию
    MyVector(const MyVector& other); // Конструктор копирования
    MyVector(MyVector&& other) noexcept; // Конструктор перемещения

    ~MyVector(); // Деструктор

    MyVector& operator=(const MyVector& other); // Оператор копирующего присваивания
    MyVector& operator=(MyVector&& other) noexcept; // Оператор перемещающего присваивания

    void push_back(const T& value); // Добавление элемента в конеец вектора
    void pop_back(); // Удаление последнего элемента вектора
    size_t size() const; // Возвращает текущее количество элементов
    size_t capacity() const; // Возвращает текущую емкость вектора
    T& operator[](size_t index); // Доступ к элементу по индексу (для изменения)
    const T& operator[](size_t index) const; // Доступ к элементу по индексу (для чтения)
    void sort(); // Сортирует элементы вектора

    // Перегрузка оператора вывода
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyVector<U>& vec);
};


template <typename T>
// Инициализация пустого вектора без выделения памяти
MyVector<T>::MyVector() : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
// Конструктор копирования
// Выделение памяти и копированиее данных из другого вектора
MyVector<T>::MyVector(const MyVector& other) : data_(nullptr), size_(other.size_), capacity_(other.capacity_) {
    if (capacity_ > 0) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}


template <typename T>
// Конструктор перемещения
// Перемещаеет ресурсы от другого объекта и обнуляет его
MyVector<T>::MyVector(MyVector&& other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

// Деструктор
// Освобождает выделенную память
template <typename T>
MyVector<T>::~MyVector() {
    delete[] data_;
}

// Оператор копирующего присваивания
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        if (capacity_ > 0) {
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        } else {
            data_ = nullptr;
        }
    }
    return *this;
}

// Оператор перемещающего присваивания
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

// Метод добавления элемента
template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        resize(new_capacity);
    }
    data_[size_++] = value;
}

// Метод удаления последнего элемента
template <typename T>
void MyVector<T>::pop_back() {
    if (size_ == 0) {
        throw std::out_of_range("Vector is empty");
    }
    --size_;
}

// Текущее количество элементов
template <typename T>
size_t MyVector<T>::size() const {
    return size_;
}

// Текущая емкость (максимальное количество элементов без перевыделения памяти)
template <typename T>
size_t MyVector<T>::capacity() const {
    return capacity_;
}

// Доступ к элементу по индексу (с проверкой диапазона)
template <typename T>
T& MyVector<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

// Константный доступ к элементу по индексу (для неизменяемых объектов)
template <typename T>
const T& MyVector<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

// Метод для изменения емкости вектора 
template <typename T>
void MyVector<T>::resize(size_t new_capacity) {
    // Выделение новой памяти
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
        // Копирование старых данных
        new_data[i] = data_[i];
    }
    // Освобождение старой памяти
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

// Метод сортировки (пузырьковая сортировка)
template <typename T>
void MyVector<T>::sort() {
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_ - i - 1; ++j) {
            if (data_[j] > data_[j + 1]) {
                T temp = data_[j];
                data_[j] = data_[j + 1];
                data_[j + 1] = temp;
            }
        }
    }
}

// Перегрузка оператора вывода для удобного отображения содержимого вектора
template <typename U>
std::ostream& operator<<(std::ostream& os, const MyVector<U>& vec) {
    os << "[ ";
    for (size_t i = 0; i < vec.size_; ++i) {
        os << vec.data_[i] << " ";
    }
    os << "]";
    return os;
}

#endif