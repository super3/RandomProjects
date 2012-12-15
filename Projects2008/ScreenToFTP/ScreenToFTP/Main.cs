using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Media;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace ScreenToFTP
{
    public partial class Main : Form
    {
        public string error = "";
            // FTP Error Message.
        public string[] hotKeysGlobal = new String[3];
            // Takes Global Hotkeys.
        KeyboardHook hook = new KeyboardHook();
            //Keyboard Hook.

        public Main()
        {
            InitializeComponent();

            //Recovers FTP Info
            txtHost.Text = Properties.Settings.Default.ftpHost;
            txtUser.Text = Properties.Settings.Default.ftpUser;
            txtPass.Text = Properties.Settings.Default.ftpPass;
            txtPath.Text = Properties.Settings.Default.ftpPath;
            txtUrl.Text = Properties.Settings.Default.ftpUrl;

            //Recovers Configuration Info
            comboFile.SelectedIndex = Properties.Settings.Default.fileType;
            lbExt.Text = "." + comboFile.Text;
            comboSounds.SelectedIndex = Properties.Settings.Default.soundEnabled;
            checkPrefix.Checked = Properties.Settings.Default.prefixEnabled;
            if (checkPrefix.Checked) { txtPrefix.Enabled = true; }
            txtPrefix.Text = Properties.Settings.Default.prefix;

            //Recovers Hotkey Info
            UpdateHotKeys(Properties.Settings.Default.hotFull, checkFullAlt, checkFullControl,
                          checkFullShift, checkFullWin, comboFullKey);
            UpdateHotKeys(Properties.Settings.Default.hotArea, checkAreaAlt, checkAreaControl,
                          checkAreaShift, checkAreaWin, comboAreaKey);
            UpdateHotKeys(Properties.Settings.Default.hotActive, checkActiveAlt, checkActiveControl,
                          checkActiveShift, checkActiveWin, comboActiveKey);

            //Set Hotkeys
            hook.KeyPressed += new EventHandler<KeyPressedEventArgs>(hook_KeyPressed);
                // Register the event that is fired after the key press. 

            string[] hotKeys = new String[3];
            hotKeys[0] = Properties.Settings.Default.hotFull;
            hotKeys[1] = Properties.Settings.Default.hotArea;
            hotKeys[2] = Properties.Settings.Default.hotActive;

            for (int i = 0; i < hotKeys.Length; i++)
            {
                hotKeysGlobal[i] = getModifierKeys(hotKeys[i]).ToString() +
                    " + " + getKeys(hotKeys[i]).ToString();
                    // Saves Hot Key as string so it can be recognized later. 
                hook.RegisterHotKey(getModifierKeys(hotKeys[i]), getKeys(hotKeys[i]));
                    // Register the Hot Key with System.
            }        

            //Example
            //hook.RegisterHotKey((ModifierKeys)2 | (ModifierKeys)1, Keys.N);
                //Register the control + alt + N combination as hot key.     
        }

        private ModifierKeys getModifierKeys(String hotKeyCode)
        {
            ModifierKeys key = new ModifierKeys();
            string[] result = hotKeyCode.Split(new Char[] { ',' });
            for (int i = 0; i < (result.Length-1); i++)
            {
                key |= (ModifierKeys)System.Convert.ToInt32(result[i]);
            }
            return key;
        }

        private Keys getKeys(String hotKeyCode)
        {    
            string[] result = hotKeyCode.Split(new Char[] { ',' });
            return (Keys)Enum.Parse(typeof(Keys),(result[result.Length - 1]));
        }

        private String SaveHotKeys(CheckBox checkAlt, CheckBox checkControl,
                                 CheckBox checkShift, CheckBox checkWin, ComboBox comboKey)
        {
            string keycombo = "";

            if (checkAlt.Checked) { keycombo += "1,"; }
            if (checkControl.Checked) { keycombo += "2,"; }
            if (checkShift.Checked) { keycombo += "4,"; }
            if (checkWin.Checked) { keycombo += "8,"; }
            keycombo += comboKey.Text.ToString(); //Must have alpha key

            return keycombo;
        }

        private void UpdateHotKeys(String hotkey, CheckBox checkAlt, CheckBox checkControl,
                                   CheckBox checkShift, CheckBox checkWin, ComboBox comboKey)
        {
            string[] result = hotkey.Split(new Char[] { ',' });
            for (int i = 0; i < result.Length; i++)
            {
                switch (result[i].ToString())
                {
                    case "1": //Alt
                        checkAlt.Checked = true;
                        break;
                    case "2": //Control
                        checkControl.Checked = true;
                        break;
                    case "4": //Shift
                        checkShift.Checked = true;
                        break;
                    case "8": //Win Key
                        checkWin.Checked = true;
                        break;
                    default: //Letter or Number
                        if (IsAlphaNumeric(result[i])) { comboKey.Text = result[i]; }
                        break;
                }
            }
        }

        public bool IsAlphaNumeric(String str)
        {
            Regex regexAlphaNum = new Regex("[^a-zA-Z0-9]");
            return !regexAlphaNum.IsMatch(str);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Disable edits for the screenshot urls
            txtScreenURL.ReadOnly = true; 
        }

        void hook_KeyPressed(object sender, KeyPressedEventArgs e)
        {
            for (int i = 0; i < hotKeysGlobal.Length; i++)
            {
                if (i == 0 && hotKeysGlobal[i] == e.Modifier.ToString() + " + " + e.Key.ToString()) 
                {
                    ScreenFull();
                }
                else if (i == 1 && hotKeysGlobal[i] == e.Modifier.ToString() + " + " + e.Key.ToString())
                {
                    ScreenArea();
                }
                else if (i == 2 && hotKeysGlobal[i] == e.Modifier.ToString() + " + " + e.Key.ToString())
                {
                    //ScreenActive();
                }
            } 
        }

        public void ScreenArea()
        {
            //Hide Form
            this.Hide();

            //Lauch screenshot form as a Dialog 
            Screenshot oForm2 = new Screenshot();
            oForm2.MyParentForm = this;
            if (oForm2.ShowDialog() == DialogResult.Abort)
            {
                //Do Nothing. Screenhot Cancelled.
            }
            else
            {
                //Display Image
                picSave.Image = oForm2.UserName.Image;
                bmpScreenshot = (Bitmap)picSave.Image;

                //Enabled Save? Controls
                picSave.Enabled = true;
                btnPreview.Enabled = true;
                btnUpload.Enabled = true;
                btnCancel.Enabled = true;

                //Show Form Again
                this.WindowState = FormWindowState.Normal;
                tabControl1.SelectedTab = tabPage6;
            }

            //Reshow Form
            this.Show();
        }
        private void ScreenActive()
        {
            //Not Implemented
        }

        private void comboFile_SelectedIndexChanged(object sender, EventArgs e)
        {
            //Keeps file extension correct on form
            lbExt.Text = "." + comboFile.Text;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            // Enables/Disables Prefix Textbox
            if (checkPrefix.Checked)
            {
                txtPrefix.Enabled = true;
            }
            else
            {
                txtPrefix.Enabled = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("http://super3.org");
        }

        private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            Show();
        }

        public string alphakey()
        {
            Random r = new Random();
            int len = 5;

            string str= "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
            StringBuilder sb = new StringBuilder();

            while ((len--) > 0)
                sb.Append(str[(int)(r.NextDouble() * str.Length)]);

            return sb.ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            SoundPlayer sound = new SoundPlayer(ScreenToFTP.Properties.Resources.Pass);
            sound.Play();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            SoundPlayer sound = new SoundPlayer(ScreenToFTP.Properties.Resources.Fail);
            sound.Play();
        }

        private Boolean UploadFile(string filename)
        {
            //Set Varibles
            string ftpServerIP = txtHost.Text.ToString();
            string ftpUserID = txtUser.Text.ToString();
            string ftpPassword = txtPass.Text.ToString();
            string ftpPath = txtPath.Text.ToString();
            string url = txtUrl.Text.ToString() + ftpPath + Path.GetFileName(filename);

            FileInfo fileInf = new FileInfo(filename);
            string uri = "ftp://" +
            ftpServerIP + ftpPath + fileInf.Name;
            FtpWebRequest reqFTP;

            // Create FtpWebRequest object from the Uri provided
            reqFTP = (FtpWebRequest)FtpWebRequest.Create(new Uri("ftp://" + ftpServerIP +
            ftpPath + fileInf.Name));

            // Provide the WebPermission Credintials
            reqFTP.Credentials = new NetworkCredential(ftpUserID, ftpPassword);

            // By default KeepAlive is true, where the control connection is not closed
            // after a command is executed.
            reqFTP.KeepAlive = false;

            // Specify the command to be executed.
            reqFTP.Method = WebRequestMethods.Ftp.UploadFile;

            // Specify the data transfer type.
            reqFTP.UseBinary = true;

            // Notify the server about the size of the uploaded file
            reqFTP.ContentLength = fileInf.Length;

            // The buffer size is set to 2kb
            int buffLength = 2048;
            byte[] buff = new byte[buffLength];
            int contentLen;

            // Opens a file stream (System.IO.FileStream) to read the file to be uploaded
            FileStream fs = fileInf.OpenRead();

            try
            {
                // Stream to which the file to be upload is written
                Stream strm = reqFTP.GetRequestStream();

                // Read from the file stream 2kb at a time
                contentLen = fs.Read(buff, 0, buffLength);

                // Till Stream content ends
                while (contentLen != 0)
                {
                    // Write Content from the file stream to the FTP Upload Stream
                    strm.Write(buff, 0, contentLen);
                    contentLen = fs.Read(buff, 0, buffLength);
                }

                // Close the file stream and the Request Stream
                strm.Close();
                fs.Close();

                //MessageBox.Show("Upload Worked");
                status(true);
                return true;                
            }
            catch (Exception ex)
            {
                error = ex.Message.ToString();
                status(false);  
                return false; 
            }
        }

        private void Upload(string filename)
        {
            notifyIcon1.BalloonTipTitle = "ScreenToFTP";
            notifyIcon1.BalloonTipText = "Uploading...";
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Info;
            notifyIcon1.ShowBalloonTip(10);

            String url = txtUrl.Text.ToString() + txtPath.Text.ToString() +
            Path.GetFileName(filename);

            if (UploadFile(filename))
            {
                //Play Sound, Copy to Clipboard, and Edit Textboxes
                lbMessage.Text = ("Upload Successful.");
                lbError.Visible = false; lbError.Enabled = false;

                Clipboard.SetDataObject(url, true);
                txtScreenURL.Text = url.ToString();

                if (comboSounds.Text == "Enabled")
                {
                    SoundPlayer sound = new SoundPlayer(ScreenToFTP.Properties.Resources.Pass);
                    sound.Play();
                }

                //Disable Everyting
                picSave.Enabled = false;
                btnPreview.Enabled = false;
                btnUpload.Enabled = false;
                btnCancel.Enabled = false;

                picSave.Image = ScreenToFTP.Properties.Resources.noimage;

                tabControl1.SelectedTab = tabPage1;

                notifyIcon1.BalloonTipTitle = "ScreenToFTP";
                notifyIcon1.BalloonTipText = "Success! URL Copied to clipboard.";
                notifyIcon1.ShowBalloonTip(10);
            }
            else
            {
                notifyIcon1.BalloonTipTitle = "ScreenToFTP";
                notifyIcon1.BalloonTipText = "Upload Failed.";
                notifyIcon1.ShowBalloonTip(10);

                //Play Sound and Edit Textboxes
                lbMessage.Text = ("Upload Failed.");
                lbError.Visible = true; lbError.Enabled = true;

                //MessageBox.Show(ex.Message, "Upload Error");

                if (comboSounds.Text == "Enabled")
                {
                    SoundPlayer sound = new SoundPlayer(ScreenToFTP.Properties.Resources.Fail);
                    sound.Play();
                }
            }
        }

        private void status(bool connect)
        {
            if (connect)
            {
                lbStatus.Text = "Connected";
                lbStatus.ForeColor = Color.Green;
            }
            else
            {
                lbStatus.Text = "Not Connected";
                lbStatus.ForeColor = Color.Red;
            }
        }

        private void UploadTest(string filename)
        {
            String url = txtUrl.Text.ToString() + txtPath.Text.ToString() +
                Path.GetFileName(filename);

            btnTestFtp.Enabled = false;
            try
            {
                if (UploadFile(filename) && DoesExsist(url))
                {
                    lbGood.Visible = true;
                    label19.Visible = false;
                }
                else
                {
                    lbGood.Visible = false;
                    label19.Visible = true;
                }
            }
            catch
            {
                lbGood.Visible = false;
                label19.Visible = true;
            }
            btnTestFtp.Enabled = true;
        }

        private void checkImageFolder()
        {
            String path = Application.StartupPath + "\\images\\";

            if (File.Exists(path))
            {
                //Do nothing.
            }
            else
            {
                //Create One
                Directory.CreateDirectory(path);
            }

        }

        private void btnTestFtp_Click(object sender, EventArgs e)
        {
            //Check or Create /images folder
            checkImageFolder();

            //Save test.png Image
            PictureBox pictureBox1 = new PictureBox();
            pictureBox1.Image = ScreenToFTP.Properties.Resources.test;
            pictureBox1.Image.Save(Application.StartupPath + "\\images\\test.png", ImageFormat.Png);

            //Attempt Upload
            UploadTest(Application.StartupPath + "\\images\\test.png");
        }

        private Boolean DoesExsist(string url)
        {
            Uri urlCheck = new Uri(url);
            WebRequest request = WebRequest.Create(urlCheck);
            request.Timeout = 15000;

            WebResponse response;
            try
            {
                response = request.GetResponse();
                return true;
            }
            catch (Exception)
            {
                return false; //url does not exist
            }
        }

        private void lbError_Click(object sender, EventArgs e)
        {
            MessageBox.Show(error);
        }

        private void btnSaveFTP_Click(object sender, EventArgs e)
        {
            //Sets FTP Info
            Properties.Settings.Default.ftpHost = txtHost.Text;
            Properties.Settings.Default.ftpUser = txtUser.Text;
            Properties.Settings.Default.ftpPass = txtPass.Text;
            Properties.Settings.Default.ftpPath = txtPath.Text;
            Properties.Settings.Default.ftpUrl = txtUrl.Text;

            Properties.Settings.Default.Save();
        }

        private void btnSaveConfig_Click(object sender, EventArgs e)
        {
            //Sets Configuration Info
            Properties.Settings.Default.fileType = comboFile.SelectedIndex;
            Properties.Settings.Default.soundEnabled = comboSounds.SelectedIndex;
            Properties.Settings.Default.prefixEnabled = checkPrefix.Checked;
            Properties.Settings.Default.prefix = txtPrefix.Text;

            Properties.Settings.Default.Save();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("http://super3.org/ScreenToFTP");
        }

        private void btnSaveHot_Click(object sender, EventArgs e)
        {
            //Make Warning Visible
            lbWarning.Visible = true;

            //Save Hotkey Info
            Properties.Settings.Default.hotFull = SaveHotKeys(checkFullAlt, checkFullControl,
                          checkFullShift, checkFullWin, comboFullKey);
            Properties.Settings.Default.hotArea = SaveHotKeys(checkAreaAlt, checkAreaControl,
                          checkAreaShift, checkAreaWin, comboAreaKey);
            Properties.Settings.Default.hotActive = SaveHotKeys(checkActiveAlt, checkActiveControl,
                          checkActiveShift, checkActiveWin, comboActiveKey);

            Properties.Settings.Default.Save();
        }

        private void btnShot_Click(object sender, EventArgs e)
        {
            ScreenArea();
        }

        private static Bitmap bmpScreenshot;
        private static Graphics gfxScreenshot;

        private void ScreenFull()
        {  
            //Conceal this form while the screen capture takes place
            this.Hide();

            //Allow 250 milliseconds for the screen to repaint itself
            System.Threading.Thread.Sleep(250);

            // Set the bitmap object to the size of the screen
            bmpScreenshot = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height, PixelFormat.Format32bppArgb);

            // Create a graphics object from the bitmap
            gfxScreenshot = Graphics.FromImage(bmpScreenshot);

            // Take the screenshot from the upper left corner to the right bottom corner
            gfxScreenshot.CopyFromScreen(Screen.PrimaryScreen.Bounds.X, Screen.PrimaryScreen.Bounds.Y, 0, 0, Screen.PrimaryScreen.Bounds.Size, CopyPixelOperation.SourceCopy);

            picSave.Image = bmpScreenshot;

            picSave.Enabled = true;
            btnPreview.Enabled = true;
            btnUpload.Enabled = true;
            btnCancel.Enabled = true;

            //Show Form Again
            this.Show();
            this.WindowState = FormWindowState.Normal;

            tabControl1.SelectedTab = tabPage6;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            //Disable Everyting
            picSave.Enabled = false;
            btnPreview.Enabled = false;
            btnUpload.Enabled = false;
            btnCancel.Enabled = false;

            picSave.Image = ScreenToFTP.Properties.Resources.noimage;

            tabControl1.SelectedTab = tabPage1;
        }

        private void btnUpload_Click(object sender, EventArgs e)
        {
            //Hide
            this.Hide();
            
            //Generate Filename
            String filename = alphakey();
            if (checkPrefix.Checked) { filename = txtPrefix.Text + filename; }
            filename = Application.StartupPath + "\\images\\" + filename.ToString();

            // Save the screenshot to the specified path that the user has chosen
            if (comboFile.Text == "PNG")
            {
                filename += ".png";
                bmpScreenshot.Save(filename, ImageFormat.Png);
            }
            else
            {
                filename += ".jpeg";
                bmpScreenshot.Save(filename, ImageFormat.Jpeg);
            }

            Upload(filename);
        }

        private void btnPreview_Click(object sender, EventArgs e)
        {
            Preview previewForm = new Preview(picSave);
            previewForm.Show();
        }

        private void btnHide_Click(object sender, EventArgs e)
        {
            Hide();
        }

        private void btnQuit_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
