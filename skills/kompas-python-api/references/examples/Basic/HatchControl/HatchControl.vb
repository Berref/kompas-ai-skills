Option Strict Off
Option Explicit On
<System.Runtime.InteropServices.ProgId("HatchControl_NET.HatchControl")> Public Class HatchControl
	Inherits System.Windows.Forms.UserControl
	
	Public Event AngleChange(ByVal Sender As System.Object, ByVal e As System.EventArgs)
	
	Public Event StepChange(ByVal Sender As System.Object, ByVal e As System.EventArgs)
	
	
	Public Property AngleEditValue() As Object
		Get
			'UPGRADE_WARNING: Couldn't resolve default property of object AngleEditValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			AngleEditValue = AngleEdit.Text
		End Get
		Set(ByVal Value As Object)
			'UPGRADE_WARNING: Couldn't resolve default property of object vNewValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			AngleEdit.Text = Value
		End Set
	End Property
	
	
	Public Property StepEditValue() As Object
		Get
			'UPGRADE_WARNING: Couldn't resolve default property of object StepEditValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			StepEditValue = StepEdit.Text
		End Get
		Set(ByVal Value As Object)
			'UPGRADE_WARNING: Couldn't resolve default property of object vNewValue. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			StepEdit.Text = Value
		End Set
	End Property
	
	'UPGRADE_WARNING: Event AngleEdit.TextChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub AngleEdit_TextChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles AngleEdit.TextChanged
		RaiseEvent AngleChange(Me, Nothing)
	End Sub
	
	'UPGRADE_WARNING: Event StepEdit.TextChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub StepEdit_TextChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles StepEdit.TextChanged
		RaiseEvent StepChange(Me, Nothing)
	End Sub
End Class