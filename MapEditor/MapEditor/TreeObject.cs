using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace MapEditor
{
    class TreeObject
    {
        private Rectangle pRect; //khung cua doi tuong 
        //(neu doi tuong dung yen thi lay bang sprite con di chuyen thi lay bang khung di chuyen)
        private int ID;
        private GameObject m_listObject;

        public TreeObject()
        {
            this.ID = 0;
            this.pRect = new Rectangle(0, 0, 0, 0);
        }

        public TreeObject(int id, Rectangle rect)
        {
            this.ID = id;
            this.pRect = rect;
        }

        public void setRect(Rectangle rect)
        {
            this.pRect = rect;
        }

        public void setID(int id)
        {
            this.ID = id;
        }

        public Rectangle getRect()
        {
            return pRect;
        }

        public int getID()
        {
            return this.ID;
        }
    }
}
