using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace MapEditor
{
    public partial class FrmQuadTree : Form
    {
        private Image imageObject;
        private Bitmap bitmapMap;
        private Graphics graphic;
        private int SizeMap;
        private List<Nodes> listNodes = new List<Nodes>();
        private List<TreeObject> listObject = new List<TreeObject>();
        private Nodes quadTree;

        private String resource;
        private int width;
        private int height;
        private int column;
        private int row;
        private int[][] matrix;
        private Nodes Root;

        public FrmQuadTree()
        {
            InitializeComponent();
            listNodes.Clear();
            listObject.Clear();

            //InitializeComponent();
            resource = "";
            width = 0;
            height = 0;
            column = 0;
            row = 0;
            matrix = null;
            this.btDivQuadTree.Enabled = false;
        }

        private void ptrMap_Click(object sender, EventArgs e)
        {

        }

        private void btInit_Click(object sender, EventArgs e)
        {
            //Load Map

            FileManager file = new FileManager();
            file.ReadFile(ref resource, ref width, ref height, ref row, ref column, ref matrix);
            Bitmap imageTiled = new Bitmap(resource);
            int widthMap = column * width;
            int heightMap = row * height;

            SizeMap = widthMap;
            quadTree = new Nodes(0, new Rectangle(0, 0, SizeMap, SizeMap));

            this.ptrMap.Width = SizeMap;
            this.ptrMap.Height = this.ptrMap.Width;
            this.ptrMap.BackColor = Color.Black;

            this.bitmapMap = new Bitmap(SizeMap, SizeMap);
            graphic = Graphics.FromImage(bitmapMap);
            graphic.FillRectangle(new Pen(Color.Black).Brush, new Rectangle(0, 0, SizeMap, SizeMap));
            //this.ptrMap.Image = bitmapMap;
            this.btInit.Text = "Reset";

            //Graphics graphics = Graphics.FromImage(bitmapMap);
            Rectangle rect = new Rectangle(0, 0, width, height);

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    rect.X = matrix[i][j] * width;
                    graphic.DrawImage(imageTiled, j * width, (widthMap - heightMap) + i * height, rect, GraphicsUnit.Pixel);
                }
            }

            //this.ptrMap.Width = bitmapMap.Width;
            //this.ptrMap.Height = bitmapMap.Height;
            this.ptrMap.Image = bitmapMap;
            this.btDivQuadTree.Enabled = true;

            this.Root = new Nodes(1, new Rectangle(0, 0, widthMap, widthMap));
            this.listNodes.Clear();
            this.listObject.Clear();
        }

        private void btDivQuadTree_Click(object sender, EventArgs e)
        {
            //QuaTree Map mau Blue
            for (int i = 0; i < 10; i++)
            {
                Pen pBlue = new Pen(Color.Red);
                graphic.DrawRectangle(pBlue, new Rectangle(i * 10, i * 10, 200, 200));
            }
            //Thay doi pictureMap
            this.ptrMap.Image = bitmapMap;
        }

        private void cbbObject_TextChanged(object sender, EventArgs e)
        {
            Image imageTile = Image.FromFile("D:\\D\\Data\\" + this.cbbObject.Text.ToString() + ".png");
            this.tbWidth.Text = imageTile.Width.ToString();
            this.textBox2.Text = imageTile.Height.ToString();
            this.ptrObject.Image = imageTile;
            imageObject = imageTile;
        }

        private void ptrObject_Click(object sender, EventArgs e)
        {
            //imageObject = 
        }

        private void ptrMap_MouseClick(object sender, MouseEventArgs e)
        {
            graphic.DrawImage(imageObject, new Rectangle(e.X, e.Y, imageObject.Width, imageObject.Height), new Rectangle(0, 0, imageObject.Width, imageObject.Height), GraphicsUnit.Pixel);
            this.ptrMap.Image = bitmapMap;

            TreeObject objectTemp = new TreeObject();
            objectTemp.setID(int.Parse(this.cbbObject.Text.ToString()));
            objectTemp.setRect(new Rectangle(e.X, e.Y, imageObject.Width, imageObject.Height));
            listObject.Add(objectTemp);
        }

        private void ptrMap_MouseMove(object sender, MouseEventArgs e)
        {
            this.tbX.Text = e.X.ToString();
            this.tbY.Text = e.Y.ToString();
        }

        private void btOk_Click(object sender, EventArgs e)
        {

            string s = "";
            foreach (TreeObject obj in listObject)
            {
                s += obj.getID().ToString() + " : ";
                this.Root.Insert(obj);
            }

            Pen pBlue = new Pen(Color.Red);
            List<Nodes> listNodes = new List<Nodes>();
            this.Root.getListNodes(listNodes);

            foreach (Nodes node in listNodes)
                graphic.DrawRectangle(pBlue, node.getBound());

            this.ptrMap.Image = bitmapMap;

            //MessageBox.Show(s);

            List<TreeObject> mylistTreeObject1 = new List<TreeObject>();

            String path = "D:\\D\\QuadTree.txt";
            StreamWriter writer = File.CreateText(path);

            foreach (Nodes node in listNodes)
            {
                if (!node.idLeaf())
                {
                    writer.WriteLine(node.getID().ToString() + "\t" + node.getBound().X.ToString() + "\t" + node.getBound().Y.ToString() + "\t" + node.getBound().Width.ToString() + "\t" + node.getBound().Height.ToString());
                }
                else 
                {
                    writer.WriteLine(node.getID().ToString() + "\t" + node.getBound().X.ToString() + "\t" + node.getBound().Y.ToString() + "\t" + node.getBound().Width.ToString() + "\t" + node.getBound().Height.ToString() + "\t" + node.getStringIDObject());
                }
            }

            writer.WriteLine("Nguyen Trung Hieu");

            writer.Flush();
            writer.Close();



        }
    }
}
