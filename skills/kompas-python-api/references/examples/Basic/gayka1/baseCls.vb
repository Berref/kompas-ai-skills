Option Strict Off
Option Explicit On
<System.Runtime.InteropServices.ProgId("class1_NET.class1")> Public Class class1
	
	'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Object)
		iKompasObject = kompas_
		iDocument2D = iKompasObject.ActiveDocument2D
		iKomApp = iKompasObject.ksGetApplication7
		Dim Gayka As Object
		Select Case command_Renamed
			Case 1
				Gayka = New GaykaObj
				'UPGRADE_WARNING: Couldn't resolve default property of object Gayka.Draw. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
				Gayka.Draw()
		End Select
		
		'UPGRADE_NOTE: Object iKomApp may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iKomApp = Nothing
		'UPGRADE_NOTE: Object iDocument2D may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iDocument2D = Nothing
		'UPGRADE_NOTE: Object iKompasObject may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
		iKompasObject = Nothing
	End Sub
	
	Public Function GetLibraryName() As String
		GetLibraryName = "Гайки с исп-ем панели свойств"
	End Function
	
	
	'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
		Select Case number
			Case 1
				itemType = 1 'MENUITEM'
				ExternalMenuItem = "Гайка ГОСТ 5915-70 на VB"
				command_Renamed = 1
			Case Else
				itemType = 3 '"ENDMENU"'
				ExternalMenuItem = ""
				command_Renamed = -1
		End Select
	End Function
End Class