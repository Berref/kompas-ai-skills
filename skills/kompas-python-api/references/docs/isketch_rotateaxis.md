# RotateAxis - Сменить направление оси на противоположное

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Эскиз ](bc2287727.html) > [Интерфейс ISketch ](isketch.html) > [ISketch - методы ](isketch_methods.html) |  Scroll [ [ [ ](isketch_setlocation.html "К следующему разделу")](isketch_methods.html "На уровень выше")](isketch_getpoint3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isketch.html)

Синтаксис Automation:

BOOL RotateAxis( ksObj3dTypeEnum axis );

Синтаксис COM:

HRESULT RotateAxis( ksObj3dTypeEnum axis, BOOL * Result);

Входной параметр:

axis | \- тип оси из перечисления [ksObj3dTypeEnum](obj3dtype.html) (должны передаваться типы : o3d_axisOX o3d_axisOY ).  
---|---  
  
Возвращаемое значение :

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Метод позволяет менять направления осей на противоположные.

2\. Для осей можно выбирать направляющие объекты (см. метод [ISketch::DirectingObject](isketch_directingobject.html), [ISketch::Vector3D](isketch_vector3d.html)).

3\. Можно выбрать направление для оси X или оси Y, третья ось ориентируется, исходя из положения оси Z и выбранной.

4\. Менять направление на противоположное можно только у выбранных осей.

Подразделы:

(отсутствуют)
