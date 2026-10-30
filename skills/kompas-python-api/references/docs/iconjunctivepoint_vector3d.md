# Vector3D - Получить параметры вектора

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс IConjunctivePoint ](iconjunctivepoint.html) > [IConjunctivePoint - свойства ](iconjunctivepoint_props.html) |  Scroll [ [ [ ](iconjunctivepoint_methods.html "К следующему разделу")](iconjunctivepoint_props.html "На уровень выше")](iconjunctivepoint_usedirection2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconjunctivepoint.html)

Тип данных: указатель на интерфейс [IVector3D](ivector3d.html)

Синтаксис Automation:

Vector3D = Object.Vector3D( First ) | Получить свойство ([* ](1.html))  
---|---  
Vector3D = Object.GetVector3D( First ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Vector3D( First, &Vector3D ) | Получить свойство  
---|---  
  
Входные параметры:

First | TRUE - вектор, задающий направление оси X, FALSE - вектор, задающий направление оси Y.  
---|---  
  
Примечание.

1\. Свойство позволяет получить интерфейс вектора, задающего направление присоединительной точки.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
