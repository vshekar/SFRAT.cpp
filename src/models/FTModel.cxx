#include"models/FTModel.h"

using namespace std;


FTModel::FTModel(){}


FTModel::FTModel(vector<float> *d):Model(d){
    this->vecLen = this->data->size();
    this->lastT = this->data->at(this->vecLen - 1);
    this->totalT = 0;
    int count = 0;
    for(auto it = this->data->begin(); it < this->data->end(); it++){
        this->totalT += *it;
        this->fn->push_back(count);
        count++; 
    }

}