# Closed - Замкнутость

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IPolyLine ](ipolyline.html) > [IPolyLine - свойства ](ipolyline_props.html) |  Scroll [ [ [ ](ipolyline_edges.html "К следующему разделу")](ipolyline_props.html "На уровень выше")](ipolyline_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipolyline.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- пространственная ломаная замкнута,  
---|---  
FALSE | \- пространственная ломаная разомкнута.  
  
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

Свойство позволяет получить/установить разомкнутую или замкнутую ломаную.

Подразделы:

(отсутствуют)
