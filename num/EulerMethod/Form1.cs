using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EulerMethod
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            var a = Euler.EulerDefault();

            foreach (var item in a)
            {
                chart1.Series[0].Points.AddXY(item[0], item[1]);
                chart1.Series[1].Points.AddXY(item[0], item[2]);

                richTextBox1.Text +=  $"Точка: x: {item[0]}; y: {item[0]}\n";
                richTextBox1.Text += $"Точка: x: {item[0]}; z: {item[2]}\n";
            }
        }
    }
}
