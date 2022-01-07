using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _02_expression
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            // 跨线程访问
            Control.CheckForIllegalCrossThreadCalls = false;
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            txtLabel.AutoSize = false;
            txtLabel.Width = this.Width / 2;
            txtLabel.Height = txtLabel.Height * 10;
            txtLabel.Text = "亲爱的,如果非要给我们的爱情定一个期限,那我希望是一万年; 如果你问我现在有什么愿望,那我希望你能现在就嫁给我, 嫁给我好吗?";
        }

        private void btnNo_Click(object sender, EventArgs e)
        {

        }

        private void btnOk_Click(object sender, EventArgs e)
        {
            Form form = new OkItem();
            form.Show();
        }

        Random r = new Random();
        private void btnNo_MouseEnter(object sender, EventArgs e)
        {
            // 此高和宽是整个显示window的高和宽, 需要设置为clientSize中的高和宽 
            /*int width = this.Width - btnNo.Width;
            int height = this.Height - btnNo.Height - SystemInformation.CaptionHeight;*/
            int width = this.ClientSize.Width - btnNo.Width;
            int height = this.ClientSize.Height - btnNo.Height;

            int x = r.Next(0, width);
            int y = r.Next(0, height);
            Console.WriteLine("x={0}, y={1}", x, y);
            btnNo.Location = new Point(x, y);
        }
    }
}
