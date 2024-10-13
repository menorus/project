using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Phonetable
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
            Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
            Close();
        }
        public Dictionary<int, string> AbonentData
        {
            set
            {
                abonentCombo.DataSource = value.ToArray();
                abonentCombo.DisplayMember = "Value";
            }
        }

        /*public Dictionary<int, string> ContactData
        {
            set
            {
                contactCombo.DataSource = value.ToArray();
                contactCombo.DisplayMember = "Value";
            }
        }*/
        public Dictionary<int, string> CountryData
        {
            set
            {
                Countrycombo.DataSource = value.ToArray();
                Countrycombo.DisplayMember = "Value";
            }
        }
        public Dictionary<int, string> TypeData
        {
            set
            {
                TypeCombo.DataSource = value.ToArray();
                TypeCombo.DisplayMember = "Value";
            }
        }
        public int AbonentID
        {
            get
            {
                return ((KeyValuePair<int, string>)abonentCombo.SelectedItem).Key;
            }
            set
            {
                int idx = 0;
                foreach (KeyValuePair<int, string> item in abonentCombo.Items)
                {
                    if (item.Key == value)
                    { break; }
                    idx++;
                }
                abonentCombo.SelectedIndex = idx;
            }
        }
        public int CountryID
        {
            get
            {
                return ((KeyValuePair<int, string>)Countrycombo.SelectedItem).Key;
            }
            set
            {
                int idx = 0;
                foreach (KeyValuePair<int, string> item in Countrycombo.Items)
                {
                    if (item.Key == value)
                    { break; }
                    idx++;
                }
                Countrycombo.SelectedIndex = idx;
            }
        }
        /*public string ContactID
        {
            get
            {
                return ((KeyValuePair<int, string>)contactCombo.SelectedItem).Value;
            }
            set
            {
                int idx = 0;
                foreach (KeyValuePair<int, string> item in contactCombo.Items)
                {
                    if (item.Value == value)
                    { break; }
                    idx++;
                }
                contactCombo.SelectedIndex = idx;
            }
        }*/
        public string TypeID
        {
            get
            {
                return ((KeyValuePair<int, string>)TypeCombo.SelectedItem).Value;
            }
            set
            {
                int idx = 0;
                foreach (KeyValuePair<int, string> item in TypeCombo.Items)
                {
                    if (item.Value == value)
                    { break; }
                    idx++;
                }
                TypeCombo.SelectedIndex = idx;
            }
        }
    }
}
