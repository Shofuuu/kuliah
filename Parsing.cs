using System;

namespace Parsing{
    class Program{

        static decimal[] ParseValue(string data){
            string tmp = "";
            decimal cnv = 0.0M;
            decimal[] dat = new decimal[255];
            int index = 0;
            bool stat = false;

            Int16[] key_table = new Int16[9]{
                0x3a, 0x3b, 0x2c,
                0x2a, 0x25, 0x23,
                0x26, 0x2f, 0x24
            };

            for(int x=0;x<data.Length;x++){
                for(int z=0;z<9;z++){
                    if(data[x] != Convert.ToChar(key_table[z]))
                        stat = false;
                    else{
                        stat = true;
                        break;
                    }
                }

                if(stat != true){
                    tmp += data[x];
                }else{
                    cnv = Convert.ToDecimal(tmp);
                    tmp = "";
                    dat[index] = cnv;
                    index++;
                }
            }

            return dat;
        }

        static void Main(string[] args){
            decimal[] data = ParseValue(args[0]);
            //for(int x=0;x<3;x++)
            //    Console.WriteLine(data[0]);
            Console.WriteLine(data[0]);
        }
    }
}
