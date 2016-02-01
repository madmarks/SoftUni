using System;
using System.Windows.Forms;

namespace BGN_to_EUR_Converter
{
    public partial class FormConverter : Form
    {
        public FormConverter()
        {
            InitializeComponent();
        }

        private void ConvertCurrency()
        {
            var amountBGN = numericUpDownAmount.Value;
            var amountEUR = 1.95583m * amountBGN;
            labelResult.Text =
                Math.Round(amountBGN, 2) +
                " BGN = " +
                Math.Round(amountEUR, 2) +
                " EUR";
        }

        private void FormConverter_Load(object sender, EventArgs e)
        {
            ConvertCurrency();
        }

        private void numericUpDownAmount_ValueChanged(object sender, EventArgs e)
        {
            ConvertCurrency();
        }

        private void numericUpDownAmount_KeyUp(object sender, KeyEventArgs e)
        {
            ConvertCurrency();
        }

        private void numericUpDownAmount_MouseUp(object sender, MouseEventArgs e)
        {
            ConvertCurrency();
        }
    }
}
