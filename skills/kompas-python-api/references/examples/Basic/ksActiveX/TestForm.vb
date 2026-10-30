Option Strict Off
Option Explicit On
Friend Class TestForm
	Inherits System.Windows.Forms.Form
	
	Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
		Dim iKompasObject As Kompas6API5.Application
		iKompasObject = KGAX.GetKompasObject
		Dim iDocument3D As Kompas6API5.Document3D
		Dim part As Kompas6API5.ksPart
		Dim entitySketch As Kompas6API5.ksEntity
		Dim sketchDef As Kompas6API5.ksSketchDefinition
		Dim basePlane As Kompas6API5.ksEntity
		Dim sketchEdit As Kompas6API5.ksDocument2D
		Dim entityExtr As Kompas6API5.ksEntity
    Dim extrusionDef As Kompas6API5.ksBossExtrusionDefinition
    If Not iKompasObject Is Nothing Then
			'############################################################################
			iDocument3D = iKompasObject.ActiveDocument3D
			If Not iDocument3D Is Nothing Then
				'UPGRADE_WARNING: Couldn't resolve default property of object iDocument3D.GetPart(). Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				'UPGRADE_WARNING: Couldn't resolve default property of object part. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				part = iDocument3D.GetPart(Kompas6Constants3D.Part_Type.pTop_Part) ' новый компонент
				If Not part Is Nothing Then
					entitySketch = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_sketch)
					If Not entitySketch Is Nothing Then
						' интерфейс свойств эскиза
						sketchDef = entitySketch.GetDefinition()
						If Not sketchDef Is Nothing Then
							
							' получим интерфейс базовой плоскости XOY
							basePlane = part.GetDefaultEntity(Kompas6Constants3D.Obj3dType.o3d_planeXOY)
							sketchDef.SetPlane(basePlane) ' установим плоскость XOY базовой для эскиза
							sketchDef.angle = 45 ' угол поворота эскиза
							entitySketch.Create() ' создадим эскиз
							
							' интерфейс редактора эскиза
							sketchEdit = sketchDef.BeginEdit()
							' введем новый эскиз - квадрат
							sketchEdit.ksLineSeg(50, 50, -50, 50, 1)
							sketchEdit.ksLineSeg(50, -50, -50, -50, 1)
							sketchEdit.ksLineSeg(50, -50, 50, 50, 1)
							sketchEdit.ksLineSeg(-50, -50, -50, 50, 1)
							sketchDef.EndEdit() ' завершение редактирования эскиза

              entityExtr = part.NewEntity(Kompas6Constants3D.Obj3dType.o3d_bossExtrusion)
              If Not entityExtr Is Nothing Then
								
								' интерфейс свойств базовой операции выдавливания
								extrusionDef = entityExtr.GetDefinition ' интерфейс базовой операции выдавливания
								If Not extrusionDef Is Nothing Then
									extrusionDef.directionType = Kompas6Constants3D.Direction_Type.dtNormal ' направление выдавливания
									extrusionDef.SetSideParam(True, Kompas6Constants3D.End_Type.etBlind, 200, 0, False)
									extrusionDef.SetThinParam(True, Kompas6Constants3D.Direction_Type.dtBoth, 10, 10) ' тонкая стенка в два направления
									extrusionDef.SetSketch(entitySketch) ' эскиз операции выдавливания
									entityExtr.Create() ' создать операцию
									
									'UPGRADE_NOTE: Object extrusionDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
									extrusionDef = Nothing
								Else
									MsgBox("BAD extrusionDef")
								End If
                KGAX.ZoomEntireDocument()
								'UPGRADE_NOTE: Object entityExtr may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
								entityExtr = Nothing
							Else
								MsgBox("BAD entityExtr")
							End If
							
							'UPGRADE_NOTE: Object sketchDef may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
							sketchDef = Nothing
						Else
							MsgBox("BAD sketchDef")
						End If
						'UPGRADE_NOTE: Object entitySketch may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
						entitySketch = Nothing
					Else
						MsgBox("BAD entitySketch")
					End If
					
					'UPGRADE_NOTE: Object part may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
					part = Nothing
				Else
					MsgBox("BAD Part")
				End If
				'UPGRADE_NOTE: Object iDocument3D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
				iDocument3D = Nothing
			Else
				MsgBox("BAD Document3D")
			End If
			
			'############################################################################
			'UPGRADE_NOTE: Object iKompasObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iKompasObject = Nothing
		Else
			MsgBox("BAD KompasObject")
		End If
	End Sub
	
	Private Sub Command11_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command11.Click
		Dim Index As Short = Command11.GetIndex(eventSender)
		KGAX.OrientationDocument()
	End Sub
	
	Private Sub Command12_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command12.Click
		Dim Index As Short = Command12.GetIndex(eventSender)
		KGAX2D.StopCurrentProcess(True)
	End Sub
	
	Private Sub Command13_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command13.Click
		Dim Index As Short = Command13.GetIndex(eventSender)
		KGAX.StopCurrentProcess(True)
	End Sub
	
	Private Sub Command14_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command14.Click
		Dim Index As Short = Command14.GetIndex(eventSender)
		KGAX.StopCurrentProcess(False)
	End Sub
	
	Private Sub Command15_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command15.Click
		Dim Index As Short = Command15.GetIndex(eventSender)
		KGAX2D.StopCurrentProcess(False)
	End Sub
	
	Private Sub Command16_Click(ByRef Index As Short)
		
	End Sub
	
	Private Sub Command2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command2.Click
		KGAX.ZoomEntireDocument()
	End Sub
	
	Private Sub Command3_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command3.Click
		Dim Index As Short = Command3.GetIndex(eventSender)
		KGAX.Document3DDrawMode = KGAXLib.KDocument3DDrawMode.vt_WireframeMode
	End Sub
	
	Private Sub Command4_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command4.Click
		Dim Index As Short = Command4.GetIndex(eventSender)
		KGAX.Document3DDrawMode = KGAXLib.KDocument3DDrawMode.vt_HiddenRemovedMode
	End Sub
	
	Private Sub Command5_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command5.Click
		KGAX.Document3DDrawMode = KGAXLib.KDocument3DDrawMode.vt_ShadedMode
	End Sub
	
	Private Sub Command6_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command6.Click
		Dim Index As Short = Command6.GetIndex(eventSender)
		Dim iKompasObject As Kompas6API5.Application
		iKompasObject = KGAX2D.GetKompasObject
		Dim iDocument2D As Kompas6API5.Document2D
		If Not iKompasObject Is Nothing Then
			'############################################################################
			iDocument2D = iKompasObject.ActiveDocument2D
			If Not iDocument2D Is Nothing Then
				iDocument2D.ksLineSeg(100, 100, 200, 200, 1)
				iDocument2D.ksLineSeg(200, 100, 100, 200, 0)
				
				'UPGRADE_NOTE: Object iDocument2D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
				iDocument2D = Nothing
			Else
				MsgBox("BAD Document2D")
			End If
			
			'############################################################################
			'UPGRADE_NOTE: Object iKompasObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			iKompasObject = Nothing
		Else
			MsgBox("BAD KompasObject")
		End If
	End Sub
	
	Private Sub Command7_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command7.Click
		Dim Index As Short = Command7.GetIndex(eventSender)
		KGAX.MoveViewDocument()
	End Sub
	
	Private Sub Command8_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command8.Click
		Dim Index As Short = Command8.GetIndex(eventSender)
		KGAX.PanoramaViewDocument()
	End Sub
	
	
	Private Sub Command9_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command9.Click
		Dim Index As Short = Command9.GetIndex(eventSender)
		KGAX.RotateViewDocument()
	End Sub
	
	
	Private Sub KGAX2D_OnKgMouseDown(ByVal eventSender As System.Object, ByVal eventArgs As AxKGAXLib._DKGAXEvents_OnKgMouseDownEvent) Handles KGAX2D.OnKgMouseDown
		
		If eventArgs.nButton <> 2 Then
			eventArgs.proceed = True
		Else
			MsgBox("KgMouseDown")
			eventArgs.proceed = False
		End If
	End Sub
	
	
	Private Sub KGAX_OnKgStopCurrentProcess(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles KGAX.OnKgStopCurrentProcess
		MsgBox("KGAX_OnKgStopCurrentProcess")
	End Sub

  Private Sub KGAX_OnKgMouseDown(ByVal sender As System.Object, ByVal e As AxKGAXLib._DKGAXEvents_OnKgMouseDownEvent) Handles KGAX.OnKgMouseDown
    e.proceed = True

  End Sub

  Private Sub KGAX_OnKgMouseUp(sender As Object, e As AxKGAXLib._DKGAXEvents_OnKgMouseUpEvent) Handles KGAX.OnKgMouseUp
    e.proceed = True
  End Sub
End Class