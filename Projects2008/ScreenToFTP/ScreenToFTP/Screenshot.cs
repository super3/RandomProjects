using System.Drawing;
using System.Drawing.Imaging;
using System.Windows.Forms;

namespace ScreenToFTP
{
    public partial class Screenshot : Form
    {
        public Point SourcePoint;
        public Point DestinationPoint;
        public bool LeftButtonDown = false;
        private static Bitmap bmpScreenshot;
        private static Graphics gfxScreenshot;
        public PictureBox theimage = new PictureBox();
        public Main MyParentForm;

        public Screenshot()
        {
            InitializeComponent();
        }

        public PictureBox UserName
        {
            get { return theimage; }
        }

        private void Screenshot_MouseUp(object sender, MouseEventArgs e)
        {
            if (LeftButtonDown)
            {
                LeftButtonDown = false;
                DestinationPoint = new Point(System.Windows.Forms.Control.MousePosition.X, System.Windows.Forms.Control.MousePosition.Y);

                //Conceal this form while the screen capture takes place
                this.Hide();

                //Allow 250 milliseconds for the screen to repaint itself
                System.Threading.Thread.Sleep(250);

                int height = 0;
                int width = 0;

                if (SourcePoint.X < DestinationPoint.X && SourcePoint.Y < DestinationPoint.Y)
                {
                    width = DestinationPoint.X - SourcePoint.X;
                    height = DestinationPoint.Y - SourcePoint.Y;
                }
                else if (SourcePoint.X >= DestinationPoint.X && SourcePoint.Y >= DestinationPoint.Y)
                {
                    width = SourcePoint.X - DestinationPoint.X;
                    height = SourcePoint.Y - DestinationPoint.Y;
                }
                else
                {
                    //ScreenFail
                    height = 50;
                    width = 50;
                }

                // Set the bitmap object to the size of the screen
                bmpScreenshot = new Bitmap(width, height, PixelFormat.Format32bppArgb);
                //bmpScreenshot = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height, PixelFormat.Format32bppArgb);

                // Create a graphics object from the bitmap
                gfxScreenshot = Graphics.FromImage(bmpScreenshot);

                Size screen = new Size(width, height);

                // Take the screenshot from the upper left corner to the right bottom corner
                if (SourcePoint.X < DestinationPoint.X && SourcePoint.Y < DestinationPoint.Y)
                {
                    gfxScreenshot.CopyFromScreen(SourcePoint.X, SourcePoint.Y, 0, 0, screen, CopyPixelOperation.SourceCopy);
                }
                else
                {
                    gfxScreenshot.CopyFromScreen(DestinationPoint.X, DestinationPoint.Y, 0, 0, screen, CopyPixelOperation.SourceCopy);
                }

                theimage.Image = bmpScreenshot;
                this.Close();
            }
        }

        private void Screenshot_MouseDown(object sender, MouseEventArgs e)
        {
            LeftButtonDown = true;
            SourcePoint = new Point(System.Windows.Forms.Control.MousePosition.X, System.Windows.Forms.Control.MousePosition.Y);
        }

        private void Screenshot_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)Keys.Escape)
            {
                DialogResult = DialogResult.Abort;
                Dispose();
            }
        }
    }
}
