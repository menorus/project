namespace Phonetable
{
    partial class Form2
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
            CityCodes = new TextBox();
            CountryCodes = new TextBox();
            City = new TextBox();
            Country = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            label4 = new Label();
            button1 = new Button();
            SuspendLayout();
            // 
            // CityCodes
            // 
            CityCodes.Location = new Point(81, 22);
            CityCodes.Name = "CityCodes";
            CityCodes.Size = new Size(148, 23);
            CityCodes.TabIndex = 0;
            // 
            // CountryCodes
            // 
            CountryCodes.Location = new Point(81, 64);
            CountryCodes.Name = "CountryCodes";
            CountryCodes.Size = new Size(148, 23);
            CountryCodes.TabIndex = 1;
            // 
            // City
            // 
            City.Location = new Point(81, 103);
            City.Name = "City";
            City.Size = new Size(148, 23);
            City.TabIndex = 2;
            // 
            // Country
            // 
            Country.Location = new Point(81, 143);
            Country.Name = "Country";
            Country.Size = new Size(148, 23);
            Country.TabIndex = 3;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(5, 25);
            label1.Name = "label1";
            label1.Size = new Size(70, 15);
            label1.TabIndex = 4;
            label1.Text = "Код страны";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(5, 67);
            label2.Name = "label2";
            label2.Size = new Size(68, 15);
            label2.TabIndex = 5;
            label2.Text = "Код города";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(5, 106);
            label3.Name = "label3";
            label3.Size = new Size(46, 15);
            label3.TabIndex = 6;
            label3.Text = "Страна";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(5, 146);
            label4.Name = "label4";
            label4.Size = new Size(40, 15);
            label4.TabIndex = 7;
            label4.Text = "Город";
            // 
            // button1
            // 
            button1.Location = new Point(81, 219);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 8;
            button1.Text = "ОК";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Form2
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(241, 278);
            Controls.Add(button1);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(Country);
            Controls.Add(City);
            Controls.Add(CountryCodes);
            Controls.Add(CityCodes);
            Name = "Form2";
            Text = "Form2";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Button button1;
        public TextBox CityCodes;
        public TextBox CountryCodes;
        public TextBox City;
        public TextBox Country;
    }
}