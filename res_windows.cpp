#include <iostream>
#define pause() char x;scanf("%c",&x)

double s=0,p=0,data[100];
void hitung(int max);

int main(int argc, char* argv[]){
	if(argc<2)
		std::cout<<"Kekurangan argumen!\nUsage\t: "<<argv[0]<<" [R1] [R2] [..]\n";
	else{
		for(int cp=1;cp<argc;cp++)
			data[cp]=atof(argv[cp]);
		
		std::cout<<"PERHITUNGAN RANGKAIAN RESISTOR\n\n";
		hitung(argc);

		std::cout<<"Hasil Perhitungan\nSeri\t: "<<s<<" ohm\n";
		std::cout<<"Pararel\t: "<<(1/p)<<" ohm\nTotal\t: "<<(s+(1/p))<<" ohm\n";
	}
	pause();
}

void hitung(int max){
	for(int range=1;range<max;range++){
		s+=data[range];
		if(data[range]!=0)
			p+=(1/data[range]);
		std::cout<<" R"<<range<<"\t: "<<data[range]<<" ohm\n";
	}
}