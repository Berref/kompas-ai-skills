# GetObject3DNotify - Получить объект обработки событий для объектов 3D документов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getobject3dnotifyresult.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getobjectbyname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

ksObject3DNotify * GetObject3DNotify (long objType, LPDISPATCH obj);

Входные параметры:

Obj | \- указатель на объект,  
---|---  
objType | \- [тип объекта](obj3dtype.html) (o3d_unknown...o3d_sketch, o3d_axis2Planes...o3d_thread, o3d_part, o3d_feature).  
  
Возвращаемое значение:

| \- указатель на интерфейс источника событий [Object3DNotify](object3dnotify.html).  
---|---  
  
Примечание:

Если задан указатель на объект, события генерируются только для этого объекта. Если задан тип объекта, события генерируются для всех объектов этого типа. Если задан тип o3d_unknown, события генерируются для всех объектов.

Подразделы:

(отсутствуют)
