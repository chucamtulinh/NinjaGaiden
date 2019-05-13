namespace MapEditor
{
    partial class DevideAndCutMap
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
            this.panelMap = new System.Windows.Forms.Panel();
            this.ptrMap = new System.Windows.Forms.PictureBox();
            this.btDevide = new System.Windows.Forms.Button();
            this.tbWidth = new System.Windows.Forms.TextBox();
            this.lbWidth = new System.Windows.Forms.Label();
            this.tbHeight = new System.Windows.Forms.TextBox();
            this.lbHeight = new System.Windows.Forms.Label();
            this.btLoad = new System.Windows.Forms.Button();
            this.btSave = new System.Windows.Forms.Button();
            this.panelMap.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).BeginInit();
            this.SuspendLayout();
            // 
            // panelMap
            // 
            this.panelMap.AutoScroll = true;
            this.panelMap.Controls.Add(this.ptrMap);
            this.panelMap.Location = new System.Drawing.Point(25, 48);
            this.panelMap.Name = "panelMap";
            this.panelMap.Size = new System.Drawing.Size(740, 457);
            this.panelMap.TabIndex = 0;
            // 
            // ptrMap
            // 
            this.ptrMap.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ptrMap.Location = new System.Drawing.Point(15, 15);
            this.ptrMap.Name = "ptrMap";
            this.ptrMap.Size = new System.Drawing.Size(707, 427);
            this.ptrMap.TabIndex = 0;
            this.ptrMap.TabStop = false;
            // 
            // btDevide
            // 
            this.btDevide.Location = new System.Drawing.Point(812, 259);
            this.btDevide.Name = "btDevide";
            this.btDevide.Size = new System.Drawing.Size(90, 26);
            this.btDevide.TabIndex = 2;
            this.btDevide.Text = "Devide";
            this.btDevide.UseVisualStyleBackColor = true;
            this.btDevide.Click += new System.EventHandler(this.btDevide_Click);
            // 
            // tbWidth
            // 
            this.tbWidth.Location = new System.Drawing.Point(859, 156);
            this.tbWidth.Name = "tbWidth";
            this.tbWidth.Size = new System.Drawing.Size(89, 20);
            this.tbWidth.TabIndex = 3;
            // 
            // lbWidth
            // 
            this.lbWidth.AutoSize = true;
            this.lbWidth.Location = new System.Drawing.Point(797, 163);
            this.lbWidth.Name = "lbWidth";
            this.lbWidth.Size = new System.Drawing.Size(35, 13);
            this.lbWidth.TabIndex = 4;
            this.lbWidth.Text = "Width";
            // 
            // tbHeight
            // 
            this.tbHeight.Location = new System.Drawing.Point(859, 205);
            this.tbHeight.Name = "tbHeight";
            this.tbHeight.Size = new System.Drawing.Size(89, 20);
            this.tbHeight.TabIndex = 5;
            // 
            // lbHeight
            // 
            this.lbHeight.AutoSize = true;
            this.lbHeight.Location = new System.Drawing.Point(794, 212);
            this.lbHeight.Name = "lbHeight";
            this.lbHeight.Size = new System.Drawing.Size(38, 13);
            this.lbHeight.TabIndex = 6;
            this.lbHeight.Text = "Height";
            // 
            // btLoad
            // 
            this.btLoad.Location = new System.Drawing.Point(812, 48);
            this.btLoad.Name = "btLoad";
            this.btLoad.Size = new System.Drawing.Size(136, 57);
            this.btLoad.TabIndex = 9;
            this.btLoad.Text = "Load";
            this.btLoad.UseVisualStyleBackColor = true;
            this.btLoad.Click += new System.EventHandler(this.btLoad_Click);
            // 
            // btSave
            // 
            this.btSave.Location = new System.Drawing.Point(812, 333);
            this.btSave.Name = "btSave";
            this.btSave.Size = new System.Drawing.Size(90, 32);
            this.btSave.TabIndex = 10;
            this.btSave.Text = "Save";
            this.btSave.UseVisualStyleBackColor = true;
            this.btSave.Click += new System.EventHandler(this.btSave_Click);
            // 
            // DevideAndCutMap
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(988, 517);
            this.Controls.Add(this.btSave);
            this.Controls.Add(this.btLoad);
            this.Controls.Add(this.lbHeight);
            this.Controls.Add(this.tbHeight);
            this.Controls.Add(this.lbWidth);
            this.Controls.Add(this.tbWidth);
            this.Controls.Add(this.btDevide);
            this.Controls.Add(this.panelMap);
            this.Name = "DevideAndCutMap";
            this.Text = "Devide And Cut Map";
            this.panelMap.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.ptrMap)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panelMap;
        private System.Windows.Forms.PictureBox ptrMap;
        private System.Windows.Forms.Button btDevide;
        private System.Windows.Forms.TextBox tbWidth;
        private System.Windows.Forms.Label lbWidth;
        private System.Windows.Forms.TextBox tbHeight;
        private System.Windows.Forms.Label lbHeight;
        private System.Windows.Forms.Button btLoad;
        private System.Windows.Forms.Button btSave;
    }
}