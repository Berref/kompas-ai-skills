# GetObject2DNotify - Получить интерфейс источника событий для 2D документов

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_getobject2dnotifyresult.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_getfragment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Синтаксис Automation:

ksObject2DNotify * GetObject2DNotify (long objType);

Входные параметры:

objType | \- объекты, для которых предназначен данный интерфейс событий.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс источника событий [Object2DNotify](object2dnotify.html).  
---|---  
  
Примечание:

Значением objType является либо [тип объекта](objtypes.html) (ALL_OBJ...AXISLINE_OBJ, VIEW_OBJ), либо указатель на объект.

•Если задан тип объекта, события генерируются для всех объектов этого типа.

•Если задан указатель на объект, события генерируются только для этого объекта.

•Если задан тип объектов ALL_OBJ, события генерируются для всех объектов.

Подразделы:

(отсутствуют)
