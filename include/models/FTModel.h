//FTModel.h


#ifndef __FTMODEL_H__
#define __FTMODEL_H__
#include"Model.h"
#include<vector>
#include<string>
#include<map>

using namespace std;

class FTModel: public Model{
public:
    FTModel();
    FTModel(vector<float> *d);

protected:
    int vecLen;
    float lastT;
    float totalT;
    vector<float> fn;
    map<string, float> params;
    
};



#endif