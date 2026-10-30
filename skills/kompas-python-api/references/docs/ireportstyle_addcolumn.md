# AddColumn - Добавить колонку

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Таблицы отчетов ](ba1858294.html) > [Интерфейс IReportStyle ](ireportstyle.html) > [IReportStyle - методы ](ireportstyle_methods.html) |  Scroll [ [ [ ](ireportstyle_clear.html "К следующему разделу")](ireportstyle_methods.html "На уровень выше")](ireportstyle_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ireportstyle.html)

Синтаксис Automation:

LPDISPATCH AddColumn( long IndexAt, BSTR Name, IProperty * Property );

Синтаксис COM:

HRESULT AddColumn( long IndexAt, BSTR Name, IProperty * Property, IReportStyleColumn ** Result );

Возвращаемое значение:

| \- указатель на интерфейс колонки стиля.  
---|---  
  
Входные параметры:

IndexAt | \- индекс добавляемой колонки,  
---|---  
Name | \- имя колонки,  
Property | \- указатель на интерфейс свойства, которое будет отображаться в колонке. Можно передать NULL.  
  
Подразделы:

(отсутствуют)
