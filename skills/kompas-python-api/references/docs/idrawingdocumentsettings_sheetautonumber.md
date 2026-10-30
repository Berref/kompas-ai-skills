# SheetAutoNumber - Автоматическая нумерация листов

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс IDrawingDocumentSettings ](idrawingdocumentsettings.html) > [IDrawingDocumentSettings - свойства ](idrawingdocumentsettings_props.html) |  Scroll [ [ [ ](idrawingdocumentsettings_sheetscount.html "К следующему разделу")](idrawingdocumentsettings_props.html "На уровень выше")](idrawingdocumentsettings_sheetautocount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingdocumentsettings.html)

Тип данных: BOOL

Синтаксис Automation:

SheetAutoNumber = Object.SheetAutoNumber | Получить свойство ([* ](1.html))  
---|---  
Object.SheetAutoNumber = SheetAutoNumber | Установить свойство ([* ](1.html))  
SheetAutoNumber = Object.GetSheetAutoNumber() | Получить свойство ([**](2.html))  
Object.SetSheetAutoNumber( SheetAutoNumber ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SheetAutoNumber( &SheetAutoNumber ) | Получить свойство,  
---|---  
Object.put_SheetAutoNumber( SheetAutoNumber ) | Установить свойство.  
  
Примечание:

Опция, управляющая автонумерацией листов.

•Если опция включена, то всем листам документа автоматически присваиваются порядковые номера.

•Если опция выключена, то графа Номер листа в основной надписи текущего документа не заполняется.

Вы можете ввести произвольный номер для каждого листа документа.

Подразделы:

(отсутствуют)
