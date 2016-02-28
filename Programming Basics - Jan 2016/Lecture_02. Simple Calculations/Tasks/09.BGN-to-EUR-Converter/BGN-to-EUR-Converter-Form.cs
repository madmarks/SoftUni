namespace BGN_to_EUR_Converter
{
    using System;
    using System.Windows.Forms;

    public partial class FormConverter : Form
    {
        public FormConverter()
        {
            this.InitializeComponent();
        }

        private void ConvertCurrency()
        {
            var amountBGN = this.numericUpDownAmount.Value;
            var amountEUR = 1.95583m * amountBGN;
            this.labelResult.Text =
                string.Format("{0:F2}", Math.Round(amountBGN, 2)) +
                " BGN = " +
                string.Format("{0:F2}", Math.Round(amountEUR, 2)) +
                " EUR";
        }

        private void FormConverter_Load(object sender, EventArgs e)
        {
            this.ConvertCurrency();
        }

        private void numericUpDownAmount_ValueChanged(object sender, EventArgs e)
        {
            this.ConvertCurrency();
        }

        private void numericUpDownAmount_KeyUp(object sender, KeyEventArgs e)
        {
            this.ConvertCurrency();
        }

        private void numericUpDownAmount_MouseUp(object sender, MouseEventArgs e)
        {
            this.ConvertCurrency();
        }
    }
}
