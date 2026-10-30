# DirectingObject - Направляющий объект для оси

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCSAxesDirectionParam ](ilocalcsaxesdirectionparam.html) > [ILocalCSAxesDirectionParam - свойства ](ilocalcsaxesdirectionparam_props.html) |  Scroll [ [ [ ](ilocalcsaxesdirectionparam_leadaxis.html "К следующему разделу")](ilocalcsaxesdirectionparam_props.html "На уровень выше")](ilocalcsaxesdirectionparam_anglebyownaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcsaxesdirectionparam.html)

Тип данных: указатель на интерфейс модельного объекта [IModelObject](imodelobject.html)

Синтаксис Automation:

DirectingObject = iObject.DirectingObject( axis ); | Получить свойство ([* ](1.html))  
---|---  
DirectingObject = iObject.GetDirectingObject( axis ); | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DirectingObject( axis, &DirectingObject ); | Получить свойство  
---|---  
  
Входные параметры:

axis | \- тип оси из перечисления [ksObj3dTypeEnum](obj3dtype.html), допустимые значения: \- o3d_axisOX \- o3d_axisOY \- o3d_axisOZ.  
---|---  
  
Примечание:

Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
