Option Strict Off
Option Explicit On
<System.Runtime.InteropServices.ProgId("Class1_NET.Class1")> Public Class Class1
	' step11 - Пример запроса командного окна
	
	
	Public iKompasObject As Kompas6API5.Application ' Интерфейс KompasObject
	Public doc As Kompas6API5.Document2D ' Интерфейс ksDocument2D
	
	' Функция обратной связи
	' 0 - плоскость, 1 - цилиндр, 2 - ось - состав collection
	
	Public Function CALLBACKPROCCOMMANDWINDOW(ByRef comm As Short, ByRef rInfo As Object) As Short
		iKompasObject.ksMessage("Выполняется команда : " & comm)
		
		' Заменяем заголовок окна в зависимости от выполненной команды
		' аналогично можно заменить и состав дерева команд
		Dim info As Kompas6API5.RequestInfo ' Интерфейс ksRequestInfo
		info = rInfo ' Параметры запроса к системе
		
		If Not info Is Nothing Then
			info.Title = "Последняя выбранная команда : " & comm
			'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			info = Nothing
		End If
		
		' Возвращаемый результат определяет, должна ли система продолжать запрашивать команду :
		' ( TRUE - продолжать, FALSE - завержить работу с окном )
		If comm = 3 Then
			CALLBACKPROCCOMMANDWINDOW = False
		Else
			CALLBACKPROCCOMMANDWINDOW = True
		End If
	End Function
	
	' Определить имя библиотеки
	
	Public Function GetLibraryName() As String
		GetLibraryName = "Пример запроса командного окна" ' Имя библиотеки
	End Function
	
	' Головная функция библиотеки - вызывается при выборе пункта меню библиотеки
	
	' Обращаемся к системе с запросом на создание окна с деревом команд.
	' Если в качестве функции обратного вызова задан NULL,
	' то управление из CommandWindow возвращается немедленно,
	' как только пользователь выберет команду в дереве команд.
	' Прт этом возвращается идентификатор выбранной команды.
	' В противном случае управление вернется, если пользователь закроет окно
	' или функция обратного вызова вернет FALSE, при этом возвращается -1.
	
	'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Public Sub ExternalRunCommand(ByVal command_Renamed As Short, ByVal mode As Short, ByVal kompas_ As Kompas6API5.Application)
		iKompasObject = kompas_ ' Интерфейс приложения КОМПАС
		
		If iKompasObject Is Nothing Then ' Если интерфейс не задан - выходим
			Exit Sub ' и ничего не делаем
		End If
		
		doc = iKompasObject.ActiveDocument2D ' Возьмем интерфейс текущего 2D документа
		
		Dim info As Kompas6API5.RequestInfo ' Интерфейс ksRequestInfo
		' Создать интерфейс параметров запроса к системе
		info = iKompasObject.GetParamStruct(Kompas6Constants.StructType2DEnum.ko_RequestInfo)
		
		' Если нет текущего документа или интерфейс создать не удалось - выходим из процедуры
		Dim command1 As Short
		If Not doc Is Nothing And Not info Is Nothing Then
			info.Init() ' Инициализация интерфейса параметров запроса к системе
			
			info.menuId = 3000 'ID_TREE_CONTENTS      ' Идентификатор меню с составом дерева команд
			info.Title = "Дерево команд" ' Заголовка окна команд
			info.SetCallBackCm("CALLBACKPROCCOMMANDWINDOW", 0, Me) ' Функции обратного вызова
			
			command1 = doc.ksCommandWindow(info) ' Создание меню в диалоговом окне
			iKompasObject.ksMessage("Выбрана команда : " & command1)
			'UPGRADE_NOTE: Object info may not be destroyed until it is garbage collected. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="6E35BFF6-CD74-4B09-9689-3E1A43DF8969"'
			info = Nothing
		End If
		
	End Sub
	
	' Сформировать меню библиотеки
	
	'UPGRADE_NOTE: command was upgraded to command_Renamed. Click for more: 'ms-help://MS.VSCC.v80/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Public Function ExternalMenuItem(ByVal number As Short, ByRef itemType As Short, ByRef command_Renamed As Short) As String
		itemType = 3 '"ENDMENU"'
		ExternalMenuItem = ""
		command_Renamed = -1
		
		Select Case number
			Case 1 ' Команда 1 - Пример запроса командного окна
				itemType = 1 'MENUITEM'
				ExternalMenuItem = "Пример запроса командного окна"
				command_Renamed = 1
			Case 2 ' Завершение формирования меню
				itemType = 3 '"ENDMENU"'
				ExternalMenuItem = ""
				command_Renamed = -1
		End Select
	End Function
End Class