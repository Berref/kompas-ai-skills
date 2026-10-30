# Интерфейс ILayoutSheets

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Листы и оформление ](bb2345331.html) |  Scroll [ [ [ ](ilayoutsheets_props.html "К следующему разделу")](bb2345331.html "На уровень выше")](bb2345331.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции листов оформления.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[ILayoutSheets](ilayoutsheets.html)

Описание:

Управляет массивом интерфейсов листов оформления [ILayoutSheet](ilayoutsheet.html).

Примечание:

1\. После вызова метода Add лист оформления будет добавлен с умолчательными параметрами (заданными в настройках). Для изменения параметров листа нужно изменить их у полученного объекта и вызывать [ILayoutSheet::Update](ilayoutsheet_update.html).

2\. Данный интерфейс может быть получен от интерфейса документа [IKompasDocument](ikompasdocument.html) с помощью свойства [IKompasDocument::LayoutSheets](ikompasdocument_layoutsheets.html).

Подразделы:

[ILayoutSheets - свойства ](ilayoutsheets_props.html)

[ILayoutSheets - методы ](ilayoutsheets_methods.html)
