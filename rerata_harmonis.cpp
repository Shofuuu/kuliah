#include <iostream>

int score[2][100];
float average(int index){ return (2.0*score[0][index]*score[1][index])/(score[0][index]+score[1][index]); }

int main(void){
};
    int x=0;

    while(1){
        std::cout<<"Masukkan Data Nilai\n";
        while(1){
            std::cout<<" "<<x+1<<"). NILAI\t: ";
            std::cin>>score[0][x]>>score[1][x];
            if((score[0][x]+score[1][x])==0)
                exit(0);
            else{
                std::cout<<" Hasil\t: "<<average(x)<<"\n";
                x++;
            }
        }
    }

    return 0;
}
