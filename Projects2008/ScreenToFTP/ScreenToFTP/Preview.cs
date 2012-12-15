using System;
using System.Drawing;
using System.Windows.Forms;

namespace ScreenToFTP
{
    public partial class Preview : Form
    {     
        public Preview(PictureBox previewer)
        {
            InitializeComponent();

            pictureBox1.Image = previewer.Image;

            int height = pictureBox1.Image.Height;
            int width = pictureBox1.Image.Width;

            if (height <= 600 && width <= 800)
            {
                this.FormBorderStyle = FormBorderStyle.None;
                this.Size = new Size(width, height);
                this.FormBorderStyle = FormBorderStyle.FixedSingle;
            }
            else
            {
                this.FormBorderStyle = FormBorderStyle.None;
                this.Size = new Size((int)(width * 0.5), (int)(height * 0.5));
                this.Text = "Preview Screenshot (Scaled 50%)";
                this.FormBorderStyle = FormBorderStyle.Sizable;
                //aspectRatio();
            }
        }

        private void aspectRatio()
        {
            int height = pictureBox1.Image.Height;
            int width = pictureBox1.Image.Width;

            double ratio = (double)1 / (double)((double)height / (double)width);
            int var = (int)(this.Size.Height * ratio);
            this.Size = new Size(this.Size.Width, var);
        }

        private void Preview_Resize(object sender, EventArgs e)
        {
            int height = pictureBox1.Image.Height;
            int width = pictureBox1.Image.Width;

            if (height <= 600 && width <= 800)
            {
                this.Text = "Preview Screenshot";
            }
            else
            {
                this.Text = "Preview Screenshot (Scaled)";
                //aspectRatio();
            }
        }
    }
}
