#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
using namespace std;

int Math(int R1, int R2,string command){
    int res;


    if (command == "ADD" || command == "SUB" || command == "MUL"|| command == "DIV")
    {
        // Arithmetic operations:
        if (command == "ADD")
        {
            res = R1+R2;
        }
        else if(command == "SUB"){
            res = R1-R2;
        }
        else if(command == "MUL"){
            res = R1*R2;
        }
        else if(command == "DIV"){
            res = R1/R2;
        }
        else {
            cout << "Error 1 \n";
        }
    }
    else if (command == "OR" || command == "AND" || command == "NOT" || command == "XOR")
    {
        //Logic operations:
        if (command == "OR")
        {
            res = R1|R2;
        }
        else if (command == "AND")
        {
            res = R1&R2;
        }
        else if (command == "NOT")
        {
            res = ~R1;
        }
        else if (command == "XOR")
        {
            res = R1^R2;
        }
        else {
            cout << "Error 2 \n";
        }
    }
    else if (command == "MOV")
    {
        if (command == "MOV")
        {
            R1 = R2;
        }
        else {
            cout << "Error 3 \n";
        }
    }
    else{cout << "Error: Unknown command\n";}
    return res;
}


int main(){

    int R1 = 0, R2 = 0, res = 0;
    string command;

    ifstream file("main.lou");

while (getline(file, command)) {
        istringstream iss(command);
        string operation;

        iss >> operation;
        if (operation == "NOT") {
            iss >> R1;
        } else {
            iss >> R1 >> R2;
        }

        res = Math(R1, R2, operation);
        cout << res << endl;
    }


    


}

