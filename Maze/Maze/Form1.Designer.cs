namespace Maze
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.maze = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.blocks_show = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // maze
            // 
            this.maze.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.maze.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.maze.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.maze.Location = new System.Drawing.Point(10, 12);
            this.maze.Name = "maze";
            this.maze.Size = new System.Drawing.Size(702, 702);
            this.maze.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(728, 65);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(135, 15);
            this.label1.TabIndex = 1;
            this.label1.Text = "number of blocks";
            // 
            // blocks_show
            // 
            this.blocks_show.Location = new System.Drawing.Point(731, 96);
            this.blocks_show.Name = "blocks_show";
            this.blocks_show.Size = new System.Drawing.Size(100, 25);
            this.blocks_show.TabIndex = 2;
            this.blocks_show.Text = "0";
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.button1.Location = new System.Drawing.Point(731, 153);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(100, 50);
            this.button1.TabIndex = 3;
            this.button1.Text = "find";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(923, 724);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.blocks_show);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.maze);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Panel maze;
        private My_button [,] block_table;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox blocks_show;
        private System.Windows.Forms.Button button1;
    }
    class test
    {
        private System.Windows.Forms.Button button;
        public test()
        {
            button = new System.Windows.Forms.Button();
        }
    }
}

