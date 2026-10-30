# AddTextLine - Добавить строку c внешними данными

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Текст ](bb2377713.html) > [Интерфейс IText ](itext.html) > [IText - методы ](itext_methods.html) |  Scroll [ [ [ ](itext_addtextlinebefore.html "К следующему разделу")](itext_methods.html "На уровень выше")](itext_addtable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itext.html)

Синтаксис Automation:

LPDISPATCH AddTextLine( ksTextLineType type,

BSTR filename );

Синтаксис COM:

HRESULT AddTextLine( ksTextLineType type,

BSTR filename,

ITextLine ** Value );

Входные параметры:

type | \- тип строки [ksTextLineType](kstextlinetype.html),  
---|---  
filename | \- имя файла - источник вставки.  
  
Возвращаемое значение:

Указатель на интерфейс [ITextLine](itextline.html) строки текста.  
---  
  
Примечание:

1\. В 2D объекте таблица [IDrawingTable](idrawingtable.html) доступна возможность вставки вертикального текста, растрового объекта и фрагмента.

2\. В текстовом документе есть возможность вставки таблицы в текст.

3\. С помощью функции AddTextLine и [AddTextLineBefore](itext_addtextlinebefore.html) можно выполнить вставку следующих объектов через API системы КОМПАС:

\- для типов:

•ksTLText - простой текст,

•ksTLVerticalText - вертикальный текст.

Параметр filename используется для передачи пути к файлу с расширениями txt, rtf и kdw. Из файла будет вставлена первая строчка текста. Если расширение не задано, то параметр filename воспринимается как обычная строка и она добавляется в текст.

•ksTLFragment - вставка фрагмента.

Параметр filename используется для передачи пути к файлу фрагмента системы КОМПАС с расширением frw.

•ksTLRaster - вставка рисунка.

Параметр filename используется для передачи пути к растровым файлам.

•ksTLTable - вставка таблицы.

Параметр filename используется для передачи пути к файлу таблицы с расширением kdw. Не реализовано, вставка таблицы будет доступна в текстовом документе.

4\. Получить и изменить параметры вставленного объекта можно с помощью свойства [ITextLine::TextLineData](itextline_textlinedata.html).

Подразделы:

(отсутствуют)
