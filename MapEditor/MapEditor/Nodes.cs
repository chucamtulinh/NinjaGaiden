using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.IO;

namespace MapEditor
{
    class Nodes
    {
        private const int MAX_OBJECT = 1;
        private const int MIN_SIZE = 320;

        private int m_ID = -1;
        private Nodes[] m_nodes = null;
        private Rectangle m_rect;
        private List<TreeObject> m_listObject = new List<TreeObject>();

        public bool idLeaf()
        {
            if (m_nodes == null)
                return true;
            else
                return false;
        }

        public Rectangle getBound()
        {
            return m_rect;
        }

        public int getID()
        {
            return m_ID;
        }

        public string getStringIDObject()
        {
            string myString = "";
          
                foreach (TreeObject obj in m_listObject)
                {
                    myString += (obj.getID().ToString() + "\t");
                }
            
            return myString;
        }

        public Nodes(int ID, Rectangle rect)
        {
            m_ID = ID;
            m_rect = rect;
            m_listObject.Clear();
            m_listObject.Clear();
        }

        //Xoa node
        public void ClearNode()
        {
            if (m_nodes != null)
            {
                for (int i = 0; i < 4; i++)
                {
                    m_nodes[i].ClearNode();
                    m_nodes[i] = null;
                }
                m_listObject.Clear();
            }
        }

        //Kiem tra xem doi tuong co thuoc node khong
        public bool isBelongNode(Rectangle myrect)
        {
            return !(myrect.X + myrect.Width < m_rect.X ||
                myrect.X > m_rect.X + m_rect.Width ||
                myrect.Y + myrect.Height < m_rect.Y ||
                myrect.Y > m_rect.Y + m_rect.Height);
        }

        //Kiem tra node object co thuoc node khong
        //Khoi tao 4 node cho Node hien tai
        // -------------
        // |  0  |  1  |
        // -------------
        // |  3  |  2  |
        // -------------
        public void CreateNode()
        {
            if (m_nodes == null)
            {
                m_nodes = new Nodes[4];

                m_nodes[0] = new Nodes(m_ID * 10 + 1, new Rectangle(m_rect.X, m_rect.Y, m_rect.Width / 2, m_rect.Height / 2));
                m_nodes[1] = new Nodes(m_ID * 10 + 2, new Rectangle(m_rect.X + m_rect.Width / 2, m_rect.Y, m_rect.Width / 2, m_rect.Height / 2));
                m_nodes[2] = new Nodes(m_ID * 10 + 3, new Rectangle(m_rect.X + m_rect.Width / 2, m_rect.Y + m_rect.Height / 2, m_rect.Width / 2, m_rect.Height / 2));
                m_nodes[3] = new Nodes(m_ID * 10 + 4, new Rectangle(m_rect.X, m_rect.Y + m_rect.Height / 2, m_rect.Width / 2, m_rect.Height / 2));
            }
        }

        //Chen doi tuong vao trong Nodes
        public void Insert(TreeObject myobject)
        {
            if (m_nodes != null) //if nodes khong phai la nodes la thi khoi tao cac nodes con va goi ham insert cho nodes
            {
                for (int i = 0; i < 4; i++)
                {
                    if (m_nodes[i].isBelongNode(myobject.getRect()))
                    {
                        m_nodes[i].Insert(myobject);
                    }
                }
            }
            else //Neu la nodes la thi kiem tra doi tuong co thuoc nodes khong neu co thi them vao nodes
            {

                if (this.isBelongNode(myobject.getRect()))
                {
                    this.m_listObject.Add(myobject);
                }



                if (this.m_rect.Width / 2 >= MIN_SIZE && this.m_listObject.Count >= MAX_OBJECT)
                {
                    CreateNode();
                    TreeObject temp = new TreeObject();

                    while (m_listObject.Count > 0)
                    {
                        temp = m_listObject.First();
                        m_listObject.Remove(temp);

                        for (int i = 0; i < 4; i++)
                        {
                            if (m_nodes[i].isBelongNode(myobject.getRect()))
                            {
                                m_nodes[i].m_listObject.Add(temp);
                            }
                        }
                    }
                    m_listObject.Clear();
                    //m_listObject = null;
                }
            }
        }

        public void GetListObject(List<TreeObject> myListObject, Rectangle myrect)
        {
            if (isBelongNode(myrect))
            {
                if (m_nodes == null)
                {
                    foreach (TreeObject treeobjce in m_listObject)
                    {
                        myListObject.Add(treeobjce);
                    }
                }
                else
                {
                    for (int i = 0; i < 4; i++)
                    {
                        m_nodes[i].GetListObject(myListObject, myrect);
                    }
                }
            }
        }

        public void getListNodes(List<Nodes> listNodes)
        {
            if(listNodes == null)
                listNodes = new List<Nodes>();
           
            if (m_nodes != null)
            {
                for(int i = 0; i  < 4; i++)
                    m_nodes[i].getListNodes(listNodes);
            }

            listNodes.Add(this);           
        }
    }
}
