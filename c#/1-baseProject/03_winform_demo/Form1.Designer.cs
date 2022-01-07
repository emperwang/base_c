namespace _03_winform_demo
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.btn1 = new System.Windows.Forms.Button();
            this.timeShow = new System.Windows.Forms.TextBox();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.pwdTxt = new System.Windows.Forms.TextBox();
            this.cbox1 = new System.Windows.Forms.CheckBox();
            this.comBox1 = new System.Windows.Forms.ComboBox();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.listBoxCheck = new System.Windows.Forms.CheckBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timerClock);
            // 
            // btn1
            // 
            this.btn1.Location = new System.Drawing.Point(378, 3);
            this.btn1.Name = "btn1";
            this.btn1.Size = new System.Drawing.Size(79, 20);
            this.btn1.TabIndex = 0;
            this.btn1.Text = "开始";
            this.btn1.UseVisualStyleBackColor = true;
            this.btn1.Click += new System.EventHandler(this.OnClick);
            // 
            // timeShow
            // 
            this.timeShow.Dock = System.Windows.Forms.DockStyle.Fill;
            this.timeShow.Location = new System.Drawing.Point(3, 3);
            this.timeShow.Name = "timeShow";
            this.timeShow.Size = new System.Drawing.Size(369, 21);
            this.timeShow.TabIndex = 1;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 85F));
            this.tableLayoutPanel1.Controls.Add(this.btn1, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.timeShow, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.pwdTxt, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.cbox1, 1, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(460, 64);
            this.tableLayoutPanel1.TabIndex = 2;
            // 
            // pwdTxt
            // 
            this.pwdTxt.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pwdTxt.Location = new System.Drawing.Point(3, 35);
            this.pwdTxt.Name = "pwdTxt";
            this.pwdTxt.PasswordChar = '*';
            this.pwdTxt.Size = new System.Drawing.Size(369, 21);
            this.pwdTxt.TabIndex = 2;
            // 
            // cbox1
            // 
            this.cbox1.AutoSize = true;
            this.cbox1.Location = new System.Drawing.Point(378, 35);
            this.cbox1.Name = "cbox1";
            this.cbox1.Size = new System.Drawing.Size(72, 16);
            this.cbox1.TabIndex = 3;
            this.cbox1.Text = "显示密码";
            this.cbox1.UseVisualStyleBackColor = true;
            this.cbox1.CheckStateChanged += new System.EventHandler(this.onStateChanged);
            // 
            // comBox1
            // 
            this.comBox1.FormattingEnabled = true;
            this.comBox1.Items.AddRange(new object[] {
            "清华",
            "北大"});
            this.comBox1.Location = new System.Drawing.Point(12, 70);
            this.comBox1.Name = "comBox1";
            this.comBox1.Size = new System.Drawing.Size(121, 20);
            this.comBox1.TabIndex = 3;
            this.comBox1.SelectedIndexChanged += new System.EventHandler(this.OnSelectedIndexChange);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 12;
            this.listBox1.Location = new System.Drawing.Point(13, 111);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(120, 88);
            this.listBox1.TabIndex = 4;
            // 
            // listBoxCheck
            // 
            this.listBoxCheck.AutoSize = true;
            this.listBoxCheck.Location = new System.Drawing.Point(166, 111);
            this.listBoxCheck.Name = "listBoxCheck";
            this.listBoxCheck.Size = new System.Drawing.Size(90, 16);
            this.listBoxCheck.TabIndex = 5;
            this.listBoxCheck.Text = "Listbox多选";
            this.listBoxCheck.UseVisualStyleBackColor = true;
            this.listBoxCheck.CheckedChanged += new System.EventHandler(this.listBoxCheck_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(460, 461);
            this.Controls.Add(this.listBoxCheck);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.comBox1);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button btn1;
        private System.Windows.Forms.TextBox timeShow;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TextBox pwdTxt;
        private System.Windows.Forms.CheckBox cbox1;
        private System.Windows.Forms.ComboBox comBox1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.CheckBox listBoxCheck;
    }
}

