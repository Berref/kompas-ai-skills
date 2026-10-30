# GetDefaultEntity - Получить указатель на интерфейс объекта, создаваемого системой по умолчанию

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getdensity.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getcountobj.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH GetDefaultEntity (short objType);

Синтаксис COM:

LPENTITY GetDefaultEntity (short objType);

Входной параметр:

objType | \- тип объекта.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс [ksEntity](ksentity.html) или [IEntity](ksentity.html).  
---|---  
  
Типы объектов (objType):

o3d_planeXOY | 1 | \- плоскость XOY  
---|---|---  
o3d_planeXOZ | 2 | \- плоскость XOZ  
o3d_planeYOZ | 3 | \- плоскость YOZ  
o3d_pointCS | 4 | \- точка начала системы координат  
o3d_axisOX | 71 | \- ось OX  
o3d_axisOY | 72 | \- ось OY  
o3d_axisOZ | 73 | \- ось OZ  
  
Подразделы:

(отсутствуют)
