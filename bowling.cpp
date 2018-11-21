#include <iostream>

int score[10];
float average(void){
    short sum=0;
    for(int x=0;x<10;x++)
        sum+=score[x]; // sum = sum+score[x];
    sum=sum/10;
    return sum;
}

int main(void){
    bool r;

    while(1){
        std::cout<<"Masukkan Score Bowling\n";
        for(int x=0;x<10;x++){
            std::cout<<" "<<x+1<<" VALUE\t: ";
            std::cin>>score[x];
        }
        std::cout<<"\nRata-Rata Score\t: "<<average()<<"\n";
        std::cout<<"\nUlangi? (1/0)\t: ";
        std::cin>>r;
        if(r!=1) break;
    }

    return 0;
}
