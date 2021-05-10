#include <iostream>
#include "CImg.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
using namespace cimg_library;

struct Color
{
    int red = 0;
    int blue = 0;
    int green = 0;
    int alpha = 0;
};
class ConvertImageToArray{
    public:
        vector<vector<Color>> Procesing(CImg<unsigned char> src){
            int width = src.width();
            int height = src.height();
            int canales = src.spectrum();

            vector<vector<Color>> rgbs_values = vector<vector<Color>> (width, vector<Color>(height));;
            cout << width << "x" << height << " canales: " << canales << endl;
            int counter = 0;
            ofstream MyFile("rgb_values.txt");
            std::stringstream buffer;
            for (int r = 0; r < height; r++){
                for (int c = 0; c < width; c++){
                    counter += 1;
                    Color color = {(int)src(c,r,0,0), (int)src(c,r,0,1), (int)src(c,r,0,2), (int)src(c,r,0,3)};
                    rgbs_values[r][c] = color;
                    buffer << "counter: " << counter << " (" << r << "," << c << ") =" << " R: " << (int)src(c,r,0,0) << " G: " << (int)src(c,r,0,1) << " B: " << (int)src(c,r,0,2) << " A: " << (int)src(c,r,0,3) << endl;
                }
            }
            MyFile << buffer.str();
            MyFile.close();
            return rgbs_values;
        };
};

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

    string filename = "sword_16x16.png";
    CImg<unsigned char> src(filename.c_str());

    ConvertImageToArray converted;
    vector<vector<Color>> vect = converted.Procesing(src);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j].blue << " ";
        }
        cout << endl;
    }

    return 0;
}
