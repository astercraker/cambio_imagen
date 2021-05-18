#include <iostream>
#include "CImg.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "ConvertImageToArray.h"

using namespace std;
using namespace cimg_library;

class CISmatrix{
    public:
    int N;
    int m;
    int w;
    float V;

    CISmatrix(int N, int M, int w);
    void windowTour(int _N, int _W){
    }
    int lenVector(int _N, int W){
    }
    float performVecCalc(){
    }
    int get_pixel(){
    }
    int get_ChannelPixel(){
    }
    void set_pixel(){
    }
};
CISmatrix::CISmatrix(int _N, int _M, int _w){
    N = _N;
    m = _M;
    w = _w;
};

class ChangesVector{
    public:
    int lenVector;
    float V;
    ChangesVector(float _V, float _lenVect);
};
ChangesVector::ChangesVector(float _V, float _lenVect){
    lenVector = _lenVect;
    V = _V;
};
int main()
{

    string filename = "sword_16x16.jpg";
    CImg<unsigned char> src(filename.c_str());

    ConvertImageToArray converted;
    vector<vector< vector<int> >> vect = converted.Procesing(src);
    cout << "Pixel Size: " << vect[0][0].size() << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j][0] << " ";
        }
        cout << endl;
    }

    return 0;
}
