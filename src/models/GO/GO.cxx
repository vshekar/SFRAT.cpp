// GO.cxx
#include"models/GO/GO.h"
#include<vector>
#include<map>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

GO::GO():FTModel(){}

GO::GO(vector<float> *d):FTModel(d){cout << "This is GO class\n";}

void GO::run(){
    //a_MLE and b_MLE are filled here

    
}

float GO::MLE(float b){
   return ((this->totalT*this->lastT*exp(-b*this->lastT))/(1-exp(-b*this->lastT)))+this->totalT - this->vecLen/b; 
}

void GO::MVF(){

    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->mvf.push_back(this->a_MLE*(1 - exp(-this->b_MLE * (*it) ))) ;

    }
     
}

void GO::MVF_inv(){
    for(auto it = this->fn.begin(); it < this->fn.end(); it++){
        this->cumuFailTimes.push_back(-(log((this->a_MLE - *it)/this->a_MLE))/this->b_MLE);
    }

    float numPredPoints = floor(this->a_MLE) - (this->fn.at(0) - 1);
    

}

void GO::MTTF(){
    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->mttf.push_back(1/(this->a_MLE*this->b_MLE*exp(-this->b_MLE*(*it))));
        
        }

}

void GO::FI(){
    
    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->fi.push_back(this->a_MLE*this->b_MLE*exp(-this->b_MLE*(*it))) ;
        
        }
}

void GO::R(){
    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->r.push_back(-this->b_MLE*(*it)) ;
        
        }

}

void GO::lnL(){
    float firstSumTerm = 0;
    for(int i=0; i < this->vecLen; i++){
        firstSumTerm += -this->b_MLE*this->data->at(i);
    }
    
    this->lnl = -(this->a_MLE)*(1-exp(-this->b_MLE*this->lastT)) + this->vecLen*(log(this->a_MLE)) +this->vecLen*log(this->b_MLE) + firstSumTerm;
}

float GO::MVF_cont(float t){
    return(this->a_MLE*(1-exp(-this->b_MLE*t)));
}

