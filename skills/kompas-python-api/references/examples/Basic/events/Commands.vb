Option Strict Off
Option Explicit On
Friend Class Commands
	
	'    Case lt_DocSheetStandart, lt_DocSheetUser, lt_DocFragment
	'      Set iObject2DNotify = iDoc2D.GetObject2DNotify(0)
	'      Set iSelMng2D = iDoc2D.GetSelectionMngNotify
	'    Case lt_DocPart3D, lt_DocAssemble3D
	'      Set iSelMng3D = iDoc3D.GetSelectionMng
	
	Public WithEvents iKompasObject As Kompas6API5.Application
	Public WithEvents iDoc2D As Kompas6API5.Document2D
	Public WithEvents iDoc3D As Kompas6API5.Document3D
	Public WithEvents iDocSpc As Kompas6API5.SpcDocument
	Public WithEvents iDocTxt As Kompas6API5.DocumentTxt
	Public WithEvents iObject2DNotify As Kompas6API5.Object2DNotify
	Public WithEvents iStamp As Kompas6API5.Stamp
	Public WithEvents iSelMng2D As Kompas6API5.SelectionMngNotify
	Public WithEvents iSelMng3D As Kompas6API5.SelectionMng
	Public WithEvents iSpcObjects As KompasAPI7.SpecificationBaseObjects
	Public WithEvents iSpcObject As KompasAPI7.SpecificationObject

	
	Public libraryName As String
	
	' Комманда 1
  ' Подписаться на события текущего документа
  Sub Command1()
    '    Dim flag As Boolean ' признак удачного завершения
    Dim newDoc As Object ' текущий документ
    newDoc = iKompasObject.ActiveDocument2D ' попробуем взять 2Д документ

    ' текущим является 2Д документ и мы еще на него не подписаны
    If Not newDoc Is Nothing And iDoc2D Is Nothing Then
      iDoc2D = newDoc ' подпишемся на его события
    Else ' текущий документ не 2Д
      newDoc = iKompasObject.ActiveDocument3D ' попробуем взять 3Д документ

      ' текущим является 3Д документ и мы еще на него не подписаны
      If Not newDoc Is Nothing And iDoc3D Is Nothing Then
        iDoc3D = newDoc ' подпишемся на его события
      Else ' текущий документ не 3Д
        newDoc = iKompasObject.SpcActiveDocument ' попробуем взять СП документ

        ' текущим является СП документ и мы еще на него не подписаны
        If Not newDoc Is Nothing And iDocSpc Is Nothing Then
          iDocSpc = newDoc ' подпишемся на его события
        Else ' текущий документ не СП
          newDoc = iKompasObject.ActiveDocumentTxt ' попробуем взять текстовый документ

          ' текущим является текстовый документ и мы еще на него не подписаны
          If Not newDoc Is Nothing And iDocTxt Is Nothing Then
            iDocTxt = newDoc ' подпишемся на его события
          End If
        End If
      End If
    End If

    'UPGRADE_NOTE: Object newDoc may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    newDoc = Nothing ' освободим текущий документ
  End Sub
	
	' Комманда 2
  ' Отписаться от событий текущего документа
	
	Sub Command2()
		Dim newDoc As Object ' текущий документ
		newDoc = iKompasObject.ActiveDocument2D ' попробуем взять 2Д документ
		
		' текущим является 2Д документ и мы на него подписаны
		If Not newDoc Is Nothing And Not iDoc2D Is Nothing Then
			'UPGRADE_NOTE: Object iDoc2D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iDoc2D = Nothing ' отпишемся от событий 2Д документа
		Else ' текущий документ не 2Д
			newDoc = iKompasObject.ActiveDocument3D ' попробуем взять 3Д документ
			
			' текущим является 3Д документ и мы на него подписаны
			If Not newDoc Is Nothing And Not iDoc3D Is Nothing Then
				iDoc3D = newDoc ' отпишемся от событий 3Д документа
			Else ' текущий документ не 3Д
				newDoc = iKompasObject.SpcActiveDocument ' попробуем взять СП документ
				
				' текущим является СП документ и мы на него подписаны
				If Not newDoc Is Nothing And Not iDocSpc Is Nothing Then
					iDocSpc = newDoc ' отпишемся от событий СП документа
				Else ' текущий документ не СП
					newDoc = iKompasObject.ActiveDocumentTxt ' попробуем взять текстовый документ
					
					' текущим является текстовый документ и мы на него подписаны
					If Not newDoc Is Nothing And Not iDocTxt Is Nothing Then
						iDocTxt = newDoc ' отпишемся от событий текстового документа
					End If
				End If
			End If
		End If
		
		'UPGRADE_NOTE: Object newDoc may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		newDoc = Nothing ' освободим текущий документ
	End Sub
	
	' Комманда 3
	' Позволяет подписаться на штамп текущего документа, если уже подписывались
	' на штамп другого или этого же документа, то при подписки на новый штамп
	' на старый произойдет отписка
	
	Sub Command3()
		Dim newDoc As Object ' текущий документ
		newDoc = iKompasObject.ActiveDocument2D ' попробуем взять 2Д документ
		
		Dim doc2D As Kompas6API5.Document2D
		Dim docSp As Kompas6API5.SpcDocument
		Dim Doc As Kompas6API5.DocumentTxt ' интерфейс текстового документа ' интерфейс СП документа ' интерфейс 2Д документа
		If Not newDoc Is Nothing Then ' текущим является 2Д документ
			doc2D = newDoc ' преобразование к 2Д документу
			iStamp = doc2D.GetStamp ' подписаться на события штампа
			'UPGRADE_NOTE: Object doc2D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			doc2D = Nothing ' освободить документ
		Else ' текущий документ не 2Д
			newDoc = iKompasObject.SpcActiveDocument ' попробуем взять СП документ
			
			If Not newDoc Is Nothing Then ' текущим является СП документ
				docSp = newDoc ' преобразование к СП документу
				iStamp = docSp.GetStamp ' подписаться на события штампа
				'UPGRADE_NOTE: Object docSp may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
				docSp = Nothing ' освободить документ
			Else ' текущий документ не СП
				newDoc = iKompasObject.ActiveDocumentTxt ' попробуем взять текстовый документ
				
				If Not newDoc Is Nothing Then ' текущим является текстовый документ
					Doc = newDoc ' преобразование к текстовому документу
					iStamp = Doc.GetStamp ' подписаться на события штампа
					'UPGRADE_NOTE: Object Doc may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
					Doc = Nothing ' освободить документ
				End If
			End If
		End If
		
		'UPGRADE_NOTE: Object newDoc may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		newDoc = Nothing ' освободим текущий документ
	End Sub
	
	' Комманда 4
	' Позволяет отписаться от событий штампа
	
	Sub Command4()
		If Not iStamp Is Nothing Then ' если была подписка на события штампа
			'UPGRADE_NOTE: Object iStamp may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iStamp = Nothing ' отпишемся
		End If
	End Sub
	
	' Комманда 5
  ' Подписаться на события базовых объектов спецификации
	Sub Command5()
		Dim api7 As KompasAPI7.IApplication
		Dim Doc As KompasAPI7.KompasDocument
		If iSpcObjects Is Nothing Then ' если была подписка на события базовых объектов
			api7 = iKompasObject.ksGetApplication7
			If Not api7 Is Nothing Then
				Doc = api7.ActiveDocument
				If Not Doc Is Nothing Then
					iSpcObjects = Doc.SpecificationDescriptions.Active.BaseObjects
				End If
			End If
		End If
	End Sub
	
	' Комманда 6
  ' Отписаться от событий базовых объектов спецификации
	Sub Command6()
		If Not iSpcObjects Is Nothing Then ' если была подписка на события базовых объектов
			'UPGRADE_NOTE: Object iSpcObjects may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iSpcObjects = Nothing ' отпишемся
		End If
	End Sub
	
	' Комманда 7
	
	Sub Command7()
		Dim iSpcBaseObject As KompasAPI7.SpecificationBaseObject
		Dim docs() As String
		If Not iSpcObjects Is Nothing And iSpcObjects.Count > 0 Then ' если была подписка на события базовых объектов
			iSpcBaseObject = iSpcObjects(0)
			'Dim docs As Variant
			'Set docs = iSpcBaseObject.Documents
			'UPGRADE_WARNING: Couldn't resolve default property of object iSpcBaseObject.Documents. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
			docs = iSpcBaseObject.Documents
			iSpcObject = iSpcBaseObject
			
		End If
	End Sub
	
	' Комманда 8
  ' Отписаться от событий базового объета спецификации
	Sub Command8()
		If Not iSpcObject Is Nothing Then ' если была подписка на события базовых объектов
			'UPGRADE_NOTE: Object iSpcObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iSpcObject = Nothing ' отпишемся
		End If
	End Sub
	

	
	'UPGRADE_NOTE: Class_Initialize was upgraded to Class_Initialize_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Private Sub Class_Initialize_Renamed()
    libraryName = My.Resources.LibraryName()  '"Использованиe математических функций"
	End Sub
	Public Sub New()
		MyBase.New()
		Class_Initialize_Renamed()
	End Sub
	
	'UPGRADE_NOTE: Class_Terminate was upgraded to Class_Terminate_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Private Sub Class_Terminate_Renamed()
		'UPGRADE_NOTE: Object iDoc2D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDoc2D = Nothing
		'UPGRADE_NOTE: Object iObject2DNotify may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iObject2DNotify = Nothing
		'UPGRADE_NOTE: Object iStamp may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iStamp = Nothing
		'UPGRADE_NOTE: Object iSelMng2D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iSelMng2D = Nothing
		'UPGRADE_NOTE: Object iSelMng3D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iSelMng3D = Nothing
		'UPGRADE_NOTE: Object iDoc3D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDoc3D = Nothing
		'UPGRADE_NOTE: Object iDocSpc may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDocSpc = Nothing
		'UPGRADE_NOTE: Object iDocTxt may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDocTxt = Nothing
		'UPGRADE_NOTE: Object iKompasObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iKompasObject = Nothing
		'UPGRADE_NOTE: Object iSpcObjects may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iSpcObjects = Nothing
		'UPGRADE_NOTE: Object iSpcObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iSpcObject = Nothing
	End Sub
	Protected Overrides Sub Finalize()
		Class_Terminate_Renamed()
		MyBase.Finalize()
	End Sub
	
	Private Function iDoc2D_Activate() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc2D->Activate")
		iDoc2D_Activate = True
	End Function
	
	Private Function iDoc2D_BeginCloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc2D->BeginCloseDocument")
		iDoc2D_BeginCloseDocument = True
	End Function
	
	Private Function iDoc2D_BeginSaveDocument(ByVal fileName As String) As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc2D->BeginSaveDocument : " & fileName)
		iDoc2D_BeginSaveDocument = True
	End Function
	
	Private Function iDoc2D_CloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc2D->CloseDocument")
		'UPGRADE_NOTE: Object iDoc2D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDoc2D = Nothing
		iDoc2D_CloseDocument = True
	End Function
	
	Private Function iDoc2D_Deactivate() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc2D->Deactivate")
		iDoc2D_Deactivate = True
	End Function
	
	Private Function iDoc2D_SaveDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc2D->SaveDocument")
		iDoc2D_SaveDocument = True
	End Function
	
	Private Function iDoc3D_Activate() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc3D->Activate")
		iDoc3D_Activate = True
	End Function
	
	Private Function iDoc3D_BeginCloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc3D->BeginCloseDocument")
		iDoc3D_BeginCloseDocument = True
	End Function
	
	Private Function iDoc3D_BeginSaveDocument(ByVal fileName As String) As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc3D->BeginSaveDocument : " & fileName)
		iDoc3D_BeginSaveDocument = True
	End Function
	
	Private Function iDoc3D_CloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc3D->CloseDocument")
		'UPGRADE_NOTE: Object iDoc3D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDoc3D = Nothing
		iDoc3D_CloseDocument = True
	End Function
	
	Private Function iDoc3D_Deactivate() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc3D->Deactivate")
		iDoc3D_Deactivate = True
	End Function
	
	Private Function iDoc3D_SaveDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  Doc3D->SaveDocument")
		iDoc3D_SaveDocument = True
	End Function
	
	Private Function iDocSpc_Activate() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocSpc->Activate")
		iDocSpc_Activate = True
	End Function
	
	Private Function iDocSpc_BeginCloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocSpc->BeginCloseDocument")
		iDocSpc_BeginCloseDocument = True
	End Function
	
	Private Function iDocSpc_BeginSaveDocument(ByVal fileName As String) As Boolean
		iKompasObject.ksMessage(libraryName & "  DocSpc->BeginSaveDocument : " & fileName)
		iDocSpc_BeginSaveDocument = True
	End Function
	
	Private Function iDocSpc_CloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocSpc->CloseDocument")
		'UPGRADE_NOTE: Object iDocSpc may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDocSpc = Nothing
		'UPGRADE_NOTE: Object iSpcObjects may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		'UPGRADE_WARNING: Couldn't resolve default property of object iSpcObjects. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
		iSpcObjects = Nothing
		'UPGRADE_NOTE: Object iSpcObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		'UPGRADE_WARNING: Couldn't resolve default property of object iSpcObject. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
		iSpcObject = Nothing
		iDocSpc_CloseDocument = True
		
	End Function
	
	Private Function iDocSpc_Deactivate() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocSpc->Deactivate")
		iDocSpc_Deactivate = True
	End Function
	
	Private Function iDocSpc_SaveDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocSpc->SaveDocument")
		iDocSpc_SaveDocument = True
	End Function
	
	Private Function iDocTxt_Activate() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocTxt->Activate")
		iDocTxt_Activate = True
	End Function
	
	Private Function iDocTxt_BeginCloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocTxt->BeginCloseDocument")
		iDocTxt_BeginCloseDocument = True
	End Function
	
	Private Function iDocTxt_BeginSaveDocument(ByVal fileName As String) As Boolean
		iKompasObject.ksMessage(libraryName & "  DocTxt->BeginSaveDocument : " & fileName)
		iDocTxt_BeginSaveDocument = True
	End Function
	
	Private Function iDocTxt_CloseDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocTxt->CloseDocument")
		'UPGRADE_NOTE: Object iDocTxt may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDocTxt = Nothing
		iDocTxt_CloseDocument = True
	End Function
	
	Private Function iDocTxt_Deactivate() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocTxt->Deactivate")
		iDocTxt_Deactivate = True
	End Function
	
	Private Function iDocTxt_SaveDocument() As Boolean
		iKompasObject.ksMessage(libraryName & "  DocTxt->SaveDocument")
		iDocTxt_SaveDocument = True
	End Function
	
	Private Function iKompasObject_ApplicationDestroy() As Boolean
		iKompasObject.ksMessage(libraryName & "  Application->ApplicationDestroy")
		'UPGRADE_NOTE: Object iKompasObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iKompasObject = Nothing
		iKompasObject_ApplicationDestroy = True
	End Function
	
	Private Function iKompasObject_BeginOpenDocument(ByVal fileName As String) As Boolean
		'iKompasObject.ksMessage libraryName & "  Application->BeginOpenDocumen : " + fileName
		Dim res As Integer
		res = iKompasObject.ksYesNo(libraryName & " Application->BeginOpenDocumen : " & fileName & "?")
		iKompasObject_BeginOpenDocument = Not (res = 0) 'True
	End Function
	
	Private Function iKompasObject_ChangeActiveDocument(ByVal newDoc As Object, ByVal docType As Integer) As Boolean
		iKompasObject.ksMessage(libraryName & "  Application->ChangeActiveDocument")
		iKompasObject_ChangeActiveDocument = True
	End Function
	
	Private Function iKompasObject_CreateDocument(ByVal newDoc As Object, ByVal docType As Integer) As Boolean
		
		'  Select Case docType
		'
		'    Case lt_DocSheetStandart, lt_DocSheetUser, lt_DocFragment
		'      Set iDoc2D = newDoc
		'      Set iObject2DNotify = iDoc2D.GetObject2DNotify(0)
		'      Set iStamp = iDoc2D.GetStamp
		'      Set iSelMng2D = iDoc2D.GetSelectionMngNotify
		'
		'    Case lt_DocPart3D, lt_DocAssemble3D
		'      Set iDoc3D = newDoc
		'      Set iSelMng3D = iDoc3D.GetSelectionMng
		'
		'    Case lt_DocSpc, lt_DocSpcUser
		'      Set iDocSpc = newDoc
		'
		'    Case lt_DocTxtStandart, lt_DocTxtUser
		'      Set iDocTxt = newDoc
		'  End Select
		
		iKompasObject.ksMessage(libraryName & "  Application->CreateDocument")
		iKompasObject_CreateDocument = True
	End Function
	
	Private Function iKompasObject_OpenDocument(ByVal newDoc As Object, ByVal docType As Integer) As Boolean
		iKompasObject.ksMessage(libraryName & "  Application->OpenDocumen")
		
		'  Select Case docType
		'
		'    Case lt_DocSheetStandart, lt_DocSheetUser, lt_DocFragment
		'      Set iDoc2D = newDoc
		'      Set iStamp = iDoc2D.GetStamp
		'      Set iSelMng2D = iDoc2D.GetSelectionMngNotify
		'
		'    Case lt_DocPart3D, lt_DocAssemble3D
		'      Set iDoc3D = newDoc
		'      Set iSelMng3D = iDoc3D.GetSelectionMng
		'
		'    Case lt_DocSpc, lt_DocSpcUser
		'      Set iDocSpc = newDoc
		'
		'    Case lt_DocTxtStandart, lt_DocTxtUser
		'      Set iDocTxt = newDoc
		'  End Select
		
		iKompasObject_OpenDocument = True
	End Function
	
	Private Function iSelMng2D_Select(ByVal obj As Object) As Boolean
		iKompasObject.ksMessage(libraryName & "  SelMng2D->Select")
		iSelMng2D_Select = True
	End Function
	
	Private Function iSelMng2D_Unselect(ByVal obj As Object) As Boolean
		iKompasObject.ksMessage(libraryName & "  SelMng2D->Unselect")
		iSelMng2D_Unselect = True
	End Function
	
	Private Function iSelMng2D_UnselectAll() As Boolean
		iKompasObject.ksMessage(libraryName & "  SelMng2D->UnselectAll")
		iSelMng2D_UnselectAll = True
	End Function
	
	Private Function iSelMng3D_Select(ByVal obj As Object) As Boolean
		iKompasObject.ksMessage(libraryName & "  SelMng3D->Select")
		'UPGRADE_NOTE: Object obj may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		obj = Nothing
		iSelMng3D_Select = True
	End Function
	
	Private Function iSelMng3D_Unselect(ByVal obj As Object) As Boolean
		iKompasObject.ksMessage(libraryName & "  SelMng3D->Unselect")
		'UPGRADE_NOTE: Object obj may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		obj = Nothing
		iSelMng3D_Unselect = True
	End Function
	
	Private Function iSelMng3D_UnselectAll() As Boolean
		iKompasObject.ksMessage(libraryName & "  SelMng3D->UnselectAll")
		iSelMng3D_UnselectAll = True
	End Function
	
	Private Function iStamp_BeginEditStamp() As Boolean
		Dim res As Integer
		res = iKompasObject.ksYesNo(libraryName & "Редактировать штамп?")
		iStamp_BeginEditStamp = Not (res = 0)
	End Function
	
	Private Function iStamp_EndEditStamp(ByVal editResult As Boolean) As Boolean
		'UPGRADE_NOTE: str was upgraded to str_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
		Dim str_Renamed As String
		If editResult Then
			str_Renamed = " -> штамп отредактирован"
		Else
			str_Renamed = " -> отказались от редактирования"
		End If
		iKompasObject.ksMessage(libraryName & "  Stamp->EndEditStamp" & str_Renamed)
	End Function
	
	Private Function iStamp_StampCellBeginEdit(ByVal number As Integer) As Boolean
		Dim res As Integer
		res = iKompasObject.ksYesNo(libraryName & "Редактировать ячейку с номером " & CStr(number) & "?")
		iStamp_StampCellBeginEdit = Not (res = 0)
	End Function
	
	Private Function iStamp_StampCellDblClick(ByVal number As Integer) As Boolean
		Dim res As Integer
		res = iKompasObject.ksYesNo(libraryName & "Редактировать по DBLCLICK'у ячейку с номером " & CStr(number) & "?")
		iStamp_StampCellDblClick = Not (res = 0)
		
		Dim iDynamicArray As Kompas6API5.ksDynamicArray
		Dim iItemArray As Kompas6API5.ksDynamicArray
		Dim iTextLine As Kompas6API5.ksTextLineParam
		Dim iTextItem As Kompas6API5.ksTextItemParam
		If number = 1 Then
			iStamp.ksOpenStamp()
			
			
			iDynamicArray = iKompasObject.GetDynamicArray(TEXT_LINE_ARR)
			iTextLine = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextLineParam)
			iTextLine.Init()
			iItemArray = iTextLine.GetTextItemArr
			iTextItem = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_TextItemParam)
			iTextItem.Init()
			iTextItem.s = libraryName
			iItemArray.ksAddArrayItem(-1, iTextItem)
			
			iDynamicArray.ksAddArrayItem(-1, iTextLine)
			
			iStamp.ksSetStampColumnText(number, iDynamicArray)
			
			iItemArray.ksDeleteArray()
			iDynamicArray.ksDeleteArray()
			'UPGRADE_NOTE: Object iDynamicArray may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iDynamicArray = Nothing
			'UPGRADE_NOTE: Object iItemArray may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iItemArray = Nothing
			'UPGRADE_NOTE: Object iTextLine may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iTextLine = Nothing
			'UPGRADE_NOTE: Object iTextItem may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iTextItem = Nothing
			
			iStamp.ksCloseStamp()
		End If
	End Function
	
	Private Function iSpcObjects_BeginDelete(ByVal obj As KompasAPI7.ISpecificationObject) As Boolean
		iKompasObject.ksMessage("iSpcObjects_BeginDelete")
		Dim res As Integer
		res = iKompasObject.ksYesNo(libraryName & "Удалить объект?")
		iSpcObjects_BeginDelete = Not (res = 0)
	End Function
	
	Private Function iSpcObjects_CreateObject(ByVal obj As KompasAPI7.ISpecificationObject) As Boolean
		iKompasObject.ksMessage("iSpcObjects_CreateObject")
	End Function
	
	
	Private Function iSpcObject_BeginDelete(ByVal obj As KompasAPI7.ISpecificationObject) As Boolean
		iKompasObject.ksMessage("iSpcObject_BeginDelete")
		Dim res As Integer
		res = iKompasObject.ksYesNo(libraryName & "Удалить объект?")
		iSpcObject_BeginDelete = Not (res = 0)
		If res = 1 Then
			'UPGRADE_NOTE: Object iSpcObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iSpcObject = Nothing
		End If
	End Function
	
	Private Function iSpcObject_Delete(ByVal obj As KompasAPI7.ISpecificationObject) As Boolean
		iKompasObject.ksMessage("iSpcObject_Delete")
		'UPGRADE_NOTE: Object iSpcObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iSpcObject = Nothing
	End Function
	
	Private Function iSpcObject_CreateObject(ByVal obj As KompasAPI7.ISpecificationObject) As Boolean
		iKompasObject.ksMessage("iSpcObject_CreateObject")
	End Function
End Class