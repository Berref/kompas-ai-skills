# Update - Обновить данные компонента

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextItem ](itextitem.html) > [ITextItem - методы ](itextitem_methods.html) |  Scroll [ [ [ ](itextline.html "К следующему разделу")](itextitem_methods.html "На уровень выше")](itextitem_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextitem.html)

Синтаксис Automation:

BOOL Update();

Синтаксис COM:

HRESULT Update( [out, retval] VARIANT_BOOL* Value );

Возвращаемое значение:

TRUE | \- обновление данных компонента прошло успешно,  
---|---  
FALSE | \- ошибка.  
  
Примечание:

Обновление данных компонента необходимо, так как многие параметры компонента взаимосвязаны и зависят от типа [ksTextItemEnum](kstextitemenum.html). Поэтому менять компоненту в строке нужно целиком.

Подразделы:

(отсутствуют)
