#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

//Fungsi untuk melakukan permutasi pada suatu array integer berjumlah 4
void permuteNumbers (int array[4], int (*arrOfArr)[4]){
    int line = 0;
    int count = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    if (i != j && i != k && i != l && j != k && j != l && k != l){
                        arrOfArr[line][0] = array[i];
                        arrOfArr[line][1] = array[j];
                        arrOfArr[line][2] = array[k];
                        arrOfArr[line][3] = array[l];
                        line++;
                    }
                }
            }
        }
    }
}

//Fungsi untuk melakukan permutasi kepada array yang berisi operasi matematika
void permuteOp (char arrOfArr [64][3]){
    char array[4] = {'+', '-', '*', '/'};
    int line = 0;
    int count = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for (int k = 0; k < 4; k++){
                arrOfArr[line][0] = array[i];
                arrOfArr[line][1] = array[j];
                arrOfArr[line][2] = array[k];
                line++;
            }
        }
    }
}

//Fungsi untuk melakukan operasi
double performOperation(double num1, double num2, char op) {
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    if (op == '/') {
        if (num2 == 0) {
            return false;
        }
        else{
            return num1 / num2;
        }
    }
    return -1; // in case of invalid operator
}

//Fungsi untuk mencocokkan array
int checkArr(int arrBin[7]){
    int arr1[7] = {0, 0, 0, 0, 1, 1, 1};
    int arr2[7] = {0, 0, 0, 1, 0, 1, 1};
    int arr3[7] = {0, 0, 0, 1, 1, 0, 1};
    int arr4[7] = {0, 0, 1, 0, 0, 1 ,1};
    int arr5[7] = {0, 0, 1, 0, 1, 0, 1};
    bool valid = true;
    int i;

    for(i = 2; i < 7; i++){
        if(arrBin[i] != arr1[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        return 1;
    }
   valid = true;

   for( i = 2; i < 7; i++){
        if(arrBin[i] != arr2[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        return 2;
    }
   valid = true;

   for( i = 2; i < 7; i++){
        if(arrBin[i] != arr3[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        return 3;
    }
   valid = true;

   for( i = 2; i < 7; i++){
        if(arrBin[i] != arr4[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        return 4;
    }
   valid = true;

   for( i = 2; i < 7; i++){
        if(arrBin[i] != arr5[i]){
            valid = false;
            break;
        }
    }
    if(valid){
        return 5;
    }
    return -1;
}


//Fungsi untuk menghasilkan string yang sudah diubah dari postfix ke infix
string genPostFix (int arrNum[4], char arrOp[3], int arrBin[7]){
    int ret = checkArr(arrBin);
    string res = "";
    switch(ret){
        case 1:
            res += std::to_string(arrNum[0]) + " " + arrOp[2] + " " + "(" + std::to_string(arrNum[1]) + " " + arrOp[1] + " " + "(" + std::to_string(arrNum[2]) + " " + arrOp[0] + " " + std::to_string(arrNum[3]) + ")" + ")";
            break;
        case 2:
            res += std::to_string(arrNum[0]) + " " + arrOp[2] + " " + "(" + "(" + std::to_string(arrNum[1]) + " " + arrOp[0] + " " + std::to_string(arrNum[2]) + ")" + " " + arrOp[1] + " " + std::to_string(arrNum[3]) + ")";
            break;
            //a+((b+c)+d)
        case 3:
            res += "(" + std::to_string(arrNum[0]) + " " + arrOp[1] + " " + "(" + std::to_string(arrNum[1]) + " " + arrOp[0] + " " + std::to_string(arrNum[2]) + ")" + ")" + " " + arrOp[2] + " " + std::to_string(arrNum[3]);
            break;

        case 4:
            res += "(" + std::to_string(arrNum[0]) + " " + arrOp[0] + " " + std::to_string(arrNum[1]) + ")" + " " + arrOp[2] + " " + "(" + std::to_string(arrNum[2]) + " " + arrOp[1] + " " + std::to_string(arrNum[3]) + ")"; 
            break;
        case 5:
            res += "(";
            res += "(" + std::to_string(arrNum[0]) + " " + arrOp[0] + " " + std::to_string(arrNum[1]) + ")" + " " + arrOp[1] + " " + std::to_string(arrNum[2]) + ")" + " "+ arrOp[2] + " " + std::to_string(arrNum[3]);
            break;
    }
    return res;  
}

//Fungsi untuk melakukan perhitungan postfix
int postFix(int arrOfNum[24][4], std:: vector<string>& arrStr){
    int arrOfBin[5][7] = {{0, 0, 0, 0, 1, 1, 1}, 
                        {0, 0, 0, 1, 0, 1, 1},  
                        {0, 0, 0, 1, 1, 0, 1}, 
                        {0, 0, 1, 0, 0, 1 ,1},
                        {0, 0, 1, 0, 1, 0, 1}};
    char arrOp[64][3];
    int resultSum = 0;
    bool valid;

    permuteOp(arrOp);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 24; j++){
            for(int k = 0; k < 64; k++){
                int currNum = 0;
                int currOp = 0;
                std:: stack<double> stack;
                for(int l = 0; l < 7; l++){
                    if (arrOfBin[i][l] == 0){
                        stack.push(arrOfNum[j][currNum]);
                        currNum++;
                    }
                    else{
                        double num2 = stack.top(); stack.pop();
                        double num1 = stack.top(); stack.pop();
                        double result = performOperation(num1, num2, arrOp[k][currOp]);
                        stack.push(result);
                        currOp++;
                        if (l == 6) {
                            result = stack.top(); stack.pop();
                            if (result == 24){
                                arrStr.push_back(genPostFix(arrOfNum[j], arrOp[k], arrOfBin[i]));
                                resultSum++;
                            }
                        }
                    }
                }
            }
        }
    }
    if (resultSum > 0) {
        cout << resultSum << " " << "solutions found" << '\n';
    }
    else{
        cout << "Tidak ada solusi" << '\n';
    }
    for(int i = 0; i < arrStr.size(); i++){
        cout << arrStr[i] << "\n";
    }
    return resultSum;
}

//Fungsi untuk mengubah array of strings menjadi array of int
void converter(string arr[4], int arrNum[4]){
    for(int i = 0; i < 4; i++){
        if (arr[i] == "A"){
            arrNum[i] = 1;
        }
        if (arr[i] == "2"){
            arrNum[i] = 2;
        }
        if (arr[i] == "3"){
            arrNum[i] = 3;
        }
        if (arr[i] == "4"){
            arrNum[i] = 4;
        }
        if (arr[i] == "5"){
            arrNum[i] = 5;
        }
        if (arr[i] == "6"){
            arrNum[i] = 6;
        }
        if (arr[i] == "7"){
            arrNum[i] = 7;
        }
        if (arr[i] == "8"){
            arrNum[i] = 8;
        }
        if (arr[i] == "9"){
            arrNum[i] = 9;
        }
        if (arr[i] == "10"){
            arrNum[i] = 10;
        }
        if (arr[i] == "J"){
            arrNum[i] = 11;
        }
        if (arr[i] == "Q"){
            arrNum[i] = 12;
        }
        if (arr[i] == "K"){
            arrNum[i] = 13;
        }     
    }
    
}

//Fungsi untuk mengubah array of int menjadi array of string
void converterKartu(int arrNum[4], string arr[4]){
    for(int i = 0; i < 4; i++){
        if (arrNum[i] == 1){
            arr[i] = "A";
        }
        if (arrNum[i] == 2){
            arr[i] = "2";
        }
        if (arrNum[i] == 3){
            arr[i] = "3";
        }
        if (arrNum[i] == 4){
            arr[i] = "4";
        }
        if (arrNum[i] == 5){
            arr[i] = "5";
        }
        if (arrNum[i] == 6){
            arr[i] = "6";
        }
        if (arrNum[i] == 7){
            arr[i] = "7";
        }
        if (arrNum[i] == 8){
            arr[i] = "8";
        }
        if (arrNum[i] == 9){
            arr[i] = "9";
        }
        if (arrNum[i] == 10){
            arr[i] = "10";
        }
        if (arrNum[i] == 11){
            arr[i] = "J";
        }
        if (arrNum[i] == 12){
            arr[i] = "Q";
        }
        if (arrNum[i] == 13){
            arr[i] = "K";
        }     
    }
    
}

//Fungsi untuk menulis output dalam suatu file yang akan dibuat
void writeToFile(string kartu[4], int solusi, vector<string>& arrStr, double time){
    string namaFile;
    cout << "Nama file yang diinginkan: ";
    cin >> namaFile;
    
    ofstream outFile;
    outFile.open("./test/" + namaFile);
   
    outFile << "Kartu: " << kartu[0] << " " << kartu[1] << " " << kartu[2] << " " << kartu[3] << std::endl;
    if (solusi > 0){
        outFile << solusi << " solutions found" << std::endl;
    }
    else{
        outFile << "Tidak ada solusi" << std::endl;
    }
    for(int i = 0; i < arrStr.size(); i++){
        outFile << arrStr[i] << "\n";
    }
    outFile << "Runtime: " << time << " detik" << std::endl;

    // Close the file
    outFile.close();

}
    