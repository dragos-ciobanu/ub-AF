#include <iostream>
#include <fstream>
#include <cmath>

void change(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/** Suma cifrelor */
void runProgram1() {
    std::cout << "\t - Suma cifrelor. - " << std::endl;
    unsigned char digit, sum = 0;
    unsigned long long number;
    std::cout << "Introduceti numarul: ";
    std::cin >> number;

    do {
        digit = number % 10;
        sum += digit;
        number /= 10;
    } while (number > 0);

    std::cout << "Suma cifrelor = " << int(sum) << std::endl;
}

/** Numarul de cifre */
void runProgram2() {
    std::cout << "\t - Numarul de cifre. - " << std::endl;
    unsigned char digitNumber = 0;
    unsigned long long number;
    std::cout << "Introduceti numarul: ";
    std::cin >> number;

    if (number > 0) {
        digitNumber = (int)log10(number) + 1;
    } else {
        digitNumber = 1;
    }

    std::cout << "Numarul de cifre = " << int(digitNumber) << std::endl;
}

/** Oglinditul lui N */
void runProgram3() {
    std::cout << "\t - Oglinditul lui N. - " << std::endl;
    unsigned char digit;
    unsigned long long number, reverseNumber = 0;
    std::cout << "Introduceti numarul: ";
    std::cin >> number;

    do {
        digit = number % 10;
        number /= 10;
        reverseNumber *= 10;
        reverseNumber += digit;
    } while (number > 0);

    std::cout << "Oglinditul lui " << number << " = " << reverseNumber << std::endl;
}

/** Palindrom */
void runProgram4() {
    std::cout << "\t - Este palindrom. - " << std::endl;
    unsigned char digit;
    unsigned long long number, tempNumber, reverseNumber = 0;
    std::cout << "Introduceti numarul: ";
    std::cin >> number;
    tempNumber = number;
    do {
        digit = tempNumber % 10;
        tempNumber /= 10;
        reverseNumber *= 10;
        reverseNumber += digit;
    } while (tempNumber > 0);

    std::cout << "Numarul \"" << number << "\" " << (number != reverseNumber ? " NU " : "") << "este palindrom." << std::endl;
}

/** Numar prim */
void runProgram5() {
    std::cout << "\t - Este numar prim. - " << std::endl;
    unsigned long long number, factor;
    bool isPrim = true;
    std::cout << "Introduceti numarul: ";
    std::cin >> number;

    for (factor = 2; factor <= (long long)sqrt(number); factor++) {
        if (number % factor == 0) {
            isPrim = false;
            break;
        }
    }

    std::cout << "Numarul \"" << number << "\" " << (!isPrim ? " NU " : "") << "este prim." << std::endl;
}

/** Descompunere factori primi */
/** Multimea divizorilor proprii primi */
void runProgram6() {
    std::cout << "\t - Descompunere factori primi. - " << std::endl;
    unsigned long long number, tempNumber, factor;
    unsigned long factors[100];
    unsigned char powers[100];
    unsigned short currentFactor = 0;
    std::cout << "Introduceti numarul: ";
    std::cin >> number;
    tempNumber = number;

    for (factor = 2; factor <= (long long)tempNumber; factor++) {
        if (tempNumber % factor == 0) {
            unsigned char power = 0;
            factors[currentFactor] = factor;
            while (tempNumber % factor == 0) {
                tempNumber /= factor;
                power++;
            }
            powers[currentFactor] = power;
            currentFactor++;
        }
    }

    std::cout << "Numarul \"" << number << "\" " << (currentFactor != 1 ? " NU " : "") << "este prim." << std::endl;
    std::cout << "Factorii primi sunt: " << std::endl;
    std::cout << 1 << std::endl;
    for (unsigned short i = 0; i < currentFactor; i++) {
        std::cout << factors[i] << " ^ " << (int)powers[i] << std::endl;
    }

    std::cout << "Multimea divizorilor proprii ai lui " << number << ": " << std::endl;
    if (currentFactor == 1) {
        std::cout << "MULTIMEA VIDA" << std::endl;
    } else {
        std::cout << "{ " << factors[0];
        for (unsigned short i = 1; i < currentFactor; i++) {
            std::cout << ", " << factors[i];
        }
        std::cout << " }" << std::endl;
    }
}


/** Algoritmul lui Euclid */

unsigned long long gcdRecursive(unsigned long long x, unsigned long long y) {
    if (x == 0) {
        return y;
    }

    return gcdRecursive(y % x, x);
}

unsigned long long gcd(unsigned long long x, unsigned long long y) {
    while (y % x != 0) {
        unsigned long long temp = x;
        x = y % x;
        y = temp;
    }

    return x;
}

void runProgram8() {
    std::cout << "\t - Cel mai mare divizor comun. - " << std::endl;
    unsigned long long number1, number2;
    std::cout << "Introduceti numarul 1: ";
    std::cin >> number1;
    std::cout << "Introduceti numarul 2: ";
    std::cin >> number2;

    std::cout << "CMMDC: (iterativ)" << gcd(number1, number2) << std::endl;
    std::cout << "CMMDC: (recursiv)" << gcdRecursive(number1, number2) << std::endl;
}

/** Fibonacci */
unsigned long long fibonacciIterativ(unsigned short  n) {
    unsigned long long temp, number1 = 2, number2 = 3;
    if (n <= 3) {
        return n;
    }

    for (unsigned short i = 4; i <= n; i++) {
        temp = number2;
        number2 += number1;
        number1 = temp;
    }

    return number2;
}

unsigned long long fibonacci(unsigned short n) {
    if (n <= 3) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void runProgram9() {
    std::cout << "\t - Secventa lui Fibonacci. - " << std::endl;
    unsigned short number;
    std::cout << "Introduceti numarul: ";
    std::cin >> number;

    std::cout << "Numarul lui fibonacci de pe pozitia " << number << " (iterativ): " << fibonacciIterativ(number) << std::endl;
    std::cout << "Numarul lui fibonacci de pe pozitia " << number << "(recursiv): " << fibonacci(number) << std::endl;
}

/** BUBBLE SORT */
void bubbleSort(int n, int* data) {
    int i,j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                change(&data[i], &data[j]);
            }
        }
    }
}

void runProgramA() {
    std::cout << "Bubble Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-A.txt";
    std::ifstream inFile;

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     */
    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    bubbleSort(n, data);

    std::ofstream outFile;
    outFile.open("iesire-A.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}

/** QUICK SORT */
int quickPartition(int* data,int p, int r) {
    int x, i, j;
    x = data[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++) {
        if (data[j] <= x) {
            i++;
            change(&data[i], &data[j]);
        }
    }
    change(&data[i+1], &data[r]);

    return i+1;
}
void quickSort(int* data, int p, int r) {
   if (p < r) {
        int q;
        q = quickPartition(data, p, r);
       quickSort(data, p, q-1);
       quickSort(data, q+1, r);
   }
}
void runProgramB() {
    std::cout << "Quick Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-B.txt";
    std::ifstream inFile;

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     */
    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    quickSort(data, 0, n-1);

    std::ofstream outFile;
    outFile.open("iesire-B.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}

/** Insert Sort */
void insertSort(int* data, int n) {
    int i, j, k;
    for (i = 1; i < n; i++) {
        k = data[i];
        j = i -1;
        while (j >= 0 && data[j] > k) {
            data[j+1] = data[j];
            j = j - 1;
        }
        data[j+1] = k;
    }
}

void runProgramC() {
    std::cout << "Insert Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-C.txt";
    std::ifstream inFile;

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     */
    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    insertSort(data, n);

    std::ofstream outFile;
    outFile.open("iesire-C.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}


/** Merge Sort  */
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int* data, int l, int r) {
    if (l >= r) {
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(data,l,m);
    mergeSort(data,m+1,r);
    merge(data,l,m,r);
}
void runProgramD() {
    std::cout << "Merge Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-D.txt";
    std::ifstream inFile;

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     */
    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    mergeSort(data, 0, n-1);

    std::ofstream outFile;
    outFile.open("iesire-D.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}

/** Heap Sort  */
void buildHeap(int* data, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l] > data[largest])
        largest = l;

    if (r < n && data[r] > data[largest])
        largest = r;

    if (largest != i) {
        change(&data[i], &data[largest]);

        buildHeap(data, n, largest);
    }
}
void heapSort(int* data, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        buildHeap(data, n, i);

    for (int i = n - 1; i > 0; i--) {
        change(&data[0], &data[i]);

        buildHeap(data, i, 0);
    }
}

void runProgramE() {
    std::cout << "Heap sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-E.txt";
    std::ifstream inFile;

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     */
    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    heapSort(data, n);

    std::ofstream outFile;
    outFile.open("iesire-E.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();

}

/** Counting Sort */
void countingSort(int* data, int length) {
    int count[1000] = {0};
    int i;
    int result[length];

    for (i = 0; i < length; i++) {
        count[data[i]]++;
    }

    for (i = 1; i <= 1000; ++i) {
        count[i] += count[i - 1];
    }

    for (i = 0; data[i]; ++i) {
        result[count[data[i]] - 1] = data[i];
        count[data[i]]--;
    }
    for(i = 0; i < length; i++) {
        data[i] = result[i];
    }
}
void runProgramF() {
    std::cout << "Counting Sort. Limit: 1000" << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-F.txt";
    std::ifstream inFile;

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     */
    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    countingSort(data, n);

    std::ofstream outFile;
    outFile.open("iesire-F.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}

/** Radix Sort */
void countSortByDigit(int* arr, int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;


    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
int getMax(const int *data, int n) {
    int i, max = data[0];
    for (i = 1; i < n; i++) {
        if (max < data[i]) {
            max = data[i];
        }
    }

    return max;
}
void radixSort(int* data, int n) {
    int m = getMax(data, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortByDigit(data, n, exp);
}
void runProgramG() {
    std::cout << "Radix Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-G.txt";
    std::ifstream inFile;

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     */
    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    radixSort(data, n);

    std::ofstream outFile;
    outFile.open("iesire-G.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}

int main() {
    char programNo;
    do {
        programNo = '0';
        std::cout << "Program [1]: Suma cifrelor." << std::endl;
        std::cout << "Program [2]: Numarul de cifre." << std::endl;
        std::cout << "Program [3]: Oglinditul lui N." << std::endl;
        std::cout << "Program [4]: Verificare Palindrom." << std::endl;
        std::cout << "Program [5]: Verificare numar prim." << std::endl;
        std::cout << "Program [6|7]: Descompunere factori primi & divizori proprii." << std::endl;
        std::cout << "Program [8]: Algoritmul lui Euclid" << std::endl;
        std::cout << "Program [9]: Fibonacci" << std::endl;
        std::cout << "Program [A]: Bubble sort. " << std::endl;
        std::cout << "Program [B]: Quick Sort. " << std::endl;
        std::cout << "Program [C]: Insert Sort." << std::endl;
        std::cout << "Program [D]: Merge Sort." << std::endl;
        std::cout << "Program [E]: Heap Sort. " << std::endl;
        std::cout << "Program [F]: Counting Sort. " << std::endl;
        std::cout << "Program [G]: Radix Sort. " << std::endl;
        std::cout << "Alege un program [1-9A-G] 0 - to exit: " << std::endl;
        std::cin >> programNo;

        switch (programNo) {
            case '1' :
                runProgram1();
                break;
            case '2' :
                runProgram2();
                break;
            case '3' :
                runProgram3();
                break;
            case '4' :
                runProgram4();
                break;
            case '5' :
                runProgram5();
                break;
            case '6' :
            case '7' :
                runProgram6();
                break;
            case '8':
                runProgram8();
                break;
            case '9':
                runProgram9();
                break;
            case 'a' :
            case 'A' :
                runProgramA();
                break;
            case 'b' :
            case 'B' :
                runProgramB();
                break;
            case 'c' :
            case 'C' :
                runProgramC();
                break;
            case 'd' :
            case 'D' :
                runProgramD();
                break;
            case 'e' :
            case 'E' :
                runProgramE();
                break;
            case 'f' :
            case 'F' :
                runProgramF();
                break;
            case 'g' :
            case 'G' :
                runProgramG();
                break;
            case '0' :
                std::cout << "Iesire.";
                break;
            default:
                std::cout << "Intrare invalida!" << std::endl;
        }
        std::cout << "Apasa orice tasta pentru a continua...";
        getchar();
        getchar();
    } while (programNo != '0');

    return 0;
}
