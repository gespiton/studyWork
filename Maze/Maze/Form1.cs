using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;
using System.Windows;
using System.IO;
namespace Maze
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            block_table = new My_button[10, 10];
            for(int row = 0;row!= 10; ++row)
            {
                for(int col = 0;col!= 10; ++col)
                {
                    // appearance
                    My_button button_ref = new My_button();
                    button_ref.Location = new Point(col*70,row * 70);
                    button_ref.Name = row.ToString() + col.ToString();
                    button_ref.Size = new Size(70, 70);
                    button_ref.TabIndex = row * 10 + col;
                    //button_ref.Text = button_ref.Name;
                    button_ref.FlatStyle = FlatStyle.Flat;
                    button_ref.FlatAppearance.BorderSize = 1;
                    button_ref.FlatAppearance.BorderColor = Color.AntiqueWhite;
                    button_ref.BackColor = Color.AliceBlue;

                    // event creator
                    button_ref.Click += new EventHandler(button_Click);

                    //
                    button_ref.pos = new int[] { row, col };

                    // list manager
                    blocked = new List<int[]>();

                    maze.Controls.Add(button_ref);
                    block_table[row, col] = button_ref;
                }
            }


            //Button my_button = new Button();
            //my_button.Location = new Point(72, 0);
            //maze.Controls.Add(my_button);

            start_point = new int[] { 0, 0 };
            ent_point = new int[] { 9, 9 };
            route = new Stack<int[]>();


        }
        public class My_button : Button
        {
            public bool isBlock { get; set; }
            public int[] pos { get; set; }

            private void InitializeComponent()
            {
                this.SuspendLayout();
                this.ResumeLayout(false);
            }
        }
        

        private void button_Click(object sender, EventArgs e)
        {
            var buf = (My_button)sender;
            if (buf.BackColor == Color.Gray)
            {

                buf.BackColor = Color.AliceBlue;
                buf.isBlock = false;
                --num_blocks;
                //blockedChanged(new int[] { (int)buf.Name[0], (int)buf.Name[1] });
            }
            else
            {
                buf.BackColor = Color.Gray;
                buf.isBlock = true;
                ++num_blocks;
                //blocked.Add(new int[] { (int)buf.Name[0], (int)buf.Name[1] });
            }
            //buf.BackColor = (buf.BackColor == Color.Gray) ? Color.AliceBlue : Color.Gray;
            this.blocks_show.Text = num_blocks.ToString();


        }
        private void blockedChanged(int[] dest)
        {
            int i = -1, ii = 0 ;
            foreach(var ite in blocked)
            {
                if (ite.SequenceEqual(dest))
                    i = ii;
                ++ii;
            }
            blocked.RemoveAt(i);
            
        }


        private bool get_status(int row , int col)
        {
            return !block_table[row, col].isBlock;
        }

        
        private bool not_worked(int row, int col)
        {
            foreach(var ite in route)
            {
                if (ite[0]==row&&ite[1]==col)
                {
                    return false;
                }
            }
            return true;
        }

        private void find_route(int[] start_point)
        {
            route.Clear();
            for (int row = 0; row != 10; ++row)
            {
                for (int col = 0; col != 10; ++col)
                {
                    block_table[row, col].isBlock = block_table[row, col].BackColor == Color.Gray ? true : false;
                }
            }
            StreamWriter recoder = new StreamWriter(File.Create(@"D:\我的文档\Desktop\rote.txt"));

            route.Push(start_point);
      
            while (route.Count != 0)
            {
                //if(block_table[start_point[0],start_point[1]])

                var row = route.Peek()[0];
                var col = route.Peek()[1];
                recoder.WriteLine(row + "  " + col);
                // reach the end
                if(ent_point[0]==row&&ent_point[1] == col)
                {
                    break;
                }


                // go up
                if (0<row&&get_status(row-1,col)&&not_worked(row-1,col))
                {
                    route.Push(new int[] { row - 1, col });
                    continue;
                }
                // go right 
                if(col<9&& get_status(row,col+1)&& not_worked(row, col + 1))
                {
                    route.Push(new int[] { row, col + 1 });
                    continue;
                }

                // go down
                if (row<9&&get_status(row+1,col)&&not_worked(row+1,col))
                {
                    route.Push(new int[] { row + 1, col });
                    continue;
                }

                // go left
                if (col > 0 && get_status(row, col - 1) && not_worked(row, col - 1))
                {
                    route.Push(new int[] { row, col - 1 });
                    continue;
                }


                // no path
                block_table[row, col].isBlock = true;
                route.Pop();
                continue;

            }
            recoder.Dispose();


           
            if(route.Count!=0)
            {

                var itee = route.ToList();
                
                for (int i = itee.Count-1; i >= 0; i--)
                {
                    //itee.MoveNext();
                    block_table[itee[i][0], itee[i][1]].BackColor = Color.LightGreen;

                    block_table[itee[i][0], itee[i][1]].Refresh();
                    Thread.Sleep(50);

                }
                MessageBox.Show("found");
                foreach (var ite in route)
                {
                    block_table[ite[0], ite[1]].BackColor = Color.AliceBlue;
                }

            }
            else
            {
                MessageBox.Show("not found");
            }
        }


        //private List<int[]> blocked;
        private List<int[]> blocked { get; set; }
        public int num_blocks { get; set; }

        private Stack<int[]> route { get; set; }

        private int[] start_point { get; set; }

        public int[] ent_point { get; set; }

        private void button1_Click(object sender, EventArgs e)
        {
            find_route(start_point);
        }
    }

}
