# ChooseBodies - Массив тел

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс ICut ](icut.html) > [ICut - свойства ](icut_propers.html) |  Scroll [ [ [ ](icut_chooseparts.html "К следующему разделу")](icut_propers.html "На уровень выше")](icut_buildingtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icut.html)

Тип данных: VARIANT

Синтаксис Automation:

ChooseBodies = Object.ChooseBodies | Получить свойство ([* ](1.html))  
---|---  
Object.ChooseBodies = ChooseBodies | Установить свойство ([* ](1.html))  
ChooseBodies = Object.GetChooseBodies() | Получить свойство ([**](2.html))  
Object.SetChooseBodies( ChooseBodies ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ChooseBodies( &ChooseBodies ) | Получить свойство  
---|---  
Object.put_ChooseBodies( ChooseBodies ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать тело или массив тел, участвующих в операции.

Массив возвращается в виде массива SAFEARRAY тел LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
