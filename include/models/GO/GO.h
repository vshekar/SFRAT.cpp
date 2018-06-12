// Go.h


#ifndef __GO_H__
#define __GO_H__
#include<vector>

using namespace std;

class GO {
public:
    GO();
    GO(vector<float> *d);

protected:
    vector<float> *data;
};
#endif
