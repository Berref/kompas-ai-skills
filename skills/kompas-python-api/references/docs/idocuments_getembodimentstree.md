# GetEmbodimentsTree - Дерево исполнений

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Коллекция документов ](ap2013730.html) > [Интерфейс IDocuments ](idocuments.html) > [IDocuments - методы ](idocuments_methods.html) |  Scroll [ [ [ ](idocuments_getloadcombinations.html "К следующему разделу")](idocuments_methods.html "На уровень выше")](idocuments_addwithdefaultsettings.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocuments.html)

Синтаксис Automation:

VARIANT GetEmbodimentsTree( BSTR FileName, ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer, BOOL AddSpaces, long * CurrentEmbodiment );

Синтаксис COM:

HRESULT GetEmbodimentsTree( BSTR FileName, ksVariantMarkingTypeEnum MarkingType, BOOL AddSystemDelimer, BOOL AddSpaces, long * CurrentEmbodiment, VARIANT * Tree );

Входные параметры:

FileName | \- Имя файла,  
---|---  
MarkingType | \- Формат возвращаемых обозначений [ksVariantMarkingTypeEnum](ksvariantmarkingtypeenum.html),  
AddSystemDelimer | \- Возвращать системные разделители в обозначении,  
AddSpaces | \- Добавить пробелы для определения уровня исполнения в дереве исполнений,  
CurrentEmbodiment | \- Индекс текущего исполнения в списке исполнений.  
  
Возвращаемое значение:

\- Дерево исполнений. Массив узлов дерева исполнений. SAFEARRAY BSTR - (VT_ARRAY | VT_BSTR)

Подразделы:

(отсутствуют)
