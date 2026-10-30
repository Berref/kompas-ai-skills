# Find - Найти текст, начиная с заданной позиции

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс ITextLine ](itextline.html) > [ITextLine - методы ](itextline_methods.html) |  Scroll [ [ [ ](itextline_inserthypertextreference.html "К следующему разделу")](itextline_methods.html "На уровень выше")](itextline_edit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itextline.html)

Синтаксис Automation :

int64 Find( int64 StartPosition, BSTR SrcText, BOOL Case, BOOL WordOnly );

Синтаксис COM :

HRESULT Find( int64 StartPosition, BSTR SrcText, BOOL Case, BOOL WordOnly, int64 * Result );

Возвращаемое значение:

| Позиция найденного текста или -1, если текст не найден.  
---|---  
  
Входные параметры:

StartPosition | \- начальная позиция для поиска,  
---|---  
SrcText | \- искомая подстрока,  
NewText | \- новая строка,  
Case | \- TRUE - различать регистр, \- FALSE - поиск без учета регистра,  
WordOnly | \- TRUE - только слово целиком,  
  
Версия Компас v21

Подразделы:

(отсутствуют)
