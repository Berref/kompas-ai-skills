Option Strict Off
Option Explicit On

Imports System.Runtime.InteropServices
Imports Microsoft.Win32

'UPGRADE_WARNING: Class instancing was changed to public. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="ED41034B-3890-49FC-8076-BD6FC2F42A85"'
<ClassInterface(ClassInterfaceType.AutoDispatch), System.Runtime.InteropServices.ProgId("EventsVB.Events")> _
Public Class Events
  Dim m_Commands As Commands

  ' GetLibraryName

  Public Function GetLibraryName() As String
    GetLibraryName = My.Resources.LibraryName()
  End Function

  ' ExternalMenuItem

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command As Short) As String
    itemType = 1 'MENUITEM'

    Select Case number
      Case 1
        ExternalMenuItem = My.Resources.cm_1()
        command = 1
      Case 2
        ExternalMenuItem = My.Resources.cm_2()
        command = 2
      Case 3
        ExternalMenuItem = My.Resources.cm_3()
        command = 3
      Case 4
        ExternalMenuItem = My.Resources.cm_4()
        command = 4
      Case 5
        ExternalMenuItem = My.Resources.cm_5()
        command = 5
      Case 6
        ExternalMenuItem = My.Resources.cm_6()
        command = 6
      Case 7
        ExternalMenuItem = My.Resources.cm_7()
        command = 7
      Case 8
        ExternalMenuItem = My.Resources.cm_8()
        command = 8

      Case Else
        itemType = 3 'ENDMENU'
        ExternalMenuItem = ""
        command = -1
    End Select
  End Function

  'ExternalGetToolBarId

  Public Function ExternalGetToolBarId(ByVal barType As Integer, ByRef index As Integer) As Integer
    ExternalGetToolBarId = -1
    If barType = 0 And index = 0 Then
      ExternalGetToolBarId = 203
    End If
  End Function

  ' ExternalRunCommand

  'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal Kompas As Object)
    If m_Commands Is Nothing Then
      m_Commands = New Commands
    End If

    If m_Commands.iKompasObject Is Nothing Then
      m_Commands.iKompasObject = Kompas
    End If

    If m_Commands.iKompasObject Is Nothing Then
      Exit Sub
    End If

    Select Case command_Renamed
      Case 1
        m_Commands.Command1() ' Комманда 1
      Case 2
        m_Commands.Command2() ' Комманда 2
      Case 3
        m_Commands.Command3() ' Комманда 3
      Case 4
        m_Commands.Command4() ' Комманда 4
      Case 5
        m_Commands.Command5() ' Комманда 5
      Case 6
        m_Commands.Command6() ' Комманда 6
      Case 7
        m_Commands.Command7() ' Комманда 7
      Case 8
        m_Commands.Command8() ' Комманда 8

    End Select

    m_Commands.iKompasObject.ksMessageBoxResult()

  End Sub

  'LibInterfaceNotifyEntry

  Public Function LibInterfaceNotifyEntry(ByVal Kompas As Object) As Boolean
    If m_Commands Is Nothing Then
      m_Commands = New Commands
    End If

    If m_Commands.iKompasObject Is Nothing Then
      m_Commands.iKompasObject = Kompas
    End If
  End Function

  'UPGRADE_NOTE: Class_Terminate was upgraded to Class_Terminate_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
  Private Sub Class_Terminate_Renamed()
    'UPGRADE_NOTE: Object m_Commands may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
    m_Commands = Nothing
  End Sub
  Protected Overrides Sub Finalize()
    Class_Terminate_Renamed()
    MyBase.Finalize()
  End Sub

  <ComRegisterFunctionAttribute()> _
  Friend Shared Sub RegisterKompasLib(ByVal typeToRegister As Type)
    Try
      Dim regKey As RegistryKey
      regKey = Registry.LocalMachine
      Dim keyName As String
      keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
      regKey = regKey.OpenSubKey(keyName, True)
      regKey.CreateSubKey("Kompas_Library")
      regKey = regKey.OpenSubKey("InprocServer32", True)
      regKey.SetValue(Nothing, System.Environment.GetFolderPath(Environment.SpecialFolder.System) + "\mscoree.dll")
      regKey.Close()

    Catch e As Exception
      MsgBox(e.Message, MsgBoxStyle.OkOnly)
    End Try

  End Sub

  <ComUnregisterFunctionAttribute()> _
  Friend Shared Sub UnregisterKompasLib(ByVal typeToRegister As Type)
    Dim regKey As RegistryKey
    regKey = Registry.LocalMachine
    Dim keyName As String
    keyName = "SOFTWARE\Classes\CLSID\{" + typeToRegister.GUID.ToString() + "}"
    regKey = regKey.OpenSubKey(keyName, True)
    regKey.DeleteSubKey("Kompas_Library")
    regKey.Close()
  End Sub
End Class