// Сформировать новую строку, удалив из исходной строки все десятичные цифры

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
//#include <cstring>

// Функция для удаления цифр из строки (С-строка)
char* removeDigitsC(char *destination, const char *source) {
    // Проверяем на nullptr (защита от некорректных данных)
    if (source == nullptr || destination == nullptr) {
        return destination;
    }

    int j = 0; // Индекс для записи в destination

    // Перебираем символы исходной строки
    for(int i = 0; source[i] != '\0'; ++i) {
        // Если символ не является цифрой, добавляем его в destination
        if(!std::isdigit(static_cast<unsigned char>(source[i]))) {
            destination[j++] = source[i];
        }
    }

    // Завершаем строку нулевым символом
    destination[j] = '\0';
    return destination;
}

// Функция для удаления цифр из строки (std::string)
std::string removeDigitsString(const std::string &source) {
    std::string result; // Результирующая строка
    result.reserve(source.size()); // Резервируем память

    // Перебираем символы строки
    for(char ch : source) {
        // Если символ не являеется цифрой, добавляем в результат
        if(!std::isdigit(static_cast<unsigned char>(ch))) {
            result += ch;
        }
    }

    return result; // Возвращаем строку без цифр
}

int main() {
    // Имя входного файла
    const std::string filename = "input.txt";

    // Открываем файл для чтения
    std::ifstream inputFile(filename);
    if(!inputFile) {
        // Ошибка, если не удалось открыть файл
        std::cerr << "Не удалось открыть файл: " << filename << "\n";
        return 1;
    }

    std::cout << "Чтение строк из файла \"" << filename << "\" и обработка:\n\n";

    std::string line; // Переменная для хранения строки из файла
    int lineNumber = 1; // Номер текущей строки

    // Читаем файл построчно
    while(std::getline(inputFile, line)) {
        const int MAX_LENGTH = 256; // Максимальная длина строки для С-строк
        char sourceC[MAX_LENGTH + 1]; // Исходная строка в формате C-строки
        char destinationC[MAX_LENGTH + 1]; // Результирующая строка в формате С-строки

        // Прямой способ копирования строки в массив без использования <cstring>
        int i = 0;
        for (; i < MAX_LENGTH && i < line.size(); ++i) {
            sourceC[i] = line[i];
        }
        sourceC[i] = '\0'; // Завершаем строку нулевым символом

        // Копируем строку из std::string в C-строку
        //std::strncpy(sourceC, line.c_str(), MAX_LENGTH);
        //sourceC[MAX_LENGTH] = '\0'; // Убеждаемся, что строка завершена

        // Удаляем цифры с использованием функции для С-строк
        removeDigitsC(destinationC, sourceC);

        // Удаляем цифры с использованием функции для std::string
        std::string resultString = removeDigitsString(line);

        // Выводим результаты
        std::cout << "Строка " << lineNumber << ":\n";
        std::cout << "Исходная строка: " << line << "\n";
        std::cout << "После удаления цифр (C-строки): \"" << destinationC << "\"\n";
        std::cout << "После удаления цифр (std::string): \"" << resultString << "\"\n\n";

        ++lineNumber; // Следующая строка
    }

    inputFile.close(); // Закрываем файл
    return 0;
}
