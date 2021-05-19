#include <iostream>
#include "CImg.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "ConvertImageToArray.h"
#include <stdlib.h>
#include <ctype.h>

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
    FILE *f = popen("zenity --file-selection --title=\"Escoge una imagen\" --file-filter=\'Image files (png,jpg,bmp) | *.png *.jpg *.bmp\' ", "r");
    string filename;
    char c;
    while(fread(&c,1,1,f)==1 && c!=EOF) {
        filename.push_back(c);
    }

    if(filename.length() == 0){
        cout << "No selecciono ningun archivo";
    }
    else
    {
        filename.erase(std::remove_if(filename.begin(), filename.end(), ::isspace), filename.end());

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

    }

    return 0;
}
