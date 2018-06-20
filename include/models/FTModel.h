//FTModel.h


#ifndef __FTMODEL_H__
#define __FTMODEL_H__
#include"Model.h"
#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class FTModel: public Model{
public:
    FTModel();
    FTModel(vector<float> *d);
    virtual ~FTModel();
    virtual void run(){cout<<"FTModel derived class not implemented!\n";}
    virtual void lnL(){cout<<"FTModel derived class not implemented!\n";}
    virtual void MVF(){cout<<"FTModel derived class not implemented!\n";}
    virtual void MVF_inv(){cout<<"FTModel derived class not implemented!\n";}
    virtual void MTTF(){cout<<"FTModel derived class not implemented!\n";}
    virtual void FI(){cout<<"FTModel derived class not implemented!\n";}
    virtual float MVF_cont(float t){cout<<"FTModel derived class not implemented!\n"; return 0;}
    virtual float R_delta(float cur_time, float delta){cout<<"FTModel derived class not implemented!\n"; return 0;}
    virtual void R_growth(float delta){cout<<"FTModel derived class not implemented!\n";}
    virtual float R_MLE_root(float cur_time, float delta, float reliability){cout<<"FTModel derived class not implemented!\n";return 0;}
    virtual void target_T(){cout<<"FTModel derived class not implemented!\n";}
    virtual float OR_CC(float c1, float c2, float c3){cout<<"FTModel derived class not implemented!\n"; return 0;}
    virtual float cost(float c1, float c2, float c3, float t, float t_lifecycle){cout<<"FTModel derived class not implemented!\n";return 0;}
    virtual float OR_RC(float x, float R){cout<<"FTModel derived class not implemented!\n"; return 0;}



    virtual void R(){}






protected:
    int vecLen;
    float lastT;
    float totalT;
    vector<float> fn;
    map<string, float> params;
    
};



#endif
