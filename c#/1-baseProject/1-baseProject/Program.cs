using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_baseProject
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello C#..");
            Person p = new Student("zhangsan", 20,"三年级", 100);

            p.showMsg();

            Console.ReadLine();
        }
    }
}
