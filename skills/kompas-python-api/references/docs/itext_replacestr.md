# ReplaceStr - Заменить текст, начиная с заданной позиции

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - методы ](itext_methods.html) |  Scroll [ [ [ ](itextfont.html "К следующему разделу")](itext_methods.html "На уровень выше")](itext_replace.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Синтаксис Automation:

BOOL ReplaceStr( int64 StartPosition, BSTR SrcText, BSTR NewText, BOOL Case, BOOL WordOnly, BOOL ReplaceAll );

Синтаксис COM:

HRESULT ReplaceStr( int64 StartPosition, BSTR SrcText, BSTR NewText, BOOL Case, BOOL WordOnly, BOOL ReplaceAll, BOOL * Result );

Входные параметры:

StartPosition | \- начальная позиция поиска текста,  
---|---  
SrcText | \- строка поиска,  
NewText | \- новое значение,  
Case | \- различать регистр,  
WordOnly | \- только слово целиком.  
ReplaceAll | \- заменить все.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
