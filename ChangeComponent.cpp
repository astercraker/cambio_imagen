#include <iostream>
#include <vector>
using namespace std;

class ChangeComponent {
public:
    int width_W = 0;
    int height_W = 0;
    int channels_W = 0;
    vector< vector< vector<int> > > window;

    virtual float Lcalc() = 0;
    virtual float Hcalc() = 0;
    virtual float Dcalc() = 0;

    float media(){
        //Calcular la media
        vector<int> color;
        float pixelval = 0.0;
        float promedio_pixel;
        float media;
        float average_sum = 0.0;
        float denominator = 0.0;
        for (int i = 0; i < height_W; i++){
            for (int j= 0; j < width_W; j++){
                for (int k= 0; k < channels_W; k++){
                    pixelval = float((pixelval + window[i][j][k]));
                }
                promedio_pixel = float (pixelval / channels_W);
                //cout << promedio_pixel << "+++" << endl;
                denominator = denominator + 1.0;
                average_sum = average_sum + promedio_pixel;
                pixelval = 0.0;
                //cout << average_sum << endl;
            }
        }
        //cout << "=========================" << endl;
        //cout << average_sum << endl;
        media = average_sum / denominator;
        return media;
    }
};

class ChannelAverage: public ChangeComponent{
public:
    float Low;
    float High;

    ChannelAverage(vector< vector< vector<int> > > awindow, int width_V, int height_V, int channels_V){
        window = awindow;
        width_W = width_V;
        height_W = height_V;
        channels_W = channels_V;
    }

    float Lcalc(){
        int Lcount = 0;
        int L;
        float lamedia;
        float pixelval = 0.0;
        float promedio_pixel;
        lamedia = media();
        //Contar los que están por debajo de la media
        for (int i = 0; i < height_W; i++){
            for (int j= 0; j < width_W; j++){
                for (int k= 0; k < channels_W; k++){
                    pixelval = float((pixelval + window[i][j][k]));
                }
                promedio_pixel = float (pixelval / channels_W);
                if (promedio_pixel < lamedia){
                    Lcount++;
                }
                pixelval = 0.0;
            }
        }
        L = Lcount;
        Low = L;
        return L;
    }

    float Hcalc(){
        int Hcount = 0;
        int H;
        float lamedia;
        float pixelval = 0.0;
        float promedio_pixel;
        lamedia = media();
        //Contar los que están por debajo de la media
        for (int i = 0; i < height_W; i++){
            for (int j= 0; j < width_W; j++){
                for (int k= 0; k < channels_W; k++){
                    pixelval = float((pixelval + window[i][j][k]));
                }
                promedio_pixel = float (pixelval / channels_W);
                //cout << promedio_pixel << endl;
                if (promedio_pixel > lamedia){
                    Hcount ++;
                    //cout << Hcount << endl;
                }
                pixelval = 0.0;
            }
        }
        H = Hcount;
        High = H;
        return H;
    }
    float Dcalc(){
        int theL, theH;
        float Dcalc = 0.0;
        theL = Lcalc();
        theH = Hcalc();
        Dcalc = float ((theL + theH) / 2);
        return Dcalc;
    }
};

class ChannelMax: public ChangeComponent{
public:
    float Low;
    float High;

    ChannelMax(vector< vector< vector<int> > > awindow, int width_V, int height_V, int channels_V){
        window = awindow;
        width_W = width_V;
        height_W = height_V;
        channels_W = channels_V;
    }

    float Lcalc(){
        int Lcount = 0;
        int L;
        float lamedia;
        int pixelmax = 0;
        float promedio_pixel;
        lamedia = media();
        for (int i = 0; i < height_W; i++){
            for (int j= 0; j < width_W; j++){
                for (int k= 0; k < channels_W; k++){
                    if (window[i][j][k] >= pixelmax){
                        pixelmax = window[i][j][k];
                    }
                }
                //cout << pixelmax << endl;
                if (pixelmax < lamedia){
                    Lcount++;
                }
                pixelmax = 0.0;
            }
        }
        L = Lcount;
        Low = L;
        return L;
    }

    float Hcalc(){
        int Hcount = 0;
        int H;
        float lamedia;
        int pixelmax = 0;
        float promedio_pixel;
        lamedia = media();
        for (int i = 0; i < height_W; i++){
            for (int j= 0; j < width_W; j++){
                for (int k= 0; k < channels_W; k++){
                    if (window[i][j][k] >= pixelmax){
                        pixelmax = window[i][j][k];
                    }
                }
                //cout << pixelmax << endl;
                if (pixelmax < lamedia){
                    Hcount++;
                }
                pixelmax = 0.0;
            }
        }
        H = Hcount;
        High = H;
        return H;
    }

    float Dcalc(){
        int theL, theH;
        float Dcalc = 0.0;
        theL = Lcalc();
        theH = Hcalc();
        Dcalc = float ((theL + theH) / 2);
        return Dcalc;
    }
};
