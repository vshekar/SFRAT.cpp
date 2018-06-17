//Model.h


#ifndef __MODEL_H__
#define __MODEL_H__
#include<vector>

using namespace std;

class Model{
public:
    Model();
    Model(vector<float> *d);

protected:
    vector<float> *data;
};



#endif