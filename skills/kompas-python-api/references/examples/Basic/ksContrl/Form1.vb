Option Strict Off
Option Explicit On
Friend Class Form1
	Inherits System.Windows.Forms.Form
	
	Dim Kompas As Object
	Dim documentId As Integer ' HANDLE документа запущенного на редактиролвание
	Dim libraryId As Integer ' HANDLE загруженной библиотеки
	
	Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
		If Kompas Is Nothing Then
			' запустить График и создать соответствующий ему объект
			Kompas = CreateObject("KOMPAS.Application.5")
			If Not Kompas Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Visible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				Kompas.Visible = True
			End If
			' передать Графику указатель на IDispatch, по которому График вызывает уведомления об изенении своего состояния
		End If
	End Sub
	
	'Выполнить некоторый код
	Private Sub Command11_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command11.Click
		Dim ksDocument2D As Object
		If Not Kompas Is Nothing Then
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ActiveDocument2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			ksDocument2D = Kompas.ActiveDocument2D
			If Not ksDocument2D Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object ksDocument2D.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				ksDocument2D.ksCircle(50, 50, 20, 1)
				'UPGRADE_WARNING: Couldn't resolve default property of object ksDocument2D.ksCircle. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				ksDocument2D.ksCircle(50, 50, 50, 2)
			End If
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksMessage. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			Kompas.ksMessage("Привет")
		End If
	End Sub
	
	Private Sub Command12_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command12.Click
		If Not Kompas Is Nothing Then
			' принудительно закрыть График
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Quit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			Kompas.Quit()
			'UPGRADE_NOTE: Object Kompas may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			Kompas = Nothing
		End If
	End Sub
	
	Private Sub Command13_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command13.Click
		If Kompas Is Nothing Then
			' запустить График и создать соответствующий ему объект
			Kompas = GetObject( , "KOMPAS.Application.5")
			If Not Kompas Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Visible. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				Kompas.Visible = True
				'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ActivateControllerAPI. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				Kompas.ActivateControllerAPI()
			End If
		End If
	End Sub
	
	Private Sub Command2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command2.Click
		If Not Kompas Is Nothing Then
			' принудительно закрыть График
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Quit. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			Kompas.Quit()
			'UPGRADE_NOTE: Object Kompas may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			Kompas = Nothing
		End If
		End ' завершить работу
	End Sub
	
	Private Sub Command3_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command3.Click
		If Not Kompas Is Nothing Then
			' Отцепиться от Графика, больше уведомления об изменении
			' своего состояния График присылать не будет
			'UPGRADE_NOTE: Object Kompas may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			Kompas = Nothing
		End If
		End ' завершить работу
	End Sub
	
	Private Sub Command4_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command4.Click
		Dim docType As Short
		Dim ksDocument3D As Object
		Dim ksDocument2D As Object
		Dim ksSpcDocument As Object
		Dim ksDocumentTxt As Object
		'UPGRADE_NOTE: err was upgraded to err_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
		Dim err_Renamed As Short
		If Not Kompas Is Nothing Then
			'UPGRADE_WARNING: CommonDialog variable was not upgraded Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="671167DC-EA81-475D-B690-7A40C7BF4A23"'
      With CommonDialog1Open
        .Title = "Open file name"
        'UPGRADE_WARNING: Filter has a new behavior. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="9B7D5ADD-D8FE-4819-A36C-6DEDAF088CC7"'
        .Filter = "(*.frw)|*.frw|(*.cdw)|*.cdw|(*.m3d)|*.m3d|(*.a3d)|*.a3d"
        .InitialDirectory = CurDir()
        .FileName = ""
        'UPGRADE_ISSUE: Constant cdlOFNExplorer was not upgraded. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="55B59875-9A95-4B71-9D6A-7C294BF7139D"'
        'UPGRADE_ISSUE: MSComDlg.CommonDialog property CommonDialog1.Flags was not upgraded. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="CC4C7EC0-C903-48FC-ACCC-81861D12DA4A"'
        ' CommonDialog1Open.Flags = MSComDlg.FileOpenConstants.cdlOFNExplorer
        'UPGRADE_WARNING: MSComDlg.CommonDialog property CommonDialog1.Flags was upgraded to CommonDialog1Open.CheckFileExists which has a new behavior. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="DFCDE711-9694-47D7-9C50-45A99CD8E91E"'
        .CheckFileExists = True
        .CheckPathExists = True
        .ShowDialog()
        If .FileName <> "" Then
          ' Открыть документ с диска
          ' первый параметр - имя открываемого файла
          ' второй параметр указывает на необходимость выдачи запроса "Файл изменен. Сохранять?" при закрытии файла
          ' третий параметр - указатель на IDispatch, по которому Графие вызывает уведомления об изенении своего состояния
          ' ф-ия возвращает HANDLE открытого документа
          ' documentId = Kompas.OpenAutoDocument(.FileName, True, Me)
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksGetDocumentTypeByName. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          docType = Kompas.ksGetDocumentTypeByName(.FileName)
          Select Case docType
            Case lt_DocPart3D, lt_DocAssemble3D
              'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Document3D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksDocument3D = Kompas.Document3D
              'UPGRADE_WARNING: Couldn't resolve default property of object ksDocument3D.Open. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksDocument3D.Open(.FileName, 0)
            Case lt_DocSheetStandart, lt_DocFragment
              'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Document2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksDocument2D = Kompas.Document2D
              'UPGRADE_WARNING: Couldn't resolve default property of object ksDocument2D.ksOpenDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksDocument2D.ksOpenDocument(.FileName, False)
            Case lt_DocSpc, lt_DocSpcUser
              'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.SpcDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksSpcDocument = Kompas.SpcDocument
              'UPGRADE_WARNING: Couldn't resolve default property of object ksSpcDocument.ksOpenDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksSpcDocument.ksOpenDocument(.FileName, False)
            Case lt_DocTxtStandart
              'UPGRADE_WARNING: Couldn't resolve default property of object ksDocumentTxt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.DocumentTxt. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksDocumentTxt = Kompas.DocumentTxt
              'UPGRADE_WARNING: Couldn't resolve default property of object ksDocumentTxt.ksOpenDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
              ksDocumentTxt.ksOpenDocument(.FileName, False)
          End Select
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksReturnResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          err_Renamed = Kompas.ksReturnResult
          If err_Renamed Then
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.MassageBoxResult. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.MassageBoxResult()
            'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ResultNULL. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
            Kompas.ResultNULL()
          End If
        End If
      End With
		End If
	End Sub
	
	Private Sub Command5_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command5.Click
		Dim ksDocument2D As Object
		Dim ksDocumentParam As Object
		If Not Kompas Is Nothing Then
			' создать новый документ
			' первый параметр - тип открываемого файла
			'   0 - лист чертежа
			'   1 - фрагмент
			'   2 - текстовый документ
			'   3 - спецификация
			'   4 - 3D-модель
			' второй параметр указывает на необходимость выдачи запроса "Файл изменен. Сохранять?" при закрытии файла
			' третий параметр - указатель на IDispatch, по которому Графие вызывает уведомления об изенении своего состояния
			' ф-ия возвращает HANDLE открытого документа
			' documentId = Kompas.NewAutoDocument(0, True, Me)
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.Document2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			ksDocument2D = Kompas.Document2D
			If Not ksDocument2D Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.GetParamStruct. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				ksDocumentParam = Kompas.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_DocumentParam)
				If Not ksDocumentParam Is Nothing Then
					'UPGRADE_WARNING: Couldn't resolve default property of object ksDocumentParam.Init. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					ksDocumentParam.Init()
					'UPGRADE_WARNING: Couldn't resolve default property of object ksDocumentParam.Type. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					ksDocumentParam.Type = lt_DocSheetStandart
					'UPGRADE_WARNING: Couldn't resolve default property of object ksDocument2D.ksCreateDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
					ksDocument2D.ksCreateDocument(ksDocumentParam)
				End If
			End If
		End If
	End Sub
	
	Private Sub Command6_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command6.Click
		Dim ksDocument2D As Object
		If Not Kompas Is Nothing Then
			' сохранить документ, открытый на редактирование
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ActiveDocument2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			ksDocument2D = Kompas.ActiveDocument2D
			If Not ksDocument2D Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object ksDocument2D.ksSaveDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				ksDocument2D.ksSaveDocument("")
			End If
		End If
	End Sub
	
	Private Sub Command7_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command7.Click
		Dim ksDocument2D As Object
		If Not Kompas Is Nothing Then
			' закрыть документ, открытый на редактирование
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ActiveDocument2D. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			ksDocument2D = Kompas.ActiveDocument2D
			If Not ksDocument2D Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object ksDocument2D.ksCloseDocument. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				ksDocument2D.ksCloseDocument()
			End If
		End If
	End Sub
	
	Private Sub Command8_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command8.Click
		If Not Kompas Is Nothing Then
			'UPGRADE_WARNING: CommonDialog variable was not upgraded Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="671167DC-EA81-475D-B690-7A40C7BF4A23"'
      With CommonDialog1Open
        .Title = "Open library name"
        'UPGRADE_WARNING: Filter has a new behavior. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="9B7D5ADD-D8FE-4819-A36C-6DEDAF088CC7"'
        .Filter = "(*.rtw)|*.rtw"
        .InitialDirectory = CurDir()
        .FileName = ""
        'UPGRADE_ISSUE: Constant cdlOFNExplorer was not upgraded. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="55B59875-9A95-4B71-9D6A-7C294BF7139D"'
        'UPGRADE_ISSUE: MSComDlg.CommonDialog property CommonDialog1.Flags was not upgraded. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="CC4C7EC0-C903-48FC-ACCC-81861D12DA4A"'
        '.Flags = MSComDlg.FileOpenConstants.cdlOFNExplorer
        'UPGRADE_WARNING: MSComDlg.CommonDialog property CommonDialog1.Flags was upgraded to CommonDialog1Open.CheckFileExists which has a new behavior. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="DFCDE711-9694-47D7-9C50-45A99CD8E91E"'
        .CheckFileExists = True
        .CheckPathExists = True
        .ShowDialog()
        If .FileName <> "" Then
          ' загрузить библиотеку
          ' ф-ия возвращает HANDLE загруженной библиотеки
          'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksAttachKompasLibrary. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
          libraryId = Kompas.ksAttachKompasLibrary(.FileName)
        End If
      End With
		End If
	End Sub
	
	Private Sub Command9_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command9.Click
		If Not Kompas Is Nothing Then
			' выгрузить библиотеку
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksDetachKompasLibrary. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			Kompas.ksDetachKompasLibrary(libraryId)
		End If
	End Sub
	
	Private Sub Command10_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command10.Click
		If Not Kompas Is Nothing Then
			' выполнить команду у загруженной библиотеки
			' первй параметр - HANDLE библиотеки
			' второй параметр - идентификатор выполняемой команды
			'UPGRADE_WARNING: Couldn't resolve default property of object Kompas.ksExecuteKompasLibraryCommand. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			Kompas.ksExecuteKompasLibraryCommand(libraryId, 1)
		End If
	End Sub

  Private Sub Command14_Click(sender As Object, e As EventArgs) Handles Command14.Click
    If Not Kompas Is Nothing Then
      Kompas.Visible = Not Kompas.Visible
    End If
  End Sub
End Class