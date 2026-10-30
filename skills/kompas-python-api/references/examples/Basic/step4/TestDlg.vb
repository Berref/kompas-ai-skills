Option Strict Off
Option Explicit On

Public Class TestDialog
  Inherits System.Windows.Forms.Form


  Public kompasDocName As String
  Public IdSlide As Short
  Public resurs As String
  'Public doc As Object
  'Public kompasOb As Object

  Private Sub CancelButton_Renamed_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles CancelButton_Renamed.Click
    Me.Close()
  End Sub

  Private Sub TestDialog_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
    kompasDocName = "c:\1.frw"
    IdSlide = 100
    ' для отрисовки слайда из файла ресурса
    '  resurs = kompasOb.ksReadString("Введите имя *.rc файла", "c:\libVB\st4.rc")
  End Sub

  Public Shared Sub TestShowDialog()
    '  Set doc = doc_
    '  Set kompasOb = kompas_
    Dim dlg As TestDialog
    dlg = New TestDialog

    ' создаем диалог - хендл окна компаса не нужен, вижал сам разбирается
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksEnableTaskAccess. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    kompasOb.ksEnableTaskAccess(0) ' закрыть доступ к компасу
    dlg.ShowDialog() ' вывод диалога
    'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksEnableTaskAccess. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    kompasOb.ksEnableTaskAccess(1) ' открыть доступ к компасу
  End Sub

    Private Sub OKButton_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles OKButton.Click
      Me.Close()
    End Sub


  Private Sub TestDialog_Paint(sender As Object, e As PaintEventArgs) Handles MyBase.Paint
    '  kompasOb.ksDrawSlide CLng(ShowFrame.hWnd), IdSlide
    '  kompasOb.ksDrawBitmap CLng(ShowFrame.hWnd), IdSlide
    '  docActive.ksDrawKompasDocument CLng(ShowFrame.hWnd), kompasDocName

    'UPGRADE_WARNING: Couldn't resolve default property of object docActive.Reference. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
    Dim gr As Integer
    If Not docActive Is Nothing And docActive.Reference <> 0 Then
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksNewGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      gr = docActive.ksNewGroup(1)
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksMtr(20, 15, 45, 1, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksLineSeg(-10, 0, 10, 0, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksLineSeg(10, 0, 10, 20, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksLineSeg(10, 20, -10, 20, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksLineSeg. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksLineSeg(-10, 20, -10, 0, 1)
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksDeleteMtr. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksDeleteMtr()
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksEndGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksEndGroup()
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksDrawKompasGroup. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksDrawKompasGroup(CInt(ShowFrame.Handle.ToInt32), gr)
      'UPGRADE_WARNING: Couldn't resolve default property of object docActive.ksDeleteObj. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      docActive.ksDeleteObj(gr)
    Else
      'UPGRADE_WARNING: Couldn't resolve default property of object kompasOb.ksError. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
      kompasOb.ksError("Графический документ не активен")
    End If

    '  Для отладки слайда можно использовать функцию: при изменении файла .rc не нужно
    '  перекомпилировать библиотеку
    '  If Len(resurs) <> 0 Then
    '    kompasOb.ksDrawSlideFromFile CLng(ShowFrame.hWnd), resurs
    '  End If

  End Sub
End Class