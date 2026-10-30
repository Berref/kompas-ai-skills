# Update - Обновить данные

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Листы и оформление ](bb2345331.html) > [Интерфейс ILayoutSheet ](ilayoutsheet.html) > [ILayoutSheet - методы ](ilayoutsheet_methods.html) |  Scroll [ [ [ ](isheetformat.html "К следующему разделу")](ilayoutsheet_methods.html "На уровень выше")](ilayoutsheet_getplaceinsideframes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayoutsheet.html)

Синтаксис Automation:

BOOL Update();

Синтаксис COM:

HRESULT Update ([out, retval] VARIANT_BOOL* pVal);

Возвращаемое значение:

TRUE | \- обновление прошло успешно,  
---|---  
FALSE | \- обновить настройки не удалось.  
  
Примечание:

Все изменения, сделанные в данном интерфейсе и интерфейсе формата листа, вступят в силу только после вызова этого метода.

Подразделы:

(отсутствуют)
