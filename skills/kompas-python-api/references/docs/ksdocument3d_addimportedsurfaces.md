# AddImportedSurfaces - Добавить импортированные поверхности

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_addmateconstraint.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_additionformatparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

AddImportedSurfaces (BSTR fileName, BOOL together)

Синтаксис COM:

LPENTITYCOLLECTION AddImportedSurfaces (LPOLESTR fileName, BOOL together)

Входные параметры:

fileName | \- имя файла (*.igs, *.sat) импортированной поверхности,  
---|---  
together | \- Если параметр имеет значение TRUE, то импортированные поверхности будут сшиваться; \- если параметр имеет значение FALSE, то будет импортирован массив импортированных поверхностей.  
  
Возвращаемое значение:

Указатель на интерфейс [ksEntityCollection](ksentitycollection.html) или [IEntityCollection](ksentitycollection.html), | \- в случае успеха,  
---|---  
NULL | \- в случае неудачи.  
  
Примечания:

В документ можно вставить импортированную поверхность из файла, причем в общем случае может импортироваться массив импортированных поверхностей, если together = FALSE.

Подразделы:

(отсутствуют)
