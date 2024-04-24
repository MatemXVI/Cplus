using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Studenty
{
    public partial class StudentForm : Form

    {

        private Student student;

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }


        public StudentForm(Student student)
        {
            this.student = student;
            InitializeComponent();
        }

        private void StudentForm_Load(object sender, EventArgs e)
        {
            if (student != null)
            {
                nameTextBox.Text = student.Name;
                indexTextBox.Text = student.Index.ToString();
                birthDateTimePicker.Value = student.BirthDate;
            }
        }

        private void okButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }
    }
}

