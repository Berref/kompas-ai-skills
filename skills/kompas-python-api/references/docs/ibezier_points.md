# Points - Параметры узлов в виде SAFEARRAY | VT_R8

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IBezier ](ibezier.html) > [IBezier - свойства ](ibezier_props.html) |  Scroll [ [ [ ](ibezier_methods.html "К следующему разделу")](ibezier_props.html "На уровень выше")](ibezier_pointscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ibezier.html)

Тип данных: VARIANT типа VT_ARRAY | VT_R8

Синтаксис Automation:

Points = Object.Points( AllPoints ) | Получить свойство([* ](1.html))  
---|---  
Object.Points( AllPoints ) = Points | Установить свойство ([* ](1.html))  
Points = Object.GetPoints( AllPoints ) | Получить свойство ([**](2.html))  
Object.SetPoints( AllPoints, Points ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Points( AllPoints, &Points ) | Получить свойство  
---|---  
Object.put_Points( AllPoints, Points ) | Установить свойство  
  
Входные параметры:

BOOL AllPoints | \- TRUE - узел в массиве Points представлен опорной точкой и двумя крайними, \- FALSE - узел в массиве Points представлен только опорной точкой.  
---|---  
  
Примечание:

Свойство позволяет устанавливать и получать параметры узлов кривой.

Подразделы:

(отсутствуют)
