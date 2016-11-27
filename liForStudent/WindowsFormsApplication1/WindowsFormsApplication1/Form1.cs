using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            //button_table = new System.Windows.Forms.Button[3, 3];
            //for (int i = 0; i != 2; ++i)
            //{
            //    for (int ii = 0; ii != 2; ++ii)
            //    {
            //        button_table[i, ii] = new System.Windows.Forms.Button();
            //        button_table[i, ii].Location = new System.Drawing.Point(16, 15);
            //        button_table[i, ii].Name = "me";
            //        button_table[i, ii].Size = new System.Drawing.Size(500, 500);
            //        button_table[i, ii].TabIndex = 0;
            //        button_table[i, ii].Text = "you";
            //        button_table[i, ii].UseVisualStyleBackColor = true;
            //    }
            //}
            
            //this.panel1 = new Panel();
            //this.button1 = new Button();
            //this.button1.Location = new System.Drawing.Point(179, 110);
            //this.button1.Name = "you";
            //this.button1.Size = new System.Drawing.Size(75, 23);
            //this.button1.TabIndex = 0;
            //this.button1.Text = "";
            //this.button1.UseVisualStyleBackColor = true;

            //this.panel1.Controls.Add(this.button1);
            //this.Controls.Add(this.button1);
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button2_MouseUp(object sender, MouseEventArgs e)
        {
            MessageBox.Show("hah");

        }

        private void button2_CursorChanged(object sender, EventArgs e)
        {
            MessageBox.Show("hah");

        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            MessageBox.Show("hah");
        }

        private void statusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void toolStripTextBox1_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("fuck you");
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
