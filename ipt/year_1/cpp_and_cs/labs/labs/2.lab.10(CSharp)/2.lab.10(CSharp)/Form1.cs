using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace _2.lab._10_CSharp_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            button1.Left = r.Next(0, this.Size.Width - button1.Width);
            button1.Top = r.Next (0, this.Size.Height - button1.Height);
        }
    }
}
