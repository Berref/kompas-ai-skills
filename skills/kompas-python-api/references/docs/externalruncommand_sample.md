# Пример использования функции ExternalRunCommand

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Public Sub ExternalRunCommand(ByVal command As Integer, ByVal mode As Integer, ByVal Kompas As Object)

Select Case command

Case 1

Dim document As Object 'КОМПАС-документ

Set document = Kompas.Document3D '3D-документ

If Not document is Nothing Then

Kompas.ksMessage "Получен 3D-документ"

End If

Set document = Nothing 'освободить документ

Case Else

MsgBox "Команда " + Str(command) + " не выполнена"

End Select

End Sub
