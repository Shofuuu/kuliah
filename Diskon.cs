using System;

namespace antarmukaTugas{
    class Program{
        static void Main(string[] args){
            string[,] data = new string[,]{
                {"Xilinx","445.6"},
                {"Altera","362.4"},
                {"Intel","462.2"}
            };
            decimal price = 0, total = 0;
            int items = 0, num = 1, item = 0;

            if(args.Length < 2)
                Console.WriteLine("Usage : ./main [Product (Xilinx, Altera, Intel)] [Total (x)]");
            else{
                for(int y=0;y<args.Length;y++){
                    for(int x=0;x<=data.GetLength(1);x++){
                        if(string.Equals((data[x,0]).ToLower(),(args[y]).ToLower())){
                            price = (decimal)(double.Parse(data[x,1]));
                            item = Convert.ToInt32(args[y+1]);

                            Console.WriteLine((num) + "). " + ((data[x,0]).Equals("Intel") ? data[x,0]+" " : data[x,0]) + " [$" +price+ "] [" +item+ "x]\t : $"+(price*item));
                            total += price;
                            items += item;
                            num++;
                        }
                    }
                }

                Console.WriteLine("\nTotal\t\t\t\t : $"+total);
                Console.WriteLine("Discount\t\t\t : $"+(total - (items*2)));
            }
        }
    }
}
