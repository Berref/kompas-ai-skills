# RotateAxis - Сменить направление оси на противоположное

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCSAxesDirectionParam ](ilocalcsaxesdirectionparam.html) > [ILocalCSAxesDirectionParam - методы ](ilocalcsaxesdirectionparam_methods.html) |  Scroll [ [ [ ](ilocalcsaxesdirectionparam_setdirectingobject.html "К следующему разделу")](ilocalcsaxesdirectionparam_methods.html "На уровень выше")](ilocalcsaxesdirectionparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcsaxesdirectionparam.html)

Синтаксис Automation:

BOOL RotateAxis( ksObj3dTypeEnum axis );

Синтаксис Automation:

HRESULT RotateAxis( ksObj3dTypeEnum axis,

BOOL * Result);

Входные параметры:

axis | \- тип оси из перечисления [ksObj3dTypeEnum](obj3dtype.html), допустимые значения: \- o3d_axisOX \- o3d_axisOY \- o3d_axisOZ.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет менять направления осей на противоположные.

2\. Для осей можно выбирать направляющие объекты (см. метод [ILocalCSAxesDirectionParam::SetDirectingObject](ilocalcsaxesdirectionparam_setdirectingobject.html)).

3\. Можно выбрать направление для двух осей, третья ось ориентируется, исходя из положения двух выбранных. Менять направление на противоположное можно только у выбранных осей.

4\. У оси с автоориентацией смена направления на противоположное недоступна.

Подразделы:

(отсутствуют)
