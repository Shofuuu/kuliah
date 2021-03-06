using System;

namespace Maxvalue{
    class Program{
        static int counter = 0;
        static int[] parsingValue(string raw){ // convert string to array data
            int[] val = new int[100];
            string tmp = "";
            counter = 0;

            raw = raw+=',';
            for(int x=0;x<raw.Length;x++){
                if(raw[x] != ',') tmp += raw[x];
                if(raw[x] == ','){
                    val[counter] = Int32.Parse(tmp);
                    counter++;
                    tmp="";
                }
            }

            return val;
        }
        static string removeChar(string raw, char ch){
            string filter = "";

            for(int x=0;x<raw.Length;x++)
                if(raw[x] != ch) filter += raw[x];

            return filter;
        }
        static int GetMax(int[] data){
            int max = 0;

            for(int x=0;x<data.Length;x++)
                if(data[x] > max)
                    max = data[x];

            return max;
        }
        static int GetMin(int[] data){
            int min = GetMax(data);

            for(int x=0;x<counter;x++)
                if(data[x] < min)
                    min = data[x];

            return min;
        }
        static void Main(string[] args){
            string input;

            Console.WriteLine("Please write the number separated by comma");
            Console.Write("> ");
            input = Console.ReadLine();
            input = removeChar(input,' ');
            Console.WriteLine("Max Value : " + GetMax(parsingValue(input)));
            Console.WriteLine("Min Value : " + GetMin(parsingValue(input)));
            Console.ReadKey();
        }
    }
}
