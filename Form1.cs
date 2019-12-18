using System;
using System.IO.Ports;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Responsi_Antarmuka
{
    public partial class Form1 : Form
    {
        SerialPort Port;
        bool isopen = false;
        DataTable Tabel = new DataTable();
        int counter = 0;

        public Form1()
        {
            InitializeComponent();
            foreach (string port in SerialPort.GetPortNames())
            {
                ListPort.Items.Add(port);
            }

            try
            {
                Tabel.Columns.Add("Voltage (V)");
                Tabel.Columns.Add("Second (s)");
                DataValue.DataSource = Tabel;
            }catch(Exception ex){
                MessageBox.Show("[ERROR CREATE TABLE] Error has been occured");
            }

            Grafik.Series["Volt"].Color = Color.Red;
            Grafik.Series["Time"].Color = Color.Blue;
        }

        private void ConnectBtn_Click(object sender, EventArgs e)
        {
            try
            {
                if (Port == null)
                {
                    Port = new SerialPort(ListPort.SelectedItem.ToString(), 9600);
                    Port.Open();
                    MessageBox.Show("Connected!");
                    isopen = true;
                    Pewaktu.Start();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("[OPENING PORT] Error has been occured!");
            }
        }

        private void CloseBtn_Click(object sender, EventArgs e)
        {
            try
            {
                if (Port.IsOpen) Port.Close();
                MessageBox.Show("Port Closed!");
                isopen = false;
            }
            catch (Exception ex)
            {
                MessageBox.Show("[CLOSING PORT] Error has been occured!");
            }
        }

        private void Pewaktu_Tick(object sender, EventArgs e)
        {
            counter++;
            Tabel.Rows.Add(Port.ReadLine(),counter);

            string data = Port.ReadLine();
            if (Convert.ToDouble(data) > 2.5)
            {
                LEDOn.Visible = true;
                LEDOff.Visible = false;
            }
            else
            {
                LEDOn.Visible = false;
                LEDOff.Visible = true;
            }

            Grafik.Series["Volt"].Points.AddY(data);
            Grafik.Series["Time"].Points.AddY(counter);
        }
    }
}
