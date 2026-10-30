# AddBefore - Добавить строку перед строкой с заданным индексом

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - методы ](itext_methods.html) |  Scroll [ [ [ ](itext_addtable.html "К следующему разделу")](itext_methods.html "На уровень выше")](itext_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Синтаксис Automation:

LPDISPATCH AddBefore( long Index );

Синтаксис COM:

HRESULT AddBefore([in] long Index, [out, retval] ITextLine ** Value );

Входные параметры:

Index (long) | \- индекс строки, перед которой нужно вставить новую строку.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ITextLine](itextline.html) строка текста.  
---|---  
  
Примечание:

Позволяет добавить строку перед строкой с заданным индексом.

Подразделы:

(отсутствуют)
