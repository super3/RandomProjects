using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;

namespace LifeSimulator
{
    public partial class Form1 : Form
    {
        public int[,] grid = new int[31, 31];
        ArrayList space = new ArrayList();

        public Form1()
        {
            InitializeComponent();
            space.Add(new Ameba(5, 5));
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            Brush water = new SolidBrush(Color.Blue);
            Brush ameba = new SolidBrush(Color.Green);

            int x = 0, y = 0;
            while (y <= 300)
            {
                while (x <= 300)
                {
                    if (grid[(x / 10), (y / 10)] == 1)
                    {
                        e.Graphics.FillRectangle(ameba, x, y, 5, 5);
                    }
                    else
                    {
                        e.Graphics.FillRectangle(water, x, y, 5, 5);
                    }
                    x += 5;
                }
                x = 0;
                y += 5;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int x=0, y=0;
            while (y <= 30)
            {
                while (x <= 30)
                {
                    grid[x, y] = 0;
                    x += 5;
                }
                x = 0;
                y += 5;
            }

            foreach (Ameba ameba in space)
            {
                ameba.move();

                grid[ameba.getX(), ameba.getY()] = 1;
                pictureBox1.Invalidate();
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            int x = 0, y = 0;
            while (y <= 30)
            {
                while (x <= 30)
                {
                    grid[x, y] = 0;
                    x += 1;
                }
                x = 0;
                y += 1;
            }

            ArrayList tmp = new ArrayList();

            foreach (Ameba ameba in space)
            {
                ameba.move();
                if (ameba.reproduce())
                {
                    if( ameba.canMove( ameba.getX() + 1, ameba.getY()))
                    { tmp.Add(new Ameba(ameba.getX() + 1, ameba.getY())); }
                }
                grid[ameba.getX(), ameba.getY()] = 1;
            }

            if (tmp != null) {
                foreach (Ameba insert in tmp)
                {
                    space.Add(insert);
                }          
            }

            pictureBox1.Invalidate();
        }
    }

    public class Ameba
    {
        private int x, y;
        private int steps = 0;
        private Random rand = new Random();

        public Ameba(int _x, int _y)

        {
            x = _x;
            y = _y;
        }
        public void move()
        {
            int decision = rand.Next(0, 8);

            if (decision == 0) { }
            else if (decision == 1 && canMove((x - 1), (y - 1))) { x -= 1; y -= 1; }
            else if (decision == 2 && canMove(x, (y - 1))) { y -= 1; }
            else if (decision == 3 && canMove((x + 1), (y - 1))) { x += 1; y -= 1; }
            //else if (decision == 4 && canMove((x + 1), y)) { x += 1; }
            else if (decision == 5 && canMove((x + 1), (y + 1))) { x += 1; y += 1; }
            else if (decision == 6 && canMove(x, (y + 1))) { y += 1; }
            else if (decision == 7 && canMove((x - 1), (y + 1))) { x -= 1; y += 1; }
            else if (decision == 8 && canMove((x - 1), (y))) { x -= 1; }
            else { }

            steps++;
        }
        public bool canMove(int _x, int _y)
        {
            bool result = true;
            if (!(_x >= 0 && _x < 30)) { result = false; }
            if (!(_y >= 0 && _y < 30)) { result = false; }
            //Check for other Amebas
            return result;
        }
        public int getX()
        {
            return x;
        }
        public int getY()
        {
            return y;
        }
        public bool reproduce()
        {
            if (steps == 12) { steps = 0; return true; }
            else { return false; }
        }
    }
}
