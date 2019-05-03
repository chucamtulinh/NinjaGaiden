namespace MapEditor
{
    partial class FrmQuadTree
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
            this.panel1 = new System.Windows.Forms.Panel();
            this.btInit = new System.Windows.Forms.Button();
            this.btDivQuadTree = new System.Windows.Forms.Button();
            this.cbbSize = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cbbObject = new System.Windows.Forms.ComboBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.ptrMap = new System.Windows.Forms.PictureBox();
            this.ptrObject = new System.Windows.Forms.PictureBox();
            this.tbWidth = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.tbX = new System.Windows.Forms.TextBox();
            this.tbY = new System.Windows.Forms.TextBox();
            this.btOk = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptrObject)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.btOk);
            this.panel1.Controls.Add(this.tbY);
            this.panel1.Controls.Add(this.tbX);
            this.panel1.Controls.Add(this.label6);
            this.panel1.Controls.Add(this.label5);
            this.panel1.Controls.Add(this.label4);
            this.panel1.Controls.Add(this.textBox2);
            this.panel1.Controls.Add(this.tbWidth);
            this.panel1.Controls.Add(this.btInit);
            this.panel1.Controls.Add(this.btDivQuadTree);
            this.panel1.Controls.Add(this.cbbSize);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.cbbObject);
            this.panel1.Controls.Add(this.ptrObject);
            this.panel1.Location = new System.Drawing.Point(795, 13);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(279, 507);
            this.panel1.TabIndex = 2;
            // 
            // btInit
            // 
            this.btInit.Location = new System.Drawing.Point(52, 25);
            this.btInit.Name = "btInit";
            this.btInit.Size = new System.Drawing.Size(170, 60);
            this.btInit.TabIndex = 10;
            this.btInit.Text = "Init";
            this.btInit.UseVisualStyleBackColor = true;
            this.btInit.Click += new System.EventHandler(this.btInit_Click);
            // 
            // btDivQuadTree
            // 
            this.btDivQuadTree.Location = new System.Drawing.Point(74, 193);
            this.btDivQuadTree.Name = "btDivQuadTree";
            this.btDivQuadTree.Size = new System.Drawing.Size(113, 23);
            this.btDivQuadTree.TabIndex = 9;
            this.btDivQuadTree.Text = "Chia QuadTree";
            this.btDivQuadTree.UseVisualStyleBackColor = true;
            this.btDivQuadTree.Click += new System.EventHandler(this.btDivQuadTree_Click);
            // 
            // cbbSize
            // 
            this.cbbSize.FormattingEnabled = true;
            this.cbbSize.Items.AddRange(new object[] {
            "320",
            "480",
            "512",
            "1024"});
            this.cbbSize.Location = new System.Drawing.Point(74, 156);
            this.cbbSize.Name = "cbbSize";
            this.cbbSize.Size = new System.Drawing.Size(183, 21);
            this.cbbSize.TabIndex = 8;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(16, 164);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(50, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Max Size";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(71, 126);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "QuadTree";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(113, 233);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(38, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Object";
            // 
            // cbbObject
            // 
            this.cbbObject.FormattingEnabled = true;
            this.cbbObject.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32",
            "33",
            "34",
            "35",
            "36",
            "37",
            "38",
            "39",
            "40",
            "41",
            "42",
            "43",
            "44"});
            this.cbbObject.Location = new System.Drawing.Point(19, 439);
            this.cbbObject.Name = "cbbObject";
            this.cbbObject.Size = new System.Drawing.Size(240, 21);
            this.cbbObject.TabIndex = 3;
            this.cbbObject.Text = "0";
            this.cbbObject.TextChanged += new System.EventHandler(this.cbbObject_TextChanged);
            // 
            // panel2
            // 
            this.panel2.AutoScroll = true;
            this.panel2.Controls.Add(this.ptrMap);
            this.panel2.Location = new System.Drawing.Point(8, 8);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(775, 512);
            this.panel2.TabIndex = 3;
            // 
            // ptrMap
            // 
            this.ptrMap.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptrMap.Location = new System.Drawing.Point(4, 5);
            this.ptrMap.Name = "ptrMap";
            this.ptrMap.Size = new System.Drawing.Size(768, 504);
            this.ptrMap.TabIndex = 0;
            this.ptrMap.TabStop = false;
            this.ptrMap.Click += new System.EventHandler(this.ptrMap_Click);
            this.ptrMap.MouseClick += new System.Windows.Forms.MouseEventHandler(this.ptrMap_MouseClick);
            this.ptrMap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ptrMap_MouseMove);
            // 
            // ptrObject
            // 
            this.ptrObject.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptrObject.Location = new System.Drawing.Point(19, 302);
            this.ptrObject.Name = "ptrObject";
            this.ptrObject.Size = new System.Drawing.Size(240, 88);
            this.ptrObject.TabIndex = 2;
            this.ptrObject.TabStop = false;
            // 
            // tbWidth
            // 
            this.tbWidth.Location = new System.Drawing.Point(77, 404);
            this.tbWidth.Name = "tbWidth";
            this.tbWidth.Size = new System.Drawing.Size(49, 20);
            this.tbWidth.TabIndex = 11;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(210, 406);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(49, 20);
            this.textBox2.TabIndex = 12;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(27, 410);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(35, 13);
            this.label4.TabIndex = 13;
            this.label4.Text = "Width";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(143, 408);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(38, 13);
            this.label5.TabIndex = 14;
            this.label5.Text = "Height";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(7, 271);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(44, 13);
            this.label6.TabIndex = 15;
            this.label6.Text = "Position";
            // 
            // tbX
            // 
            this.tbX.Location = new System.Drawing.Point(59, 269);
            this.tbX.Name = "tbX";
            this.tbX.Size = new System.Drawing.Size(66, 20);
            this.tbX.TabIndex = 16;
            // 
            // tbY
            // 
            this.tbY.Location = new System.Drawing.Point(146, 268);
            this.tbY.Name = "tbY";
            this.tbY.Size = new System.Drawing.Size(66, 20);
            this.tbY.TabIndex = 17;
            // 
            // btOk
            // 
            this.btOk.Location = new System.Drawing.Point(77, 466);
            this.btOk.Name = "btOk";
            this.btOk.Size = new System.Drawing.Size(103, 28);
            this.btOk.TabIndex = 18;
            this.btOk.Text = "OK";
            this.btOk.UseVisualStyleBackColor = true;
            this.btOk.Click += new System.EventHandler(this.btOk_Click);
            // 
            // FrmQuadTree
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1086, 539);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Name = "FrmQuadTree";
            this.Text = "QuadTree";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptrObject)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox ptrMap;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox ptrObject;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.ComboBox cbbSize;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cbbObject;
        private System.Windows.Forms.Button btDivQuadTree;
        private System.Windows.Forms.Button btInit;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox tbWidth;
        private System.Windows.Forms.TextBox tbY;
        private System.Windows.Forms.TextBox tbX;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btOk;
    }
}