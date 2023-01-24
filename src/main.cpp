#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include <ctime>
#include <fstream>
#include "functions.cpp"
using namespace std;

int main (){
    int pil;
    cout << "Ketik 1 untuk memasukkan kartu\n" << "Ketik 2 untuk mengacak kartu\n";
    cin >> pil;
    if (pil == 1){
        bool valid = false;
        int arrNum[4];
        int arrOfNum[24][4];
        string arr[4];
        std:: vector<string> arrStr;
        while(!valid){
            cout << "Kartu (contoh input: A B C D): ";
            string input;
            string input1;
            string input2;
            string input3;
            int count = 0;
            cin >> input >> input1 >> input2 >> input3;
            if (input == "2"|| input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "8" || input == "9" || input == "10" || input == "A" || input == "J" || input == "Q" || input == "K"){
                count++;
                arr[0] = input;
            }
            if (input1 == "2"|| input1 == "3" || input1 == "4" || input1 == "5" || input1 == "6" || input1 == "7" || input1 == "8" || input1 == "9" || input1 == "10" || input1 == "A" || input1 == "J" || input1 == "Q" || input1 == "K"){
                count++;
                arr[1] = input1;
            }
            if (input2 == "2"|| input2 == "3" || input2 == "4" || input2 == "5" || input2 == "6" || input2 == "7" || input2 == "8" || input2 == "9" || input2 == "10" || input2 == "A" || input2 == "J" || input2 == "Q" || input2 == "K"){
                count++;
                arr[2] = input2;
            }
            if (input3 == "2"|| input3 == "3" || input3 == "4" || input3 == "5" || input3 == "6" || input3 == "7" || input3 == "8" || input3 == "9" || input3 == "10" || input3 == "A" || input3 == "J" || input3 == "Q" || input3 == "K"){
                count++;
                arr[3] = input3;
            }
            if(count == 4){
                valid = true;
            }
            else{
                cout << "Masukkan salah\n";
            }
        }
        clock_t start = clock();
        converter(arr, arrNum);
        permuteNumbers(arrNum, arrOfNum);
        int solusi = postFix(arrOfNum, arrStr);
        clock_t end = clock();
        double runtime = (double)(end - start) / CLOCKS_PER_SEC;
        std::cout << "Runtime: " << runtime << " detik" << std::endl;
        cout << "Apakah ingin menyimpan output di dalam file (y/n)\n";
        char pil;
        cin >> pil;
        while(pil != 'y' && pil != 'n'){
            cout << "Masukkan tidak valid, silahkan ulangi\n";
            cout << "Apakah ingin menyimpan output di dalam file (y/n)\n";
            cin >> pil;
        }
        if(pil == 'y'){
            writeToFile(arr, solusi, arrStr, runtime);
            return 0;
        }
        else{
            return 0;
        }
    }
    if (pil == 2){
        int arrNum[4];
        int arrOfNum[24][4];
        string kartu[4];
        std:: vector<string> arrStr;
        srand(time(0));
        arrNum[0] = rand() % 13 + 1;
        arrNum[1] = rand() % 13 + 1;
        arrNum[2] = rand() % 13 + 1;
        arrNum[3] = rand() % 13 + 1;
        converterKartu(arrNum, kartu);
        cout << "Hasil acak kartu: ";
        cout << kartu[0] << " " << kartu[1] << " " << kartu[2] << " " << kartu[3] << "\n";
        clock_t start = clock();
        permuteNumbers(arrNum, arrOfNum);
        int solusi = postFix(arrOfNum, arrStr);
        clock_t end = clock();
        double runtime = (double)(end - start) / CLOCKS_PER_SEC;
        std::cout << "Runtime: " << runtime << " detik" << std::endl;
        cout << "Apakah ingin menyimpan output di dalam file (y/n)\n";
        char pil;
        cin >> pil;
        while(pil != 'y' && pil != 'n'){
            cout << "Masukkan tidak valid, silahkan ulangi\n";
            cout << "Apakah ingin menyimpan output di dalam file (y/n)\n";
            cin >> pil;
        }
        if(pil == 'y'){
            writeToFile(kartu, solusi, arrStr, runtime);
            return 0;
        }
        else{
            return 0;
        }
    }
}