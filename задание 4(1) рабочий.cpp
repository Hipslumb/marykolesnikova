#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>

const unsigned size = 100;
std::vector<int> arr;
void readArrayFromFile(const std::string & filename, std::vector<int>&arr) /*открывает файл, считывает размер массива и его элементы.*/
{
    std::ifstream infile(filename);

    if (!infile) 
    {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return;
    }
    
    int n;
    infile >> n; // Читаем размер массива
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        infile >> arr[i]; // Читаем элементы массива
    }

    infile.close();
}
void writeResultsToFile(const std::string & filename, int sum1, int sum2, int difference)
{
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return;
    }
    outfile << "Элементы массива: ";
    for (const int& element : arr)
    {
        outfile << element << " ";
    }
    outfile << std::endl;
    outfile << "Сумма от k=1 до n/2 (b по 2k-1): " << sum1 << std::endl;
    outfile << "Сумма от k=n/2 до n-1 (b по k): " << sum2 << std::endl;
    outfile << "Разность сумм: " << difference << std::endl;

    outfile.close();
}
int main() {
    setlocale(LC_CTYPE, "RU");
    std::cout << "Задание: Найти разность сумм:\n";
    std::cout << "n/2                 n-1        \n";
    std::cout << "sum (B (2k-1))  и   sum (B (k))  \n";
    std::cout << "k=1                 k=n/2      \n";
    std::cout << "Автор: Колесникова Мария Андреевна, группа 4352, гр. 1.\n";
    std::cout << "Версия: 1.1.1\n";
    std::cout << "Даты: начало: 20.10.2024, конец: 29.10.2024 \n";
    std::fstream f;
    float buffer[size];
    unsigned k = 0, len = 0, uni = 0;
    char filename[101]{};
    char* start;
    readArrayFromFile(inputFile, arr);
    int n = arr.size();
    if (n == 0) {
        std::cerr << "Массив пуст." << std::endl;
        return 1;
    }
    int sum1 = 0, sum2 = 0;
    for (int k = 1; k <= n / 2; ++k) {
        sum1 += arr[2 * k - 1];
    }
    for (int k = n / 2; k < n; ++k) {
        sum2 += arr[k];
    }
    int difference = sum1 - sum2;
    writeResultsToFile(outputFile, sum1, sum2, difference); /*принимает суммы и разность, а затем записывает их в выходной файл*/
    std::cout << "Результаты успешно записаны в файл " << outputFile << std::endl;
    return 0;
}