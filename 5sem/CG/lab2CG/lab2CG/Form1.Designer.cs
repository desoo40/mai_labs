namespace lab2CG
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
            this.mashtabPanel = new System.Windows.Forms.Panel();
            this.mashtabLabel = new System.Windows.Forms.Label();
            this.mashtabPlusButton = new System.Windows.Forms.Button();
            this.mashtabMinusButton = new System.Windows.Forms.Button();
            this.invLinCheckBox = new System.Windows.Forms.CheckBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.textBoxOfPirRadius = new System.Windows.Forms.TextBox();
            this.labelOfPirRadius = new System.Windows.Forms.Label();
            this.labelOfPirHight = new System.Windows.Forms.Label();
            this.textBoxOfPirHight = new System.Windows.Forms.TextBox();
            this.buttonOfApply1 = new System.Windows.Forms.Button();
            this.izometrCheckBox = new System.Windows.Forms.CheckBox();
            this.mashtabPanel.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // mashtabPanel
            // 
            this.mashtabPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.mashtabPanel.Controls.Add(this.mashtabLabel);
            this.mashtabPanel.Controls.Add(this.mashtabPlusButton);
            this.mashtabPanel.Controls.Add(this.mashtabMinusButton);
            this.mashtabPanel.Location = new System.Drawing.Point(12, 12);
            this.mashtabPanel.Name = "mashtabPanel";
            this.mashtabPanel.Size = new System.Drawing.Size(142, 33);
            this.mashtabPanel.TabIndex = 22;
            // 
            // mashtabLabel
            // 
            this.mashtabLabel.AutoSize = true;
            this.mashtabLabel.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.mashtabLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mashtabLabel.Location = new System.Drawing.Point(3, 8);
            this.mashtabLabel.Name = "mashtabLabel";
            this.mashtabLabel.Size = new System.Drawing.Size(68, 15);
            this.mashtabLabel.TabIndex = 18;
            this.mashtabLabel.Text = "Масштаб";
            // 
            // mashtabPlusButton
            // 
            this.mashtabPlusButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mashtabPlusButton.Location = new System.Drawing.Point(110, 5);
            this.mashtabPlusButton.Name = "mashtabPlusButton";
            this.mashtabPlusButton.Size = new System.Drawing.Size(27, 23);
            this.mashtabPlusButton.TabIndex = 5;
            this.mashtabPlusButton.Text = "+";
            this.mashtabPlusButton.UseVisualStyleBackColor = true;
            this.mashtabPlusButton.Click += new System.EventHandler(this.mashtabPlusButton_Click);
            // 
            // mashtabMinusButton
            // 
            this.mashtabMinusButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mashtabMinusButton.Location = new System.Drawing.Point(77, 5);
            this.mashtabMinusButton.Name = "mashtabMinusButton";
            this.mashtabMinusButton.Size = new System.Drawing.Size(27, 23);
            this.mashtabMinusButton.TabIndex = 4;
            this.mashtabMinusButton.Text = "-";
            this.mashtabMinusButton.UseVisualStyleBackColor = true;
            this.mashtabMinusButton.Click += new System.EventHandler(this.mashtabMinusButton_Click);
            // 
            // invLinCheckBox
            // 
            this.invLinCheckBox.AutoSize = true;
            this.invLinCheckBox.Location = new System.Drawing.Point(160, 21);
            this.invLinCheckBox.Name = "invLinCheckBox";
            this.invLinCheckBox.Size = new System.Drawing.Size(167, 17);
            this.invLinCheckBox.TabIndex = 6;
            this.invLinCheckBox.Text = "рисовать невидимые линии";
            this.invLinCheckBox.UseVisualStyleBackColor = true;
            this.invLinCheckBox.CheckedChanged += new System.EventHandler(this.invLinCheckBox_CheckedChanged);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.textBoxOfPirRadius);
            this.panel1.Controls.Add(this.labelOfPirRadius);
            this.panel1.Controls.Add(this.labelOfPirHight);
            this.panel1.Controls.Add(this.textBoxOfPirHight);
            this.panel1.Controls.Add(this.buttonOfApply1);
            this.panel1.Location = new System.Drawing.Point(12, 51);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(142, 119);
            this.panel1.TabIndex = 24;
            // 
            // textBoxOfPirRadius
            // 
            this.textBoxOfPirRadius.Location = new System.Drawing.Point(20, 60);
            this.textBoxOfPirRadius.Name = "textBoxOfPirRadius";
            this.textBoxOfPirRadius.Size = new System.Drawing.Size(100, 20);
            this.textBoxOfPirRadius.TabIndex = 2;
            this.textBoxOfPirRadius.Text = "5";
            this.textBoxOfPirRadius.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // labelOfPirRadius
            // 
            this.labelOfPirRadius.AutoSize = true;
            this.labelOfPirRadius.Location = new System.Drawing.Point(22, 44);
            this.labelOfPirRadius.Name = "labelOfPirRadius";
            this.labelOfPirRadius.Size = new System.Drawing.Size(98, 13);
            this.labelOfPirRadius.TabIndex = 8;
            this.labelOfPirRadius.Text = "Радиус пирамиды";
            // 
            // labelOfPirHight
            // 
            this.labelOfPirHight.AutoSize = true;
            this.labelOfPirHight.Location = new System.Drawing.Point(20, 5);
            this.labelOfPirHight.Name = "labelOfPirHight";
            this.labelOfPirHight.Size = new System.Drawing.Size(100, 13);
            this.labelOfPirHight.TabIndex = 5;
            this.labelOfPirHight.Text = "Высота пирамиды";
            // 
            // textBoxOfPirHight
            // 
            this.textBoxOfPirHight.Location = new System.Drawing.Point(20, 21);
            this.textBoxOfPirHight.Name = "textBoxOfPirHight";
            this.textBoxOfPirHight.Size = new System.Drawing.Size(100, 20);
            this.textBoxOfPirHight.TabIndex = 1;
            this.textBoxOfPirHight.Text = "5";
            this.textBoxOfPirHight.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonOfApply1
            // 
            this.buttonOfApply1.Location = new System.Drawing.Point(20, 86);
            this.buttonOfApply1.Name = "buttonOfApply1";
            this.buttonOfApply1.Size = new System.Drawing.Size(100, 23);
            this.buttonOfApply1.TabIndex = 3;
            this.buttonOfApply1.Text = "Применить";
            this.buttonOfApply1.UseVisualStyleBackColor = true;
            this.buttonOfApply1.Click += new System.EventHandler(this.buttonOfApply1_Click);
            // 
            // izometrCheckBox
            // 
            this.izometrCheckBox.AutoSize = true;
            this.izometrCheckBox.Location = new System.Drawing.Point(333, 21);
            this.izometrCheckBox.Name = "izometrCheckBox";
            this.izometrCheckBox.Size = new System.Drawing.Size(161, 17);
            this.izometrCheckBox.TabIndex = 25;
            this.izometrCheckBox.Text = "изометрическая проекция";
            this.izometrCheckBox.UseVisualStyleBackColor = true;
            this.izometrCheckBox.CheckedChanged += new System.EventHandler(this.izometrCheckBox_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(590, 581);
            this.Controls.Add(this.izometrCheckBox);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.invLinCheckBox);
            this.Controls.Add(this.mashtabPanel);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.mashtabPanel.ResumeLayout(false);
            this.mashtabPanel.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel mashtabPanel;
        private System.Windows.Forms.Label mashtabLabel;
        private System.Windows.Forms.Button mashtabPlusButton;
        private System.Windows.Forms.Button mashtabMinusButton;
        private System.Windows.Forms.CheckBox invLinCheckBox;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TextBox textBoxOfPirRadius;
        private System.Windows.Forms.Label labelOfPirRadius;
        private System.Windows.Forms.Label labelOfPirHight;
        private System.Windows.Forms.TextBox textBoxOfPirHight;
        private System.Windows.Forms.Button buttonOfApply1;
        private System.Windows.Forms.CheckBox izometrCheckBox;
    }
}

