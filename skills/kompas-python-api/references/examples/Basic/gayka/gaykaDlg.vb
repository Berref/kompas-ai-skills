Option Strict Off
Option Explicit On
Friend Class GaykaDlg
	Inherits System.Windows.Forms.Form
	
	Dim gayka As GaykaObj
	Public Result As Boolean
	
	Public Sub SetBufObj(ByRef buf As GaykaObj) ' буфер
		gayka = buf
	End Sub
	
  Private Sub GaykaDlg_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
    AddHandler ShowPicture.Paint, AddressOf Me.ShowPicture_Paint
  End Sub
	
	
	'UPGRADE_WARNING: Event Perform1Radio.CheckedChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub Perform1Radio_CheckedChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Perform1Radio.CheckedChanged
		If eventSender.Checked Then ' исполнение 1
			If Perform1Radio.Checked Then
				gayka.GaykaObj_perform = 0
        Invalidate()
			End If
		End If
	End Sub
	
	'UPGRADE_WARNING: Event Perform2Radio.CheckedChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub Perform2Radio_CheckedChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Perform2Radio.CheckedChanged
		If eventSender.Checked Then ' исполнение 2
			If Perform2Radio.Checked Then
				gayka.GaykaObj_perform = 1
        Invalidate()
			End If
		End If
	End Sub
	' управление контролами с параметрами штриховки ( доступны\недоступны )
	Private Sub EnableHatchParam(ByVal enable As Boolean)
		AngleEdit.Enabled = enable
		StepEdit.Enabled = enable
	End Sub
	
	'UPGRADE_WARNING: Event ViewRadio.CheckedChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub ViewRadio_CheckedChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles ViewRadio.CheckedChanged
		If eventSender.Checked Then
			Dim Index As Short = ViewRadio.GetIndex(eventSender)
			Select Case Index
				Case 0
					gayka.GaykaObj_drawType = ID_VID ' главный вид
					EnableHatchParam(False)
				Case 1
					gayka.GaykaObj_drawType = ID_SIDEVID ' вид сбоку
					EnableHatchParam(False)
				Case 2
					gayka.GaykaObj_drawType = ID_TOPVID ' вид сверху
					EnableHatchParam(False)
				Case 3
					gayka.GaykaObj_drawType = ID_VIDSEC ' главный вид \ разрез
					EnableHatchParam(True)
			End Select
			
      Invalidate()
		End If
	End Sub
	
	'UPGRADE_WARNING: Event DiamCombo.SelectedIndexChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub DiamCombo_SelectedIndexChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles DiamCombo.SelectedIndexChanged ' Изменение выделенного значения в списке Диаметров
		'UPGRADE_NOTE: val was upgraded to val_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
		Dim val_Renamed As Single
		val_Renamed = CSng(DiamCombo.Text)
		gayka.GaykaObj_dr = val_Renamed
		gayka.ReadGaykaBase(val_Renamed)
	End Sub
	
	Private Sub AngleEdit_Validating(ByVal eventSender As System.Object, ByVal eventArgs As System.ComponentModel.CancelEventArgs) Handles AngleEdit.Validating
		Dim KeepFocus As Boolean = eventArgs.Cancel ' валидатор на значение угла штриховки
		If Not IsNumeric(AngleEdit.Text) Or Val(AngleEdit.Text) < -360 Or Val(AngleEdit.Text) > 360 Then
			KeepFocus = True
			MsgBox("Введите число от -360 до 360")
		End If
		eventArgs.Cancel = KeepFocus
	End Sub
	
	'UPGRADE_WARNING: Event AngleEdit.TextChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub AngleEdit_TextChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles AngleEdit.TextChanged ' угол штриховки
		If IsNumeric(AngleEdit.Text) Then
			gayka.GaykaObj_angle = CSng(AngleEdit.Text)
		End If
	End Sub
	
	Private Sub StepEdit_Validating(ByVal eventSender As System.Object, ByVal eventArgs As System.ComponentModel.CancelEventArgs) Handles StepEdit.Validating
		Dim KeepFocus As Boolean = eventArgs.Cancel ' валидатор на значение шага штриховки
		If Not IsNumeric(StepEdit.Text) Or Val(StepEdit.Text) < 0 Or Val(StepEdit.Text) > 100 Then
			KeepFocus = True
			MsgBox("Введите число от 0 до 100")
		End If
		eventArgs.Cancel = KeepFocus
	End Sub
	
	'UPGRADE_WARNING: Event StepEdit.TextChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub StepEdit_TextChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles StepEdit.TextChanged ' шаг штриховки
		If IsNumeric(StepEdit.Text) Then
			gayka.GaykaObj_step = CSng(StepEdit.Text)
		End If
	End Sub
	
	Private Sub CancelButton_Renamed_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles CancelButton_Renamed.Click
		Result = False
		Me.Close() ' выгрузить форму
	End Sub
	
	Private Sub OKButton_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles OKButton.Click
		Result = True
		Me.Close() ' выгрузить форму
	End Sub
	
	'UPGRADE_WARNING: Event SimpleCheck.CheckStateChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub SimpleCheck_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles SimpleCheck.CheckStateChanged ' упрощенное изображение
		gayka.GaykaObj_simple = CByte(SimpleCheck.CheckState)
    Invalidate()
	End Sub
	
	'UPGRADE_WARNING: Event SpcObjCheck.CheckStateChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub SpcObjCheck_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles SpcObjCheck.CheckStateChanged ' объект спецификации
		gayka.GaykaObj_attr = CByte(SpcObjCheck.CheckState)
	End Sub
	
	'UPGRADE_WARNING: Event SmallStepCheck.CheckStateChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub SmallStepCheck_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles SmallStepCheck.CheckStateChanged ' мелкий шаг
		gayka.GaykaObj_SmallStep = CByte(SmallStepCheck.CheckState)
	End Sub
	
	'UPGRADE_WARNING: Event AddKeyCheck.CheckStateChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub AddKeyCheck_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles AddKeyCheck.CheckStateChanged ' дополнительный размер под ключ
		gayka.GaykaObj_key_s = CByte(AddKeyCheck.CheckState)
	End Sub
	
	'UPGRADE_WARNING: Event AxisCheck.CheckStateChanged may fire when form is initialized. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="88B12AE1-6DE0-48A0-86F1-60C0686C026A"'
	Private Sub AxisCheck_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles AxisCheck.CheckStateChanged ' рисовать ось
		If AxisCheck.CheckState Then
			gayka.GaykaObj_axis_off = 0
		Else
			gayka.GaykaObj_axis_off = 1
		End If
		
    Invalidate()
	End Sub
	
  Private Sub ShowPicture_Paint(ByVal eventSender As System.Object, ByVal eventArgs As System.Windows.Forms.PaintEventArgs) Handles MyBase.Paint ' отрисовка группы предварительного просмотра
    Dim gr As Integer ' референс группы
    Dim buffer As GaykaObj
    buffer = New GaykaObj
    buffer.init() ' инициализация параметров по умолчанию
    buffer.GaykaObj_drawType = gayka.GaykaObj_par.drawType
    buffer.GaykaObj_perform = gayka.GaykaObj_tmp.perform
    buffer.GaykaObj_axis_off = gayka.GaykaObj_tmp.axis_off
    buffer.GaykaObj_simple = gayka.GaykaObj_tmp.simple

    buffer.GetGroup(gr) ' собирем группу для отрисовки в окне предварительного просмотра
    'UPGRADE_NOTE: Object buffer may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    buffer = Nothing
    'UPGRADE_WARNING: Couldn't resolve default property of object iDocument2D.ksDrawKompasGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    iDocument2D.ksDrawKompasGroup(ShowPicture.Handle.ToInt32, gr) ' отрисуем созданную группу
  End Sub

  Private Sub GaykaDlg_Shown(sender As Object, e As EventArgs) Handles MyBase.Shown
 
    If gayka.GaykaObj_tmp.perform Then ' выделим исполнение
      Perform2Radio.Checked = System.Windows.Forms.CheckState.Checked ' исполнение 2
    Else
      Perform1Radio.Checked = System.Windows.Forms.CheckState.Checked ' исполнение 1
    End If

    Select Case gayka.GaykaObj_par.drawType ' выделим текущий вид
      Case ID_VID : ViewRadio(0).Checked = System.Windows.Forms.CheckState.Checked ' главный вид
      Case ID_SIDEVID : ViewRadio(1).Checked = System.Windows.Forms.CheckState.Checked ' вид сбоку
      Case ID_TOPVID : ViewRadio(2).Checked = System.Windows.Forms.CheckState.Checked ' вид сверху
      Case ID_VIDSEC : ViewRadio(3).Checked = System.Windows.Forms.CheckState.Checked ' главный вид \ разрез
    End Select

    ' заполним список диаметров
    Dim item As Object ' ksLtVariant
    'UPGRADE_WARNING: Couldn't resolve default property of object iKompasObject.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    item = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_LtVariant)
    Dim arr As Object ' ksDynamicArray
    'UPGRADE_WARNING: Couldn't resolve default property of object gayka.GaykaObj_paramTmp.GetUserArray. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    arr = gayka.GaykaObj_paramTmp.GetUserArray
    Dim i As Short
    If (Not item Is Nothing) And (Not arr Is Nothing) Then
      i = 1
      Do While i
        'UPGRADE_WARNING: Couldn't resolve default property of object gayka.GaykaObj_data.ksReadRecord. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        i = gayka.GaykaObj_data.ksReadRecord(gayka.GaykaObj_base.bg, gayka.GaykaObj_base.rg, gayka.GaykaObj_paramTmp)

        If i > 0 Then
          'UPGRADE_WARNING: Couldn't resolve default property of object arr.ksGetArrayItem. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          arr.ksGetArrayItem(0, item)
          'UPGRADE_WARNING: Couldn't resolve default property of object item.floatVal. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          DiamCombo.Items.Add(CStr(item.floatVal))
        End If
      Loop
    End If

    DiamCombo.SelectedText = CStr(gayka.GaykaObj_tmp.dr) ' выделим текущий диаметр гайки
    AngleEdit.Text = CStr(gayka.GaykaObj_tmp.hatchAng) ' угол штриховки
    StepEdit.Text = CStr(gayka.GaykaObj_tmp.hatchStep) ' шаг штриховки

    SmallStepCheck.CheckState = CByte(gayka.GaykaObj_tmp.pitch)
    SimpleCheck.CheckState = CByte(gayka.GaykaObj_tmp.simple) ' упрощенное изображение
    SpcObjCheck.CheckState = CByte(gayka.GaykaObj_par.flagAttr) ' объект спецификации
    AddKeyCheck.CheckState = CByte(gayka.GaykaObj_tmp.key_s) ' дополнительный размер под ключ
    If gayka.GaykaObj_tmp.axis_off = 0 Then
      AxisCheck.CheckState = System.Windows.Forms.CheckState.Checked
    End If
  End Sub
End Class