namespace MapEditor
{
    partial class CreateMap
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
            this.ptbTitle = new System.Windows.Forms.PictureBox();
            this.btnNewTitle = new System.Windows.Forms.Button();
            this.tbRow = new System.Windows.Forms.TextBox();
            this.tbColumn = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.btCreate = new System.Windows.Forms.Button();
            this.ptrMap = new System.Windows.Forms.PictureBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.ptbTitle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).BeginInit();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // ptbTitle
            // 
            this.ptbTitle.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptbTitle.Location = new System.Drawing.Point(4, 3);
            this.ptbTitle.Name = "ptbTitle";
            this.ptbTitle.Size = new System.Drawing.Size(258, 293);
            this.ptbTitle.TabIndex = 1;
            this.ptbTitle.TabStop = false;
            this.ptbTitle.MouseClick += new System.Windows.Forms.MouseEventHandler(this.ptbTitle_MouseClick);
            // 
            // btnNewTitle
            // 
            this.btnNewTitle.Location = new System.Drawing.Point(923, 477);
            this.btnNewTitle.Name = "btnNewTitle";
            this.btnNewTitle.Size = new System.Drawing.Size(117, 27);
            this.btnNewTitle.TabIndex = 2;
            this.btnNewTitle.Text = "New";
            this.btnNewTitle.UseVisualStyleBackColor = true;
            this.btnNewTitle.Click += new System.EventHandler(this.btnNewTitle_Click);
            // 
            // tbRow
            // 
            this.tbRow.Location = new System.Drawing.Point(995, 39);
            this.tbRow.Name = "tbRow";
            this.tbRow.Size = new System.Drawing.Size(132, 20);
            this.tbRow.TabIndex = 7;
            // 
            // tbColumn
            // 
            this.tbColumn.Location = new System.Drawing.Point(995, 84);
            this.tbColumn.Name = "tbColumn";
            this.tbColumn.Size = new System.Drawing.Size(131, 20);
            this.tbColumn.TabIndex = 8;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(923, 42);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 13);
            this.label1.TabIndex = 9;
            this.label1.Text = "Row";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(919, 84);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(42, 13);
            this.label2.TabIndex = 10;
            this.label2.Text = "Column";
            // 
            // btCreate
            // 
            this.btCreate.Location = new System.Drawing.Point(926, 131);
            this.btCreate.Name = "btCreate";
            this.btCreate.Size = new System.Drawing.Size(75, 24);
            this.btCreate.TabIndex = 11;
            this.btCreate.Text = "Create Map";
            this.btCreate.UseVisualStyleBackColor = true;
            this.btCreate.Click += new System.EventHandler(this.btCreate_Click);
            // 
            // ptrMap
            // 
            this.ptrMap.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptrMap.Location = new System.Drawing.Point(13, 18);
            this.ptrMap.Name = "ptrMap";
            this.ptrMap.Size = new System.Drawing.Size(876, 465);
            this.ptrMap.TabIndex = 0;
            this.ptrMap.TabStop = false;
            this.ptrMap.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ptrMap_MouseDown);
            this.ptrMap.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ptrMap_MouseMove);
            this.ptrMap.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ptrMap_MouseUp);
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.Controls.Add(this.ptrMap);
            this.panel1.Location = new System.Drawing.Point(12, 21);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(901, 498);
            this.panel1.TabIndex = 12;
            // 
            // panel2
            // 
            this.panel2.AutoScroll = true;
            this.panel2.Controls.Add(this.ptbTitle);
            this.panel2.Location = new System.Drawing.Point(922, 172);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(265, 299);
            this.panel2.TabIndex = 13;
            // 
            // CreateMap
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1199, 531);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.btCreate);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbColumn);
            this.Controls.Add(this.tbRow);
            this.Controls.Add(this.btnNewTitle);
            this.Name = "CreateMap";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.ptbTitle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox ptbTitle;
        private System.Windows.Forms.Button btnNewTitle;
        private System.Windows.Forms.TextBox tbRow;
        private System.Windows.Forms.TextBox tbColumn;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button btCreate;
        private System.Windows.Forms.PictureBox ptrMap;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
    }
}

