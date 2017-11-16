using System;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int prg = 0; prg < 1; )
            {
                Console.WriteLine("Enter the number\n");
                string s = Console.ReadLine();
                //char[] arr;
                //s.ToCharArray(0 , s.Length);
                Console.Clear();
                bool check = false;
                for (int j = 0; j < s.Length; )
                {
                    if (Char.IsDigit(s, j))
                    {
                        j++;
                        check = true;
                    }
                    else
                    {
                        Console.WriteLine("Error input");
                        Console.ReadKey();
                        Console.Clear();
                        check = false;
                        j = s.Length;
                    }
                }
                if (check == true)
                { 
                    int number = Convert.ToInt32(s);
                    if (number <= 0)
                    {
                        Console.WriteLine("0");
                        prg = 1;
                    }
                    else
                    {
                        Console.WriteLine(number * 3);
                        prg = 1;
                    }
                }
            }
            Console.ReadKey();
        }
    }
}
