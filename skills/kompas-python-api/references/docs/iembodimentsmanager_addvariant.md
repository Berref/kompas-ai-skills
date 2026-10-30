# AddVariant - Добавляет вариант геометрии исполнения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodimentsManager ](iembodimentsmanager.html) > [IEmbodimentsManager - методы ](iembodimentsmanager_methods.html) |  Scroll [ [ [ ](iembodimentsmanager_deleteembodiment.html "К следующему разделу")](iembodimentsmanager_methods.html "На уровень выше")](iembodimentsmanager_addmirrorembodiment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodimentsmanager.html)

Синтаксис Automation:

BOOL AddVariant( VARIANT ParentIndex, BSTR VariantName );

Синтаксис COM:

HRESULT AddVariant( VARIANT ParentIndex, BSTR VariantName, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ParentIndex | \- индекс родительского исполнения,  
---|---  
VariantName | \- наименование варианта геометрии.  
  
Версия КОМПАС v23

Подразделы:

(отсутствуют)
