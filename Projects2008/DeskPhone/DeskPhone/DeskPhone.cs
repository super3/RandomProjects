using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DeskPhone
{
    public partial class DeskPhone : Form
    {
        //For a Movable Form
        private bool dragging;
        private Point pointClicked;

        //Darken Icon
        Image imgPicture;
        Bitmap bmpPicture;
        System.Drawing.Imaging.ImageAttributes iaPicture;
        System.Drawing.Imaging.ColorMatrix cmPicture;
        Graphics gfxPicture;
        Rectangle rctPicture;


        private void PreparePicture()
        {
            // If there's a picture
            if (imgPicture != null)
            {
                // Create new Bitmap object with the size of the picture
                    bmpPicture = new Bitmap(imgPicture.Width, imgPicture.Height);
                // Image attributes for setting the attributes of the picture
                    iaPicture = new System.Drawing.Imaging.ImageAttributes();
            }
        }
        private void FinalizePicture()
        {
            // Set the new color matrix
            iaPicture.SetColorMatrix(cmPicture);
            // Set the Graphics object from the bitmap
            gfxPicture = Graphics.FromImage(bmpPicture);
            // New rectangle for the picture, same size as the original picture
            rctPicture = new Rectangle(0, 0, imgPicture.Width, imgPicture.Height);
            // Draw the new image
            gfxPicture.DrawImage(imgPicture, rctPicture, 0, 0, imgPicture.Width, imgPicture.Height, GraphicsUnit.Pixel, iaPicture);
            // Set the PictureBox to the new inverted colors bitmap
            pictureBox3.Image = bmpPicture;
        }


        public DeskPhone()
        {
            InitializeComponent();
        }

        private void DeskPhone_Load(object sender, EventArgs e)
        {
            //Set Current Time
            timelb.Text = String.Format("{0: h:mm tt}", DateTime.Now);
            imgPicture = pictureBox3.Image;

        }

        #region "Makes Form Movable"

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                dragging = true;
                pointClicked = new Point(e.X, e.Y);
            }
            else
            {
                dragging = false;
            }
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (dragging)
            {
                Point pointMoveTo;
                pointMoveTo = this.PointToScreen(new Point(e.X, e.Y));

                pointMoveTo.Offset(-pointClicked.X, -pointClicked.Y);

                this.Location = pointMoveTo;
            }   
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            dragging = false;
        }
        #endregion

        //Updates Time Every 60 seconds
        private void clock_Tick(object sender, EventArgs e)
        {
            timelb.Text = String.Format("{0: h:mm tt}", DateTime.Now);
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            PreparePicture();
            cmPicture = new System.Drawing.Imaging.ColorMatrix();
            // Change the elements
             float bf = -0.1f;
            cmPicture = new System.Drawing.Imaging.ColorMatrix(new float[][]
            {
              
                        new float[]{1f,    0f,    0f,    0f,    0f},
                         new float[]{0f,    1f,    0f,    0f,    0f},
                         new float[]{0f,    0f,    1f,    0f,    0f},
                         new float[]{0f,    0f,    0f,    1f,    0f},
                         new float[]{bf,    bf,    bf,    1f,    1f}
            });
            FinalizePicture();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox3_MouseHover(object sender, EventArgs e)
        {
            PreparePicture();
            cmPicture = new System.Drawing.Imaging.ColorMatrix();
            // Change the elements
            float bf = -0.1f;
            cmPicture = new System.Drawing.Imaging.ColorMatrix(new float[][]
            {
              
                        new float[]{1f,    0f,    0f,    0f,    0f},
                         new float[]{0f,    1f,    0f,    0f,    0f},
                         new float[]{0f,    0f,    1f,    0f,    0f},
                         new float[]{0f,    0f,    0f,    1f,    0f},
                         new float[]{bf,    bf,    bf,    1f,    1f}
            });
            FinalizePicture();
        }

        private void pictureBox3_MouseLeave(object sender, EventArgs e)
        {
            PreparePicture();
            cmPicture = new System.Drawing.Imaging.ColorMatrix();
            // Change the elements
            float bf = 0f;
            cmPicture = new System.Drawing.Imaging.ColorMatrix(new float[][]
            {
              
                        new float[]{1f,    0f,    0f,    0f,    0f},
                         new float[]{0f,    1f,    0f,    0f,    0f},
                         new float[]{0f,    0f,    1f,    0f,    0f},
                         new float[]{0f,    0f,    0f,    1f,    0f},
                         new float[]{bf,    bf,    bf,    1f,    1f}
            });
            FinalizePicture();
        }


    }
}
