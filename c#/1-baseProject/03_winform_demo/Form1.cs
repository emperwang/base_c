using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _03_winform_demo
{
    public partial class Form1 : Form
    {
        private bool isStart = false;

        public bool IsStart
        {
            get
            {
                return this.isStart;
            }

            set
            {
                this.isStart = value;
            }
        }

        public Form1()
        {
            InitializeComponent();
            this.comBox1.Items.Add("深大");
            this.comBox1.Items.AddRange(new object[] { "复旦", "交大" });

            this.listBox1.Items.AddRange(new object[] { "上海复旦", "上海交大", "广州中山","北航" });
        }

        private void OnClick(object sender, EventArgs e)
        {
            IsStart = !IsStart;
            setBtnText();
            this.timer1.Enabled = IsStart;
        }

        public void setBtnText()
        {
            if (!IsStart)
            {
                this.btn1.Text = "开始";
            }else
            {
                this.btn1.Text = "停止";
            }
        }

        private void timerClock(object sender, EventArgs e)
        {
            this.timeShow.Text = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss.fff");
        }

        private void onStateChanged(object sender, EventArgs e)
        {
            if(this.cbox1.Checked)
            {
                this.pwdTxt.PasswordChar = '\0';
            }else
            {
                this.pwdTxt.PasswordChar = '*';
            }
        }

        private void OnSelectedIndexChange(object sender, EventArgs e)
        {
            String val = this.comBox1.SelectedItem.ToString();
            MessageBox.Show(String.Format("选择结果: {0}", val));
        }

        private void listBoxCheck_CheckedChanged(object sender, EventArgs e)
        {
            if(this.listBoxCheck.Checked)
            {
                this.listBox1.SelectionMode = SelectionMode.MultiSimple;
            }else
            {
                this.listBox1.SelectionMode = SelectionMode.One;
            }
        }
    }
}
