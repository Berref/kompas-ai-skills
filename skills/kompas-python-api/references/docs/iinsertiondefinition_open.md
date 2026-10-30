# Open - Открыть документ-источник на редактирование

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) > [Интерфейс IInsertionDefinition ](iinsertiondefinition.html) > [IInsertionDefinition - методы ](iinsertiondefinition_methods.html) |  Scroll [ [ [ ](iinsertionparameters.html "К следующему разделу")](iinsertiondefinition_methods.html "На уровень выше")](iinsertiondefinition_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](iinsertiondefinition.html)

Синтаксис Automation:

LPDISPATCH Open( BOOL Visible,

BOOL ReadOnly );

Синтаксис COM:

HRESULT Open( BOOL Visible,

BOOL ReadOnly,

IKompasDocument2D ** Result );

Выходные параметры:

Visible | \- открыть в видимом режиме (по умолчанию - TRUE),  
---|---  
ReadOnly | \- открыть только для чтения (по умолчанию - FALSE).  
  
Возвращаемое значение:

| \- указатель на интерфейс документа [IKompasDocument2D](ikompasdocument2d.html).  
---|---  
  
Примечание:

Метод позволяет открыть документ-источник на редактирование.

Подразделы:

(отсутствуют)
