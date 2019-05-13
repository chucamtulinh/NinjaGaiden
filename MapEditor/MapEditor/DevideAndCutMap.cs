using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Imaging;
using System.Security.Cryptography;
using System.Threading;
using System.Runtime.InteropServices;

namespace MapEditor
{
    public partial class DevideAndCutMap : Form
    {
        private string pathImage;
        private int widthTitle;
        private int heightTitle;
        private Graphics graphics;
        private Image imageMap;
        private Bitmap bitmap;

        public DevideAndCutMap()
        {
            InitializeComponent();
        }

        private void btLoad_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFile = new OpenFileDialog();
            openFile.ShowDialog();
            pathImage = openFile.FileName.ToString();
        }

        private void btDevide_Click(object sender, EventArgs e)
        {
            imageMap = Image.FromFile(pathImage);
            bitmap = new Bitmap(imageMap);
            graphics = Graphics.FromImage(bitmap);
            this.widthTitle = int.Parse(this.tbWidth.Text.ToString());
            this.heightTitle = int.Parse(this.tbHeight.Text.ToString());
            Pen pen = new Pen(Color.White, 1);
            int i = 0;

            for (i = 0; i * this.heightTitle < imageMap.Height; i++)
            {
                graphics.DrawLine(pen, 0, i * this.heightTitle, imageMap.Width, i * this.heightTitle);
            }
            for (i = 0; i * this.widthTitle < imageMap.Width; i++)
            {
                graphics.DrawLine(pen, i * this.widthTitle, 0, i * this.widthTitle, imageMap.Height);
            }

            this.ptrMap.Image = bitmap;
            this.ptrMap.Width = bitmap.Width;
            this.ptrMap.Height = bitmap.Height;
            pen.Dispose();
        }

        private bool CompareBitmap(Bitmap bmp1, Bitmap bmp2) // so sanh hai bitmap co giong nhau trung khop?
        {
            if (bmp1 == null || bmp2 == null)
                return false;
            if (object.Equals(bmp1, bmp2))
                return true;
            if (!bmp1.Size.Equals(bmp2.Size) || !bmp1.PixelFormat.Equals(bmp2.PixelFormat))
                return false;

            int bytes = bmp1.Width * bmp1.Height * (Image.GetPixelFormatSize(bmp1.PixelFormat) / 8);
            byte[] b1bytes = new byte[bytes];
            byte[] b2bytes = new byte[bytes];
            BitmapData bitmapData1 = bmp1.LockBits(new Rectangle(0, 0, bmp1.Width - 1, bmp1.Height - 1), ImageLockMode.ReadOnly, bmp1.PixelFormat);
            BitmapData bitmapData2 = bmp2.LockBits(new Rectangle(0, 0, bmp2.Width - 1, bmp2.Height - 1), ImageLockMode.ReadOnly, bmp2.PixelFormat);
            Marshal.Copy(bitmapData1.Scan0, b1bytes, 0, bytes);
            Marshal.Copy(bitmapData2.Scan0, b2bytes, 0, bytes);
            bool result = true;

            for (int n = 0; n < bytes; n++)
            {
                if (b1bytes[n] != b2bytes[n])
                {
                    result = false;
                    break;
                }
            }

            bmp1.UnlockBits(bitmapData1);
            bmp2.UnlockBits(bitmapData2);
            return result;
        }

        private Rectangle CreateRectangle(int index, int column, int width, int height)
        {
            Rectangle rectangle = new Rectangle();
            rectangle.X = index % column * width;
            rectangle.Y = index / column * height;
            rectangle.Width = width;
            rectangle.Height = height;
            return rectangle;
        }

        private void btSave_Click(object sender, EventArgs e)
        {
            int column = (this.imageMap.Width / this.widthTitle);
            int row = (this.imageMap.Height / this.heightTitle);
            int numberTitle = column * row;
            int[][] matrixMap;
            List<int> listMSofTitle = new List<int>();
            matrixMap = new int[row][];

            for (int i = 0; i < row; i++)
            {
                matrixMap[i] = new int[column];
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    matrixMap[i][j] = -1;
                }
            }

            List<Rectangle> listBitmapMap = new List<Rectangle>();
            List<Rectangle> listBitmapTitle = new List<Rectangle>();

            for (int i = 0; i < numberTitle; i++)
            {
                listBitmapMap.Add(CreateRectangle(i, column, this.widthTitle, this.heightTitle));
            }

            Bitmap bmpMain = new Bitmap(this.widthTitle, this.heightTitle); // 1 anh chinh
            Graphics gMain = Graphics.FromImage(bmpMain);
            Bitmap bmpCheck = new Bitmap(this.widthTitle, this.heightTitle); // 1 anh phu de kiem tra
            Graphics gCheck = Graphics.FromImage(bmpCheck);
            bitmap = new Bitmap(imageMap);
            bool result = true;
            listBitmapTitle.Add(listBitmapMap[0]);
            listMSofTitle.Clear(); // stack so, vd listMSofTitle[11] = 2 tuc la o index 11 trung voi o tileset 2
            listMSofTitle.Add(0);

            for (int i = 1; i < numberTitle; i++)
            {
                gMain.DrawImage(bitmap, 0, 0, listBitmapMap[i], GraphicsUnit.Pixel); // ve o co so index i len anh chinh
                for (int k = 0; k < listBitmapTitle.Count(); k++)
                {
                    gCheck.DrawImage(this.bitmap, 0, 0, listBitmapTitle[k], GraphicsUnit.Pixel); // ve tile k cua tileset len anh phu
                    if (CompareBitmap(bmpMain, bmpCheck))
                    {
                        result = false;
                        listMSofTitle.Add(k);
                        break;
                    }
                    gCheck.Clear(Color.White);
                }
                if (result)
                {
                    listBitmapTitle.Add(listBitmapMap[i]);
                    listMSofTitle.Add(listBitmapTitle.Count - 1);
                }
                gMain.Clear(Color.White);
                result = true;
            }

            int[][] matrixSaveMap = new int[row][];
            for (int i = 0; i < row; i++)
            {
                matrixSaveMap[i] = new int[column];
            }

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    matrixSaveMap[i][j] = listMSofTitle[j + i * column];
                }
            }

            Bitmap bitmapFinish = new Bitmap(listBitmapTitle.Count * this.widthTitle, this.heightTitle);
            Graphics gFinish = Graphics.FromImage(bitmapFinish);
            bitmap = new Bitmap(imageMap);
            for (int i = 0; i < listBitmapTitle.Count; i++)
            {
                gFinish.DrawImage(this.bitmap, this.widthTitle * i, 0, listBitmapTitle[i], GraphicsUnit.Pixel);
            }

            this.ptrMap.Image = bitmapFinish;
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Title = " Save file...";
            saveFileDialog1.InitialDirectory = "D:\\D\\";
            saveFileDialog1.DefaultExt = "jpg";
            saveFileDialog1.Filter = " Image file (*.PNG)|*.png";
            saveFileDialog1.OverwritePrompt = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
                this.ptrMap.Image.Save(saveFileDialog1.FileName);

            FileManager writeFile = new FileManager();
            writeFile.WriteFile(saveFileDialog1.FileName, widthTitle, heightTitle, row, column, matrixSaveMap);

            gMain.Dispose();
            gFinish.Dispose();
            gCheck.Dispose();
            bitmapFinish.Dispose();
            bmpCheck.Dispose();
            bmpMain.Dispose();
            this.Close();
        }
    }
}
