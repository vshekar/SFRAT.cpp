// MO.h


#ifndef __MO_H__
#define __MO_H__
#include"models/FTModel.h"


using namespace std;

class MO: public FTModel {
public:
    MO();
    MO(vector<float> *d);
    virtual ~MO();
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
