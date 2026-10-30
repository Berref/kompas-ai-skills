# Find - Найти текст

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - методы ](itext_methods.html) |  Scroll [ [ [ ](itext_replace.html "К следующему разделу")](itext_methods.html "На уровень выше")](itext_edit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Синтаксис Automation:

int64 Find( int64 StartPosition, BSTR SrcText, BOOL Case, BOOL WordOnly );

Синтаксис COM :

RESULT Find( int64 StartPosition, BSTR SrcText, BOOL Case, BOOL WordOnly, int64 * Result );

Возвращаемое значение:

| \- позиция найденного текста.  
---|---  
  
Входные параметры:

StartPosition | \- начальная позиция поиска текста,  
---|---  
SrcText | \- строка поиска,  
Case | \- различать регистр,  
WordOnly | \- только слово целиком.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
