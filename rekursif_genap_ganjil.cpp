#include <iostream>

void genap_ganjil(int _first, int _end, bool mode){
    if(mode==1){
        if(_first<_end){
            if(_first%2==0)
                std::cout<<_first<<" adalah GENAP"<<std::endl;

            if(_first==_end)
                std::cout<<"Selesai!\n";
            else
                genap_ganjil(_first+1,_end,1);
        }else{
            if(_first%2==0)
                std::cout<<_first<<" adalah GENAP"<<std::endl;

            if(_first==_end)
                std::cout<<"Selesai!\n";
            else
                genap_ganjil(_first-1,_end,1);
        }
    }else{
        if(_first<_end){
            if(_first%2!=0)
                std::cout<<_first<<" adalah GANJIL"<<std::endl;

            if(_first==_end)
                std::cout<<"Selesai!\n";
            else
                genap_ganjil(_first+1,_end,0);
        }else{
            if(_first%2!=0)
                std::cout<<_first<<" adalah GANJIL"<<std::endl;

            if(_first==_end)
                std::cout<<"Selesai!\n";
            else
                genap_ganjil(_first-1,_end,0);
        }
    }
}

int main(void){
    int start, stop, mode;

    std::cout<<"Masukkan nilai mulai : ";
    std::cin>>start;
    std::cout<<"Masukkan nilai ahir : ";
    std::cin>>stop;
    std::cout<<"Masukkan (1=genap/0=ganjil) : ";
    std::cin>>mode;

    std::cout<<std::endl;
    genap_ganjil(start,stop,mode);
    return 0;
}