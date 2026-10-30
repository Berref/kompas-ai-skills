# ReplaceStr - Заменить текст, начиная с заданной позиции

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextLine ](itextline.html) > [ITextLine - методы ](itextline_methods.html) |  Scroll [ [ [ ](itextstyle.html "К следующему разделу")](itextline_methods.html "На уровень выше")](itextline_inserthypertextreference.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextline.html)

Синтаксис Automation:

BOOL ReplaceStr( int64 StartPosition, BSTR SrcText, BSTR NewText, BOOL Case, BOOL WordOnly, BOOL ReplaceAll );

Синтаксис COM :

HRESULT ReplaceStr( int64 StartPosition, BSTR SrcText, BSTR NewText, BOOL Case, BOOL WordOnly, BOOL ReplaceAll, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае изменения текста,  
---|---  
FALSE | \- в случае отмены.  
  
Входные параметры:

StartPosition | \- начальная позиция для поиска,  
---|---  
SrcText | \- искомая подстрока,  
NewText | \- новая строка,  
Case | \- TRUE - различать регистр, \- FALSE - поиск без учета регистра,  
WordOnly | \- TRUE - только слово целиком,  
ReplaceAll | \- TRUE - заменить все вхождения, \- FALSE - заменить только первое вхождение.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
