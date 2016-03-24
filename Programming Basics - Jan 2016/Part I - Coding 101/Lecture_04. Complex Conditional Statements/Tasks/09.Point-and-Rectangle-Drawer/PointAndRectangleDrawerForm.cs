namespace Point_and_Rectangle_Drawer
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Data;
    using System.Drawing;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;
    using System.Windows.Forms;

    public partial class PointAndRectangleDrawerForm : Form
    {
        public PointAndRectangleDrawerForm()
        {
            this.InitializeComponent();
        }

        private void Draw()
        {
            // Get the rectangle and point coordinates from the form
            var x1 = this.numericUpDownX1.Value;
            var y1 = this.numericUpDownY1.Value;
            var x2 = this.numericUpDownX2.Value;
            var y2 = this.numericUpDownY2.Value;
            var x = this.numericUpDownX.Value;
            var y = this.numericUpDownY.Value;

            // Display the location of the point: Inside / Border / Outside
            this.DisplayPointLocation(x1, y1, x2, y2, x, y);

            /* Calculate the scale factor (ratio) for the diagram holding the
             * rectangle and point in order to fit them well in the picture box
             */
            var minX = Math.Min(x, Math.Min(x1, x2));
            var maxX = Math.Max(x, Math.Max(x1, x2));
            var minY = Math.Min(y, Math.Min(y1, y2));
            var maxY = Math.Max(y, Math.Max(y1, y2));
            var diagramWidth = maxX - minX;
            var diagramHeight = maxY - minY;
            var offset = 10;
            var ratio = 1.0m;

            if (diagramWidth != 0 && diagramHeight != 0)
            {
                var ratioWidth = (this.pictureBox.Width - (2 * offset) - 1) / diagramWidth;
                var ratioHeight = (this.pictureBox.Height - (2 * offset) - 1) / diagramHeight;
                ratio = Math.Min(ratioWidth, ratioHeight);
            }

            // Calculate the scaled rectangle coordinates
            var rectLeft = offset + (int)Math.Round((Math.Min(x1, x2) - minX) * ratio);
            var rectTop = offset + (int)Math.Round((Math.Min(y1, y2) - minY) * ratio);
            var rectWidth = (int)Math.Round(Math.Abs(x2 - x1) * ratio);
            var rectHeight = (int)Math.Round(Math.Abs(y2 - y1) * ratio);
            var rect = new Rectangle(rectLeft, rectTop, rectWidth, rectHeight);

            // Calculate the scalled point coordinates
            var pointX = offset + (int)Math.Round((x - minX) * ratio);
            var pointY = offset + (int)Math.Round((y - minY) * ratio);
            var pointRect = new Rectangle(pointX - 2, pointY - 2, 5, 5);

            // Draw the rectangle and point
            this.pictureBox.Image = new Bitmap(this.pictureBox.Width, this.pictureBox.Height);
            using (var g = Graphics.FromImage(this.pictureBox.Image))
            {
                // Draw diagram background (white area)
                g.Clear(Color.White);

                // Draw the rectangle (scalled to the picture box size)
                var pen = new Pen(Color.Blue, 3);
                g.DrawRectangle(pen, rect);

                // Draw the point (scalled to the picture box size)
                pen = new Pen(Color.Red, 5);
                g.DrawEllipse(pen, pointRect);
            }
        }

        private void DisplayPointLocation(decimal x1, decimal y1, decimal x2, decimal y2, decimal x, decimal y)
        {
            var left = Math.Min(x1, x2);
            var right = Math.Max(x1, x2);
            var top = Math.Min(y1, y2);
            var bottom = Math.Max(y1, y2);

            if (left < x && x < right && top < y && y < bottom)
            {
                this.lblLocation.Text = "Inside";
                this.lblLocation.BackColor = Color.PaleGreen;
            }
            else if (x < left || right < x || y < top || bottom < y)
            {
                this.lblLocation.Text = "Outside";
                this.lblLocation.BackColor = Color.LightSalmon;
            }
            else
            {
                this.lblLocation.Text = "Border";
                this.lblLocation.BackColor = Color.Gold;
            }
        }

        private void PointAndRectangleDrawerForm_Load(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void PointAndRectangleDrawerForm_Resize(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void btnDraw_Click(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX1_ValueChanged(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX1_KeyUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX1_MouseUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY1_ValueChanged(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY1_KeyUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY1_MouseUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX2_ValueChanged(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX2_KeyUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX2_MouseUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY2_ValueChanged(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY2_KeyUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY2_MouseUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX_ValueChanged(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX_KeyUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownX_MouseUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY_ValueChanged(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY_KeyUp(object sender, EventArgs e)
        {
            this.Draw();
        }

        private void numericUpDownY_MouseUp(object sender, EventArgs e)
        {
            this.Draw();
        }
    }
}
