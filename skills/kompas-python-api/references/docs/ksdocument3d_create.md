# Create - Создать документ-модель (деталь или сборку)

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_createpartinassembly.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_copypart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL Create (BOOL invisible, BOOL typeDoc);

Синтаксис COM:

BOOL Create (BOOL invisible, BOOL _typeDoc);

Входные параметры:

invisible | \- признак режима редактирования документа (TRUE - невидимый режим, FALSE - видимый режим),  
---|---  
typeDoc | \- тип документа (TRUE - деталь, FALSE - сборка).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
