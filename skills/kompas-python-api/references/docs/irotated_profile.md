# Profile - Сечение для операции вращения

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IRotated ](irotated.html) > [IRotated - свойства ](irotated_props.html) |  Scroll [ [ [ ](irotated_rotatedtype.html "К следующему разделу")](irotated_props.html "На уровень выше")](irotated_direction.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irotated.html)

Тип данных: указатель на интерфейс [IModelObject](imodelobject.html)

Синтаксис Automation:

Profile = Object.Profile | Получить свойство ([* ](1.html))  
---|---  
Object.Profile = Profile | Установить свойство ([**](2.html))  
Profile = Object.GetProfile() | Получить свойство ([**](2.html))  
Object.SetProfile( Profile ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Profile( &Profile ) | Получить свойство  
---|---  
Object.put_Profile( Profile ) | Установить свойство  
  
Свойство позволяет устанавливать и получать объект, определяющий форму сечения операции. Это может быть эскиз, грань, кривая 3D.

Примечание:

Если в эскизе, задающем сечение, присутствует ось, и ось не задана свойством [IRotated::Axis](irotated_axis.html), то для построения операции будет использоваться ось из эскиза.

Подразделы:

(отсутствуют)
