namespace lab3CG
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
            this.textBoxOfNumberOfParabols = new System.Windows.Forms.TextBox();
            this.labelOfNumberOfParabols = new System.Windows.Forms.Label();
            this.labelOfNumberOfCircles = new System.Windows.Forms.Label();
            this.textBoxOfNumberOfCircles = new System.Windows.Forms.TextBox();
            this.buttonOfApply1 = new System.Windows.Forms.Button();
            this.panelOfLightSource = new System.Windows.Forms.Panel();
            this.buttonOtNas = new System.Windows.Forms.Button();
            this.buttonNaNas = new System.Windows.Forms.Button();
            this.buttonDown = new System.Windows.Forms.Button();
            this.buttonLeft = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.buttonRight = new System.Windows.Forms.Button();
            this.buttonUp = new System.Windows.Forms.Button();
            this.panelOfLight = new System.Windows.Forms.Panel();
            this.trackBarMir = new System.Windows.Forms.TrackBar();
            this.trackBarRas = new System.Windows.Forms.TrackBar();
            this.trackBarFon = new System.Windows.Forms.TrackBar();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.buttonOfColor = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.panelOfMaterial = new System.Windows.Forms.Panel();
            this.buttonOfMatApply = new System.Windows.Forms.Button();
            this.label16 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.textBoxMirB = new System.Windows.Forms.TextBox();
            this.textBoxMirG = new System.Windows.Forms.TextBox();
            this.textBoxMirR = new System.Windows.Forms.TextBox();
            this.textBoxRasR = new System.Windows.Forms.TextBox();
            this.textBoxRasG = new System.Windows.Forms.TextBox();
            this.textBoxRasB = new System.Windows.Forms.TextBox();
            this.textBoxFonG = new System.Windows.Forms.TextBox();
            this.textBoxFonB = new System.Windows.Forms.TextBox();
            this.textBoxFonR = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.checkBoxOfIlluminate = new System.Windows.Forms.CheckBox();
            this.mashtabPanel.SuspendLayout();
            this.panelOfApproximation.SuspendLayout();
            this.panelOfLightSource.SuspendLayout();
            this.panelOfLight.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarMir)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRas)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFon)).BeginInit();
            this.panelOfMaterial.SuspendLayout();
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
            this.panelOfApproximation.Controls.Add(this.textBoxOfNumberOfParabols);
            this.panelOfApproximation.Controls.Add(this.labelOfNumberOfParabols);
            this.panelOfApproximation.Controls.Add(this.labelOfNumberOfCircles);
            this.panelOfApproximation.Controls.Add(this.textBoxOfNumberOfCircles);
            this.panelOfApproximation.Controls.Add(this.buttonOfApply1);
            this.panelOfApproximation.Location = new System.Drawing.Point(320, 12);
            this.panelOfApproximation.Name = "panelOfApproximation";
            this.panelOfApproximation.Size = new System.Drawing.Size(142, 119);
            this.panelOfApproximation.TabIndex = 23;
            // 
            // textBoxOfNumberOfParabols
            // 
            this.textBoxOfNumberOfParabols.Location = new System.Drawing.Point(20, 60);
            this.textBoxOfNumberOfParabols.Name = "textBoxOfNumberOfParabols";
            this.textBoxOfNumberOfParabols.Size = new System.Drawing.Size(100, 20);
            this.textBoxOfNumberOfParabols.TabIndex = 2;
            this.textBoxOfNumberOfParabols.Text = "10";
            this.textBoxOfNumberOfParabols.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // labelOfNumberOfParabols
            // 
            this.labelOfNumberOfParabols.AutoSize = true;
            this.labelOfNumberOfParabols.Location = new System.Drawing.Point(17, 44);
            this.labelOfNumberOfParabols.Name = "labelOfNumberOfParabols";
            this.labelOfNumberOfParabols.Size = new System.Drawing.Size(117, 13);
            this.labelOfNumberOfParabols.TabIndex = 8;
            this.labelOfNumberOfParabols.Text = "Количество парабол  ";
            // 
            // labelOfNumberOfCircles
            // 
            this.labelOfNumberOfCircles.AutoSize = true;
            this.labelOfNumberOfCircles.Location = new System.Drawing.Point(3, 5);
            this.labelOfNumberOfCircles.Name = "labelOfNumberOfCircles";
            this.labelOfNumberOfCircles.Size = new System.Drawing.Size(135, 13);
            this.labelOfNumberOfCircles.TabIndex = 5;
            this.labelOfNumberOfCircles.Text = "Количество окружностей";
            // 
            // textBoxOfNumberOfCircles
            // 
            this.textBoxOfNumberOfCircles.Location = new System.Drawing.Point(20, 21);
            this.textBoxOfNumberOfCircles.Name = "textBoxOfNumberOfCircles";
            this.textBoxOfNumberOfCircles.Size = new System.Drawing.Size(100, 20);
            this.textBoxOfNumberOfCircles.TabIndex = 6;
            this.textBoxOfNumberOfCircles.Text = "10";
            this.textBoxOfNumberOfCircles.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonOfApply1
            // 
            this.buttonOfApply1.Location = new System.Drawing.Point(20, 86);
            this.buttonOfApply1.Name = "buttonOfApply1";
            this.buttonOfApply1.Size = new System.Drawing.Size(100, 23);
            this.buttonOfApply1.TabIndex = 7;
            this.buttonOfApply1.Text = "Применить";
            this.buttonOfApply1.UseVisualStyleBackColor = true;
            this.buttonOfApply1.Click += new System.EventHandler(this.buttonOfApply1_Click);
            // 
            // panelOfLightSource
            // 
            this.panelOfLightSource.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelOfLightSource.Controls.Add(this.buttonOtNas);
            this.panelOfLightSource.Controls.Add(this.buttonNaNas);
            this.panelOfLightSource.Controls.Add(this.buttonDown);
            this.panelOfLightSource.Controls.Add(this.buttonLeft);
            this.panelOfLightSource.Controls.Add(this.label5);
            this.panelOfLightSource.Controls.Add(this.buttonRight);
            this.panelOfLightSource.Controls.Add(this.buttonUp);
            this.panelOfLightSource.Enabled = false;
            this.panelOfLightSource.Location = new System.Drawing.Point(178, 12);
            this.panelOfLightSource.Name = "panelOfLightSource";
            this.panelOfLightSource.Size = new System.Drawing.Size(121, 115);
            this.panelOfLightSource.TabIndex = 24;
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
            this.label5.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(3, 9);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(113, 15);
            this.label5.TabIndex = 12;
            this.label5.Text = "Источник света";
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
            // panelOfLight
            // 
            this.panelOfLight.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelOfLight.Controls.Add(this.trackBarMir);
            this.panelOfLight.Controls.Add(this.trackBarRas);
            this.panelOfLight.Controls.Add(this.trackBarFon);
            this.panelOfLight.Controls.Add(this.label4);
            this.panelOfLight.Controls.Add(this.label2);
            this.panelOfLight.Controls.Add(this.label1);
            this.panelOfLight.Controls.Add(this.label3);
            this.panelOfLight.Controls.Add(this.buttonOfColor);
            this.panelOfLight.Enabled = false;
            this.panelOfLight.Location = new System.Drawing.Point(8, 133);
            this.panelOfLight.Name = "panelOfLight";
            this.panelOfLight.Size = new System.Drawing.Size(171, 238);
            this.panelOfLight.TabIndex = 25;
            // 
            // trackBarMir
            // 
            this.trackBarMir.Location = new System.Drawing.Point(35, 199);
            this.trackBarMir.Maximum = 5;
            this.trackBarMir.Name = "trackBarMir";
            this.trackBarMir.Size = new System.Drawing.Size(104, 45);
            this.trackBarMir.TabIndex = 25;
            this.trackBarMir.ValueChanged += new System.EventHandler(this.trackBarMir_ValueChanged);
            // 
            // trackBarRas
            // 
            this.trackBarRas.Location = new System.Drawing.Point(35, 133);
            this.trackBarRas.Maximum = 5;
            this.trackBarRas.Name = "trackBarRas";
            this.trackBarRas.Size = new System.Drawing.Size(104, 45);
            this.trackBarRas.TabIndex = 24;
            this.trackBarRas.Value = 5;
            this.trackBarRas.ValueChanged += new System.EventHandler(this.trackBarRas_ValueChanged);
            // 
            // trackBarFon
            // 
            this.trackBarFon.Location = new System.Drawing.Point(35, 67);
            this.trackBarFon.Maximum = 5;
            this.trackBarFon.Name = "trackBarFon";
            this.trackBarFon.Size = new System.Drawing.Size(104, 45);
            this.trackBarFon.TabIndex = 23;
            this.trackBarFon.ValueChanged += new System.EventHandler(this.trackBarFon_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(64, 5);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 15);
            this.label4.TabIndex = 22;
            this.label4.Text = "Цвет";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(2, 181);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(164, 15);
            this.label2.TabIndex = 20;
            this.label2.Text = "Зеркальное освещение";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(17, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(144, 15);
            this.label1.TabIndex = 19;
            this.label1.Text = "Фоновое освещение";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(3, 115);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(163, 15);
            this.label3.TabIndex = 21;
            this.label3.Text = "Рассеянное освещение";
            // 
            // buttonOfColor
            // 
            this.buttonOfColor.BackColor = System.Drawing.Color.Red;
            this.buttonOfColor.Location = new System.Drawing.Point(47, 23);
            this.buttonOfColor.Name = "buttonOfColor";
            this.buttonOfColor.Size = new System.Drawing.Size(75, 23);
            this.buttonOfColor.TabIndex = 0;
            this.buttonOfColor.UseVisualStyleBackColor = false;
            this.buttonOfColor.Click += new System.EventHandler(this.buttonOfColor_Click);
            // 
            // panelOfMaterial
            // 
            this.panelOfMaterial.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelOfMaterial.Controls.Add(this.buttonOfMatApply);
            this.panelOfMaterial.Controls.Add(this.label16);
            this.panelOfMaterial.Controls.Add(this.label13);
            this.panelOfMaterial.Controls.Add(this.label17);
            this.panelOfMaterial.Controls.Add(this.label14);
            this.panelOfMaterial.Controls.Add(this.label18);
            this.panelOfMaterial.Controls.Add(this.label15);
            this.panelOfMaterial.Controls.Add(this.textBoxMirB);
            this.panelOfMaterial.Controls.Add(this.textBoxMirG);
            this.panelOfMaterial.Controls.Add(this.textBoxMirR);
            this.panelOfMaterial.Controls.Add(this.textBoxRasR);
            this.panelOfMaterial.Controls.Add(this.textBoxRasG);
            this.panelOfMaterial.Controls.Add(this.textBoxRasB);
            this.panelOfMaterial.Controls.Add(this.textBoxFonG);
            this.panelOfMaterial.Controls.Add(this.textBoxFonB);
            this.panelOfMaterial.Controls.Add(this.textBoxFonR);
            this.panelOfMaterial.Controls.Add(this.label12);
            this.panelOfMaterial.Controls.Add(this.label11);
            this.panelOfMaterial.Controls.Add(this.label10);
            this.panelOfMaterial.Controls.Add(this.label9);
            this.panelOfMaterial.Controls.Add(this.label8);
            this.panelOfMaterial.Controls.Add(this.label7);
            this.panelOfMaterial.Controls.Add(this.label6);
            this.panelOfMaterial.Enabled = false;
            this.panelOfMaterial.Location = new System.Drawing.Point(8, 384);
            this.panelOfMaterial.Name = "panelOfMaterial";
            this.panelOfMaterial.Size = new System.Drawing.Size(171, 272);
            this.panelOfMaterial.TabIndex = 26;
            // 
            // buttonOfMatApply
            // 
            this.buttonOfMatApply.Location = new System.Drawing.Point(36, 244);
            this.buttonOfMatApply.Name = "buttonOfMatApply";
            this.buttonOfMatApply.Size = new System.Drawing.Size(100, 23);
            this.buttonOfMatApply.TabIndex = 9;
            this.buttonOfMatApply.Text = "Применить";
            this.buttonOfMatApply.UseVisualStyleBackColor = true;
            this.buttonOfMatApply.Click += new System.EventHandler(this.buttonOfMatApply_Click);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(122, 196);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(14, 13);
            this.label16.TabIndex = 48;
            this.label16.Text = "B";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(122, 133);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(14, 13);
            this.label13.TabIndex = 47;
            this.label13.Text = "B";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(75, 196);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(15, 13);
            this.label17.TabIndex = 46;
            this.label17.Text = "G";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(75, 133);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(15, 13);
            this.label14.TabIndex = 45;
            this.label14.Text = "G";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(27, 133);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(15, 13);
            this.label18.TabIndex = 44;
            this.label18.Text = "R";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(27, 197);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(15, 13);
            this.label15.TabIndex = 43;
            this.label15.Text = "R";
            // 
            // textBoxMirB
            // 
            this.textBoxMirB.Location = new System.Drawing.Point(109, 213);
            this.textBoxMirB.Name = "textBoxMirB";
            this.textBoxMirB.Size = new System.Drawing.Size(38, 20);
            this.textBoxMirB.TabIndex = 42;
            this.textBoxMirB.Text = "10";
            this.textBoxMirB.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxMirG
            // 
            this.textBoxMirG.Location = new System.Drawing.Point(62, 213);
            this.textBoxMirG.Name = "textBoxMirG";
            this.textBoxMirG.Size = new System.Drawing.Size(38, 20);
            this.textBoxMirG.TabIndex = 41;
            this.textBoxMirG.Text = "10";
            this.textBoxMirG.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxMirR
            // 
            this.textBoxMirR.Location = new System.Drawing.Point(15, 213);
            this.textBoxMirR.Name = "textBoxMirR";
            this.textBoxMirR.Size = new System.Drawing.Size(38, 20);
            this.textBoxMirR.TabIndex = 40;
            this.textBoxMirR.Text = "10";
            this.textBoxMirR.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxRasR
            // 
            this.textBoxRasR.Location = new System.Drawing.Point(15, 149);
            this.textBoxRasR.Name = "textBoxRasR";
            this.textBoxRasR.Size = new System.Drawing.Size(38, 20);
            this.textBoxRasR.TabIndex = 39;
            this.textBoxRasR.Text = "10";
            this.textBoxRasR.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxRasG
            // 
            this.textBoxRasG.Location = new System.Drawing.Point(62, 149);
            this.textBoxRasG.Name = "textBoxRasG";
            this.textBoxRasG.Size = new System.Drawing.Size(38, 20);
            this.textBoxRasG.TabIndex = 38;
            this.textBoxRasG.Text = "10";
            this.textBoxRasG.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxRasB
            // 
            this.textBoxRasB.Location = new System.Drawing.Point(109, 149);
            this.textBoxRasB.Name = "textBoxRasB";
            this.textBoxRasB.Size = new System.Drawing.Size(38, 20);
            this.textBoxRasB.TabIndex = 37;
            this.textBoxRasB.Text = "10";
            this.textBoxRasB.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxFonG
            // 
            this.textBoxFonG.Location = new System.Drawing.Point(62, 84);
            this.textBoxFonG.Name = "textBoxFonG";
            this.textBoxFonG.Size = new System.Drawing.Size(38, 20);
            this.textBoxFonG.TabIndex = 36;
            this.textBoxFonG.Text = "10";
            this.textBoxFonG.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxFonB
            // 
            this.textBoxFonB.Location = new System.Drawing.Point(109, 84);
            this.textBoxFonB.Name = "textBoxFonB";
            this.textBoxFonB.Size = new System.Drawing.Size(38, 20);
            this.textBoxFonB.TabIndex = 35;
            this.textBoxFonB.Text = "10";
            this.textBoxFonB.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxFonR
            // 
            this.textBoxFonR.Location = new System.Drawing.Point(15, 84);
            this.textBoxFonR.Name = "textBoxFonR";
            this.textBoxFonR.Size = new System.Drawing.Size(38, 20);
            this.textBoxFonR.TabIndex = 34;
            this.textBoxFonR.Text = "10";
            this.textBoxFonR.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(75, 68);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(15, 13);
            this.label12.TabIndex = 27;
            this.label12.Text = "G";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(122, 67);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(14, 13);
            this.label11.TabIndex = 26;
            this.label11.Text = "B";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(27, 67);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(15, 13);
            this.label10.TabIndex = 25;
            this.label10.Text = "R";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label9.Location = new System.Drawing.Point(48, 5);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(75, 15);
            this.label9.TabIndex = 24;
            this.label9.Text = "Материал";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label8.Location = new System.Drawing.Point(2, 181);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(164, 15);
            this.label8.TabIndex = 23;
            this.label8.Text = "Зеркальное освещение";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label7.Location = new System.Drawing.Point(3, 115);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(163, 15);
            this.label7.TabIndex = 22;
            this.label7.Text = "Рассеянное освещение";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label6.Location = new System.Drawing.Point(12, 49);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(144, 15);
            this.label6.TabIndex = 20;
            this.label6.Text = "Фоновое освещение";
            // 
            // checkBoxOfIlluminate
            // 
            this.checkBoxOfIlluminate.AutoSize = true;
            this.checkBoxOfIlluminate.Location = new System.Drawing.Point(12, 69);
            this.checkBoxOfIlluminate.Name = "checkBoxOfIlluminate";
            this.checkBoxOfIlluminate.Size = new System.Drawing.Size(134, 17);
            this.checkBoxOfIlluminate.TabIndex = 27;
            this.checkBoxOfIlluminate.Text = "включить освещение";
            this.checkBoxOfIlluminate.UseVisualStyleBackColor = true;
            this.checkBoxOfIlluminate.CheckedChanged += new System.EventHandler(this.checkBoxOfIlluminate_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(878, 859);
            this.Controls.Add(this.checkBoxOfIlluminate);
            this.Controls.Add(this.panelOfMaterial);
            this.Controls.Add(this.panelOfLight);
            this.Controls.Add(this.panelOfLightSource);
            this.Controls.Add(this.panelOfApproximation);
            this.Controls.Add(this.mashtabPanel);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.mashtabPanel.ResumeLayout(false);
            this.mashtabPanel.PerformLayout();
            this.panelOfApproximation.ResumeLayout(false);
            this.panelOfApproximation.PerformLayout();
            this.panelOfLightSource.ResumeLayout(false);
            this.panelOfLightSource.PerformLayout();
            this.panelOfLight.ResumeLayout(false);
            this.panelOfLight.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarMir)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRas)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFon)).EndInit();
            this.panelOfMaterial.ResumeLayout(false);
            this.panelOfMaterial.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel mashtabPanel;
        private System.Windows.Forms.Label mashtabLabel;
        private System.Windows.Forms.Button mashtabPlusButton;
        private System.Windows.Forms.Button mashtabMinusButton;
        private System.Windows.Forms.Panel panelOfApproximation;
        private System.Windows.Forms.TextBox textBoxOfNumberOfCircles;
        private System.Windows.Forms.Button buttonOfApply1;
        private System.Windows.Forms.Label labelOfNumberOfCircles;
        private System.Windows.Forms.TextBox textBoxOfNumberOfParabols;
        private System.Windows.Forms.Label labelOfNumberOfParabols;
        private System.Windows.Forms.Panel panelOfLightSource;
        private System.Windows.Forms.Button buttonDown;
        private System.Windows.Forms.Button buttonRight;
        private System.Windows.Forms.Button buttonLeft;
        private System.Windows.Forms.Button buttonUp;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button buttonOtNas;
        private System.Windows.Forms.Button buttonNaNas;
        private System.Windows.Forms.Panel panelOfLight;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Button buttonOfColor;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TrackBar trackBarMir;
        private System.Windows.Forms.TrackBar trackBarRas;
        private System.Windows.Forms.TrackBar trackBarFon;
        private System.Windows.Forms.Panel panelOfMaterial;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.TextBox textBoxMirB;
        private System.Windows.Forms.TextBox textBoxMirG;
        private System.Windows.Forms.TextBox textBoxMirR;
        private System.Windows.Forms.TextBox textBoxRasR;
        private System.Windows.Forms.TextBox textBoxRasG;
        private System.Windows.Forms.TextBox textBoxRasB;
        private System.Windows.Forms.TextBox textBoxFonG;
        private System.Windows.Forms.TextBox textBoxFonB;
        private System.Windows.Forms.TextBox textBoxFonR;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Button buttonOfMatApply;
        private System.Windows.Forms.CheckBox checkBoxOfIlluminate;
    }
}

