# SetDirectingObject - Установить направляющий объект для оси

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCSAxesDirectionParam ](ilocalcsaxesdirectionparam.html) > [ILocalCSAxesDirectionParam - методы ](ilocalcsaxesdirectionparam_methods.html) |  Scroll [ [ [ ](ilocalcseulerparam.html "К следующему разделу")](ilocalcsaxesdirectionparam_methods.html "На уровень выше")](ilocalcsaxesdirectionparam_rotateaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcsaxesdirectionparam.html)

Синтаксис Automation:

BOOL SetDirectingObject( ksObj3dTypeEnum axis,

LPDISPATCH obj );

Синтаксис Automation:

HRESULT SetDirectingObject( ksObj3dTypeEnum axis,

IModelObject * obj,

VARIANT_BOOL * Result );

Входные параметры:

obj | \- направляющий объект,  
---|---  
axis | \- тип оси из перечисления [ksObj3dTypeEnum](obj3dtype.html), допустимые значения: \- o3d_axisOX \- o3d_axisOY \- o3d_axisOZ.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Объекты, которые могут определять направление оси: прямолинейные объекты, плоские объекты, цилиндрические и конические поверхности. Также могут быть выбраны произвольные кривые или ребра при условии, что позиция начала ЛСК лежит на этой кривой (ребре).

2\. Можно выбрать направление для двух осей. Третья ось ориентируется, исходя из положения двух выбранных. Менять направление на противоположное можно только у выбранных осей. У оси с автоориентацией смена направления на противоположное недоступна.

Подразделы:

(отсутствуют)
