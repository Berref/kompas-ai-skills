# Add - Создать лист оформления (добавляет лист оформления в коллекцию)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Листы и оформление ](bb2345331.html) > [Интерфейс ILayoutSheets ](ilayoutsheets.html) > [ILayoutSheets - методы ](ilayoutsheets_methods.html) |  Scroll [ [ [ ](ilayoutsheet.html "К следующему разделу")](ilayoutsheets_methods.html "На уровень выше")](ilayoutsheets_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayoutsheets.html)

Синтаксис Automation:

LPDISPATCH Add();

Синтаксис COM:

HRESULT Add ([out, retval] ILayoutSheet ** Result);

Возвращаемое значение:

| \- Указатель на интерфейс листа оформления [ILayoutSheet](ilayoutsheet.html).  
---|---  
  
Примечание:

Лист оформления будет добавлен с умолчательными параметрами (заданными в настройках). Для изменения параметров листа в документе нужно задать его параметры и вызвать метод [ILayoutSheet::Update](ilayoutsheet_update.html).

Подразделы:

(отсутствуют)
