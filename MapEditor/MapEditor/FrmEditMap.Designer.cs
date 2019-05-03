namespace MapEditor
{
    partial class FrmEditMap
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
            this.ptrMap = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.tbPointEndY = new System.Windows.Forms.TextBox();
            this.tbPointStartY = new System.Windows.Forms.TextBox();
            this.tbPositionY = new System.Windows.Forms.TextBox();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.tbPointEndX = new System.Windows.Forms.TextBox();
            this.tbPointStartX = new System.Windows.Forms.TextBox();
            this.tbPositionX = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cbbObject = new System.Windows.Forms.ComboBox();
            this.panel3 = new System.Windows.Forms.Panel();
            this.tbFindwhatColumn = new System.Windows.Forms.TextBox();
            this.tbFindwhatRow = new System.Windows.Forms.TextBox();
            this.btReplaceAll = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.tbRelacewithValue = new System.Windows.Forms.TextBox();
            this.tbFindwhatValue = new System.Windows.Forms.TextBox();
            this.btReplace = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.button4 = new System.Windows.Forms.Button();
            this.tbQuadtreeHeight = new System.Windows.Forms.TextBox();
            this.tbQuadtreeWidth = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btSave = new System.Windows.Forms.Button();
            this.btOpenMap = new System.Windows.Forms.Button();
            this.btRefresh = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.panel5 = new System.Windows.Forms.Panel();
            this.tbRow = new System.Windows.Forms.TextBox();
            this.tbColumn = new System.Windows.Forms.TextBox();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).BeginInit();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.panel3.SuspendLayout();
            this.panel4.SuspendLayout();
            this.panel5.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.Controls.Add(this.ptrMap);
            this.panel1.Location = new System.Drawing.Point(13, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(668, 437);
            this.panel1.TabIndex = 0;
            // 
            // ptrMap
            // 
            this.ptrMap.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptrMap.Location = new System.Drawing.Point(7, 11);
            this.ptrMap.Name = "ptrMap";
            this.ptrMap.Size = new System.Drawing.Size(650, 415);
            this.ptrMap.TabIndex = 0;
            this.ptrMap.TabStop = false;
            this.ptrMap.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ptrMap_MouseDown);
            this.ptrMap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ptrMap_MouseMove);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.tbPointEndY);
            this.panel2.Controls.Add(this.tbPointStartY);
            this.panel2.Controls.Add(this.tbPositionY);
            this.panel2.Controls.Add(this.pictureBox2);
            this.panel2.Controls.Add(this.button2);
            this.panel2.Controls.Add(this.button1);
            this.panel2.Controls.Add(this.label6);
            this.panel2.Controls.Add(this.label5);
            this.panel2.Controls.Add(this.label3);
            this.panel2.Controls.Add(this.tbPointEndX);
            this.panel2.Controls.Add(this.tbPointStartX);
            this.panel2.Controls.Add(this.tbPositionX);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.cbbObject);
            this.panel2.Location = new System.Drawing.Point(8, 175);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(380, 293);
            this.panel2.TabIndex = 1;
            // 
            // tbPointEndY
            // 
            this.tbPointEndY.Location = new System.Drawing.Point(197, 198);
            this.tbPointEndY.Name = "tbPointEndY";
            this.tbPointEndY.Size = new System.Drawing.Size(66, 20);
            this.tbPointEndY.TabIndex = 15;
            this.tbPointEndY.Text = "0";
            // 
            // tbPointStartY
            // 
            this.tbPointStartY.Location = new System.Drawing.Point(197, 162);
            this.tbPointStartY.Name = "tbPointStartY";
            this.tbPointStartY.Size = new System.Drawing.Size(66, 20);
            this.tbPointStartY.TabIndex = 14;
            this.tbPointStartY.Text = "0";
            // 
            // tbPositionY
            // 
            this.tbPositionY.Location = new System.Drawing.Point(103, 79);
            this.tbPositionY.Name = "tbPositionY";
            this.tbPositionY.Size = new System.Drawing.Size(38, 20);
            this.tbPositionY.TabIndex = 13;
            this.tbPositionY.Text = "0";
            // 
            // pictureBox2
            // 
            this.pictureBox2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox2.Location = new System.Drawing.Point(161, 43);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(116, 101);
            this.pictureBox2.TabIndex = 12;
            this.pictureBox2.TabStop = false;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(164, 228);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(110, 32);
            this.button2.TabIndex = 11;
            this.button2.Text = "OK";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(28, 228);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(95, 32);
            this.button1.TabIndex = 10;
            this.button1.Text = "Set Activity";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(28, 201);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(53, 13);
            this.label6.TabIndex = 9;
            this.label6.Text = "Point End";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(25, 165);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(56, 13);
            this.label5.TabIndex = 8;
            this.label5.Text = "Point Start";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(10, 82);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(44, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "Position";
            // 
            // tbPointEndX
            // 
            this.tbPointEndX.Location = new System.Drawing.Point(113, 198);
            this.tbPointEndX.Name = "tbPointEndX";
            this.tbPointEndX.Size = new System.Drawing.Size(66, 20);
            this.tbPointEndX.TabIndex = 5;
            this.tbPointEndX.Text = "0";
            // 
            // tbPointStartX
            // 
            this.tbPointStartX.Location = new System.Drawing.Point(113, 162);
            this.tbPointStartX.Name = "tbPointStartX";
            this.tbPointStartX.Size = new System.Drawing.Size(66, 20);
            this.tbPointStartX.TabIndex = 4;
            this.tbPointStartX.Text = "0";
            // 
            // tbPositionX
            // 
            this.tbPositionX.Location = new System.Drawing.Point(60, 79);
            this.tbPositionX.Name = "tbPositionX";
            this.tbPositionX.Size = new System.Drawing.Size(38, 20);
            this.tbPositionX.TabIndex = 2;
            this.tbPositionX.Text = "0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(25, 19);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(38, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Object";
            // 
            // cbbObject
            // 
            this.cbbObject.FormattingEnabled = true;
            this.cbbObject.Items.AddRange(new object[] {
            "Nam",
            "Rua",
            "La"});
            this.cbbObject.Location = new System.Drawing.Point(101, 16);
            this.cbbObject.Name = "cbbObject";
            this.cbbObject.Size = new System.Drawing.Size(174, 21);
            this.cbbObject.TabIndex = 0;
            this.cbbObject.Text = "None";
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.tbFindwhatColumn);
            this.panel3.Controls.Add(this.tbFindwhatRow);
            this.panel3.Controls.Add(this.btReplaceAll);
            this.panel3.Controls.Add(this.label10);
            this.panel3.Controls.Add(this.label9);
            this.panel3.Controls.Add(this.tbRelacewithValue);
            this.panel3.Controls.Add(this.tbFindwhatValue);
            this.panel3.Controls.Add(this.btReplace);
            this.panel3.Controls.Add(this.label1);
            this.panel3.Location = new System.Drawing.Point(158, 9);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(233, 160);
            this.panel3.TabIndex = 2;
            // 
            // tbFindwhatColumn
            // 
            this.tbFindwhatColumn.Location = new System.Drawing.Point(113, 37);
            this.tbFindwhatColumn.Name = "tbFindwhatColumn";
            this.tbFindwhatColumn.ReadOnly = true;
            this.tbFindwhatColumn.Size = new System.Drawing.Size(38, 20);
            this.tbFindwhatColumn.TabIndex = 11;
            // 
            // tbFindwhatRow
            // 
            this.tbFindwhatRow.Location = new System.Drawing.Point(69, 37);
            this.tbFindwhatRow.Name = "tbFindwhatRow";
            this.tbFindwhatRow.ReadOnly = true;
            this.tbFindwhatRow.Size = new System.Drawing.Size(38, 20);
            this.tbFindwhatRow.TabIndex = 10;
            // 
            // btReplaceAll
            // 
            this.btReplaceAll.Location = new System.Drawing.Point(73, 111);
            this.btReplaceAll.Name = "btReplaceAll";
            this.btReplaceAll.Size = new System.Drawing.Size(85, 29);
            this.btReplaceAll.TabIndex = 8;
            this.btReplaceAll.Text = "Replace All";
            this.btReplaceAll.UseVisualStyleBackColor = true;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(3, 75);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(63, 13);
            this.label10.TabIndex = 7;
            this.label10.Text = "Relace with";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(5, 40);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(53, 13);
            this.label9.TabIndex = 6;
            this.label9.Text = "Find what";
            // 
            // tbRelacewithValue
            // 
            this.tbRelacewithValue.Location = new System.Drawing.Point(175, 72);
            this.tbRelacewithValue.Name = "tbRelacewithValue";
            this.tbRelacewithValue.Size = new System.Drawing.Size(55, 20);
            this.tbRelacewithValue.TabIndex = 5;
            // 
            // tbFindwhatValue
            // 
            this.tbFindwhatValue.Location = new System.Drawing.Point(175, 37);
            this.tbFindwhatValue.Name = "tbFindwhatValue";
            this.tbFindwhatValue.ReadOnly = true;
            this.tbFindwhatValue.Size = new System.Drawing.Size(55, 20);
            this.tbFindwhatValue.TabIndex = 4;
            // 
            // btReplace
            // 
            this.btReplace.Location = new System.Drawing.Point(7, 111);
            this.btReplace.Name = "btReplace";
            this.btReplace.Size = new System.Drawing.Size(60, 29);
            this.btReplace.TabIndex = 1;
            this.btReplace.Text = "Replace";
            this.btReplace.UseVisualStyleBackColor = true;
            this.btReplace.Click += new System.EventHandler(this.btReplace_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(11, 10);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Replace Tiled";
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.button4);
            this.panel4.Controls.Add(this.tbQuadtreeHeight);
            this.panel4.Controls.Add(this.tbQuadtreeWidth);
            this.panel4.Controls.Add(this.label8);
            this.panel4.Controls.Add(this.label7);
            this.panel4.Controls.Add(this.label4);
            this.panel4.Location = new System.Drawing.Point(8, 9);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(144, 159);
            this.panel4.TabIndex = 3;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(42, 111);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(77, 30);
            this.button4.TabIndex = 5;
            this.button4.Text = "OK";
            this.button4.UseVisualStyleBackColor = true;
            // 
            // tbQuadtreeHeight
            // 
            this.tbQuadtreeHeight.Location = new System.Drawing.Point(65, 79);
            this.tbQuadtreeHeight.Name = "tbQuadtreeHeight";
            this.tbQuadtreeHeight.Size = new System.Drawing.Size(71, 20);
            this.tbQuadtreeHeight.TabIndex = 4;
            this.tbQuadtreeHeight.Text = "0";
            // 
            // tbQuadtreeWidth
            // 
            this.tbQuadtreeWidth.Location = new System.Drawing.Point(64, 40);
            this.tbQuadtreeWidth.Name = "tbQuadtreeWidth";
            this.tbQuadtreeWidth.Size = new System.Drawing.Size(71, 20);
            this.tbQuadtreeWidth.TabIndex = 3;
            this.tbQuadtreeWidth.Text = "0";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(10, 82);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(36, 13);
            this.label8.TabIndex = 2;
            this.label8.Text = "height";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(10, 43);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(32, 13);
            this.label7.TabIndex = 1;
            this.label7.Text = "width";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(15, 13);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(51, 13);
            this.label4.TabIndex = 0;
            this.label4.Text = "Quadtree";
            // 
            // btSave
            // 
            this.btSave.Location = new System.Drawing.Point(300, 458);
            this.btSave.Name = "btSave";
            this.btSave.Size = new System.Drawing.Size(104, 29);
            this.btSave.TabIndex = 4;
            this.btSave.Text = "Save";
            this.btSave.UseVisualStyleBackColor = true;
            this.btSave.Click += new System.EventHandler(this.btSave_Click);
            // 
            // btOpenMap
            // 
            this.btOpenMap.Location = new System.Drawing.Point(174, 458);
            this.btOpenMap.Name = "btOpenMap";
            this.btOpenMap.Size = new System.Drawing.Size(104, 29);
            this.btOpenMap.TabIndex = 5;
            this.btOpenMap.Text = "Open Map";
            this.btOpenMap.UseVisualStyleBackColor = true;
            this.btOpenMap.Click += new System.EventHandler(this.btOpenMap_Click);
            // 
            // btRefresh
            // 
            this.btRefresh.Location = new System.Drawing.Point(428, 458);
            this.btRefresh.Name = "btRefresh";
            this.btRefresh.Size = new System.Drawing.Size(104, 29);
            this.btRefresh.TabIndex = 6;
            this.btRefresh.Text = "Refresh";
            this.btRefresh.UseVisualStyleBackColor = true;
            this.btRefresh.Click += new System.EventHandler(this.btRefresh_Click);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(547, 458);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(104, 29);
            this.button8.TabIndex = 7;
            this.button8.Text = "Exit";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // panel5
            // 
            this.panel5.Controls.Add(this.panel4);
            this.panel5.Controls.Add(this.panel3);
            this.panel5.Controls.Add(this.panel2);
            this.panel5.Location = new System.Drawing.Point(691, 14);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(406, 483);
            this.panel5.TabIndex = 8;
            // 
            // tbRow
            // 
            this.tbRow.Location = new System.Drawing.Point(29, 462);
            this.tbRow.Name = "tbRow";
            this.tbRow.ReadOnly = true;
            this.tbRow.Size = new System.Drawing.Size(38, 20);
            this.tbRow.TabIndex = 9;
            this.tbRow.Text = "0";
            // 
            // tbColumn
            // 
            this.tbColumn.Location = new System.Drawing.Point(73, 462);
            this.tbColumn.Name = "tbColumn";
            this.tbColumn.ReadOnly = true;
            this.tbColumn.Size = new System.Drawing.Size(38, 20);
            this.tbColumn.TabIndex = 10;
            this.tbColumn.Text = "0";
            // 
            // FrmEditMap
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1103, 499);
            this.Controls.Add(this.tbColumn);
            this.Controls.Add(this.tbRow);
            this.Controls.Add(this.panel5);
            this.Controls.Add(this.button8);
            this.Controls.Add(this.btRefresh);
            this.Controls.Add(this.btOpenMap);
            this.Controls.Add(this.btSave);
            this.Controls.Add(this.panel1);
            this.Name = "FrmEditMap";
            this.Text = "FrmEditMap";
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.panel5.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox ptrMap;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox tbPointEndX;
        private System.Windows.Forms.TextBox tbPointStartX;
        private System.Windows.Forms.TextBox tbPositionX;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbbObject;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox tbRelacewithValue;
        private System.Windows.Forms.TextBox tbFindwhatValue;
        private System.Windows.Forms.Button btReplace;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.TextBox tbQuadtreeHeight;
        private System.Windows.Forms.TextBox tbQuadtreeWidth;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btSave;
        private System.Windows.Forms.Button btOpenMap;
        private System.Windows.Forms.Button btRefresh;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.TextBox tbPositionY;
        private System.Windows.Forms.TextBox tbPointEndY;
        private System.Windows.Forms.TextBox tbPointStartY;
        private System.Windows.Forms.Button btReplaceAll;
        private System.Windows.Forms.TextBox tbRow;
        private System.Windows.Forms.TextBox tbColumn;
        private System.Windows.Forms.TextBox tbFindwhatColumn;
        private System.Windows.Forms.TextBox tbFindwhatRow;
    }
}