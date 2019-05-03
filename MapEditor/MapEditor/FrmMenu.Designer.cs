namespace MapEditor
{
    partial class FrmMenu
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
            this.btCreateMap = new System.Windows.Forms.Button();
            this.btDevideAndCut = new System.Windows.Forms.Button();
            this.btExit = new System.Windows.Forms.Button();
            this.btEdit = new System.Windows.Forms.Button();
            this.btQuadTree = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btCreateMap
            // 
            this.btCreateMap.DialogResult = System.Windows.Forms.DialogResult.Yes;
            this.btCreateMap.Location = new System.Drawing.Point(24, 40);
            this.btCreateMap.Name = "btCreateMap";
            this.btCreateMap.Size = new System.Drawing.Size(126, 29);
            this.btCreateMap.TabIndex = 0;
            this.btCreateMap.Text = "Create Map";
            this.btCreateMap.UseVisualStyleBackColor = true;
            this.btCreateMap.Click += new System.EventHandler(this.btCreateMap_Click);
            // 
            // btDevideAndCut
            // 
            this.btDevideAndCut.Location = new System.Drawing.Point(176, 40);
            this.btDevideAndCut.Name = "btDevideAndCut";
            this.btDevideAndCut.Size = new System.Drawing.Size(126, 29);
            this.btDevideAndCut.TabIndex = 1;
            this.btDevideAndCut.Text = "Device And Cut Map";
            this.btDevideAndCut.UseVisualStyleBackColor = true;
            this.btDevideAndCut.Click += new System.EventHandler(this.btDevideAndCut_Click);
            // 
            // btExit
            // 
            this.btExit.Location = new System.Drawing.Point(24, 151);
            this.btExit.Name = "btExit";
            this.btExit.Size = new System.Drawing.Size(126, 29);
            this.btExit.TabIndex = 2;
            this.btExit.Text = "Exit";
            this.btExit.UseVisualStyleBackColor = true;
            this.btExit.Click += new System.EventHandler(this.btExit_Click);
            // 
            // btEdit
            // 
            this.btEdit.Location = new System.Drawing.Point(24, 98);
            this.btEdit.Name = "btEdit";
            this.btEdit.Size = new System.Drawing.Size(126, 28);
            this.btEdit.TabIndex = 3;
            this.btEdit.Text = "Edit Map";
            this.btEdit.UseVisualStyleBackColor = true;
            this.btEdit.Click += new System.EventHandler(this.btEdit_Click);
            // 
            // btQuadTree
            // 
            this.btQuadTree.Location = new System.Drawing.Point(182, 98);
            this.btQuadTree.Name = "btQuadTree";
            this.btQuadTree.Size = new System.Drawing.Size(120, 28);
            this.btQuadTree.TabIndex = 4;
            this.btQuadTree.Text = "QuadTree";
            this.btQuadTree.UseVisualStyleBackColor = true;
            this.btQuadTree.Click += new System.EventHandler(this.btQuadTree_Click);
            // 
            // FrmMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(357, 232);
            this.Controls.Add(this.btQuadTree);
            this.Controls.Add(this.btEdit);
            this.Controls.Add(this.btExit);
            this.Controls.Add(this.btDevideAndCut);
            this.Controls.Add(this.btCreateMap);
            this.Name = "FrmMenu";
            this.Text = "FrmMenu";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btCreateMap;
        private System.Windows.Forms.Button btDevideAndCut;
        private System.Windows.Forms.Button btExit;
        private System.Windows.Forms.Button btEdit;
        private System.Windows.Forms.Button btQuadTree;
    }
}