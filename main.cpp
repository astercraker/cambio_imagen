#include <iostream>
#include "CImg.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <ctype.h>
#include "ConvertImageToArray.h"
#include "ChangeComponent.cpp"


using namespace std;
using namespace cimg_library;

class CISmatrix{
    public:

       // CISmatrix(int N, int M, int w);
        virtual void windowTourAverage(int _N, int w) =0;
        virtual void windowTourMax(int _N, int w)=0;

        int lenVector(int _N, int _w){
            cout<<"calcular len con "<<_N<<" y "<<_w<<endl;
            return pow(floor(_N/_w),2);
        }
};

class RGB_CISmatrix: public CISmatrix {
    private:
        int N;
        int m;
        int w;
        float V;
        vector<int> vecCalc;
        vector<vector< vector<int> >> vect;
    public:
        RGB_CISmatrix(vector<vector< vector<int> >> _vect, int _w, int _V, char type){
            N = _vect.size();//tam matriz
            m = 3;//num canales
            w = _w;//tam ventana
            V = _V;
            vector<int> vx(lenVector(N,w),0);
            vecCalc = vx;
            vect = _vect;
            switch (type)
            {
            case 'a'://average
                windowTourAverage(N, w);
                break;
            case 'm'://max
                windowTourMax(N, w);
                break;
            default:
                break;
            }
    }

    int getChannels(){
        return m;
    }

    float getV(){
        return V;
    }

    int getValueD(float D){
        if(D>getV())
            return 1;
        else{
            if(D== getV())
                return 0;
            else
                return -1;
        }
    }

        void windowTourAverage(int _N, int _W){
       //     cout<<"windTourAV con N="<<_N<<" y _W="<<_W<<endl;
       //     cout<<"vecCalc es de "<<vecCalc.size()<<endl;
           vector< vector< vector<int> > > vectTmp = vector< vector< vector<int> > > (_W, vector<vector<int>> (_W));
        //    cout<<"**vectTmp.size()="<<vectTmp.size()<<endl;
            int cont = 0;

           int actual_row = 0;
           int actual_col = 0;
         //   cout<<"_N="<<_N<<endl;
            while(actual_row < _N && actual_col < _N){
         //       cout<<"While. actual_row="<<actual_col<<" y actual_col="<<actual_col<<endl;
                int row = 0;
                int column = 0;
                for(int i=actual_row; i<(actual_row+_W); i++){
           //         cout<<"for1... row ahora tiene "<<row<<" y column "<<column<<endl;
            //        cout<<"1er for, i="<<i<<" i<"<<(actual_row+_W)<<endl;
                    for(int j=actual_col; j<(actual_col+_W); j++){
             //           cout<<"2do for, j="<<j<<" j<"<<(actual_col+_W)<<endl;
             //           cout<<"vect en vect[i][j].size()="<<(vect[i][j].size())<<endl;
                        vectTmp[row][column]=vect[i][j];
                       column= column +1;
             //           cout<<"column ahora tiene "<<column<<endl;

                    }

                    row = row + 1;
                    column = 0;
            //        cout<<"row ahora tiene "<<row<<" y column "<<column<<endl;
                }

                actual_col=actual_col + _W;
                if(actual_col == _N){
                    actual_col = 0;
                    actual_row=actual_row + _W;
                }
cout<<"++++++++ Ver ventana a mandar:"<<endl;
                for (int i = 0; i < vectTmp.size(); i++)
        {
            for (int j = 0; j < vectTmp[i].size(); j++)
            {
                for (int k = 0; k < vectTmp[i][j].size(); k++)
                {
                    cout << "["<<i<<"]["<<j<<"]["<<k<<"]"<<vectTmp[i][j][k] << " ";
                }
            }
            cout << endl;
        }
        cout<<"========Fin de ver ventana a mandar:"<<endl;

                cout<<"----------"<<actual_row<<" y "<<actual_col<<"------"<<endl;
            //ChannelAverage objTemp=ChannelAverage(vectTmp, _W,_W,2);
            ChannelAverage objTemp=ChannelAverage(vectTmp, _W,_W,getChannels());
            cout<<"obtengo:"<<objTemp.Dcalc()<<endl;
            vecCalc[cont++] = getValueD(objTemp.Dcalc());
            }
            //mostrar contenido vector cambios
            cout<<"Resultados="<<endl;
            for(int a=0; a<vecCalc.size(); a++){
                cout<<"["<<a<<"]"<<vecCalc[a]<<endl;
            }
        }

        void windowTourMax(int _N, int _W){
            //     cout<<"windTourAV con N="<<_N<<" y _W="<<_W<<endl;
       //     cout<<"vecCalc es de "<<vecCalc.size()<<endl;
           vector< vector< vector<int> > > vectTmp = vector< vector< vector<int> > > (_W, vector<vector<int>> (_W));
        //    cout<<"**vectTmp.size()="<<vectTmp.size()<<endl;
            int cont = 0;

           int actual_row = 0;
           int actual_col = 0;
         //   cout<<"_N="<<_N<<endl;
            while(actual_row < _N && actual_col < _N){
         //       cout<<"While. actual_row="<<actual_col<<" y actual_col="<<actual_col<<endl;
                int row = 0;
                int column = 0;
                for(int i=actual_row; i<(actual_row+_W); i++){
           //         cout<<"for1... row ahora tiene "<<row<<" y column "<<column<<endl;
            //        cout<<"1er for, i="<<i<<" i<"<<(actual_row+_W)<<endl;
                    for(int j=actual_col; j<(actual_col+_W); j++){
             //           cout<<"2do for, j="<<j<<" j<"<<(actual_col+_W)<<endl;
             //           cout<<"vect en vect[i][j].size()="<<(vect[i][j].size())<<endl;
                        vectTmp[row][column]=vect[i][j];
                       column= column +1;
             //           cout<<"column ahora tiene "<<column<<endl;

                    }

                    row = row + 1;
                    column = 0;
            //        cout<<"row ahora tiene "<<row<<" y column "<<column<<endl;
                }

                actual_col=actual_col + _W;
                if(actual_col == _N){
                    actual_col = 0;
                    actual_row=actual_row + _W;
                }
cout<<"++++++++ Ver ventana a mandar:"<<endl;
                for (int i = 0; i < vectTmp.size(); i++)
        {
            for (int j = 0; j < vectTmp[i].size(); j++)
            {
                for (int k = 0; k < vectTmp[i][j].size(); k++)
                {
                    cout << "["<<i<<"]["<<j<<"]["<<k<<"]"<<vectTmp[i][j][k] << " ";
                }
            }
            cout << endl;
        }
        cout<<"========Fin de ver ventana a mandar:"<<endl;

                cout<<"----------"<<actual_row<<" y "<<actual_col<<"------"<<endl;
            //ChannelAverage objTemp=ChannelAverage(vectTmp, _W,_W,2);
            ChannelMax objTemp=ChannelMax(vectTmp, _W,_W,getChannels());
            cout<<"obtengo:"<<objTemp.Dcalc()<<endl;
            vecCalc[cont++] = getValueD(objTemp.Dcalc());
            }
            //mostrar contenido vector cambios
            cout<<"Resultados="<<endl;
            for(int a=0; a<vecCalc.size(); a++){
                cout<<"["<<a<<"]"<<vecCalc[a]<<endl;
            }
        }

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
        cout << "Verifique que ha ingresado la ruta de la imagen de forma correcta e intente nuevamente";
    }
    else
    {
        filename.erase(std::remove_if(filename.begin(), filename.end(), ::isspace), filename.end());

        CImg<unsigned char> src(filename.c_str());

        ConvertImageToArray converted;
        vector<vector< vector<int> >> vect = converted.Procesing(src);

        for (int i = 0; i < vect.size(); i++)
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                for (int k = 0; k < vect[i][j].size(); k++)
                {
                    cout << "["<<i<<"]["<<j<<"]["<<k<<"]"<<vect[i][j][k] << " ";
                }
            }
            cout << endl;
        }

        cout<<"*********AVERAGE**********"<<endl;//matriz, tamVentana, factorCambios, tipoMedia
        RGB_CISmatrix objTestAverage1 = RGB_CISmatrix(vect,4,12,'a');
        cout<<"*********MAX**********"<<endl;
        RGB_CISmatrix objTestMax2 = RGB_CISmatrix(vect,4,12,'m');
        cout<<"*********END**********"<<endl;
    }

    return 0;
}
