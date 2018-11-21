#include <iostream>

void genap_ganjil(int _first, int _end){
    int temp=_first;

    if(x==0) std::cout<<"Selesai!\n";
    else{
        if(temp<=_end) temp++;
        else{
            if(temp%2==0)
                std::cout<<temp<<" adalah Genap\n";
            else
                std::cout<<temp<<" adalah Ganjil\n";
            genap_ganjil(_first,_end-1);
        }
    }
}

int main(void){
    genap_ganjil(1,10);
    return 0;
}