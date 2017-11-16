using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;
//using System.Windows.Media;

namespace _2.lab._9_C_Sharp_
{
    public partial class Rectangle : Form
    {
        public Rectangle()
        {
            InitializeComponent();
        }
        bool t=false;
        int i1 = 255;
        int j1 = 0;
        int k1 = 0;
        int i2 = 0;
        int j2 = 0;
        int k2 = 255;
        private void button1_Click(object sender, EventArgs e)
        {
            if (t == false)
            {
            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics graph = Graphics.FromImage(bmp);
            LinearGradientBrush brsh = new LinearGradientBrush(new Point(0, 0), new Point(pictureBox1.Width, pictureBox1.Height), Color.FromArgb(255, i1, j1, k1), Color.FromArgb(255, i2, j2, k2));
            //brsh.StartPoint = new Point(0, 0);
            //brsh.EndPoint = new Point(pictureBox1.Width, pictureBox1.Height);
            //brsh.GradientStops.Add(new GradientStop(Colors.Yellow, 0.0));
            //brsh.GradientStops.Add(new GradientStop(Colors.Red, 0.25));
            //brsh.GradientStops.Add(new GradientStop(Colors.Blue, 0.75));
            //brsh.GradientStops.Add(new GradientStop(Colors.LimeGreen, 1.0));
            Rectangle rect = new Rectangle();
            rect.Height = pictureBox1.Height;
            rect.Width = pictureBox1.Width;
            graph.FillRectangle(brsh, 0, 0, pictureBox1.Width, pictureBox1.Height);
            pictureBox1.BackgroundImage = bmp;
            t = true;
            }
            else
            {
                Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
                Graphics graph = Graphics.FromImage(bmp);
                if (i1 < 100)
                {
                    i1 = i1 + 150;
                }
                else
                {
                    i1 = i1 - 100;
                }
                if (k2 < 100)
                {
                    k2 = k2 + 150;
                }
                else
                {
                    k2 = k2 - 100;
                }
                if (j1 > 155)
                {
                    j1 = j1 - 150;
                }
                else
                {
                    j1 = j1 + 100;
                }
                if (k1 > 155)
                {
                    k1 = k1 - 150;
                }
                else
                {
                    k1 = k1 + 100;
                }
                if (i2 > 155)
                {
                    i2 = i2 - 150;
                }
                else
                {
                    i2 = i2 + 100;
                }
                if (j2 > 155)
                {
                    j2 = j2 - 150;
                }
                else
                {
                    j2 = j2 + 100;
                }
                LinearGradientBrush brsh = new LinearGradientBrush(new Point(0, 0), new Point(pictureBox1.Width, pictureBox1.Height), Color.FromArgb(255, i1, j1, k1), Color.FromArgb(255, i2, j2, k2));
                Rectangle rect = new Rectangle();
                rect.Height = pictureBox1.Height;
                rect.Width = pictureBox1.Width;
                graph.FillRectangle(brsh, 0, 0, pictureBox1.Width, pictureBox1.Height);
                pictureBox1.BackgroundImage = bmp;
                //t = true;
            }
        }
    }
}
