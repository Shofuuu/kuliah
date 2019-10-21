using System;

namespace Operator{
    class Program{
        static void Main(string[] args){
            int[] data = new int[20];
            int a = 10, b = 6;
            bool b1 = true, b2 = false;

            data[0] = a + b;
            data[1] = a - b;
            data[2] = a * b;
            data[3] = a / b;
            data[4] = a % b;

            b = 0xf1;
            data[5] = b >> 2;

            a = 4;
            data[6] = a;
            a++;
            data[7] = a;

            b = 4;
            data[8] = b;
            ++b;
            data[9] = b;

            a = 10;
            b = 11;
            data[10] = Convert.ToInt32(a<b);
            data[11] = Convert.ToInt32(a<=b);
            data[12] = Convert.ToInt32(a!=b);
            data[13] = Convert.ToInt32(a == b);
            data[14] = Convert.ToInt32(a >= b);
            data[15] = Convert.ToInt32(a > b);

            data[16] = Convert.ToInt32(b1&b2);
            data[17] = Convert.ToInt32((!b1&b2));
            data[18] = Convert.ToInt32(b1|b2);
            data[19] = Convert.ToInt32(b1^b2);

            for(int x=0;x<20;x++){
                if(x == 4 || x == 5 || x == 7 || x == 9 || x == 15 || x == 19) Console.WriteLine("data["+x+"] = "+data[x]+"\n");
                else Console.WriteLine("data["+x+"] = "+data[x]);
            }

            if(Int32.Parse(args[0]) >= Int32.Parse(args[1]))
                Console.WriteLine("First is bigger! --> " + Int32.Parse(args[0]) + "\n");
            else
                Console.WriteLine("Second is bigger! --> " + Int32.Parse(args[1]) + "\n");

            if(Int32.Parse(args[0]) >= Int32.Parse(args[1])){
                Console.WriteLine("First is bigger! --> " + Int32.Parse(args[0]));

                if(Int32.Parse(args[0]) % 2 == 0) Console.WriteLine("EVEN!" + "\n");
                else Console.WriteLine("ODD!" + "\n");
            }else{
                Console.WriteLine("Second is bigger! --> " + Int32.Parse(args[1]));

                if(Int32.Parse(args[1]) % 2 == 0) Console.WriteLine("EVEN!" + "\n");
                else Console.WriteLine("ODD!" + "\n");
            }

            switch(Int32.Parse(args[2])){
                case 1: Console.WriteLine("SENIN"); break;
                case 2: Console.WriteLine("SELASA"); break;
                case 3: Console.WriteLine("RABU"); break;
                case 4: Console.WriteLine("KAMIS"); break;
                case 5: Console.WriteLine("JUM'AT"); break;
                case 6: Console.WriteLine("SABTU"); break;
                case 7: Console.WriteLine("MINGGU"); break;
                default: Console.WriteLine("range (1-7)!"); break;
            }
        }
    }
}
