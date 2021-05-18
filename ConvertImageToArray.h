#include <iostream>
#include "CImg.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
using namespace cimg_library;

class ConvertImageToArray{
    public:
        vector<vector<vector<int>>> Procesing(CImg<unsigned char> src){
            int width = src.width();
            int height = src.height();
            int canales = src.spectrum();

            vector<vector< vector<int> >> color_values = vector<vector< vector<int> >> (width, vector<vector<int> >(height));
            cout << width << "x" << height << " canales: " << canales << endl;
            int counter = 0;
            ofstream MyFile("rgb_values.txt");
            std::stringstream buffer;
            for (int r = 0; r < height; r++){
                for (int c = 0; c < width; c++){
                    counter += 1;
                    vector<int> channels;
                    for(int numChannel = 0; numChannel < canales; numChannel++){
                        channels.push_back((int)src(c,r,0,numChannel));
                    }
                    color_values[r][c] = channels;

                    buffer << "counter: " << counter << " (" << r << "," << c << ") =" << " R: " << (int)src(c,r,0,0) << " G: " << (int)src(c,r,0,1) << " B: " << (int)src(c,r,0,2) << " A: " << (int)src(c,r,0,3) << endl;
                }
            }
            MyFile << buffer.str();
            MyFile.close();
            return color_values;
        };
};
