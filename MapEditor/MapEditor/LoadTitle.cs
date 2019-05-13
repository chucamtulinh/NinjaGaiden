using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MapEditor
{
    public partial class LoadTitle : Form
    {
        public LoadTitle()
        {
            InitializeComponent();
            m_height = 0;
            m_width = 0;
            m_path = "";
        }

        private String m_path; //Duong dan file Anh
        private int m_width; //Chieu nganh cua title
        private int m_height; //Chieu cao cua title
        private Image m_Image; //Hinh sau khi chia

        public String GetPath()
        {
            return m_path;
        }
        public int GetWidth()
        {
            return m_width;
        }
        public int GetHeight()
        {
            return m_height;
        }

        public Image GetImage()
        {
            return m_Image;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.ShowDialog();
            this.textBox1.Text = openFile.FileName.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            m_path = textBox1.Text.ToString();
            m_width = int.Parse(textBox2.Text.ToString());
            m_height = int.Parse(textBox3.Text.ToString());

            Image image = Image.FromFile(textBox1.Text.ToString());
            
            Graphics graphics = Graphics.FromImage(image);
            Pen pen = new Pen(Color.White, 1);

            for (int i = 0; i * m_height < image.Height; i++)
            {
                graphics.DrawLine(pen, 0, i * m_height, image.Width, i*m_height);
            }
            for (int i = 0; i * m_width < image.Width; i++)
            {
                graphics.DrawLine(pen, i * m_width, 0, i * m_width, image.Height);
            }

            this.pictureBox1.Image = image;
            this.m_Image = image;
        }
    }
}
