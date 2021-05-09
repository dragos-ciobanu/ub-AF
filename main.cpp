#include <iostream>
#include <fstream>

void change(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void runProgramOne() {
    std::cout << "Cautare binara." << std::endl;
    int data[100], n, i, search;

    std::string inFileName = "date-intrare/date-1.txt";
    std::ifstream inFile;

//    std::ifstream inFile.open(inFileName.c_str());;
//    std::ofstream outFile;
//    outFile.open("example.txt");
//    outFile << "Writing this to a file.\n";
//    outFile.close();

    /*
     * Structura fisier
     * numar-elemente
     * el1 el2 ... eln
     * numar-de-cautat
     */
    inFile.open(inFileName.c_str());

    if (inFile.is_open()) {
        inFile >> n;
        for (i = 0; i < n; i++) {
            inFile >> data[i];
        }
        inFile >> search;
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }





}
/* BUBBLE SORT ALGORITHM */
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
/* BUBBLE SORT PROGRAM */
void runProgramTwo() {
    std::cout << "Bubble Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-2.txt";
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
    outFile.open("iesire-2.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}
/* QUICK SORT ALGORITHM */
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
/* QUICK SORT PROGRAM */
void runProgramThree() {
    std::cout << "Quick Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-3.txt";
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
    outFile.open("iesire-3.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}
/* Insert Sort Algorithm */
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
/* Insert Sort Program */
void runProgramFour() {
    std::cout << "Insert Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-4.txt";
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
    outFile.open("iesire-4.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}
/* Merge Sort Algorithm */
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
/* MergeSort Program */
void runProgramFive() {
    std::cout << "Merge Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-5.txt";
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
    outFile.open("iesire-5.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}
/* Heap Sort  */
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
/* Heap Sort Program */
void runProgramSix() {
    std::cout << "Heap sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-6.txt";
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
    outFile.open("iesire-6.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();

}
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
void runProgramSeven() {
    std::cout << "Counting Sort. Limit: 1000" << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-7.txt";
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
    outFile.open("iesire-7.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}
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
void runProgramEight() {
    std::cout << "Radix Sort." << std::endl;
    int data[100], n = 0;
    std::string inFileName = "date-intrare/date-8.txt";
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
    outFile.open("iesire-8.txt");
    for (i = 0; i < n; i++)
        outFile << data[i] << " ";
    outFile << std::endl;
    outFile.close();
}

bool isCharInArray(char* arr, char el, int length) {
    for (int i=0; i < length;i++) {
        if (arr[i] == el)
            return true;
    }

    return false;
}

void runProgramNine() {
    std::cout << "Huffman." << std::endl;
    std::string inFileName = "date-intrare/date-9.txt";
    std::ifstream inFile;
    std::string data;

    inFile.open(inFileName.c_str());
    int i;
    if (inFile.is_open()) {
        std::string str;
        while (std::getline(inFile, str))
            data.append(str);
        inFile.close(); // CLose input file
    } else { //Error message
        std::cerr << "Fisierul " << inFileName << " nu exista" << std::endl;
    }

    int charCount = 0;
    char* characters;
    int* frequency;

    for (i = 0; i < data.length();i++) {
        if(isCharInArray(characters, data[i], charCount))
    }


    std::ofstream outFile;
    outFile.open("iesire-9.txt");
    outFile << data;
    outFile << std::endl;
    outFile.close();
}


int main() {
    char programNo;
    do {
        std::cout << "Program [1]: Cautare binara." << std::endl;
        std::cout << "Program [2]: Bubble sort. " << std::endl;
        std::cout << "Program [3]: Quick Sort. " << std::endl;
        std::cout << "Program [4]: Insert Sort." << std::endl;
        std::cout << "Program [5]: Merge Sort." << std::endl;
        std::cout << "Program [6]: Heap Sort. " << std::endl;
        std::cout << "Program [7]: Counting Sort. " << std::endl;
        std::cout << "Program [8]: Radix Sort. " << std::endl;
        std::cout << "Program [9]: Codificare Huffman. " << std::endl;
        std::cout << "Alege un program [1-9] 0 - to exit: " << std::endl;
        std::cin >> programNo;

        switch (programNo) {
            case '1' :
                runProgramOne();
                break;
            case '2' :
                runProgramTwo();
                break;
            case '3' :
                runProgramThree();
                break;
            case '4' :
                runProgramFour();
                break;
            case '5' :
                runProgramFive();
                break;
            case '6' :
                runProgramSix();
                break;
            case '7' :
                runProgramSeven();
                break;
            case '8' :
                runProgramEight();
                break;
            case '9' :
                runProgramNine();
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
