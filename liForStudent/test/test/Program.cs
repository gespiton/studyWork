using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> li = new List<int>() { 1, 2 };
            List<int> lii = li;
            lii.Add(33);
            stack(li);
            Console.WriteLine(li.GetType());
        }
        static void stack(List<int> li)
        {
            li.Add(11);
            stack(li);
        }
    }
}
