# Пример использования функции ExternalMenuItem

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Public Function ExternalMenuItem(ByVal number As Integer, itemType As Integer, command As Integer) As String

itemType = 3 '"ENDMENU"'

ExternalMenuItem = ""

command = -1

Select Case number

Case 1

itemType = 1 'MENUITEM'

ExternalMenuItem = "Создать деталь"

command = 1

Case 2

itemType = 2 'POPUP'

ExternalMenuItem = "Выпадающее меню_1"

command = -1

Case 3

itemType = 1 'MENUITEM'

ExternalMenuItem = "Деталь с фасками"

command = 2

Case 4

itemType = 0 'SEPARATOR'

ExternalMenuItem = ""

command = -1

Case 5

itemType = 1 'MENUITEM'

ExternalMenuItem = "Команда_3"

command = 3

Case 6

itemType = 3 'ENDMENU'

ExternalMenuItem = ""

command = -1

Case 7

itemType = 2 '"POPUP"'

ExternalMenuItem = "Выпадающее меню_2"

command = -1

Case 8

itemType = 1 '"MENUITEM"'

ExternalMenuItem = "Команда_4"

command = 4

Case 9

itemType = 3 '"ENDMENU"'

ExternalMenuItem = ""

command = -1

End Select

End Function
