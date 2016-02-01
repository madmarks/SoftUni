using System;
using System.Drawing;
using System.Windows.Forms;

namespace Catch_the_Button
{
    public partial class CatchTheButtonForm : Form
    {
        public CatchTheButtonForm()
        {
            InitializeComponent();
        }

        private void buttonCatchMe_MouseEnter(object sender, EventArgs e)
        {
            Random rand = new Random();

            var maxWidth = this.Width - buttonCatchMe.ClientSize.Width;
            var maxHeight = this.Height - buttonCatchMe.ClientSize.Height;

            this.buttonCatchMe.Location = new Point(rand.Next(maxWidth), rand.Next(maxHeight));
        }

        private void buttonCatchMe_Click(object sender, EventArgs e)
        {
            MessageBox.Show("You win!", "Congratulations");
        }
    }
}
