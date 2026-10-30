# SetOrientationObject - Установить объект, обладающий ориентацией

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCSOrientByObjectParam ](ilocalcsorientbyobjectparam.html) > [ILocalCSOrientByObjectParam - методы ](ilocalcsorientbyobjectparam_methods.html) |  Scroll [ [ [ ](ilocalcsobject.html "К следующему разделу")](ilocalcsorientbyobjectparam_methods.html "На уровень выше")](ilocalcsorientbyobjectparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcsaxesdirectionparam.html)

Синтаксис Automation:

HRESULT SetOrientationObject( IModelObject * obj, VARIANT_BOOL * Result );

Синтаксис Automation:

HRESULT SetDirectingObject( ksObj3dTypeEnum axis,

IModelObject * obj,

VARIANT_BOOL * Result );

Входные параметры:

obj | \- объект, обладающий ориентацией.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
