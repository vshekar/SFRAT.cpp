// Go.h


#ifndef __GO_H__
#define __GO_H__
#include"models/FTModel.h"


using namespace std;

class GO: public FTModel {
public:
    GO();
    GO(vector<float> *d);
    virtual ~GO();
    float MLE(float b);
    void run();
    void lnL();
    void MVF();
    void MVF_inv();
    void MTTF();
    void FI();
    float MVF_cont(float t);
    float R_delta(float cur_time, float delta);
    void R_growth(float delta);
    float R_MLE_root(float cur_time, float delta, float reliability);
    void target_T();
    float OR_CC(float c1, float c2, float c3);
    float cost(float c1, float c2, float c3, float t, float t_lifecycle);
    float OR_RC(float x, float R);

    void R();

protected:
    float a_MLE;
    float b_MLE;
    vector<float> mvf;
    vector<float> cumuFailTimes;
    vector<float> mttf;
    vector<float> fi;
    vector<float> r;
    vector<float> rel_growth;
    float lnl;
};
#endif
