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
    public partial class OkItem : Form
    {
        public OkItem()
        {
            InitializeComponent();
        }

        private void OkItem_Load(object sender, EventArgs e)
        {
            labOk.Text = "哇哦, 亲爱的, 你真的太好了...";
        }
    }
}
