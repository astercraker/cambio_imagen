#include <iostream>
#include "CImg.h"
#include <typeinfo>

using namespace std;
using namespace cimg_library;

int main()
{
    string filename = "icon.jpg";
    CImg<unsigned char> src(filename.c_str());

    cout << typeid(src.data()).name() << endl;

    int width = src.width();
    int height = src.height();
    int canales = src.spectrum();
    cout << filename << endl;
    cout << width << "x" << height << " canales: " << canales << endl;
    int counter = 0;
    /*
    for (int r = 0; r < height; r++){
        for (int c = 0; c < width; c++){
            counter += 1;
            cout << "counter: " << counter
                 << " (" << r << "," << c << ") ="
                 << " R: " << (int)src(c,r,0,0)
                 << " G: " << (int)src(c,r,0,1)
                 << " B: " << (int)src(c,r,0,2) << endl;
        }
    }
    cout << "counter: " << counter;
    */
    return 0;
}

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
