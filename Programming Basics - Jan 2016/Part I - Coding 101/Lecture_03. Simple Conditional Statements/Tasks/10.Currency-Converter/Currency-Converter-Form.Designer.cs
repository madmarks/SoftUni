namespace Currency_Converter
{
    public partial class CurrencyConverterForm
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
            this.numUpDownAmount = new System.Windows.Forms.NumericUpDown();
            this.lblBgn = new System.Windows.Forms.Label();
            this.lblArrow = new System.Windows.Forms.Label();
            this.lblResult = new System.Windows.Forms.Label();
            this.comboBoxCurrency = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.numUpDownAmount)).BeginInit();
            this.SuspendLayout();
            // 
            // numUpDownAmount
            // 
            this.numUpDownAmount.DecimalPlaces = 2;
            this.numUpDownAmount.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.numUpDownAmount.Location = new System.Drawing.Point(25, 58);
            this.numUpDownAmount.Maximum = new decimal(new int[] {
            1000000000,
            0,
            0,
            0});
            this.numUpDownAmount.Name = "numUpDownAmount";
            this.numUpDownAmount.Size = new System.Drawing.Size(220, 29);
            this.numUpDownAmount.TabIndex = 0;
            this.numUpDownAmount.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.numUpDownAmount.Value = new decimal(new int[] {
            2500,
            0,
            0,
            0});
            this.numUpDownAmount.ValueChanged += new System.EventHandler(this.numUpDownAmount_ValueChanged);
            this.numUpDownAmount.KeyUp += new System.Windows.Forms.KeyEventHandler(this.numUpDownAmount_KeyUp);
            this.numUpDownAmount.MouseUp += new System.Windows.Forms.MouseEventHandler(this.numUpDownAmount_MouseUp);
            // 
            // lblBgn
            // 
            this.lblBgn.AutoSize = true;
            this.lblBgn.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblBgn.Location = new System.Drawing.Point(261, 60);
            this.lblBgn.Name = "lblBgn";
            this.lblBgn.Size = new System.Drawing.Size(50, 24);
            this.lblBgn.TabIndex = 1;
            this.lblBgn.Text = "BGN";
            // 
            // lblArrow
            // 
            this.lblArrow.AutoSize = true;
            this.lblArrow.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblArrow.Location = new System.Drawing.Point(317, 60);
            this.lblArrow.Name = "lblArrow";
            this.lblArrow.Size = new System.Drawing.Size(27, 24);
            this.lblArrow.TabIndex = 2;
            this.lblArrow.Text = "->";
            // 
            // lblResult
            // 
            this.lblResult.BackColor = System.Drawing.Color.PaleGreen;
            this.lblResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.97015F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblResult.Location = new System.Drawing.Point(25, 131);
            this.lblResult.Name = "lblResult";
            this.lblResult.Size = new System.Drawing.Size(429, 41);
            this.lblResult.TabIndex = 3;
            this.lblResult.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // comboBoxCurrency
            // 
            this.comboBoxCurrency.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxCurrency.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.20895F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.comboBoxCurrency.FormattingEnabled = true;
            this.comboBoxCurrency.Items.AddRange(new object[] {
            "EUR",
            "USD",
            "GBP"});
            this.comboBoxCurrency.Location = new System.Drawing.Point(350, 57);
            this.comboBoxCurrency.Name = "comboBoxCurrency";
            this.comboBoxCurrency.Size = new System.Drawing.Size(104, 32);
            this.comboBoxCurrency.TabIndex = 4;
            this.comboBoxCurrency.SelectedIndexChanged += new System.EventHandler(this.comboBoxCurrency_SelectedIndexChanged);
            // 
            // CurrencyConverterForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(482, 204);
            this.Controls.Add(this.comboBoxCurrency);
            this.Controls.Add(this.lblResult);
            this.Controls.Add(this.lblArrow);
            this.Controls.Add(this.lblBgn);
            this.Controls.Add(this.numUpDownAmount);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(502, 257);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(502, 257);
            this.Name = "CurrencyConverterForm";
            this.Text = "Currency Converter";
            this.Load += new System.EventHandler(this.CurrencyConverterForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numUpDownAmount)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.NumericUpDown numUpDownAmount;
        private System.Windows.Forms.Label lblBgn;
        private System.Windows.Forms.Label lblArrow;
        private System.Windows.Forms.Label lblResult;
        private System.Windows.Forms.ComboBox comboBoxCurrency;
    }
}