# SheetFirstNumber - Номер первого листа

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс IDrawingDocumentSettings ](idrawingdocumentsettings.html) > [IDrawingDocumentSettings - свойства ](idrawingdocumentsettings_props.html) |  Scroll [ [ [ ](idrawingdocumentsettings_sheetstampmassdesignation.html "К следующему разделу")](idrawingdocumentsettings_props.html "На уровень выше")](idrawingdocumentsettings_sheetscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingdocumentsettings.html)

Тип данных: long

Синтаксис Automation:

SheetFirstNumber = Object.SheetFirstNumber | Получить свойство ([* ](1.html))  
---|---  
Object.SheetFirstNumber = SheetFirstNumber | Установить свойство ([* ](1.html))  
SheetFirstNumber = Object.GetSheetFirstNumber() | Получить свойство ([**](2.html))  
Object.SetSheetFirstNumber( SheetFirstNumber ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SheetFirstNumber( &SheetFirstNumber ) | Получить свойство,  
---|---  
Object.put_SheetFirstNumber( SheetFirstNumber ) | Установить свойство.  
  
Примечание:

Свойство задает номер, с которого начнется автоматическая нумерация.

По умолчанию он равен единице. Вы можете задать нужное значение.

Свойство используется при включенной опции Автоматическая нумерация листов ([IDrawingDocumentSettings::SheetAutoNumber](idrawingdocumentsettings_sheetautonumber.html)).

Подразделы:

(отсутствуют)
