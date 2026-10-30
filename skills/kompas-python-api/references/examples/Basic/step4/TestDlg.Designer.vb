<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> Partial Class TestDialog
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
	Public WithEvents ShowFrame As System.Windows.Forms.PictureBox
	Public WithEvents CancelButton_Renamed As System.Windows.Forms.Button
	Public WithEvents OKButton As System.Windows.Forms.Button
	'NOTE: The following procedure is required by the Windows Form Designer
	'It can be modified using the Windows Form Designer.
	'Do not modify it using the code editor.
	<System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
    Me.components = New System.ComponentModel.Container()
    Me.ToolTip1 = New System.Windows.Forms.ToolTip(Me.components)
    Me.ShowFrame = New System.Windows.Forms.PictureBox()
    Me.CancelButton_Renamed = New System.Windows.Forms.Button()
    Me.OKButton = New System.Windows.Forms.Button()
    CType(Me.ShowFrame, System.ComponentModel.ISupportInitialize).BeginInit()
    Me.SuspendLayout()
    '
    'ShowFrame
    '
    Me.ShowFrame.BackColor = System.Drawing.SystemColors.Control
    Me.ShowFrame.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
    Me.ShowFrame.Cursor = System.Windows.Forms.Cursors.Default
    Me.ShowFrame.ForeColor = System.Drawing.SystemColors.ControlText
    Me.ShowFrame.Location = New System.Drawing.Point(8, 8)
    Me.ShowFrame.Name = "ShowFrame"
    Me.ShowFrame.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.ShowFrame.Size = New System.Drawing.Size(225, 217)
    Me.ShowFrame.TabIndex = 2
    '
    'CancelButton_Renamed
    '
    Me.CancelButton_Renamed.BackColor = System.Drawing.SystemColors.Control
    Me.CancelButton_Renamed.Cursor = System.Windows.Forms.Cursors.Default
    Me.CancelButton_Renamed.ForeColor = System.Drawing.SystemColors.ControlText
    Me.CancelButton_Renamed.Location = New System.Drawing.Point(152, 240)
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
    Me.OKButton.Location = New System.Drawing.Point(8, 240)
    Me.OKButton.Name = "OKButton"
    Me.OKButton.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.OKButton.Size = New System.Drawing.Size(81, 25)
    Me.OKButton.TabIndex = 0
    Me.OKButton.Text = "OK"
    Me.OKButton.UseVisualStyleBackColor = False
    '
    'TestDialog
    '
    Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
    Me.BackColor = System.Drawing.SystemColors.Control
    Me.ClientSize = New System.Drawing.Size(240, 277)
    Me.Controls.Add(Me.ShowFrame)
    Me.Controls.Add(Me.CancelButton_Renamed)
    Me.Controls.Add(Me.OKButton)
    Me.Cursor = System.Windows.Forms.Cursors.Default
    Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
    Me.Location = New System.Drawing.Point(184, 250)
    Me.MaximizeBox = False
    Me.MinimizeBox = False
    Me.Name = "TestDialog"
    Me.RightToLeft = System.Windows.Forms.RightToLeft.No
    Me.ShowInTaskbar = False
    Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
    CType(Me.ShowFrame, System.ComponentModel.ISupportInitialize).EndInit()
    Me.ResumeLayout(False)

  End Sub
#End Region 
End Class