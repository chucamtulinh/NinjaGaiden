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
    public partial class CreateMap : Form
    {
        public CreateMap()
        {
            InitializeComponent();
            image = null;
            rectangle = new Rectangle(0, 0, 0, 0);
            index = 0;
            keypress = false;
            title = null;
            graphics = null;
        }

        private Image image;
        private Rectangle rectangle;
        private Bitmap bitmap;
        private Bitmap b;
        private Graphics graphicsMap;
        private bool keypress;
        private Image title;
        Graphics graphics;

        private int index;

        private void btnNewTitle_Click(object sender, EventArgs e)
        {
            //Khoi tao form lay kich thuoc title va path 
            LoadTitle formTitle = new LoadTitle();
            formTitle.ShowDialog();
            this.ptbTitle.Image = formTitle.GetImage();
            image = Image.FromFile(formTitle.GetPath().ToString());
            rectangle.Width = formTitle.GetWidth();
            rectangle.Height = formTitle.GetHeight();
            int column = image.Width/rectangle.Width;
            title = Image.FromFile(formTitle.GetPath());
            bitmap = new Bitmap(rectangle.Width, rectangle.Height);
            graphics = Graphics.FromImage(bitmap);
            graphics.DrawImage(title, new Rectangle(0, 0, rectangle.Width, rectangle.Height), new Rectangle((index % column) * rectangle.Width, (index / column) * rectangle.Height, rectangle.Width, rectangle.Height), GraphicsUnit.Pixel);
            b = new Bitmap(this.ptrMap.Width, this.ptrMap.Height);
            graphicsMap = Graphics.FromImage(b);
            this.ptbTitle.Width = image.Width;
            this.ptbTitle.Height = image.Height;
        }
  
        private void btCreate_Click(object sender, EventArgs e)
        {
            this.ptrMap.Width = int.Parse(this.tbColumn.Text.ToString()) * rectangle.Width;
            this.ptrMap.Height = int.Parse(this.tbRow.Text.ToString()) * rectangle.Height;
        }

        private void ptrMap_MouseDown(object sender, MouseEventArgs e)
        {
            keypress = true;
            graphicsMap.DrawImage(bitmap, new Rectangle((e.X / rectangle.Width) * rectangle.Width, (e.Y / rectangle.Height) * rectangle.Height, rectangle.Width, rectangle.Height), new Rectangle(0, 0, rectangle.Width, rectangle.Height), GraphicsUnit.Pixel);
            this.ptrMap.Image = b;
        }

        private void ptrMap_MouseUp(object sender, MouseEventArgs e)
        {
            keypress = false;
        }

        private void ptrMap_MouseMove(object sender, MouseEventArgs e)
        {
            if (keypress == true)
            {
                graphicsMap.DrawImage(bitmap, new Rectangle((e.X / rectangle.Width) * rectangle.Width, (e.Y / rectangle.Height) * rectangle.Height, rectangle.Width, rectangle.Height), new Rectangle(0, 0, rectangle.Width, rectangle.Height), GraphicsUnit.Pixel);
                this.ptrMap.Image = b;
            }
        }

        private void ptbTitle_MouseClick(object sender, MouseEventArgs e)
        {
            graphics.DrawImage(title, new Rectangle(0, 0, rectangle.Width, rectangle.Height), new Rectangle((e.X / rectangle.Width) * rectangle.Width, (e.Y / rectangle.Height) * rectangle.Height, rectangle.Width, rectangle.Height), GraphicsUnit.Pixel);
        }
    }
}
