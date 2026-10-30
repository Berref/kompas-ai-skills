# Degree - Порядок кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbs ](inurbs.html) > [INurbs - свойства ](inurbs_props.html) |  Scroll [ [ [ ](inurbs_periodic.html "К следующему разделу")](inurbs_props.html "На уровень выше")](inurbs_closed.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbs.html)

Тип данных: long

Синтаксис Automation:

Degree = Object.Degree | Получить свойство([* ](1.html))  
---|---  
Object.Degree = Degree | Установить свойство ([* ](1.html))  
Degree = Object.GetDegree() | Получить свойство ([**](2.html))  
Object.SetDegree( Degree ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Degree( &Degree ) | Получить свойство  
---|---  
Object.put_Degree( Degree ) | Установить свойство  
  
Примечание:

Свойство позволяет устанавливать и получать порядок NURBS-кривой.

Для изменения пордка NURBS-кривой нужно, чтобы количество точек было равно или больше устанавливаемого значения, см. [Пример...](example_nurbs_degree.html)

Подразделы:

(отсутствуют)
