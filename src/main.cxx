// main.cpp
#include"models/GO/GO.h"
#include<iostream>
#include<vector>

using namespace std;


int main(){
    cout << "Test\n";
    vector<float> a;
    a.push_back(1.0);
    GO go(&a);
    return 0; 
}