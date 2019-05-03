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
    public partial class FrmMenu : Form
    {
        public FrmMenu()
        {
            InitializeComponent();
        }

        private void btCreateMap_Click(object sender, EventArgs e)
        {
            CreateMap createMap = new CreateMap();
            createMap.ShowDialog();
        }

        private void btExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btDevideAndCut_Click(object sender, EventArgs e)
        {
            DevideAndCutMap DACM = new DevideAndCutMap();
            DACM.Show();
        }

        private void btEdit_Click(object sender, EventArgs e)
        {
            FrmEditMap edit = new FrmEditMap();
            edit.Show();
        }

        private void btQuadTree_Click(object sender, EventArgs e)
        {
            //frmQuadTreeCollision quadtree = new frmQuadTreeCollision();
            FrmQuadTree quadtree = new FrmQuadTree();
            quadtree.Show();
        }
    }
}
