using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml;
using System.IO;

namespace XML_Test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            XmlDocument doc = new XmlDocument();

            String strFileName = "books.xml";

            if (File.Exists(strFileName))
            {
                doc.Load(strFileName);
                //XmlElement elm = doc.DocumentElement;
                //MessageBox.Show(elm.Name);
                XmlTextReader elm = new XmlTextReader(strFileName);

                do
                {
                    switch (elm.NodeType)
                    {
                        case XmlNodeType.Text:
                            MessageBox.Show(elm.Value);
                            break;
                    }
                } while (elm.Read());

            }
            else { MessageBox.Show("The file " + strFileName + " was not found."); }
        }

        //public virtual void LoadXml(string xml);
        //public virtual void Save(string filename);
    }
}
