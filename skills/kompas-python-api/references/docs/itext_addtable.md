# AddTable - Добавить таблицу в текст (для текстового документа)

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - методы ](itext_methods.html) |  Scroll [ [ [ ](itext_addtextline.html "К следующему разделу")](itext_methods.html "На уровень выше")](itext_addbefore.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Синтаксис Automation:

LPDISPATCH AddTable( long IndexAt,

long RowsCount,

long ColumnsCount,

double RowHeigh,

double ColumnsWidth,

ksTableTileLayoutEnum TitlePos );

Синтаксис COM:

HRESULT AddTable( long IndexAt,

long RowsCount,

long ColumnsCount,

double RowHeigh,

double ColumnsWidth,

ksTableTileLayoutEnum TitlePos,

ITextTable ** Result );

Возвращаемое значение:

Указатель на интерфейс таблицы [ITextTable](itexttable.html)

Входные параметры:

RowsCount | \- количество строк,  
---|---  
ColumnsCount | \- количество столбцов,  
RowHeigh | \- высота строк,  
ColumnsWidth | \- ширина столбцов,  
TitlePos | \- расположение заголовка таблицы (из перечисления [ksTableTileLayoutEnum)](kstabletilelayoutenum.html).  
  
Выходные параметры:

IndexAt | \- индекс строки текста, с которой вставляется таблица.  
---|---  
  
Метод позволяет вставить таблицу в текстовый документ

Подразделы:

(отсутствуют)
