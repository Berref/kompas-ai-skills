# MirroringPlacement - Изменить систему координат детали на зеркальную

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_opensourcedocument.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_load.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

BOOL MirroringPlacement( ksObj3dTypeEnum Axis );

Синтаксис COM:

HRESULT MirroringPlacement( ksObj3dTypeEnum Axis, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Axis | \- ось, относительно которой делается симметрия.  
---|---  
  
Подразделы:

(отсутствуют)
