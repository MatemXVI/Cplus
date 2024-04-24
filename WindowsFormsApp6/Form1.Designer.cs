namespace WindowsFormsApp6
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.number1_numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.result_numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.number1_numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.result_numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.button1.Location = new System.Drawing.Point(284, 175);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(62, 39);
            this.button1.TabIndex = 0;
            this.button1.Text = "OK";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.okbutton1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Liczba 1";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // number1_numericUpDown1
            // 
            this.number1_numericUpDown1.Location = new System.Drawing.Point(65, 33);
            this.number1_numericUpDown1.Name = "number1_numericUpDown1";
            this.number1_numericUpDown1.Size = new System.Drawing.Size(120, 20);
            this.number1_numericUpDown1.TabIndex = 3;
            this.number1_numericUpDown1.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // result_numericUpDown1
            // 
            this.result_numericUpDown1.Location = new System.Drawing.Point(65, 69);
            this.result_numericUpDown1.Name = "result_numericUpDown1";
            this.result_numericUpDown1.Size = new System.Drawing.Size(120, 20);
            this.result_numericUpDown1.TabIndex = 4;
            this.result_numericUpDown1.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.result_numericUpDown1.ValueChanged += new System.EventHandler(this.result_numericUpDown1_ValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(606, 403);
            this.Controls.Add(this.result_numericUpDown1);
            this.Controls.Add(this.number1_numericUpDown1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.number1_numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.result_numericUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown number1_numericUpDown1;
        private System.Windows.Forms.NumericUpDown result_numericUpDown1;
    }
}

