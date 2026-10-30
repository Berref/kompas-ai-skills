# AddMirrorEmbodiment - Добавляет новое зеркальное исполнение и делает его текущим

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IEmbodimentsManager ](iembodimentsmanager.html) > [IEmbodimentsManager - методы ](iembodimentsmanager_methods.html) |  Scroll [ [ [ ](iembodimentsmanager_addvariant.html "К следующему разделу")](iembodimentsmanager_methods.html "На уровень выше")](iembodimentsmanager_addembodiment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iembodimentsmanager.html)

Синтаксис Automation:

BOOL AddMirrorEmbodiment( VARIANT ParentIndex, BSTR BaseMarking, BSTR EmbodimentNumber, BSTR AdditionalNumber );

Синтаксис COM:

HRESULT AddMirrorEmbodiment( VARIANT ParentIndex, BSTR BaseMarking, BSTR EmbodimentNumber, BSTR AdditionalNumber, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ParentIndex | \- индекс родительского исполнения,  
---|---  
BaseMarking | \- обозначение исполнения,  
EmbodimentNumber | \- номер исполнения,  
AdditionalNumber | \- дополнительный номер.  
  
Подразделы:

(отсутствуют)
