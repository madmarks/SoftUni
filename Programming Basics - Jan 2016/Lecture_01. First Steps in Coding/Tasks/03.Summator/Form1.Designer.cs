namespace Summator
{
    public partial class Form1
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
            if (disposing && (this.components != null))
            {
                this.components.Dispose();
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
            this.tbxAddend1 = new System.Windows.Forms.TextBox();
            this.tbxAddend2 = new System.Windows.Forms.TextBox();
            this.tbxSum = new System.Windows.Forms.TextBox();
            this.btnCalculate = new System.Windows.Forms.Button();
            this.lblEqual = new System.Windows.Forms.Label();
            this.lblPlus = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // tbxAddend1
            // 
            this.tbxAddend1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.tbxAddend1.Location = new System.Drawing.Point(27, 44);
            this.tbxAddend1.Name = "tbxAddend1";
            this.tbxAddend1.Size = new System.Drawing.Size(100, 29);
            this.tbxAddend1.TabIndex = 0;
            this.tbxAddend1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // tbxAddend2
            // 
            this.tbxAddend2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.tbxAddend2.Location = new System.Drawing.Point(186, 44);
            this.tbxAddend2.Name = "tbxAddend2";
            this.tbxAddend2.Size = new System.Drawing.Size(100, 29);
            this.tbxAddend2.TabIndex = 1;
            this.tbxAddend2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // tbxSum
            // 
            this.tbxSum.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.tbxSum.Location = new System.Drawing.Point(345, 44);
            this.tbxSum.Name = "tbxSum";
            this.tbxSum.Size = new System.Drawing.Size(151, 29);
            this.tbxSum.TabIndex = 2;
            this.tbxSum.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btnCalculate
            // 
            this.btnCalculate.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnCalculate.Location = new System.Drawing.Point(27, 115);
            this.btnCalculate.Name = "btnCalculate";
            this.btnCalculate.Size = new System.Drawing.Size(469, 32);
            this.btnCalculate.TabIndex = 3;
            this.btnCalculate.Text = "Calculate";
            this.btnCalculate.UseVisualStyleBackColor = true;
            this.btnCalculate.Click += new System.EventHandler(this.btnCalculate_Click);
            // 
            // lblEqual
            // 
            this.lblEqual.AutoSize = true;
            this.lblEqual.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblEqual.Location = new System.Drawing.Point(305, 46);
            this.lblEqual.Name = "lblEqual";
            this.lblEqual.Size = new System.Drawing.Size(21, 24);
            this.lblEqual.TabIndex = 4;
            this.lblEqual.Text = "=";
            // 
            // lblPlus
            // 
            this.lblPlus.AutoSize = true;
            this.lblPlus.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblPlus.Location = new System.Drawing.Point(146, 46);
            this.lblPlus.Name = "lblPlus";
            this.lblPlus.Size = new System.Drawing.Size(21, 24);
            this.lblPlus.TabIndex = 5;
            this.lblPlus.Text = "+";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(525, 184);
            this.Controls.Add(this.lblPlus);
            this.Controls.Add(this.lblEqual);
            this.Controls.Add(this.btnCalculate);
            this.Controls.Add(this.tbxSum);
            this.Controls.Add(this.tbxAddend2);
            this.Controls.Add(this.tbxAddend1);
            this.MaximumSize = new System.Drawing.Size(545, 237);
            this.MinimumSize = new System.Drawing.Size(545, 237);
            this.Name = "Form1";
            this.Text = "Summator";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbxAddend1;
        private System.Windows.Forms.TextBox tbxAddend2;
        private System.Windows.Forms.TextBox tbxSum;
        private System.Windows.Forms.Button btnCalculate;
        private System.Windows.Forms.Label lblEqual;
        private System.Windows.Forms.Label lblPlus;
    }
}