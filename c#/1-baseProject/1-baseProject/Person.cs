using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1_baseProject
{
    public class Person
    {
        private string _name;
        private int _age;

        public Person(string name, int age)
        {
            this.Name = name;
            this.Age = age;
        }

        // 属性
        public string Name
        {
            get
            {
                return _name;
            }

            set
            {
                this._name = value;
            }

        }

        public int Age
        {
            get
            {
                return _age;
            }

            set
            {
                if(value <= 0 || value > 150)
                {
                    this._age = 0;
                }else
                {
                    this._age = value;
                }
            }
        }

        public virtual void showMsg()
        {
            Console.WriteLine("name= {0}, age={1}", this.Name, this.Age);
        }

    }

    // 继承
    public class Student : Person
    {
        private string _gender;
        private int _score;

        // 默认构造
        public Student(String name, int age, string gender, int score):base(name,age)
        {
            this.Gender = gender;
            this.Score = score;
        }


        // 默认析构
        ~Student() { }

        public string Gender
        {
            get
            {
                return _gender;
            }

            set
            {
                this._gender = value;
            }
        }

        public int Score
        {
            get
            {
                return this._score;
            }

            set
            {
                this._score = value;
            }
        }

        public override void showMsg()
        {
            base.showMsg();
            Console.WriteLine("gender={0}, score={1}", this.Gender, this.Score);
        }
    }
}
