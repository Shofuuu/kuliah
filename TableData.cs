using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DataTableCSV
{
    public partial class Form1 : Form
    {
        DataTable table = new DataTable();

        public Form1()
        {
            InitializeComponent();
        }

        private void CreateTable_Click(object sender, EventArgs e)
        {
            try
            {
                table.Columns.Add("Nama");
                table.Columns.Add("Old");
                DataGrid.DataSource = table;
            }
            catch (Exception ex)
            {
                MessageBox.Show("ERROR!", "ERROR MESSAGE");
            }
        }

        private void Close_Click(object sender, EventArgs e)
        {
            DialogResult r = MessageBox.Show("Exit?","Warning Message",MessageBoxButtons.YesNo);

            if(r == DialogResult.Yes)
                Application.Exit();
        }

        private void Add_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            int x = r.Next(100);
            table.Rows.Add("D3 ELINS", x);
        }

        private string ToCSV(DataTable table) {
            var result = new StringBuilder();

            for (int x = 0; x < table.Columns.Count; x++)
            {
                result.Append(table.Columns[x].ColumnName);
                result.Append(x == table.Columns.Count - 1 ? "\n" : ",");
            }

            foreach (DataRow row in table.Rows)
            {
                for (int x = 0; x < table.Columns.Count; x++)
                {
                    result.Append(row[x].ToString());
                    result.Append(x == table.Columns.Count - 1 ? "\n" : ",");
                }
            }

            return result.ToString();
        }

        private void Save_Click(object sender, EventArgs e)
        {
            String r = ToCSV(table);
            String p = "";

            SaveFile.Filter = "csv files (*.csv)|*.csv";
            SaveFile.FilterIndex = 1;
            SaveFile.RestoreDirectory = true;

            if (SaveFile.ShowDialog() == DialogResult.OK)
            {
                p = SaveFile.FileName;
                System.IO.File.WriteAllText(p, r);
            }
        }

        private void Delete_Click(object sender, EventArgs e)
        {
            int x = DataGrid.CurrentCell.RowIndex;
            table.Rows[x].Delete();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            DataGrid.ReadOnly = true;
        }
    }
}
