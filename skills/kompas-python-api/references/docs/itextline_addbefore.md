# AddBefore - Добавить компонент строки перед компонентом с заданным индексом

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextLine ](itextline.html) > [ITextLine - методы ](itextline_methods.html) |  Scroll [ [ [ ](itextline_assign.html "К следующему разделу")](itextline_methods.html "На уровень выше")](itextline_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextline.html)

Синтаксис Automation:

LPDISPATCH AddBefore ( long Index );

Синтаксис COM:

HRESULT AddBefore ([in] long Index, [out, retval] ITextItem ** Value );

Выходные параметры:

Index (long) | \- индекс компонента строки, перед которым нужно вставить новый компонент.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ITextItem](itextitem.html) строка текста.  
---|---  
  
Примечание:

Позволяет добавить компонент строки перед компонентом с заданным индексом.

Подразделы:

(отсутствуют)
