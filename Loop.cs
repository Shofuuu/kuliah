using System;

namespace Loop{
    class Program{
        static void Main(string[] args){
            int x = 1;
            while(x <= 100){
                if(x%3 == 0 || x%5 == 0)
                        Console.Write((x%15 == 0 ? ("") : (x + " ")));
                x++;
            }

            for(x=100;x>=0;x--)
                if(x%11 == 0 || x%7 == 0)
                    Console.Write(x + " ");
        }
    }
}
