namespace Catch_the_Button
{
    using System;
    using System.Drawing;
    using System.Windows.Forms;

    public partial class CatchTheButtonForm : Form
    {
        public CatchTheButtonForm()
        {
            this.InitializeComponent();
        }

        private void buttonCatchMe_MouseEnter(object sender, EventArgs e)
        {
            Random rand = new Random();

            var maxWidth = this.Width - this.buttonCatchMe.ClientSize.Width;
            var maxHeight = this.Height - this.buttonCatchMe.ClientSize.Height;

            this.buttonCatchMe.Location = new Point(rand.Next(maxWidth), rand.Next(maxHeight));
        }

        private void buttonCatchMe_Click(object sender, EventArgs e)
        {
            MessageBox.Show("You win!", "Congratulations");
        }
    }
}
