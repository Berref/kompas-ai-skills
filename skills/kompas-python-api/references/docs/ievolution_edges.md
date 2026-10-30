# Edges - Траектория. Массив SAFEARRAY кривых, задающих траекторию движения сечения кинематического элемента

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IEvolution ](ievolution.html) > [IEvolution - свойства ](ievolution_propers.html) |  Scroll [ [ [ ](ievolution_evolutionversion.html "К следующему разделу")](ievolution_propers.html "На уровень выше")](ievolution_bysurfacenormal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ievolution.html)

Тип данных: VARIANT

Синтаксис Automation:

Edges = Object.Edges | Получить свойство ([* ](1.html))  
---|---  
Object.Edges = Edges | Установить свойство ([* ](1.html))  
Edges = Object.GetEdges() | Получить свойство ([**](2.html))  
Object.SetEdges( Edges ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Edges( &Edges ) | Получить свойство  
---|---  
Object.put_Edges( Edges ) | Установить свойство  
  
Примечание.

Позволяет получать и устанавливать массив кривых, задающих траекторию движения сечения кинематического элемента.

Массив возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
