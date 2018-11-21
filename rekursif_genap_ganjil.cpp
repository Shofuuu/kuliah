#include <iostream>

void genap_ganjil(int _first, int _end){
    if(_first%2==0)
        std::cout<<_first<<" adalah GENAP"<<std::endl;
    else
        std::cout<<_first<<" adalah GANJIL"<<std::endl;

    if(_first==_end)
        std::cout<<"Selesai!\n";
    else
        genap_ganjil(_first+1,_end);

}

int main(void){
    genap_ganjil(1,10);
    return 0;
}