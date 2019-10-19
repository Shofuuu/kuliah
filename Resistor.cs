using System;

namespace Resistor{
    class Program{
        static double[] parsingValue(string raw){
            double[] resistor = new double[100];
            string tmp = "";
            int counter = 0;

            raw = raw+=',';
            for(int x=0;x<raw.Length;x++){
                if(raw[x] != ',') tmp += raw[x];
                if(raw[x] == ','){
                    resistor[counter] = Int32.Parse(tmp);
                    counter++;
                    tmp="";
                }
            }

            return resistor;
        }
        static string removeChar(string raw, char ch){
            string filter = "";

            for(int x=0;x<raw.Length;x++)
                if(raw[x] != ch) filter += raw[x];

            return filter;
        }

        static void calculateValue(double[] value, bool mode){
            int notNull = 0;
            double calc = 0;

            for(notNull = 0; notNull<value.Length; notNull++) //set stop point
                if(value[notNull] == 0)
                    break;

            Console.Write("\n");
            if(mode == true){ // mode seri
                for(int x=0;x<notNull;x++){
                    calc += value[x];
                    Console.Write("─[" + value[x] + "R]─");
                }
                Console.WriteLine("\nHasil : " + calc);
            }else{ // mode pararel
                for(int x=0;x<notNull;x++){
                    calc += (1.0/value[x]);
                    if(x == 0)
                        Console.WriteLine("┌[" +value[x]+ "R]┐");
                    else if(x == (notNull-1))
                        Console.WriteLine("└[" +value[x]+ "R]┘");
                    else
                        Console.WriteLine("├[" +value[x]+ "R]┤");
                }
                Console.WriteLine("\nHasil : "+(1.0/calc));
            }
        }
        static void Main(){
            string param = "", opt = "";

            Console.WriteLine("--[ RESISTOR CALCULATOR ]--");
            Console.WriteLine("Type Resistor Value Separated by Comma");
            Console.Write("[INPUT] > ");
            param = Console.ReadLine();
            param = removeChar(param, ' ');

            while(true){
                Console.WriteLine("\nPilih Metode Kalkulasi : ");
                Console.WriteLine("1). Seri\n2). Pararel");
                Console.Write("[OPSI] > ");
                opt = Console.ReadLine();

                if(opt.ToLower().Equals("seri") || opt.Equals("1")){
                    calculateValue(parsingValue(param), true);
                    break;
                }else if(opt.ToLower().Equals("pararel") || opt.Equals("2")){
                    calculateValue(parsingValue(param), false);
                    break;
                }
            }

            Console.ReadKey();
        }
    }
}
