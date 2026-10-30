# Пример использования функции ExternalGetImage

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Public Function ExternalGetImage(ByVal command As Integer, enableDelete As Integer) As OLE_HANDLE

Select Case command

Case 1

ExternalGetImage = Image1.Picture.Handle

Case 2

ExternalGetImage = Image2.Picture.Handle

Case 3

ExternalGetImage = Image3.Picture.Handle

Case 4

ExternalGetImage = Image4.Picture.Handle

Case Else

ExternalGetImage = Image5.Picture.Handle

End Select

enableDelete = FALSE

End Function
