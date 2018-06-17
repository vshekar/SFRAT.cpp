// Go.h


#ifndef __GO_H__
#define __GO_H__
#include"models/FTModel.h"


using namespace std;

class GO: public FTModel {
public:
    GO();
    GO(vector<float> *d);
    float MLE(float b);
    void run();
    void MVF();
    void MVF_inv();
    void MTTF();
    void FI();
    void R();

protected:
    float a_MLE;
    float b_MLE;
    vector<float> mvf;
    vector<float> cumuFailTimes;
    vector<float> mttf;
    vector<float> fi;
    vector<float> r;
};
#endif
