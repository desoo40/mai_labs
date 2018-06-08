namespace Ч.М.Лаб._4._2_Герасименко_Н.А._8о_303
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.buttonMS = new System.Windows.Forms.Button();
            this.buttonKR = new System.Windows.Forms.Button();
            this.textBoxRg4step = new System.Windows.Forms.TextBox();
            this.label17 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImage = global::Ч.М.Лаб._4._2_Герасименко_Н.А._8о_303.Properties.Resources.КраеваяЗадача;
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Location = new System.Drawing.Point(11, 12);
            this.pictureBox1.MaximumSize = new System.Drawing.Size(256, 171);
            this.pictureBox1.MinimumSize = new System.Drawing.Size(256, 171);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(256, 171);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // buttonMS
            // 
            this.buttonMS.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.buttonMS.Font = new System.Drawing.Font("Monotype Corsiva", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonMS.Location = new System.Drawing.Point(37, 224);
            this.buttonMS.Name = "buttonMS";
            this.buttonMS.Size = new System.Drawing.Size(205, 30);
            this.buttonMS.TabIndex = 23;
            this.buttonMS.Text = "Решить (Метод стрельбы)";
            this.buttonMS.UseVisualStyleBackColor = false;
            this.buttonMS.Click += new System.EventHandler(this.buttonMS_Click);
            // 
            // buttonKR
            // 
            this.buttonKR.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.buttonKR.Font = new System.Drawing.Font("Monotype Corsiva", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonKR.Location = new System.Drawing.Point(37, 260);
            this.buttonKR.Name = "buttonKR";
            this.buttonKR.Size = new System.Drawing.Size(205, 30);
            this.buttonKR.TabIndex = 24;
            this.buttonKR.Text = "Решить (К-Р метод)";
            this.buttonKR.UseVisualStyleBackColor = false;
            this.buttonKR.Click += new System.EventHandler(this.buttonKR_Click);
            // 
            // textBoxRg4step
            // 
            this.textBoxRg4step.Location = new System.Drawing.Point(64, 9);
            this.textBoxRg4step.Name = "textBoxRg4step";
            this.textBoxRg4step.Size = new System.Drawing.Size(47, 20);
            this.textBoxRg4step.TabIndex = 40;
            this.textBoxRg4step.Text = "0,01";
            this.textBoxRg4step.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Font = new System.Drawing.Font("Monotype Corsiva", 14.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label17.Location = new System.Drawing.Point(3, 6);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(58, 22);
            this.label17.TabIndex = 39;
            this.label17.Text = "шаг t:";
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.textBoxRg4step);
            this.panel1.Controls.Add(this.label17);
            this.panel1.Location = new System.Drawing.Point(80, 182);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(119, 36);
            this.panel1.TabIndex = 41;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(279, 295);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.buttonKR);
            this.Controls.Add(this.buttonMS);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button buttonMS;
        private System.Windows.Forms.Button buttonKR;
        private System.Windows.Forms.TextBox textBoxRg4step;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Panel panel1;
    }
}

