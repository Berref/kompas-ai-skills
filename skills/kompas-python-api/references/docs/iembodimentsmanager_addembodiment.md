# AddEmbodiment - Добавляет новое исполнение и делает его текущим

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodimentsManager ](iembodimentsmanager.html) > [IEmbodimentsManager - методы ](iembodimentsmanager_methods.html) |  Scroll [ [ [ ](iembodimentsmanager_addmirrorembodiment.html "К следующему разделу")](iembodimentsmanager_methods.html "На уровень выше")](iembodimentsmanager_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodimentsmanager.html)

Синтаксис Automation:

BOOL AddEmbodiment( VARIANT ParentIndex, BOOL Depended, BSTR BaseMarking, BSTR EmbodimentNumber, BSTR AdditionalNumber );

Синтаксис COM:

HRESULT AddEmbodiment( VARIANT ParentIndex, BOOL Depended, BSTR BaseMarking, BSTR EmbodimentNumber, BSTR AdditionalNumber, BOOL * Result );

Входные параметры:

ParentIndex | \- индекс родительского исполнения,  
---|---  
Marking | \- обозначение исполнения.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
