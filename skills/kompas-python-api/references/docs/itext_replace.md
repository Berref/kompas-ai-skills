# Replace - Заменить подстроку текста

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - методы ](itext_methods.html) |  Scroll [ [ [ ](itext_replacestr.html "К следующему разделу")](itext_methods.html "На уровень выше")](itext_find.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Синтаксис Automation:

BOOL Replace( BSTR SrcText, BSTR NewText,

BOOL Case,

BOOL WordOnly,

BOOL ReplaceAll );

Синтаксис COM:

HRESULT Replace( BSTR SrcText, BSTR NewText,

BOOL Case,

BOOL WordOnly,

BOOL ReplaceAll, BOOL * Result );

Входные параметры:

SrcText | \- искомая подстрока,  
---|---  
NewText | \- новая строка,  
Case | \- TRUE - различать регистр, \- FALSE - поиск без учета регистра,  
WordOnly | \- TRUE - только слово целиком,  
ReplaceAll | \- TRUE - заменить все вхождения, \- FALSE - заменить только первое вхождение.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
