namespace Summator
{
    using System;
    using System.Windows.Forms;

    public partial class Form1 : Form
    {
        public Form1()
        {
            this.InitializeComponent();
        }

        private void btnCalculate_Click(object sender, EventArgs e)
        {
            try
            {
                var addend1 = decimal.Parse(this.tbxAddend1.Text);
                var addend2 = decimal.Parse(this.tbxAddend2.Text);
                var sum = addend1 + addend2;

                this.tbxSum.Text = sum.ToString();
            }
            catch (Exception)
            {
                this.tbxSum.Text = "error";
            }
        }
    }
}
