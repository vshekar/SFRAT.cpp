// MO.cxx
#include"models/MO/MO.h"
#include<vector>
#include<map>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

MO::MO():FTModel(){}

MO::MO(vector<float> *d):FTModel(d){cout << "This is MO class\n";}

MO::~MO(){}

void MO::run(){
    //a_MLE and b_MLE are filled here

    
}

float MO::MLE(){
    //Calculating
}



void MO::MVF(){

    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->mvf.push_back(this->a_MLE*(1 - exp(-this->b_MLE * (*it) ))) ;

    }
     
}

void MO::MVF_inv(){
    for(auto it = this->fn.begin(); it < this->fn.end(); it++){
        this->cumuFailTimes.push_back(-(log((this->a_MLE - *it)/this->a_MLE))/this->b_MLE);
    }

    float numPredPoints = floor(this->a_MLE) - (this->fn.at(0) - 1);
    

}

void MO::MTTF(){
    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->mttf.push_back(1/(this->a_MLE*this->b_MLE*exp(-this->b_MLE*(*it))));
        
        }

}

void MO::FI(){
    
    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->fi.push_back(this->a_MLE*this->b_MLE*exp(-this->b_MLE*(*it))) ;
        
        }
}

void MO::R(){
    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->r.push_back(-this->b_MLE*(*it)) ;
        
        }

}

void MO::lnL(){
    float firstSumTerm = 0;
    for(int i=0; i < this->vecLen; i++){
        firstSumTerm += -this->b_MLE*this->data->at(i);
    }
    
    this->lnl = -(this->a_MLE)*(1-exp(-this->b_MLE*this->lastT)) + this->vecLen*(log(this->a_MLE)) +this->vecLen*log(this->b_MLE) + firstSumTerm;
}

float MO::MVF_cont(float t){
    return(this->a_MLE*(1-exp(-this->b_MLE*t)));
}

float MO::R_delta(float cur_time, float delta){
    return exp(-(this->MVF_cont(cur_time+delta) - this->MVF_cont(cur_time)));
}

float MO::R_MLE_root(float cur_time, float delta, float reliability){
    return reliability - exp(this->MVF_cont(cur_time) - this->MVF_cont(cur_time+delta));
}

void MO::R_growth(float delta){
    for(auto it = this->data->begin(); it< this->data->end(); it++){
        this->rel_growth.push_back(this->R_delta(*it, delta));
    }
}

float MO::OR_CC(float c1, float c2, float c3){
    float t_opt;
    if (this->a_MLE*this->b_MLE <=  (c3/(c2-c1))){
        t_opt = 0;
    }
    else{
        t_opt = (1/this->b_MLE)*log((this->a_MLE*this->b_MLE*(c2-c2))/c3);
    }
    return t_opt;
}

float MO::OR_RC(float x, float R){
    float s;
    s = (1/this->b_MLE)*((log(this->a_MLE*(1-exp(-this->b_MLE*x)))) - log(log(1/R)));
    return s;
}

float MO::cost(float c1, float c2, float c3, float t, float t_lifecycle){
    return (c1*this->MVF_cont(t) + c2*(this->MVF_cont(t_lifecycle) - this->MVF_cont(t)) + c3*t);
}

float MO::Target_T(float cur_time, float delta, float reliability){
    float current_rel = this->R_delta(cur_time, delta);
    float sol = 0;
    if(current_rel < reliability){

        float interval_left = cur_time;
        float interval_right = 2*interval_left;
        float local_rel = this->R_delta(interval_right, delta);

        float infinity = std::numeric_limits<float>::infinity();

        while(local_rel <= reliability){
            interval_right = 2*interval_right;
            if (local_rel == reliability)
                interval_right = 2.25*interval_right;
            if (interval_right >= infinity)
                break;
            local_rel = this->R_delta(interval_right, delta);
        }

        if(interval_right<infinity && local_rel<infinity){
            cout << "Not filling it out";
        }

    }

    return sol;
}
