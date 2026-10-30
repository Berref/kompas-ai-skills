<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> Partial Class GaykaDlg
#Region "Windows Form Designer generated code "
	<System.Diagnostics.DebuggerNonUserCode()> Public Sub New()
		MyBase.New()
		'This call is required by the Windows Form Designer.
		InitializeComponent()
	End Sub
	'Form overrides dispose to clean up the component list.
	<System.Diagnostics.DebuggerNonUserCode()> Protected Overloads Overrides Sub Dispose(ByVal Disposing As Boolean)
		If Disposing Then
			If Not components Is Nothing Then
				components.Dispose()
			End If
		End If
		MyBase.Dispose(Disposing)
	End Sub
	'Required by the Windows Form Designer
	Private components As System.ComponentModel.IContainer
	Public ToolTip1 As System.Windows.Forms.ToolTip
	Public WithEvents DiamCombo As System.Windows.Forms.ComboBox
	Public WithEvents AxisCheck As System.Windows.Forms.CheckBox
	Public WithEvents SimpleCheck As System.Windows.Forms.CheckBox
	Public WithEvents AddKeyCheck As System.Windows.Forms.CheckBox
	Public WithEvents SmallStepCheck As System.Windows.Forms.CheckBox
	Public WithEvents SpcObjCheck As System.Windows.Forms.CheckBox
	Public WithEvents ShowPicture As System.Windows.Forms.PictureBox
	Public WithEvents Command1 As System.Windows.Forms.Button
	Public WithEvents StepEdit As System.Windows.Forms.TextBox
	Public WithEvents AngleEdit As System.Windows.Forms.TextBox
	Public WithEvents Label2 As System.Windows.Forms.Label
	Public WithEvents Label1 As System.Windows.Forms.Label
	Public WithEvents Frame3 As System.Windows.Forms.GroupBox
	Public WithEvents Perform2Radio As System.Windows.Forms.RadioButton
	Public WithEvents Perform1Radio As System.Windows.Forms.RadioButton
	Public WithEvents Frame2 As System.Windows.Forms.GroupBox
	Public WithEvents _ViewRadio_3 As System.Windows.Forms.RadioButton
	Public WithEvents _ViewRadio_2 As System.Windows.Forms.RadioButton
	Public WithEvents _ViewRadio_1 As System.Windows.Forms.RadioButton
	Public WithEvents _ViewRadio_0 As System.Windows.Forms.RadioButton
	Public WithEvents Frame1 As System.Windows.Forms.GroupBox
	Public WithEvents CancelButton_Renamed As System.Windows.Forms.Button
	Public WithEvents OKButton As System.Windows.Forms.Button
	Public WithEvents label As System.Windows.Forms.Label
	Public WithEvents ViewRadio As Microsoft.VisualBasic.Compatibility.VB6.RadioButtonArray
	'NOTE: The following procedure is required by the Windows Form Designer
	'It can be modified using the Windows Form Designer.
	'Do not modify it using the code editor.
	<System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
    Me.components = New System.ComponentModel.Container()
    Me.ToolTip1 = New System.Windows.Forms.ToolTip(Me.components)
    Me.DiamCombo = New System.Windows.Forms.ComboBox()
    Me.AxisCheck = New System.Windows.Forms.CheckBox()
    Me.SimpleCheck = New System.Windows.Forms.CheckBox()
    Me.AddKeyCheck = New System.Windows.Forms.CheckBox()
    Me.SmallStepCheck = New System.Windows.Forms.CheckBox()
    Me.SpcObjCheck = New System.Windows.Forms.CheckBox()
    Me.ShowPicture = New System.Windows.Forms.PictureBox()
    Me.Command1 = New System.Windows.Forms.Button()
    Me.Frame3 = New System.Windows.Forms.GroupBox()
    Me.StepEdit = New System.Windows.Forms.TextBox()
    Me.AngleEdit = New System.Windows.Forms.TextBox()
    Me.Label2 = New System.Windows.Forms.Label()
    Me.Label1 = New System.Windows.Forms.Label()
    Me.Frame2 = New System.Windows.Forms.GroupBox()
    Me.Perform2Radio = New System.Windows.Forms.RadioButton()
    Me.Perform1Radio = New System.Windows.Forms.RadioButton()
    Me.Frame1 = New System.Windows.Forms.GroupBox()
    Me._ViewRadio_3 = New System.Windows.Forms.RadioButton()
    Me._ViewRadio_2 = New System.Windows.Forms.RadioButton()
    Me._ViewRadio_1 = New System.Windows.Forms.RadioButton()
    Me._ViewRadio_0 = New System.Windows.Forms.RadioButton()
    Me.CancelButton_Renamed = New System.Windows.Forms.Button()
    Me.OKButton = New System.Windows.Forms.Button()
    Me.label = New System.Windows.Forms.Label()
    Me.ViewRadio = New Microsoft.VisualBasic.Compatibility.VB6.RadioButtonArray(Me.components)
    CType(Me.ShowPicture,System.ComponentModel.ISupportInitialize).BeginInit
    Me.Frame3.SuspendLayout
    Me.Frame2.SuspendLayout
    Me.Frame1.SuspendLayout
    CType(Me.ViewRadio,System.ComponentModel.ISupportInitialize).BeginInit
    Me.SuspendLayout
    '
    'DiamCombo
    '
    Me.DiamCombo.BackColor = System.Drawing.SystemColors.Window
    Me.DiamCombo.Cursor = System.Windows.Forms.Cursors.Default
    Me.DiamCombo.ForeColor = System.Drawing.SystemColors.WindowText
    Me.DiamCombo.Location = New System.Drawing.Point(64, 8)
    Me.DiamCombo.Name = "DiamCombo"
    Me.DiamCombo.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.DiamCombo.Size = New System.Drawing.Size(89, 21)
    Me.DiamCombo.TabIndex = 22
    '
    'AxisCheck
    '
    Me.AxisCheck.BackColor = System.Drawing.SystemColors.Control
    Me.AxisCheck.Cursor = System.Windows.Forms.Cursors.Default
    Me.AxisCheck.ForeColor = System.Drawing.SystemColors.ControlText
    Me.AxisCheck.Location = New System.Drawing.Point(214, 248)
    Me.AxisCheck.Name = "AxisCheck"
    Me.AxisCheck.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.AxisCheck.Size = New System.Drawing.Size(97, 18)
    Me.AxisCheck.TabIndex = 21
    Me.AxisCheck.Text = "Ось рисовать"
    Me.AxisCheck.UseVisualStyleBackColor = False
    '
    'SimpleCheck
    '
    Me.SimpleCheck.BackColor = System.Drawing.SystemColors.Control
    Me.SimpleCheck.Cursor = System.Windows.Forms.Cursors.Default
    Me.SimpleCheck.ForeColor = System.Drawing.SystemColors.ControlText
    Me.SimpleCheck.Location = New System.Drawing.Point(214, 224)
    Me.SimpleCheck.Name = "SimpleCheck"
    Me.SimpleCheck.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.SimpleCheck.Size = New System.Drawing.Size(89, 17)
    Me.SimpleCheck.TabIndex = 20
    Me.SimpleCheck.Text = "Упрощенно"
    Me.SimpleCheck.UseVisualStyleBackColor = False
    '
    'AddKeyCheck
    '
    Me.AddKeyCheck.BackColor = System.Drawing.SystemColors.Control
    Me.AddKeyCheck.Cursor = System.Windows.Forms.Cursors.Default
    Me.AddKeyCheck.ForeColor = System.Drawing.SystemColors.ControlText
    Me.AddKeyCheck.Location = New System.Drawing.Point(6, 272)
    Me.AddKeyCheck.Name = "AddKeyCheck"
    Me.AddKeyCheck.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.AddKeyCheck.Size = New System.Drawing.Size(225, 17)
    Me.AddKeyCheck.TabIndex = 19
    Me.AddKeyCheck.Text = "Дополнительный размер под ключ"
    Me.AddKeyCheck.UseVisualStyleBackColor = False
    '
    'SmallStepCheck
    '
    Me.SmallStepCheck.BackColor = System.Drawing.SystemColors.Control
    Me.SmallStepCheck.Cursor = System.Windows.Forms.Cursors.Default
    Me.SmallStepCheck.ForeColor = System.Drawing.SystemColors.ControlText
    Me.SmallStepCheck.Location = New System.Drawing.Point(6, 248)
    Me.SmallStepCheck.Name = "SmallStepCheck"
    Me.SmallStepCheck.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.SmallStepCheck.Size = New System.Drawing.Size(89, 17)
    Me.SmallStepCheck.TabIndex = 18
    Me.SmallStepCheck.Text = "Мелкий шаг"
    Me.SmallStepCheck.UseVisualStyleBackColor = False
    '
    'SpcObjCheck
    '
    Me.SpcObjCheck.BackColor = System.Drawing.SystemColors.Control
    Me.SpcObjCheck.Cursor = System.Windows.Forms.Cursors.Default
    Me.SpcObjCheck.ForeColor = System.Drawing.SystemColors.ControlText
    Me.SpcObjCheck.Location = New System.Drawing.Point(6, 224)
    Me.SpcObjCheck.Name = "SpcObjCheck"
    Me.SpcObjCheck.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.SpcObjCheck.Size = New System.Drawing.Size(193, 21)
    Me.SpcObjCheck.TabIndex = 17
    Me.SpcObjCheck.Text = "Создать объект спецификации"
    Me.SpcObjCheck.UseVisualStyleBackColor = False
    '
    'ShowPicture
    '
    Me.ShowPicture.BackColor = System.Drawing.SystemColors.Control
    Me.ShowPicture.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
    Me.ShowPicture.Cursor = System.Windows.Forms.Cursors.Default
    Me.ShowPicture.ForeColor = System.Drawing.SystemColors.ControlText
    Me.ShowPicture.Location = New System.Drawing.Point(160, 8)
    Me.ShowPicture.Name = "ShowPicture"
    Me.ShowPicture.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.ShowPicture.Size = New System.Drawing.Size(153, 121)
    Me.ShowPicture.TabIndex = 16
    Me.ShowPicture.TabStop = False
    '
    'Command1
    '
    Me.Command1.BackColor = System.Drawing.SystemColors.Control
    Me.Command1.Cursor = System.Windows.Forms.Cursors.Default
    Me.Command1.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Command1.Location = New System.Drawing.Point(222, 295)
    Me.Command1.Name = "Command1"
    Me.Command1.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Command1.Size = New System.Drawing.Size(81, 25)
    Me.Command1.TabIndex = 15
    Me.Command1.Text = "Справка"
    Me.Command1.UseVisualStyleBackColor = False
    '
    'Frame3
    '
    Me.Frame3.BackColor = System.Drawing.SystemColors.Control
    Me.Frame3.Controls.Add(Me.StepEdit)
    Me.Frame3.Controls.Add(Me.AngleEdit)
    Me.Frame3.Controls.Add(Me.Label2)
    Me.Frame3.Controls.Add(Me.Label1)
    Me.Frame3.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Frame3.Location = New System.Drawing.Point(160, 135)
    Me.Frame3.Name = "Frame3"
    Me.Frame3.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Frame3.Size = New System.Drawing.Size(153, 81)
    Me.Frame3.TabIndex = 10
    Me.Frame3.TabStop = False
    Me.Frame3.Text = "Параметры штриховки"
    '
    'StepEdit
    '
    Me.StepEdit.AcceptsReturn = True
    Me.StepEdit.BackColor = System.Drawing.SystemColors.Window
    Me.StepEdit.Cursor = System.Windows.Forms.Cursors.IBeam
    Me.StepEdit.ForeColor = System.Drawing.SystemColors.WindowText
    Me.StepEdit.Location = New System.Drawing.Point(80, 45)
    Me.StepEdit.MaxLength = 0
    Me.StepEdit.Name = "StepEdit"
    Me.StepEdit.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.StepEdit.Size = New System.Drawing.Size(49, 20)
    Me.StepEdit.TabIndex = 13
    '
    'AngleEdit
    '
    Me.AngleEdit.AcceptsReturn = True
    Me.AngleEdit.BackColor = System.Drawing.SystemColors.Window
    Me.AngleEdit.Cursor = System.Windows.Forms.Cursors.IBeam
    Me.AngleEdit.ForeColor = System.Drawing.SystemColors.WindowText
    Me.AngleEdit.Location = New System.Drawing.Point(80, 16)
    Me.AngleEdit.MaxLength = 0
    Me.AngleEdit.Name = "AngleEdit"
    Me.AngleEdit.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.AngleEdit.Size = New System.Drawing.Size(49, 20)
    Me.AngleEdit.TabIndex = 12
    '
    'Label2
    '
    Me.Label2.AutoSize = True
    Me.Label2.BackColor = System.Drawing.SystemColors.Control
    Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
    Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Label2.Location = New System.Drawing.Point(16, 48)
    Me.Label2.Name = "Label2"
    Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Label2.Size = New System.Drawing.Size(49, 13)
    Me.Label2.TabIndex = 14
    Me.Label2.Text = "Шаг, мм"
    '
    'Label1
    '
    Me.Label1.AutoSize = True
    Me.Label1.BackColor = System.Drawing.SystemColors.Control
    Me.Label1.Cursor = System.Windows.Forms.Cursors.Default
    Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Label1.Location = New System.Drawing.Point(16, 19)
    Me.Label1.Name = "Label1"
    Me.Label1.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Label1.Size = New System.Drawing.Size(61, 13)
    Me.Label1.TabIndex = 11
    Me.Label1.Text = "Угол, град"
    '
    'Frame2
    '
    Me.Frame2.BackColor = System.Drawing.SystemColors.Control
    Me.Frame2.Controls.Add(Me.Perform2Radio)
    Me.Frame2.Controls.Add(Me.Perform1Radio)
    Me.Frame2.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Frame2.Location = New System.Drawing.Point(8, 135)
    Me.Frame2.Name = "Frame2"
    Me.Frame2.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Frame2.Size = New System.Drawing.Size(145, 81)
    Me.Frame2.TabIndex = 7
    Me.Frame2.TabStop = False
    '
    'Perform2Radio
    '
    Me.Perform2Radio.BackColor = System.Drawing.SystemColors.Control
    Me.Perform2Radio.Cursor = System.Windows.Forms.Cursors.Default
    Me.Perform2Radio.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Perform2Radio.Location = New System.Drawing.Point(8, 48)
    Me.Perform2Radio.Name = "Perform2Radio"
    Me.Perform2Radio.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Perform2Radio.Size = New System.Drawing.Size(97, 17)
    Me.Perform2Radio.TabIndex = 9
    Me.Perform2Radio.TabStop = True
    Me.Perform2Radio.Text = "Исполнение 2"
    Me.Perform2Radio.UseVisualStyleBackColor = False
    '
    'Perform1Radio
    '
    Me.Perform1Radio.BackColor = System.Drawing.SystemColors.Control
    Me.Perform1Radio.Cursor = System.Windows.Forms.Cursors.Default
    Me.Perform1Radio.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Perform1Radio.Location = New System.Drawing.Point(8, 24)
    Me.Perform1Radio.Name = "Perform1Radio"
    Me.Perform1Radio.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Perform1Radio.Size = New System.Drawing.Size(97, 18)
    Me.Perform1Radio.TabIndex = 8
    Me.Perform1Radio.TabStop = True
    Me.Perform1Radio.Text = "Исполнение 1"
    Me.Perform1Radio.UseVisualStyleBackColor = False
    '
    'Frame1
    '
    Me.Frame1.BackColor = System.Drawing.SystemColors.Control
    Me.Frame1.Controls.Add(Me._ViewRadio_3)
    Me.Frame1.Controls.Add(Me._ViewRadio_2)
    Me.Frame1.Controls.Add(Me._ViewRadio_1)
    Me.Frame1.Controls.Add(Me._ViewRadio_0)
    Me.Frame1.ForeColor = System.Drawing.SystemColors.ControlText
    Me.Frame1.Location = New System.Drawing.Point(8, 32)
    Me.Frame1.Name = "Frame1"
    Me.Frame1.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.Frame1.Size = New System.Drawing.Size(145, 97)
    Me.Frame1.TabIndex = 2
    Me.Frame1.TabStop = False
    '
    '_ViewRadio_3
    '
    Me._ViewRadio_3.BackColor = System.Drawing.SystemColors.Control
    Me._ViewRadio_3.Cursor = System.Windows.Forms.Cursors.Default
    Me._ViewRadio_3.ForeColor = System.Drawing.SystemColors.ControlText
    Me.ViewRadio.SetIndex(Me._ViewRadio_3, CType(3, Short))
    Me._ViewRadio_3.Location = New System.Drawing.Point(8, 72)
    Me._ViewRadio_3.Name = "_ViewRadio_3"
    Me._ViewRadio_3.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me._ViewRadio_3.Size = New System.Drawing.Size(80, 19)
    Me._ViewRadio_3.TabIndex = 6
    Me._ViewRadio_3.TabStop = True
    Me._ViewRadio_3.Text = "Вид/разрез"
    Me._ViewRadio_3.UseVisualStyleBackColor = False
    '
    '_ViewRadio_2
    '
    Me._ViewRadio_2.BackColor = System.Drawing.SystemColors.Control
    Me._ViewRadio_2.Cursor = System.Windows.Forms.Cursors.Default
    Me._ViewRadio_2.ForeColor = System.Drawing.SystemColors.ControlText
    Me.ViewRadio.SetIndex(Me._ViewRadio_2, CType(2, Short))
    Me._ViewRadio_2.Location = New System.Drawing.Point(8, 54)
    Me._ViewRadio_2.Name = "_ViewRadio_2"
    Me._ViewRadio_2.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me._ViewRadio_2.Size = New System.Drawing.Size(80, 18)
    Me._ViewRadio_2.TabIndex = 5
    Me._ViewRadio_2.TabStop = True
    Me._ViewRadio_2.Text = "Вид сверху"
    Me._ViewRadio_2.UseVisualStyleBackColor = False
    '
    '_ViewRadio_1
    '
    Me._ViewRadio_1.BackColor = System.Drawing.SystemColors.Control
    Me._ViewRadio_1.Cursor = System.Windows.Forms.Cursors.Default
    Me._ViewRadio_1.ForeColor = System.Drawing.SystemColors.ControlText
    Me.ViewRadio.SetIndex(Me._ViewRadio_1, CType(1, Short))
    Me._ViewRadio_1.Location = New System.Drawing.Point(8, 35)
    Me._ViewRadio_1.Name = "_ViewRadio_1"
    Me._ViewRadio_1.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me._ViewRadio_1.Size = New System.Drawing.Size(80, 18)
    Me._ViewRadio_1.TabIndex = 4
    Me._ViewRadio_1.TabStop = True
    Me._ViewRadio_1.Text = "Вид сбоку"
    Me._ViewRadio_1.UseVisualStyleBackColor = False
    '
    '_ViewRadio_0
    '
    Me._ViewRadio_0.BackColor = System.Drawing.SystemColors.Control
    Me._ViewRadio_0.Cursor = System.Windows.Forms.Cursors.Default
    Me._ViewRadio_0.ForeColor = System.Drawing.SystemColors.ControlText
    Me.ViewRadio.SetIndex(Me._ViewRadio_0, CType(0, Short))
    Me._ViewRadio_0.Location = New System.Drawing.Point(8, 16)
    Me._ViewRadio_0.Name = "_ViewRadio_0"
    Me._ViewRadio_0.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me._ViewRadio_0.Size = New System.Drawing.Size(80, 22)
    Me._ViewRadio_0.TabIndex = 3
    Me._ViewRadio_0.TabStop = True
    Me._ViewRadio_0.Text = "Вид"
    Me._ViewRadio_0.UseVisualStyleBackColor = False
    '
    'CancelButton_Renamed
    '
    Me.CancelButton_Renamed.BackColor = System.Drawing.SystemColors.Control
    Me.CancelButton_Renamed.Cursor = System.Windows.Forms.Cursors.Default
    Me.CancelButton_Renamed.DialogResult = System.Windows.Forms.DialogResult.Cancel
    Me.CancelButton_Renamed.ForeColor = System.Drawing.SystemColors.ControlText
    Me.CancelButton_Renamed.Location = New System.Drawing.Point(126, 295)
    Me.CancelButton_Renamed.Name = "CancelButton_Renamed"
    Me.CancelButton_Renamed.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.CancelButton_Renamed.Size = New System.Drawing.Size(81, 25)
    Me.CancelButton_Renamed.TabIndex = 1
    Me.CancelButton_Renamed.Text = "Отмена"
    Me.CancelButton_Renamed.UseVisualStyleBackColor = False
    '
    'OKButton
    '
    Me.OKButton.BackColor = System.Drawing.SystemColors.Control
    Me.OKButton.Cursor = System.Windows.Forms.Cursors.Default
    Me.OKButton.ForeColor = System.Drawing.SystemColors.ControlText
    Me.OKButton.Location = New System.Drawing.Point(30, 295)
    Me.OKButton.Name = "OKButton"
    Me.OKButton.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.OKButton.Size = New System.Drawing.Size(81, 25)
    Me.OKButton.TabIndex = 0
    Me.OKButton.Text = "ОК"
    Me.OKButton.UseVisualStyleBackColor = False
    '
    'label
    '
    Me.label.BackColor = System.Drawing.SystemColors.Control
    Me.label.Cursor = System.Windows.Forms.Cursors.Default
    Me.label.ForeColor = System.Drawing.SystemColors.ControlText
    Me.label.Location = New System.Drawing.Point(8, 10)
    Me.label.Name = "label"
    Me.label.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.label.Size = New System.Drawing.Size(49, 17)
    Me.label.TabIndex = 23
    Me.label.Text = "Диаметр"
    '
    'ViewRadio
    '
    '
    'GaykaDlg
    '
    Me.AcceptButton = Me.OKButton
    Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
    Me.BackColor = System.Drawing.SystemColors.Control
    Me.CancelButton = Me.CancelButton_Renamed
    Me.ClientSize = New System.Drawing.Size(323, 327)
    Me.Controls.Add(Me.DiamCombo)
    Me.Controls.Add(Me.AxisCheck)
    Me.Controls.Add(Me.SimpleCheck)
    Me.Controls.Add(Me.AddKeyCheck)
    Me.Controls.Add(Me.SmallStepCheck)
    Me.Controls.Add(Me.SpcObjCheck)
    Me.Controls.Add(Me.ShowPicture)
    Me.Controls.Add(Me.Command1)
    Me.Controls.Add(Me.Frame3)
    Me.Controls.Add(Me.Frame2)
    Me.Controls.Add(Me.Frame1)
    Me.Controls.Add(Me.CancelButton_Renamed)
    Me.Controls.Add(Me.OKButton)
    Me.Controls.Add(Me.label)
    Me.Cursor = System.Windows.Forms.Cursors.Default
    Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
    Me.Location = New System.Drawing.Point(184, 251)
    Me.MaximizeBox = false
    Me.MinimizeBox = false
    Me.Name = "GaykaDlg"
    Me.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.ShowInTaskbar = false
    Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
    Me.Text = "Гайка ГОСТ 5915-70"
    CType(Me.ShowPicture,System.ComponentModel.ISupportInitialize).EndInit
    Me.Frame3.ResumeLayout(false)
    Me.Frame3.PerformLayout
    Me.Frame2.ResumeLayout(false)
    Me.Frame1.ResumeLayout(false)
    CType(Me.ViewRadio,System.ComponentModel.ISupportInitialize).EndInit
    Me.ResumeLayout(false)

End Sub
#End Region 
End Class