# Пример простейшей программы в среде VB, оформленной в виде ActiveX библиотеки КОМПАС

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) |  Scroll [ [ [ ](cr154576.html "К следующему разделу")](cr119224.html "На уровень выше")](lib_actx_common.html "К предыдущему разделу")  
---|---  
  
Dim iKompasObject As Object 'KompasObject

Dim iDocument2D As Object 'ksDocument2D

Public Function GetLibraryName() As String

GetLibraryName = “Самая простая библиотека”

End Function

Public Sub ExternalRunCommand(ByVal command As Integer, ByVal mode As Integer, ByVal Kompas As Object)

Set iKompasObject = Kompas

If iKompasObject Is Nothing Then

Exit Sub

End If

Set iDocument2D = iKompasObject.ActiveDocument2D

If iDocument2D Is Nothing Then

Exit Sub

End If

iKompasObject.ksMessage “Строим отрезок!”

iDocument2D.ksLineSeg 10, 10, 100, 100, 1 ' x1, y1, x2, y2, тип линии - основная

End Sub

Функция [ExternalRunCommand](externalruncommand.html) \- аналог функции [LibraryEntry](libraryentry.html). Ее наличие обязательно, так как именно ему передает управление КОМПАС при обращении к библиотеке. В данном случае она обеспечивает выдачу сообщения и построение одного единственного объекта чертежа - отрезка.

Подразделы:

[Функции ](cr154576.html)
