# AngleByOwnAxis - Угол поворота вокруг собственной оси

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCSAxesDirectionParam ](ilocalcsaxesdirectionparam.html) > [ILocalCSAxesDirectionParam - свойства ](ilocalcsaxesdirectionparam_props.html) |  Scroll [ [ [ ](ilocalcsaxesdirectionparam_directingobject.html "К следующему разделу")](ilocalcsaxesdirectionparam_props.html "На уровень выше")](ilocalcsaxesdirectionparam_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcsaxesdirectionparam.html)

Синтаксис Automation:

iObject.AngleByOwnAxis = AngleByOwnAxis( axis ); | Установить свойство ([* ](1.html))  
---|---  
iObject.SetAngleByOwnAxis( axis, angle ); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->put_AngleByOwnAxis( axis, angle ); | Установить свойство  
---|---  
  
Входные параметры:

axis | \- тип оси из перечисления [ksObj3dTypeEnum](obj3dtype.html), допустимые значения: \- o3d_axisOX \- o3d_axisOY \- o3d_axisOZ,  
---|---  
angle | \- угол поворота.  
  
Примечание:

Свойство доступно только для записи.

Подразделы:

(отсутствуют)
