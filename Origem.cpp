#include  <iostream>
using  namespace std;

class Horario {
public:
    int horaIni;
    int minIni;
    int segIni;

    int hora;
    int min;
    int seg;


    int x = 0; //segundos
    int y = 0; // minutos
    int w = 0; // horas
    int d = 0; // dias
    

    int calcSeg(){

        if((seg + segIni) >= 60){
            y = (seg + segIni) / 60; // minutos
            x = (seg + segIni) % 60; // segundos
            calcMin(y);
            return x;
        }
        else {
            x = seg + segIni; // segundos
            calcMin(y);
            return x;
        }
    }

    int calcMin(int &y){

        min += y;

        if((min + minIni)>= 60){
            w = (min + minIni) / 60; //horas
            y = (min + minIni) % 60; // minutos
            calcHoras(w);
            return y;
        }
        else {
            y = min + minIni; // minutos
            calcHoras(w);
            return y;
        }


    }

    int calcHoras(int &w){
        hora += w;
        {
            w = hora + horaIni;

            if(w >= 24) {
                d = w / 24;
                w %= 24;
                calcDia(d);
                return w;
            }
            else {
                return w;
            }
        }

    }

    int calcDia(int &d) {

        return d;
    }

   

    void getCalc(){
        
        calcSeg();
       
        cout <<  d << " dias " << w << " horas " << y << " minutos " << x << " segundos " << endl;
    }


};



int main(){
    int horaIni;
    int minIni;
    int segIni;
        

    int hora = 0;
    int min = 0;
    int seg = 0;


        cout << "Digite o valor inicial do relogio: Horas minutos Segundos\n";
        cin >> horaIni >> minIni >> segIni;

        cout << "Digite os valores que quer incrementar ao relogio: Horas minutos segundos\n";
        cin >> hora >>min >> seg;
        cout << "\n";

        Horario x = {horaIni,minIni,segIni,hora,min,seg};

        x.getCalc();

   
        return 0;
}

	
