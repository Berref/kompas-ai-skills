# ControlPoint - Указатель на элемент, заданный по индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IControlPoints ](icontrolpoints.html) > [IControlPoints - свойства ](icontrolpoints_props.html) |  Scroll [ [ [ ](icontrolpoints_methods.html "К следующему разделу")](icontrolpoints_props.html "На уровень выше")](icontrolpoints_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontrolpoints.html)

Тип данных: указатель на интерфейс [IControlPoint](icontrolpoint.html)

Синтаксис Automation:

ControlPoint = Object.ControlPoint( Index ) | Получить свойство ([* ](1.html))  
---|---  
ControlPoint = Object.GetControlPoint( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ControlPoint( Index, &ControlPoint ) | Получить свойство  
---|---  
  
Входные параметры:

Index | VT_I4 - индекс объекта.  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. В качестве индекса может использоваться индекс в коллекции и reference объекта.

Подразделы:

(отсутствуют)
