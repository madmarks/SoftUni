namespace Currency_Converter
{
    using System;
    using System.Windows.Forms;

    public partial class CurrencyConverterForm : Form
    {
        public CurrencyConverterForm()
        {
            this.InitializeComponent();
        }

        private void ConvertCurrency()
        {
            var originalAmount = this.numUpDownAmount.Value;
            var convertedAmount = 0m;

            if (this.comboBoxCurrency.SelectedItem.ToString() == "EUR")
            {
                convertedAmount = originalAmount / 1.95583m;
            }
            else if (this.comboBoxCurrency.SelectedItem.ToString() == "USD")
            {
                convertedAmount = originalAmount / 1.80810m;
            }
            else if (this.comboBoxCurrency.SelectedItem.ToString() == "GBP")
            {
                convertedAmount = originalAmount / 2.54990m;
            }

            this.lblResult.Text =
                string.Format("{0:F2}", Math.Round(originalAmount, 2)) +
                " лв. = " +
                string.Format("{0:F2} ", Math.Round(convertedAmount, 2)) +
                this.comboBoxCurrency.SelectedItem.ToString();
        }

        private void CurrencyConverterForm_Load(object sender, EventArgs e)
        {
            this.comboBoxCurrency.SelectedIndex = 0;

            this.ConvertCurrency();
        }

        private void numUpDownAmount_ValueChanged(object sender, EventArgs e)
        {
            this.ConvertCurrency();
        }

        private void comboBoxCurrency_SelectedIndexChanged(object sender, EventArgs e)
        {
            this.ConvertCurrency();
        }

        private void numUpDownAmount_KeyUp(object sender, KeyEventArgs e)
        {
            this.ConvertCurrency();
        }

        private void numUpDownAmount_MouseUp(object sender, MouseEventArgs e)
        {
            this.ConvertCurrency();
        }
    }
}
