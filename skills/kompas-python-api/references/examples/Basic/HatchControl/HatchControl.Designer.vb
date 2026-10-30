<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> Partial Class HatchControl
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
	Friend WithEvents StepEdit As System.Windows.Forms.TextBox
	Friend WithEvents AngleEdit As System.Windows.Forms.TextBox
	Friend WithEvents Label2 As System.Windows.Forms.Label
	Friend WithEvents Label1 As System.Windows.Forms.Label
	'NOTE: The following procedure is required by the Windows Form Designer
	'It can be modified using the Windows Form Designer.
	'Do not modify it using the code editor.
	<System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
		Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(HatchControl))
		Me.components = New System.ComponentModel.Container()
		Me.ToolTip1 = New System.Windows.Forms.ToolTip(components)
		Me.StepEdit = New System.Windows.Forms.TextBox
		Me.AngleEdit = New System.Windows.Forms.TextBox
		Me.Label2 = New System.Windows.Forms.Label
		Me.Label1 = New System.Windows.Forms.Label
		Me.SuspendLayout()
		Me.ToolTip1.Active = True
		MyBase.BackColor = System.Drawing.SystemColors.ActiveBorder
		Me.ClientSize = New System.Drawing.Size(180, 135)
		MyBase.Location = New System.Drawing.Point(0, 0)
		MyBase.Name = "HatchControl"
		Me.StepEdit.AutoSize = False
		Me.StepEdit.Size = New System.Drawing.Size(161, 25)
		Me.StepEdit.Location = New System.Drawing.Point(8, 96)
		Me.StepEdit.TabIndex = 3
		Me.StepEdit.Text = "Text1"
		Me.StepEdit.AcceptsReturn = True
		Me.StepEdit.TextAlign = System.Windows.Forms.HorizontalAlignment.Left
		Me.StepEdit.BackColor = System.Drawing.SystemColors.Window
		Me.StepEdit.CausesValidation = True
		Me.StepEdit.Enabled = True
		Me.StepEdit.ForeColor = System.Drawing.SystemColors.WindowText
		Me.StepEdit.HideSelection = True
		Me.StepEdit.ReadOnly = False
		Me.StepEdit.Maxlength = 0
		Me.StepEdit.Cursor = System.Windows.Forms.Cursors.IBeam
		Me.StepEdit.MultiLine = False
		Me.StepEdit.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.StepEdit.ScrollBars = System.Windows.Forms.ScrollBars.None
		Me.StepEdit.TabStop = True
		Me.StepEdit.Visible = True
		Me.StepEdit.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
		Me.StepEdit.Name = "StepEdit"
		Me.AngleEdit.AutoSize = False
		Me.AngleEdit.Size = New System.Drawing.Size(161, 25)
		Me.AngleEdit.Location = New System.Drawing.Point(8, 32)
		Me.AngleEdit.TabIndex = 1
		Me.AngleEdit.Text = "Text1"
		Me.AngleEdit.AcceptsReturn = True
		Me.AngleEdit.TextAlign = System.Windows.Forms.HorizontalAlignment.Left
		Me.AngleEdit.BackColor = System.Drawing.SystemColors.Window
		Me.AngleEdit.CausesValidation = True
		Me.AngleEdit.Enabled = True
		Me.AngleEdit.ForeColor = System.Drawing.SystemColors.WindowText
		Me.AngleEdit.HideSelection = True
		Me.AngleEdit.ReadOnly = False
		Me.AngleEdit.Maxlength = 0
		Me.AngleEdit.Cursor = System.Windows.Forms.Cursors.IBeam
		Me.AngleEdit.MultiLine = False
		Me.AngleEdit.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.AngleEdit.ScrollBars = System.Windows.Forms.ScrollBars.None
		Me.AngleEdit.TabStop = True
		Me.AngleEdit.Visible = True
		Me.AngleEdit.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
		Me.AngleEdit.Name = "AngleEdit"
		Me.Label2.BackColor = System.Drawing.SystemColors.ActiveBorder
		Me.Label2.Text = "Ўаг штриховки"
		Me.Label2.Size = New System.Drawing.Size(161, 17)
		Me.Label2.Location = New System.Drawing.Point(8, 72)
		Me.Label2.TabIndex = 2
		Me.Label2.TextAlign = System.Drawing.ContentAlignment.TopLeft
		Me.Label2.Enabled = True
		Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
		Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
		Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.Label2.UseMnemonic = True
		Me.Label2.Visible = True
		Me.Label2.AutoSize = False
		Me.Label2.BorderStyle = System.Windows.Forms.BorderStyle.None
		Me.Label2.Name = "Label2"
		Me.Label1.BackColor = System.Drawing.SystemColors.ActiveBorder
		Me.Label1.Text = "”гол штриховки"
		Me.Label1.Size = New System.Drawing.Size(161, 17)
		Me.Label1.Location = New System.Drawing.Point(8, 8)
		Me.Label1.TabIndex = 0
		Me.Label1.TextAlign = System.Drawing.ContentAlignment.TopLeft
		Me.Label1.Enabled = True
		Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
		Me.Label1.Cursor = System.Windows.Forms.Cursors.Default
		Me.Label1.RightToLeft = System.Windows.Forms.RightToLeft.No
		Me.Label1.UseMnemonic = True
		Me.Label1.Visible = True
		Me.Label1.AutoSize = False
		Me.Label1.BorderStyle = System.Windows.Forms.BorderStyle.None
		Me.Label1.Name = "Label1"
		Me.Controls.Add(StepEdit)
		Me.Controls.Add(AngleEdit)
		Me.Controls.Add(Label2)
		Me.Controls.Add(Label1)
		Me.ResumeLayout(False)
		Me.PerformLayout()
	End Sub
#End Region 
End Class