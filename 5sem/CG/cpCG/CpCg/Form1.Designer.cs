namespace CpCG
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
            this.panelOfApproximation = new System.Windows.Forms.Panel();
            this.labelOfNumberOfDrawPoints = new System.Windows.Forms.Label();
            this.textBoxOfNumberOfDrawPoints = new System.Windows.Forms.TextBox();
            this.buttonOfApply1 = new System.Windows.Forms.Button();
            this.panelOfDataPoints = new System.Windows.Forms.Panel();
            this.buttonOfDataPointCounter = new System.Windows.Forms.Button();
            this.buttonOtNas = new System.Windows.Forms.Button();
            this.buttonNaNas = new System.Windows.Forms.Button();
            this.buttonDown = new System.Windows.Forms.Button();
            this.buttonLeft = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.buttonRight = new System.Windows.Forms.Button();
            this.buttonUp = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.checkBoxOfMerkersEnabled = new System.Windows.Forms.CheckBox();
            this.mashtabPanel.SuspendLayout();
            this.panelOfApproximation.SuspendLayout();
            this.panelOfDataPoints.SuspendLayout();
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
            this.mashtabLabel.BackColor = System.Drawing.SystemColors.Highlight;
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
            this.mashtabPlusButton.TabIndex = 19;
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
            this.mashtabMinusButton.TabIndex = 20;
            this.mashtabMinusButton.Text = "-";
            this.mashtabMinusButton.UseVisualStyleBackColor = true;
            this.mashtabMinusButton.Click += new System.EventHandler(this.mashtabMinusButton_Click);
            // 
            // panelOfApproximation
            // 
            this.panelOfApproximation.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelOfApproximation.Controls.Add(this.labelOfNumberOfDrawPoints);
            this.panelOfApproximation.Controls.Add(this.textBoxOfNumberOfDrawPoints);
            this.panelOfApproximation.Controls.Add(this.buttonOfApply1);
            this.panelOfApproximation.Location = new System.Drawing.Point(8, 82);
            this.panelOfApproximation.Name = "panelOfApproximation";
            this.panelOfApproximation.Size = new System.Drawing.Size(142, 77);
            this.panelOfApproximation.TabIndex = 23;
            // 
            // labelOfNumberOfDrawPoints
            // 
            this.labelOfNumberOfDrawPoints.AutoSize = true;
            this.labelOfNumberOfDrawPoints.Location = new System.Drawing.Point(7, 5);
            this.labelOfNumberOfDrawPoints.Name = "labelOfNumberOfDrawPoints";
            this.labelOfNumberOfDrawPoints.Size = new System.Drawing.Size(130, 13);
            this.labelOfNumberOfDrawPoints.TabIndex = 5;
            this.labelOfNumberOfDrawPoints.Text = "Точночть апроксимации";
            // 
            // textBoxOfNumberOfDrawPoints
            // 
            this.textBoxOfNumberOfDrawPoints.Location = new System.Drawing.Point(20, 21);
            this.textBoxOfNumberOfDrawPoints.Name = "textBoxOfNumberOfDrawPoints";
            this.textBoxOfNumberOfDrawPoints.Size = new System.Drawing.Size(100, 20);
            this.textBoxOfNumberOfDrawPoints.TabIndex = 6;
            this.textBoxOfNumberOfDrawPoints.Text = "40";
            this.textBoxOfNumberOfDrawPoints.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonOfApply1
            // 
            this.buttonOfApply1.Location = new System.Drawing.Point(20, 47);
            this.buttonOfApply1.Name = "buttonOfApply1";
            this.buttonOfApply1.Size = new System.Drawing.Size(100, 23);
            this.buttonOfApply1.TabIndex = 7;
            this.buttonOfApply1.Text = "Применить";
            this.buttonOfApply1.UseVisualStyleBackColor = true;
            this.buttonOfApply1.Click += new System.EventHandler(this.buttonOfApply1_Click);
            // 
            // panelOfDataPoints
            // 
            this.panelOfDataPoints.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelOfDataPoints.Controls.Add(this.buttonOfDataPointCounter);
            this.panelOfDataPoints.Controls.Add(this.buttonOtNas);
            this.panelOfDataPoints.Controls.Add(this.buttonNaNas);
            this.panelOfDataPoints.Controls.Add(this.buttonDown);
            this.panelOfDataPoints.Controls.Add(this.buttonLeft);
            this.panelOfDataPoints.Controls.Add(this.label5);
            this.panelOfDataPoints.Controls.Add(this.buttonRight);
            this.panelOfDataPoints.Controls.Add(this.buttonUp);
            this.panelOfDataPoints.Location = new System.Drawing.Point(12, 171);
            this.panelOfDataPoints.Name = "panelOfDataPoints";
            this.panelOfDataPoints.Size = new System.Drawing.Size(121, 137);
            this.panelOfDataPoints.TabIndex = 24;
            // 
            // buttonOfDataPointCounter
            // 
            this.buttonOfDataPointCounter.Location = new System.Drawing.Point(3, 109);
            this.buttonOfDataPointCounter.Name = "buttonOfDataPointCounter";
            this.buttonOfDataPointCounter.Size = new System.Drawing.Size(113, 23);
            this.buttonOfDataPointCounter.TabIndex = 19;
            this.buttonOfDataPointCounter.Text = "следующая точка";
            this.buttonOfDataPointCounter.UseVisualStyleBackColor = true;
            this.buttonOfDataPointCounter.Click += new System.EventHandler(this.buttonOfDataPointCounter_Click);
            // 
            // buttonOtNas
            // 
            this.buttonOtNas.Location = new System.Drawing.Point(58, 85);
            this.buttonOtNas.Name = "buttonOtNas";
            this.buttonOtNas.Size = new System.Drawing.Size(58, 23);
            this.buttonOtNas.TabIndex = 18;
            this.buttonOtNas.Text = "X";
            this.buttonOtNas.UseVisualStyleBackColor = true;
            this.buttonOtNas.Click += new System.EventHandler(this.buttonOtNas_Click);
            // 
            // buttonNaNas
            // 
            this.buttonNaNas.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonNaNas.Location = new System.Drawing.Point(3, 85);
            this.buttonNaNas.Name = "buttonNaNas";
            this.buttonNaNas.Size = new System.Drawing.Size(49, 23);
            this.buttonNaNas.TabIndex = 17;
            this.buttonNaNas.Text = "*";
            this.buttonNaNas.UseVisualStyleBackColor = true;
            this.buttonNaNas.Click += new System.EventHandler(this.buttonNaNas_Click);
            // 
            // buttonDown
            // 
            this.buttonDown.Location = new System.Drawing.Point(58, 27);
            this.buttonDown.Name = "buttonDown";
            this.buttonDown.Size = new System.Drawing.Size(58, 23);
            this.buttonDown.TabIndex = 16;
            this.buttonDown.Text = "Вниз";
            this.buttonDown.UseVisualStyleBackColor = true;
            this.buttonDown.Click += new System.EventHandler(this.buttonDown_Click);
            // 
            // buttonLeft
            // 
            this.buttonLeft.Location = new System.Drawing.Point(3, 56);
            this.buttonLeft.Name = "buttonLeft";
            this.buttonLeft.Size = new System.Drawing.Size(49, 23);
            this.buttonLeft.TabIndex = 14;
            this.buttonLeft.Text = "Влево";
            this.buttonLeft.UseVisualStyleBackColor = true;
            this.buttonLeft.Click += new System.EventHandler(this.buttonLeft_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.SystemColors.MenuHighlight;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(7, 9);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(109, 15);
            this.label5.TabIndex = 12;
            this.label5.Text = "Опорные точки";
            // 
            // buttonRight
            // 
            this.buttonRight.Location = new System.Drawing.Point(58, 56);
            this.buttonRight.Name = "buttonRight";
            this.buttonRight.Size = new System.Drawing.Size(58, 23);
            this.buttonRight.TabIndex = 15;
            this.buttonRight.Text = "Вправо";
            this.buttonRight.UseVisualStyleBackColor = true;
            this.buttonRight.Click += new System.EventHandler(this.buttonRight_Click);
            // 
            // buttonUp
            // 
            this.buttonUp.Location = new System.Drawing.Point(3, 27);
            this.buttonUp.Name = "buttonUp";
            this.buttonUp.Size = new System.Drawing.Size(49, 23);
            this.buttonUp.TabIndex = 13;
            this.buttonUp.Text = "Вверх";
            this.buttonUp.UseVisualStyleBackColor = true;
            this.buttonUp.Click += new System.EventHandler(this.buttonUp_Click);
            // 
            // checkBoxOfMerkersEnabled
            // 
            this.checkBoxOfMerkersEnabled.Appearance = System.Windows.Forms.Appearance.Button;
            this.checkBoxOfMerkersEnabled.AutoSize = true;
            this.checkBoxOfMerkersEnabled.Location = new System.Drawing.Point(12, 53);
            this.checkBoxOfMerkersEnabled.Name = "checkBoxOfMerkersEnabled";
            this.checkBoxOfMerkersEnabled.Size = new System.Drawing.Size(138, 23);
            this.checkBoxOfMerkersEnabled.TabIndex = 25;
            this.checkBoxOfMerkersEnabled.Text = "Режим редактирования";
            this.checkBoxOfMerkersEnabled.UseVisualStyleBackColor = true;
            this.checkBoxOfMerkersEnabled.CheckedChanged += new System.EventHandler(this.checkBoxOfMerkersEnabled_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(878, 859);
            this.Controls.Add(this.checkBoxOfMerkersEnabled);
            this.Controls.Add(this.panelOfDataPoints);
            this.Controls.Add(this.panelOfApproximation);
            this.Controls.Add(this.mashtabPanel);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "CpCG";
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.mashtabPanel.ResumeLayout(false);
            this.mashtabPanel.PerformLayout();
            this.panelOfApproximation.ResumeLayout(false);
            this.panelOfApproximation.PerformLayout();
            this.panelOfDataPoints.ResumeLayout(false);
            this.panelOfDataPoints.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel mashtabPanel;
        private System.Windows.Forms.Label mashtabLabel;
        private System.Windows.Forms.Button mashtabPlusButton;
        private System.Windows.Forms.Button mashtabMinusButton;
        private System.Windows.Forms.Panel panelOfApproximation;
        private System.Windows.Forms.TextBox textBoxOfNumberOfDrawPoints;
        private System.Windows.Forms.Button buttonOfApply1;
        private System.Windows.Forms.Label labelOfNumberOfDrawPoints;
        private System.Windows.Forms.Panel panelOfDataPoints;
        private System.Windows.Forms.Button buttonDown;
        private System.Windows.Forms.Button buttonRight;
        private System.Windows.Forms.Button buttonLeft;
        private System.Windows.Forms.Button buttonUp;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button buttonOtNas;
        private System.Windows.Forms.Button buttonNaNas;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Button buttonOfDataPointCounter;
        private System.Windows.Forms.CheckBox checkBoxOfMerkersEnabled;
    }
}

