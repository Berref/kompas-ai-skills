# Closed - Замкнутость

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISpline3D ](ispline3d.html) > [ISpline3D - свойства ](ispline3d_props.html) |  Scroll [ [ [ ](ispline3d_constraintlimitobject.html "К следующему разделу")](ispline3d_props.html "На уровень выше")](ispline3d_centerpointtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispline3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- сплайн замкнутый,  
---|---  
FALSE | \- сплайн разомкнутый.  
  
Синтаксис Automation:

Closed = iObject.Closed; | Получить свойство ([* ](1.html))  
---|---  
iObject.Closed = Closed; | Установить свойство ([* ](1.html))  
Closed = iObject.GetClosed(); | Получить свойство ([**](2.html))  
iObject.SetClosed(Closed); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Closed (&Closed) | Получить свойство  
---|---  
iObject->put_Closed (Closed) | Установить свойство  
  
Примечание.

Свойство позволяет получить/установить разомкнутый или замкнутый сплайн.

Подразделы:

(отсутствуют)
