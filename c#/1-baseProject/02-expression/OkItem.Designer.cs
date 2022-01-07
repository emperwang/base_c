namespace _02_expression
{
    partial class OkItem
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labOk = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // labOk
            // 
            this.labOk.AutoSize = true;
            this.labOk.Location = new System.Drawing.Point(90, 89);
            this.labOk.Name = "labOk";
            this.labOk.Size = new System.Drawing.Size(41, 12);
            this.labOk.TabIndex = 0;
            this.labOk.Text = "label1";
            // 
            // OkItem
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.labOk);
            this.Name = "OkItem";
            this.Text = "OkItem";
            this.Load += new System.EventHandler(this.OkItem_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labOk;
    }
}