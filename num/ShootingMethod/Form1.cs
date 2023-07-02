using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace ShootingMethod
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            double stepSize = 0.001;
            double targetValue = 10;

            // Метод стрельбы
            double y0 = 0.0; // Начальное значение y
            double yp0 = targetValue; // Начальное значение производной y
            double x = 0.0; // Начальное значение x

            double y = y0;
            double yp = yp0;

            while (x <= 1.0)
            {
                double sh = Math.Sinh(x);
                double dy = yp * stepSize;
                double dyp = (-sh * yp - 5.0 * y) * stepSize;
                y += dy;
                yp += dyp;
                x += stepSize;

                chart1.Series[0].Points.AddXY(x, y);
            }

            label1.Text += $" {y} (при x = {x})";
        }
    }
}
