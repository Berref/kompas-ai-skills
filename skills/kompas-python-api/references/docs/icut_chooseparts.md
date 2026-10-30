# ChooseParts - Массив компонентов (SAFEARRAY)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс ICut ](icut.html) > [ICut - свойства ](icut_propers.html) |  Scroll [ [ [ ](icut_choosepartstype.html "К следующему разделу")](icut_propers.html "На уровень выше")](icut_choosebodies.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icut.html)

Тип данных: VARIANT

Синтаксис Automation:

ChooseParts = Object.ChooseParts | Получить свойство ([* ](1.html))  
---|---  
Object.ChooseParts = ChooseParts | Установить свойство ([* ](1.html))  
ChooseParts = Object.GetChooseParts() | Получить свойство ([**](2.html))  
Object.SetChooseParts( ChooseParts ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ChooseParts( &ChooseParts ) | Получить свойство  
---|---  
Object.put_ChooseParts( ChooseParts ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать компонент или массив компонентов, участвующих в операции.

Массив возвращается в виде массива SAFEARRAY компонентов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
