namespace Phonetable
{
    partial class Form4
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
            label1 = new Label();
            label2 = new Label();
            button1 = new Button();
            button2 = new Button();
            abonentCombo = new ComboBox();
            Countrycombo = new ComboBox();
            label3 = new Label();
            TypeCombo = new ComboBox();
            label4 = new Label();
            ContactBox = new TextBox();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(35, 37);
            label1.Name = "label1";
            label1.Size = new Size(54, 15);
            label1.TabIndex = 2;
            label1.Text = "Абонент";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(35, 136);
            label2.Name = "label2";
            label2.Size = new Size(50, 15);
            label2.TabIndex = 3;
            label2.Text = "Контакт";
            // 
            // button1
            // 
            button1.Location = new Point(288, 215);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 4;
            button1.Text = "ОК";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Location = new Point(370, 215);
            button2.Name = "button2";
            button2.Size = new Size(75, 23);
            button2.TabIndex = 5;
            button2.Text = "Отмена";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // abonentCombo
            // 
            abonentCombo.FormattingEnabled = true;
            abonentCombo.Location = new Point(145, 37);
            abonentCombo.Name = "abonentCombo";
            abonentCombo.Size = new Size(300, 23);
            abonentCombo.TabIndex = 6;
            // 
            // Countrycombo
            // 
            Countrycombo.FormattingEnabled = true;
            Countrycombo.Location = new Point(145, 85);
            Countrycombo.Name = "Countrycombo";
            Countrycombo.Size = new Size(300, 23);
            Countrycombo.TabIndex = 9;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(35, 88);
            label3.Name = "label3";
            label3.Size = new Size(40, 15);
            label3.TabIndex = 10;
            label3.Text = "Город";
            // 
            // TypeCombo
            // 
            TypeCombo.FormattingEnabled = true;
            TypeCombo.Location = new Point(145, 173);
            TypeCombo.Name = "TypeCombo";
            TypeCombo.Size = new Size(300, 23);
            TypeCombo.TabIndex = 12;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(35, 176);
            label4.Name = "label4";
            label4.Size = new Size(83, 15);
            label4.TabIndex = 11;
            label4.Text = "Тип телефона";
            // 
            // ContactBox
            // 
            ContactBox.Location = new Point(145, 133);
            ContactBox.Name = "ContactBox";
            ContactBox.Size = new Size(300, 23);
            ContactBox.TabIndex = 13;
            // 
            // Form4
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(457, 250);
            Controls.Add(ContactBox);
            Controls.Add(TypeCombo);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(Countrycombo);
            Controls.Add(abonentCombo);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form4";
            Text = "Form4";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label label1;
        private Label label2;
        private Button button1;
        private Button button2;
        private ComboBox abonentCombo;
        private ComboBox Countrycombo;
        private Label label3;
        private ComboBox TypeCombo;
        private Label label4;
        public TextBox ContactBox;
    }
}