namespace Phonetable
{
    partial class Form3
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
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            dateTimePicker1 = new DateTimePicker();
            name = new TextBox();
            surname = new TextBox();
            patronymic = new TextBox();
            address = new TextBox();
            comment = new TextBox();
            button1 = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(48, 33);
            label1.Name = "label1";
            label1.Size = new Size(31, 15);
            label1.TabIndex = 0;
            label1.Text = "Имя";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(34, 59);
            label2.Name = "label2";
            label2.Size = new Size(58, 15);
            label2.TabIndex = 1;
            label2.Text = "Фамилия";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(34, 85);
            label3.Name = "label3";
            label3.Size = new Size(58, 15);
            label3.TabIndex = 2;
            label3.Text = "Отчество";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(43, 111);
            label4.Name = "label4";
            label4.Size = new Size(40, 15);
            label4.TabIndex = 3;
            label4.Text = "Адрес";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(18, 137);
            label5.Name = "label5";
            label5.Size = new Size(90, 15);
            label5.TabIndex = 4;
            label5.Text = "Дата рождения";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(21, 163);
            label6.Name = "label6";
            label6.Size = new Size(84, 15);
            label6.TabIndex = 5;
            label6.Text = "Комментарий";
            // 
            // dateTimePicker1
            // 
            dateTimePicker1.Location = new Point(130, 130);
            dateTimePicker1.Name = "dateTimePicker1";
            dateTimePicker1.Size = new Size(121, 23);
            dateTimePicker1.TabIndex = 6;
            // 
            // name
            // 
            name.Location = new Point(130, 30);
            name.Name = "name";
            name.Size = new Size(121, 23);
            name.TabIndex = 7;
            // 
            // surname
            // 
            surname.Location = new Point(130, 55);
            surname.Name = "surname";
            surname.Size = new Size(121, 23);
            surname.TabIndex = 8;
            // 
            // patronymic
            // 
            patronymic.Location = new Point(130, 80);
            patronymic.Name = "patronymic";
            patronymic.Size = new Size(121, 23);
            patronymic.TabIndex = 9;
            // 
            // address
            // 
            address.Location = new Point(130, 105);
            address.Name = "address";
            address.Size = new Size(121, 23);
            address.TabIndex = 10;
            // 
            // comment
            // 
            comment.Location = new Point(130, 155);
            comment.Name = "comment";
            comment.Size = new Size(121, 23);
            comment.TabIndex = 11;
            // 
            // button1
            // 
            button1.Location = new Point(107, 205);
            button1.Name = "button1";
            button1.Size = new Size(75, 23);
            button1.TabIndex = 12;
            button1.Text = "Ок";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Form3
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(292, 240);
            Controls.Add(button1);
            Controls.Add(comment);
            Controls.Add(address);
            Controls.Add(patronymic);
            Controls.Add(surname);
            Controls.Add(name);
            Controls.Add(dateTimePicker1);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Name = "Form3";
            Text = "Form3";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        public DateTimePicker dateTimePicker1;
        public TextBox name;
        public TextBox surname;
        public TextBox patronymic;
        public TextBox address;
        public TextBox comment;
        private Button button1;
    }
}