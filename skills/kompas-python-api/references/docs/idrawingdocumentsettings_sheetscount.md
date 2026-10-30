# SheetsCount - Количество листов

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс IDrawingDocumentSettings ](idrawingdocumentsettings.html) > [IDrawingDocumentSettings - свойства ](idrawingdocumentsettings_props.html) |  Scroll [ [ [ ](idrawingdocumentsettings_sheetfirstnumber.html "К следующему разделу")](idrawingdocumentsettings_props.html "На уровень выше")](idrawingdocumentsettings_sheetautonumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idrawingdocumentsettings.html)

Тип данных: long

Тип данных: BOOL

Синтаксис Automation:

SheetsCount = Object.SheetsCount | Получить свойство ([* ](1.html))  
---|---  
Object.SheetsCount = SheetsCount | Установить свойство ([* ](1.html))  
SheetsCount = Object.GetSheetsCount() | Получить свойство ([**](2.html))  
Object.SetSheetsCount( SheetsCount ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_SheetsCount( &SheetsCount ) | Получить свойство,  
---|---  
Object.put_SheetsCount( SheetsCount ) | Установить свойство.  
  
Примечание:

Свойство, позволяющее задать произвольное число, которое будет занесено в графу Количество листов основной надписи каждого листа текущего документа.

Таким образом можно сформировать документ, являющийся частью другого документа.

Свойство используется если отключена автоматическая нумерация листов ([IDrawingDocumentSettings::SheetAutoCount](idrawingdocumentsettings_sheetautocount.html)).

Подразделы:

(отсутствуют)
