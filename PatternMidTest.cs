using System;

namespace Drawing{
    class Program{
        static void Main(string[] args){
            Console.WriteLine(">>>> Mid-test of Interface <<<<");
            Console.WriteLine("Program of making rectangle and cross shape\n");

            int x = 0, y = 0;
            Console.WriteLine("Starting Program..");
            System.Threading.Thread.Sleep(2000);

            Console.SetCursorPosition(Console.CursorLeft, Console.CursorTop -1);
            Console.Write("Enter your number of column(s)\t: ");
            x = Int32.Parse(Console.ReadLine());
            Console.Write("Enter your number of row(s)\t: ");
            y = Int32.Parse(Console.ReadLine());
            Console.WriteLine();

            Console.WriteLine("Processing...");
            System.Threading.Thread.Sleep(1000);

            Console.SetCursorPosition(Console.CursorLeft, Console.CursorTop -1);
            Console.WriteLine("Output : Square or Rectangle");
            for(int i=1;i<=x;i++){
                for(int j=1;j<=y;j++){
                    Console.Write(" ");
                    if(i != 1 && i != x && j != 1 && j != y) Console.Write(" ");
                    else Console.Write(j);
                }
                Console.WriteLine();
            }
            Console.WriteLine();

            Console.WriteLine("Processing...");
            System.Threading.Thread.Sleep(1000);
            Console.SetCursorPosition(Console.CursorLeft, Console.CursorTop -1);
            Console.WriteLine("Output : Cross");
            for(int i=0;i<x;i++){
                for(int j=0;j<x;j++){
                    if(i==j || j==(x-i-1)) Console.Write(" "+j);
                    else Console.Write(" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}
