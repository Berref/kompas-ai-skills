# GetEmbodimentsTree - Дерево исполнений. Массив узлов дерева исполнений SAFEARRAY BSTR - (VT_ARRAY | VT_BSTR)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodimentsManager ](iembodimentsmanager.html) > [IEmbodimentsManager - методы ](iembodimentsmanager_methods.html) |  Scroll [ [ [ ](iembodimentsmanager_getembodimentsvariants.html "К следующему разделу")](iembodimentsmanager_methods.html "На уровень выше")](iembodimentsmanager_getembodimentmarking.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodimentsmanager.html)

Синтаксис Automation:

VARIANT GetEmbodimentsTree( BOOL AddSpaces );

Синтаксис COM:

HRESULT GetEmbodimentsTree( BOOL AddSpaces, VARIANT * Result );

Возвращаемое значение:

Массив SAFEARRAY BSTR - (VT_ARRAY | VT_BSTR);

Входные параметры:

AddSpaces | \- добавлять пробелы.  
---|---  
  
Метод возвращает массив обозначений исполнений.

Примечание:

При AddSpaces = TRUE перед обозначением исполнения добавляется соответствующее уровню вложенности количество пробелов.

Подразделы:

(отсутствуют)
