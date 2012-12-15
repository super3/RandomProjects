using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Practice1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("------------");
            //Console.WriteLine(sum(123456789));
            Console.WriteLine(find());
            
            Console.Read();
        }

        public static int find()
        {
            int times = 0;
            int val1 = 123456789, val2 = 987654321;

            for (int i = val1; i <= val2; i++)
            {
                if(sum(i) == 45) { times++; Console.WriteLine(i); }
                if(times == 100000) { return i; }
            }
            return 0;
        }

        public static int sum(int value)
        {
            int sum = 0; 

            while(value > 0)
            {
                sum += value % 10;
                value /= 10;
            }

            return sum;
        }

        public static int diff21(int n)
        {
            if (n < 21)
                return Math.Abs(21 - n);
            else
                return (Math.Abs(21 - n))*2;
        }


        public static int sumDouble(int a, int b)
        {
            if (a.Equals(b))
                return (a + b) * 2;
            else
                return a + b;
        }

        public static Boolean monkeyTrouble(Boolean aSmile, Boolean bSmile)
        {
            if (aSmile == bSmile)
            {
                return true;
            }
            return false;
        }


        public static Boolean sleepIn(Boolean weekday, Boolean vacation)
        {
            if (!weekday || vacation)
            {
                return true;
            }
            return false; 
        }
    }
}
