# GetLoadCombinations - Получить массив типов загрузки в виде массива SAFEARRAY BSTR - (VT_ARRAY | VT_BSTR)

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_getloadcombinationsparam.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_getembodimentstree.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

VARIANT GetLoadCombinations (LPCTSTR PathName, long * CurrentIndex);

Синтаксис COM:

HRESULT GetLoadCombinations([in] BSTR PathName, [out] long * CurrentIndex, [out, retval] VARIANT * Value );

Входные параметры:

PathName | \- полное имя файла документа, состоящее из пути, имени и расширения файла.  
---|---  
  
Выходные параметры:

CurrentIndex | \- текущий индекс типа загрузки, по которому загружается документ по умолчанию.  
---|---  
  
Возвращаемое значение:

тип значения VARIANT - массив типов загрузки в виде массива SAFEARRAY BSTR - (VT_ARRAY | VT_BSTR) |   
---|---  
  
Примечание:

Метод позволяет получить массив типов загрузки документа до открытия документа.

Метод в настоящее время используется только для сборки 3D. У сборки 3D есть три умолчательных способа загрузки, индексы которых соответствуют перечислению [ksLoadStateEnum](ksloadstateenum.html):

Полная | 0 | \- полная загрузка,  
---|---|---  
Пустая | 1 | \- все компоненты не загружены,  
Упрощенная | 2 | \- все компоненты загружены частично.  
  
Кроме этого, могут быть еще и пользовательские типы загрузки.

Подразделы:

(отсутствуют)
