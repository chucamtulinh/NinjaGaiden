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
    public partial class FrmEditMap : Form
    {
        private String resource;
        private int width;
        private int height;
        private int column;
        private int row;
        private int[][] matrix;

        public FrmEditMap()
        {
            InitializeComponent();
            resource = "";
            width = 0;
            height = 0;
            column = 0;
            row = 0;
            matrix = null;
        }

        private void btOpenMap_Click(object sender, EventArgs e)
        {
            FileManager file = new FileManager();
            file.ReadFile(ref resource, ref width, ref height, ref row, ref column, ref matrix);
            Bitmap imageTiled = new Bitmap(resource);
            int widthMap = column * width;
            int heightMap = row * height;

            Bitmap imageMap = new Bitmap(widthMap, heightMap);

            Graphics graphics = Graphics.FromImage(imageMap);
            Rectangle rect = new Rectangle(0, 0, width, height);

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    rect.X = matrix[i][j] * width;
                    graphics.DrawImage(imageTiled, j * width, i * height, rect, GraphicsUnit.Pixel);
                }
            }

            this.ptrMap.Width = imageMap.Width;
            this.ptrMap.Height = imageMap.Height;
            this.ptrMap.Image = imageMap;
        }

        private void ptrMap_MouseDown(object sender, MouseEventArgs e)
        {
            //MessageBox.Show("row: " + (e.Y / height).ToString() + "\tcolumn: " + (e.X / width).ToString());
            //this.tbRow = 
            this.tbFindwhatValue.Text = matrix[e.Y / height][e.X / width].ToString();
            this.tbFindwhatRow.Text = (e.Y / height).ToString();
            this.tbFindwhatColumn.Text = (e.X / width).ToString();
        }

        private void ptrMap_MouseMove(object sender, MouseEventArgs e)
        {
            if (height != 0 && width != 0)
            {
                this.tbRow.Text = (e.Y / height).ToString();
                this.tbColumn.Text = (e.X / width).ToString();
            }
        }

        private void btRefresh_Click(object sender, EventArgs e)
        {
            Bitmap imageTiled = new Bitmap(resource);
            int widthMap = column * width;
            int heightMap = row * height;

            Bitmap imageMap = new Bitmap(widthMap, heightMap);

            Graphics graphics = Graphics.FromImage(imageMap);
            Rectangle rect = new Rectangle(0, 0, width, height);

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    rect.X = matrix[i][j] * width;
                    graphics.DrawImage(imageTiled, j * width, i * height, rect, GraphicsUnit.Pixel);
                }
            }

            this.ptrMap.Width = imageMap.Width;
            this.ptrMap.Height = imageMap.Height;
            this.ptrMap.Image = imageMap;
        }

        private void btReplace_Click(object sender, EventArgs e)
        {
            if (this.tbFindwhatRow.Text != "")
            {
                this.matrix[int.Parse(this.tbFindwhatRow.Text)][int.Parse(this.tbFindwhatColumn.Text)] = int.Parse(this.tbRelacewithValue.Text);

                Bitmap imageTiled = new Bitmap(resource);
                Bitmap imageMap = new Bitmap(this.ptrMap.Image);
                Graphics graphics = Graphics.FromImage(imageMap);
                Rectangle rect = new Rectangle(int.Parse(this.tbRelacewithValue.Text) * width, 0, width, height);
                graphics.DrawImage(imageTiled, int.Parse(this.tbFindwhatColumn.Text) * width, int.Parse(this.tbFindwhatRow.Text) * height, rect, GraphicsUnit.Pixel);
                this.ptrMap.Image = imageMap;
            }
        }

        private void btSave_Click(object sender, EventArgs e)
        {
            FileManager file = new FileManager();
            file.WriteFile(resource, width, height, row, column, matrix);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
