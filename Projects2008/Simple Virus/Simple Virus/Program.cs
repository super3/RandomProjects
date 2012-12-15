using System;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Net;

namespace Simple_Virus
{
    class Program
    {
        static void Main(string[] args)
        {
            WebClient Client = new WebClient();
            Client.DownloadFile("http://www.csharpfriends.com/Members/index.aspx", " index.aspx");
        }
    }
}
