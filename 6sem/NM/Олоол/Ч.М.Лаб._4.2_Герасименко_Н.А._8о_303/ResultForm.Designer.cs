namespace Ч.М.Лаб._4._2_Герасименко_Н.А._8о_303
{
    partial class ResultForm
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
            this.pictureBoxXotT = new System.Windows.Forms.PictureBox();
            this.pictureBoxRRpogrotT = new System.Windows.Forms.PictureBox();
            this.textBoxTochnPogr = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxXotT)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxRRpogrotT)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBoxXotT
            // 
            this.pictureBoxXotT.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.pictureBoxXotT.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxXotT.Location = new System.Drawing.Point(12, 48);
            this.pictureBoxXotT.Name = "pictureBoxXotT";
            this.pictureBoxXotT.Size = new System.Drawing.Size(448, 450);
            this.pictureBoxXotT.TabIndex = 31;
            this.pictureBoxXotT.TabStop = false;
            this.pictureBoxXotT.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBoxXotT_Paint);
            // 
            // pictureBoxRRpogrotT
            // 
            this.pictureBoxRRpogrotT.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.pictureBoxRRpogrotT.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBoxRRpogrotT.Location = new System.Drawing.Point(525, 48);
            this.pictureBoxRRpogrotT.Name = "pictureBoxRRpogrotT";
            this.pictureBoxRRpogrotT.Size = new System.Drawing.Size(448, 450);
            this.pictureBoxRRpogrotT.TabIndex = 32;
            this.pictureBoxRRpogrotT.TabStop = false;
            this.pictureBoxRRpogrotT.Paint += new System.Windows.Forms.PaintEventHandler(this.pictureBoxRRpogrotT_Paint);
            // 
            // textBoxTochnPogr
            // 
            this.textBoxTochnPogr.Location = new System.Drawing.Point(131, 504);
            this.textBoxTochnPogr.Name = "textBoxTochnPogr";
            this.textBoxTochnPogr.Size = new System.Drawing.Size(219, 20);
            this.textBoxTochnPogr.TabIndex = 33;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 505);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(115, 13);
            this.label1.TabIndex = 34;
            this.label1.Text = "Точная погрешность:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(196, 32);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(91, 13);
            this.label2.TabIndex = 35;
            this.label2.Text = "График функции";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(654, 32);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(214, 13);
            this.label3.TabIndex = 36;
            this.label3.Text = "Погрешность по Рунге-Ромбергу (*10^-3)";
            // 
            // ResultForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(985, 527);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBoxTochnPogr);
            this.Controls.Add(this.pictureBoxRRpogrotT);
            this.Controls.Add(this.pictureBoxXotT);
            this.Name = "ResultForm";
            this.Text = "ResultForm";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxXotT)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxRRpogrotT)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBoxXotT;
        private System.Windows.Forms.PictureBox pictureBoxRRpogrotT;
        private System.Windows.Forms.TextBox textBoxTochnPogr;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
    }
}